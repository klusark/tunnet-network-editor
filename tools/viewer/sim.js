// Tunnet network simulator: JavaScript port of tools/sim.py (same rules, same random
// numbers), plus a save importer/exporter, so the editor runs in a browser with no game.
// Works in the browser (window.TunnetSim) and in Node (require("./sim.js")).
(function (root) {
  "use strict";
  const IN = 0, OUT = 1;
  const SPAM_COLOR = "a93b3b";
  const PORTS = { relay: 2, filter: 2, hub: 3, bridge: 2, endpoint: 1, antenna: 1, tester: 1 };
  const BUILDABLE = { relay: 2, filter: 2, hub: 3 };
  const DEFAULT_FILTER = { port: 0, mask: "*.*.*.*", mask_type: "Filter", collision: "DropInbound",
                           addr: "Dst", action: "Drop", op: "Match" };

  // mulberry32, seeded by FNV over (seed, node, tick): identical to sim.Rng in Python
  class Rng {
    constructor(...parts) {
      let h = 0x811C9DC5;
      for (const p of parts) h = Math.imul(h ^ (p >>> 0), 0x01000193) >>> 0;
      this.a = h >>> 0;
    }
    u32() {
      this.a = (this.a + 0x6D2B79F5) >>> 0;
      let t = this.a;
      t = Math.imul(t ^ (t >>> 15), t | 1) >>> 0;
      t = (t ^ ((t + (Math.imul(t ^ (t >>> 7), t | 61) >>> 0)) >>> 0)) >>> 0;
      return (t ^ (t >>> 14)) >>> 0;
    }
    random() { return this.u32() / 4294967296; }
    randint(a, b) { return a + this.u32() % (b - a + 1); }
    choice(s) { return s[this.u32() % s.length]; }
  }

  const addrMatch = (addr, mask) => { const a = addr.split("."), m = mask.split(".");
    return m.every((d, i) => d === "*" || a[i] === d); };
  const pkt = (color, src, dst, payload, x = 0, f3a = 0, f3b = 0) => ({ color, src, dst, payload, x, f3a, f3b });
  const copy = p => Object.assign({}, p);

  // ---------- reply rules (tools/reply_rules.py) ----------
  function pattern(receiver, address) {
    const p = receiver.split("."), a = address.split(".");
    let x = null;
    for (let i = 0; i < Math.min(p.length, a.length); i++) {
      if (p[i] === "*") continue;
      if (p[i] === "x") { x = a[i]; continue; }
      if (p[i] !== a[i]) return null;
    }
    return x !== null ? x : true;
  }

  class Net {
    // snap: {entity: {type, pos, address, filter, hub_dir, tester, infection, ports:[{peer, peer_port, slots}]}}
    // data: sim_data.json {endpoint_rules, reply_rules, spam_rate}
    constructor(snap, data, seed = 1) {
      this.data = data; this.rules = data.endpoint_rules; this.seed = seed;
      this.nodes = new Map(); this.state = new Map();
      for (const [k, n] of Object.entries(snap)) {
        const e = +k;
        this.nodes.set(e, { type: n.type, address: n.address || null, pos: n.pos, up: n.up, angle: n.angle,
          filter: n.filter ? Object.assign({}, n.filter) : null, hub_dir: n.hub_dir ?? null,
          tester: n.tester ? Object.assign({}, n.tester) : null,
          links: n.ports.map(p => [p.peer ?? null, p.peer_port ?? null]), infected: n.infection === 5 });
        this.state.set(e, n.ports.map(p => [p.slots && p.slots[0] ? copy(p.slots[0]) : null,
                                            p.slots && p.slots[1] ? copy(p.slots[1]) : null]));
      }
      this.drops = []; this.delivered = []; this.sent = []; this.tick = 0;
    }
    clone() {
      const c = Object.create(Net.prototype);
      c.data = this.data; c.rules = this.rules; c.seed = this.seed; c.tick = this.tick;
      c.nodes = new Map([...this.nodes].map(([e, n]) => [e, Object.assign({}, n,
        { links: n.links.map(l => l.slice()), filter: n.filter && Object.assign({}, n.filter),
          tester: n.tester && Object.assign({}, n.tester) })]));
      c.state = new Map([...this.state].map(([e, P]) => [e, P.map(s => [s[0] && copy(s[0]), s[1] && copy(s[1])])]));
      c.drops = []; c.delivered = []; c.sent = [];
      return c;
    }
    drop(tick, e, reason, p) { this.drops.push([tick, e, reason, p]); }

    // ---------- one tick ----------
    transport(tick) {
      const nw = new Map();
      for (const [e, P] of this.state) nw.set(e, P.map(() => [null, null]));
      for (const [e, P] of this.state) {
        P.forEach(([, o], k) => {
          if (!o) return;
          const [peer, pp] = this.nodes.get(e).links[k];
          if (peer === null || pp === null || !nw.has(peer)) { this.drop(tick, e, "sent out an unconnected port", o); return; }
          nw.get(peer)[pp][IN] = o;
        });
      }
      this.state = nw;
    }
    nodeUpdates(tick) {
      for (const [e, P] of this.state) {
        const fn = this["upd_" + this.nodes.get(e).type];
        if (fn) { this.rng = new Rng(this.seed, e, tick); fn.call(this, e, P, tick); }
      }
    }
    step(tick) { this.transport(tick); this.nodeUpdates(tick); this.tick = tick; }

    // ---------- node rules ----------
    upd_relay(e, P) {
      if (P.length >= 2) {
        if (P[0][IN]) P[1][OUT] = copy(P[0][IN]);
        if (P[1][IN]) P[0][OUT] = copy(P[1][IN]);
      }
    }
    upd_hub(e, P) {
      const d = this.nodes.get(e).hub_dir, n = P.length;
      for (let i = 0; i < n; i++) if (P[i][IN]) P[(i + (d ? n - 1 : 1)) % n][OUT] = copy(P[i][IN]);
    }
    upd_filter(e, P, tick) {
      const f = this.nodes.get(e).filter, p = +f.port, q = 1 - p;
      let a = P[p][IN];
      if (a) {
        a = copy(a);
        if (a.f3a === 1) {
          if (a.x <= 1) { this.drop(tick, e, "out of bounces at a filter", a); a = null; } else a.x -= 1;
        }
      }
      if (a) {
        const field = f.addr === "Dst" ? a.dst : a.src;
        const hit = addrMatch(field, f.mask) === (f.op === "Match");
        if (hit && f.action === "Drop") this.drop(tick, e, "filter rule", a);
        else if (hit) P[p][OUT] = a;
        else P[q][OUT] = a;
      }
      let b = P[q][IN];
      if (b) {
        b = copy(b);
        if (!P[p][OUT]) P[p][OUT] = b;
        else if (f.collision === "DropInbound") { this.drop(tick, e, "filter collision: waiting packet replaced", P[p][OUT]); P[p][OUT] = b; }
        else if (f.collision === "DropOutbound") this.drop(tick, e, "filter collision: arriving packet dropped", b);
        else P[q][OUT] = b;
      }
    }
    upd_endpoint(e, P, tick) {
      const me = this.nodes.get(e).address, port = P[0], a = port[IN];
      const received = !!a && a.dst === me;
      if (a) {
        if (a.dst === me) {
          this.delivered.push([tick, e, a]);
          port[OUT] = this.reply(me, a);
          if (port[OUT]) this.sent.push([tick, e, port[OUT]]);
        } else if (a.src === me) this.drop(tick, e, "returned to sender", a);
        else if (a.f3b) this.drop(tick, e, "no-bounce packet at wrong endpoint", a);
        else if (a.f3a && a.x <= 1) this.drop(tick, e, "out of bounces at wrong endpoint", a);
        else { const b = copy(a); b.x -= b.f3a; port[OUT] = b; }
      }
      if (!port[OUT] && !received) {
        const g = this.generate(me, tick);
        if (g) { port[OUT] = g; this.sent.push([tick, e, g]); }
        else if (this.nodes.get(e).infected && this.rng.random() < (this.data.spam_rate[me] ?? 0.2)) {
          const d = me.split(".");
          port[OUT] = pkt(SPAM_COLOR, me, `${d[0]}.${d[1]}.${this.rng.randint(0, 3)}.${this.rng.randint(0, 3)}`, "spam");
          this.sent.push([tick, e, port[OUT]]);
        }
      }
    }
    replyTo(receiver, src, text, color) {
      for (const r of this.data.reply_rules) {
        const m = pattern(r.receiver, receiver);
        if (m === null || r.boss) continue;
        const x = receiver.split(".")[1];
        if (r.match_src && src !== r.match_src.replace("x", x)) continue;
        if (r.match_text && text !== r.match_text) continue;
        const body = r.reply === "the shop catalogue" ? "(shop catalogue)"
          : r.reply.replace("{received text}", text).replace("{random number}", "{n}");
        return { src: r.keep_src ? src : receiver, dst: r.to === "sender" ? src : r.to, text: body,
                 color: r.color || color, no_bounce: !!r.no_bounce, bounce_budget: r.bounce_budget ?? null };
      }
      return null;
    }
    reply(me, a) {
      const r = this.replyTo(me, a.src, a.payload, a.color);
      if (!r) return null;
      const text = r.text.replace("{n}", String(this.rng.randint(1, 99)));
      return pkt(r.color || a.color, r.src, r.dst, text, r.bounce_budget || 0, r.bounce_budget ? 1 : 0, r.no_bounce ? 1 : 0);
    }
    generate(me, tick) {
      const r = this.rules[me];
      if (!r) return null;
      const s = r.slots[String(tick % r.cycle)];
      if (!s) return null;
      const choice = this.rng.choice(s.messages);
      const hex = this.rng.u32().toString(16).padStart(8, "0");   // drawn always, as in Python
      const budget = s.bounce_budget ?? null;
      return pkt(s.color || r.color, me, s.dst, choice.replace("{}", hex), budget || 0,
                 budget !== null ? 1 : 0, s.no_bounce ? 1 : 0);
    }
    upd_bridge(e, P) {
      const swap = { "0": "1", "1": "0" };
      for (const [frm, to] of [[0, 1], [1, 0]]) {
        let pk = frm < P.length ? P[frm][IN] : null;
        if (!pk || to >= P.length) continue;
        pk = copy(pk);
        for (const f of ["src", "dst"]) pk[f] = (swap[pk[f][0]] ?? pk[f][0]) + pk[f].slice(1);
        const d0 = pk.dst[0], d1 = pk.dst[2];
        if (d0 === "1" || d0 === "*") { pk.f3a = 1; pk.x = (d1 === "3" || d1 === "*") ? 6 : 4; }
        else { pk.f3a = 0; if (d1 === "1" || d1 === "*") pk.f3b = 1; }
        if (this.nodes.get(e).links[to][0] !== null) P[to][OUT] = pk;
      }
    }
    upd_antenna(e, P) {
      const n = this.nodes.get(e);
      if (n.partner === undefined) {
        const others = [...this.nodes].filter(([x, m]) => m.type === "antenna" && x !== e).map(([x]) => x);
        n.partner = others.length === 1 ? others[0] : null;
      }
      const pp = n.partner !== null ? this.state.get(n.partner) : null;
      if (pp && pp[0][IN]) P[0][OUT] = copy(pp[0][IN]);
    }
    upd_tester(e, P, tick) {
      const t = this.nodes.get(e).tester, f = Math.max(1, t ? +t.freq : 1);
      if (!t || t.mode !== "Repeat" || tick % f !== 0) return;
      const d = t.destination.split(".");
      let n = Math.floor(tick / f);
      for (const i of d.map((x, i) => x === "*" ? i : -1).filter(i => i >= 0).reverse()) { d[i] = String(n % 4); n = Math.floor(n / 4); }
      P[0][OUT] = pkt("a0938e", t.address, d.join("."), "PING");
    }
  }

  // ---------- edits (same shapes as sim.apply_edits) ----------
  function applyEdits(net, edits) {
    for (const ed of edits) {
      const k = ed.kind;
      if (k === "add") {
        if (!BUILDABLE[ed.type]) throw new Error("only relays, filters and hubs can be added");
        const e = +ed.id, cfg = ed.config || {};
        net.nodes.set(e, { type: ed.type, address: null, pos: ed.pos.slice(), up: ed.up ?? null, angle: ed.angle ?? null,
          like: ed.like ?? null, added: true,
          filter: ed.type === "filter" ? Object.assign({}, DEFAULT_FILTER, cfg) : null,
          hub_dir: ed.type === "hub" ? +(cfg.hub_dir || 0) : null, tester: null,
          links: Array.from({ length: BUILDABLE[ed.type] }, () => [null, null]), infected: false });
        net.state.set(e, Array.from({ length: BUILDABLE[ed.type] }, () => [null, null]));
      } else if (k === "remove") {
        const n = net.nodes.get(ed.e);
        n.links.forEach(([peer, pp]) => { if (peer !== null && pp !== null) net.nodes.get(peer).links[pp] = [null, null]; });
        net.nodes.delete(ed.e); net.state.delete(ed.e);
      } else if (k === "filter") Object.assign(net.nodes.get(ed.e).filter, ed.config);
      else if (k === "hub") net.nodes.get(ed.e).hub_dir = +ed.config.hub_dir;
      else if (k === "tester") Object.assign(net.nodes.get(ed.e).tester, ed.config);
      else if (k === "link" && ed.op === "disconnect") {
        const n = net.nodes.get(ed.e), [peer, pp] = n.links[ed.p];
        n.links[ed.p] = [null, null];
        if (peer !== null && pp !== null) net.nodes.get(peer).links[pp] = [null, null];
      } else if (k === "link" && ed.op === "connect") {
        const [a, ap] = ed.a, [b, bp] = ed.b;
        net.nodes.get(a).links[ap] = [b, bp]; net.nodes.get(b).links[bp] = [a, ap];
      } else throw new Error("unknown edit " + JSON.stringify(ed));
    }
  }

  function run(net, startTick, ticks) {
    for (let t = startTick + 1; t <= startTick + ticks; t++) net.step(t);
    return net;
  }

  function summarize(net, ticks) {
    const name = e => { const n = net.nodes.get(e); return n ? (n.address || `${n.type} #${e}`) : `#${e}`; };
    const spam = p => p.color === SPAM_COLOR;
    const count = (rows, keyf) => { const c = {}; for (const r of rows) { const k = keyf(r); c[k] = (c[k] || 0) + 1; } return c; };
    const sum = c => Object.values(c).reduce((a, b) => a + b, 0);
    const top = (c, n) => Object.fromEntries(Object.entries(c).sort((a, b) => b[1] - a[1]).slice(0, n));
    const dl = count(net.delivered.filter(r => !spam(r[2])), r => name(r[1]));
    const sd = count(net.delivered.filter(r => spam(r[2])), r => name(r[1]));
    const snt = count(net.sent.filter(r => !spam(r[2])), r => name(r[1]));
    const dr = count(net.drops.filter(r => !spam(r[3])), r => r[2]);
    const drs = count(net.drops.filter(r => spam(r[3])), r => r[2]);
    const where = count(net.drops.filter(r => !spam(r[3])), r => `${name(r[1])}: ${r[2]}`);
    return { ticks, delivered: sum(dl), sent: sum(snt), spam_delivered: sum(sd), spam_dropped: sum(drs),
             dropped: sum(dr), drop_reasons: dr, drop_places: top(where, 15), delivered_by_endpoint: dl,
             sent_by_endpoint: snt, spam_delivered_to: sd };
  }

  function whatIf(net, edits, ticks, seed = 1) {
    const base = net.clone(); base.seed = seed;
    const alt = net.clone(); alt.seed = seed;
    applyEdits(alt, edits);
    const t0 = net.tick;
    run(base, t0, ticks); run(alt, t0, ticks);
    return { baseline: summarize(base, ticks), what_if: summarize(alt, ticks) };
  }

  // ---------- save import / export (tools/save_import.py, tools/save_export.py) ----------
  const NAME_DIGIT = { Zero: "0", One: "1", Two: "2", Three: "3", Wildcard: "*" };
  const DIGIT_NAME = Object.fromEntries(Object.entries(NAME_DIGIT).map(([k, v]) => [v, k]));
  const LISTS = { relays: "relay", filters: "filter", hubs: "hub", testers: "tester", endpoints: "endpoint",
                  antennas: "antenna", bridges: "bridge" };
  const TYPE_LIST = Object.fromEntries(Object.entries(LISTS).map(([k, v]) => [v, k]));
  const INFECTION = { Hack: 5, MainframeBio: 8 };
  const ACTION_IN = { DropPacket: "Drop", SendBackPacket: "SendBack" };
  const ACTION_OUT = { Drop: "DropPacket", SendBack: "SendBackPacket" };
  const addrOf = a => a.elements.map(d => NAME_DIGIT[d]).join(".");
  const addrJson = (t, typ) => ({ elements: t.split(".").map(d => DIGIT_NAME[d]), address_type: typ });

  function importSave(save) {
    const typ = {}, entry = {};
    for (const [lst, t] of Object.entries(LISTS)) for (const r of save[lst] || []) { typ[r.node] = t; entry[r.node] = r; }
    const snap = {};
    save.nodes.forEach((n, i) => {
      const t = typ[i], r = entry[i];
      if (!t) throw new Error(`node ${i} has no type entry`);
      const node = { type: t, pos: n.pos, up: n.up, angle: n.angle,
        ports: Array.from({ length: PORTS[t] }, () => ({ peer: null, peer_port: null, cable: null, slots: [null, null] })) };
      if (t === "endpoint") { node.address = addrOf(r.address); if (r.infection) node.infection = INFECTION[r.infection] ?? 1; }
      else if (t === "filter") { const c = r.config;
        node.filter = { port: c.port, mask: addrOf(c.mask), mask_type: c.mask.address_type, collision: c.collision,
                        addr: c.addr, action: ACTION_IN[c.action], op: c.op }; }
      else if (t === "hub") node.hub_dir = r.dir ? 1 : 0;
      else if (t === "tester") { const c = r.config;
        node.tester = { freq: c.freq, mode: c.mode, address: addrOf(c.address), address_type: c.address.address_type,
                        destination: addrOf(c.destination), destination_type: c.destination.address_type }; }
      snap[i] = node;
    });
    save.edges.forEach(([[a, pa], [b, pb]], k) => {
      Object.assign(snap[a].ports[pa], { peer: b, peer_port: pb, cable: -(k + 1) });
      Object.assign(snap[b].ports[pb], { peer: a, peer_port: pa, cable: -(k + 1) });
    });
    return snap;
  }

  // Rebuild the network sections of `base` (the save that was imported) from `net`.
  // Imported nodes keep their save index as entity id; added nodes have negative ids.
  function exportSave(base, net) {
    const report = { added: [], removed: [], new_links: [], removed_links: [], long_links: [] };
    const oldType = {}, oldEntry = {};
    for (const [lst, t] of Object.entries(LISTS)) for (const r of base[lst] || []) { oldType[r.node] = t; oldEntry[r.node] = r; }
    const order = [...net.nodes.keys()].filter(e => e >= 0).sort((a, b) => a - b)
      .concat([...net.nodes.keys()].filter(e => e < 0).sort((a, b) => b - a));
    const idx = new Map(order.map((e, k) => [e, k]));
    const out = Object.assign({}, base, { nodes: [] });
    const lists = Object.fromEntries(Object.keys(LISTS).map(k => [k, []]));
    const fixedOf = e => (e >= 0 && oldEntry[e] && oldEntry[e].fixed) || false;
    for (const e of order) {
      const n = net.nodes.get(e), k = idx.get(e);
      if (e >= 0) out.nodes.push(base.nodes[e]);
      else {
        const like = n.like != null && net.nodes.get(n.like);
        out.nodes.push({ pos: n.pos, up: n.up || (like && like.up) || [0, 1, 0], angle: n.angle ?? (like ? like.angle : 0) ?? 0 });
        report.added.push(`${n.type} at ${n.pos.map(v => v.toFixed(1)).join(", ")}`);
      }
      const t = n.type;
      let entry;
      if (t === "relay") entry = { node: k, fixed: fixedOf(e), light: (e >= 0 && oldEntry[e].light) || false };
      else if (t === "filter") { const f = n.filter;
        entry = { node: k, config: { port: +f.port, mask: addrJson(f.mask, f.mask_type), addr: f.addr,
          action: ACTION_OUT[f.action], op: f.op, collision: f.collision }, fixed: fixedOf(e) }; }
      else if (t === "hub") entry = { node: k, fixed: fixedOf(e), dir: !!n.hub_dir };
      else if (t === "tester") { const c = n.tester;
        entry = { node: k, config: { address: addrJson(c.address, c.address_type),
          destination: addrJson(c.destination, c.destination_type), mode: c.mode, freq: +c.freq } }; }
      else entry = Object.assign({}, oldEntry[e], { node: k });
      lists[TYPE_LIST[t]].push(entry);
    }
    Object.assign(out, lists);
    for (let i = 0; i < base.nodes.length; i++) if (!net.nodes.has(i)) report.removed.push(`${oldType[i]} #${i}`);
    const oldKind = new Map(), key = (a, pa, b, pb) => a < b || (a === b && pa < pb) ? `${a}:${pa}-${b}:${pb}` : `${b}:${pb}-${a}:${pa}`;
    for (const [[a, pa], [b, pb], kind] of base.edges) oldKind.set(key(a, pa, b, pb), kind);
    const edges = [], seen = new Set(), name = e => net.nodes.get(e).address || `${net.nodes.get(e).type} #${e}`;
    for (const e of order) net.nodes.get(e).links.forEach(([peer, pp], p) => {
      if (peer === null || pp === null) return;
      const back = net.nodes.get(peer).links[pp];
      if (!back || back[0] !== e || back[1] !== p) throw new Error(`link ${e}:${p} -> ${peer}:${pp} is not symmetric`);
      const kk = key(e, p, peer, pp);
      if (seen.has(kk)) return; seen.add(kk);
      edges.push([[idx.get(e), p], [idx.get(peer), pp], e >= 0 && peer >= 0 ? (oldKind.get(kk) ?? 0) : 0]);
      if (!(e >= 0 && peer >= 0 && oldKind.has(kk))) report.new_links.push(`${name(e)}:${p} - ${name(peer)}:${pp}`);
      const a = net.nodes.get(e).pos, b = net.nodes.get(peer).pos;
      const d = Math.hypot(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
      if (d > 6) report.long_links.push(`${name(e)} - ${name(peer)}: ${d.toFixed(1)} units`);
    });
    for (const [kk] of oldKind) if (!seen.has(kk)) report.removed_links.push(kk);
    out.edges = edges;
    report.counts = [`${out.nodes.length} nodes, ${edges.length} links (base save: ${base.nodes.length} nodes, ${base.edges.length} links)`];
    return { save: out, report };
  }

  const api = { Rng, Net, applyEdits, run, summarize, whatIf, importSave, exportSave, addrMatch,
                SPAM_COLOR, PORTS, BUILDABLE, DEFAULT_FILTER };
  if (typeof module !== "undefined" && module.exports) module.exports = api;
  else root.TunnetSim = api;
})(typeof window !== "undefined" ? window : globalThis);
