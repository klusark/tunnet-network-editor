// Offline backend: lets the viewer run with no game and no server. A save file is
// imported into the simulator (sim.js), which then plays the role of the game: it ticks
// in real time, and the viewer's /api/... requests are answered here with the same JSON
// the Python server sends. Edits change the simulated network; exports download a save.
(function () {
  "use strict";
  const S = window.TunnetSim;
  const TYPES = ["endpoint", "relay", "hub", "filter", "bridge", "antenna", "tester", "other"];
  const TICK_S = 0.51;
  const B = window.OfflineBackend = {
    active: false, base: null, name: null, net: null, data: null, speed: 1, paused: false,
    seq: 0, rev: 0, drops: [], dropTotal: 0, nextDropId: 1, paths: new Map(), nextPid: 1,
    sent: new Map(), recv: new Map(), counts: {}, waiters: [], timer: null, story: null,
  };

  B.load = async function (save, name) {
    if (!B.data) B.data = await (await fetch("sim_data.json")).json();
    B.base = save; B.name = name; B.story = save.story && save.story.state;
    B.net = new S.Net(S.importSave(save), B.data, 1);
    B.net.tick = 0;
    Object.assign(B, { drops: [], dropTotal: 0, nextDropId: 1, paths: new Map(), sent: new Map(), recv: new Map(),
      counts: { sent: 0, spam_sent: 0, delivered: 0, spam_delivered: 0, spam_dropped: 0, legit_dropped: 0 } });
    B.rev++; B.active = true;
    B.schedule();
  };
  B.schedule = function () {
    clearTimeout(B.timer);
    if (!B.active || B.paused) return;
    B.timer = setTimeout(() => { B.step(); B.schedule(); }, TICK_S * 1000 / B.speed);
  };

  // one simulated tick, with bookkeeping the viewer needs (paths for replays, traffic, drops)
  B.step = function () {
    const net = B.net, t = net.tick + 1;
    const d0 = net.drops.length, s0 = net.sent.length, r0 = net.delivered.length;
    net.step(t);
    const alive = new Set();
    for (const [e, P] of net.state) P.forEach((s, k) => s.forEach((p, slot) => {
      if (!p) return;
      if (!p._id) p._id = B.nextPid++;
      alive.add(p._id);
      let path = B.paths.get(p._id);
      if (!path) B.paths.set(p._id, path = { born: t, steps: [] });
      const last = path.steps[path.steps.length - 1];
      if (!last || last[1] !== e || last[2] !== k || last[3] !== slot) path.steps.push([t, e, k, slot]);
    }));
    for (const [tick, e, p] of net.sent.slice(s0)) {
      const spam = p.color === S.SPAM_COLOR;
      push(B.sent, e, [tick, 0, p.dst, kind(p.payload), spam]);
      B.counts.sent++; B.counts.spam_sent += spam;
    }
    for (const [tick, e, p] of net.delivered.slice(r0)) {
      const spam = p.color === S.SPAM_COLOR;
      push(B.recv, e, [tick, 0, p.src, kind(p.payload), spam]);
      B.counts.delivered++; B.counts.spam_delivered += spam;
    }
    for (const [tick, e, reason, p] of net.drops.slice(d0)) {
      const n = net.nodes.get(e), spam = p.color === S.SPAM_COLOR;
      const path = p._id && B.paths.get(p._id);
      B.drops.push({ id: B.nextDropId++, time: Date.now() / 1000, tick, reason, flag: null,
        node: [e, n ? n.type : "?", n ? n.address : null], pos: n ? n.pos.map(v => Math.round(v * 100) / 100) : [0, 0, 0],
        color: p.color, src: p.src, dst: p.dst, payload: p.payload, spam,
        origin: path ? "sent" : "none", path: path ? path.steps.slice() : [], born_tick: path ? path.born : null,
        path_len: path ? path.steps.length : 0 });
      B.dropTotal++; spam ? B.counts.spam_dropped++ : B.counts.legit_dropped++;
    }
    if (B.drops.length > 3000) B.drops.splice(0, B.drops.length - 3000);
    // forget packets that are gone (delivered, dropped or overwritten)
    for (const id of B.paths.keys()) if (!alive.has(id)) B.paths.delete(id);
    net.drops.length = 0; net.sent.length = 0; net.delivered.length = 0;   // keep memory flat
    B.seq++;
    const w = B.waiters; B.waiters = [];
    for (const f of w) f();
  };
  const kind = payload => payload.startsWith("Re:") ? "Re: (reply)" : payload;
  function push(map, e, row) { let a = map.get(e); if (!a) map.set(e, a = []); a.push(row); if (a.length > 2000) a.splice(0, a.length - 2000); }

  // ---------- API ----------
  const ok = (obj, status = 200) => new Response(JSON.stringify(obj), { status, headers: { "Content-Type": "application/json" } });
  const pub = d => { const { path, ...r } = d; return r; };

  function structure() {
    const nodes = [];
    for (const [e, n] of B.net.nodes) {
      const extra = {};
      if (n.filter) extra.filter = n.filter;
      if (n.type === "hub") extra.hub_dir = n.hub_dir;
      if (n.tester) extra.tester = n.tester;
      nodes.push([e, Math.max(0, TYPES.indexOf(n.type)), ...n.pos.map(v => Math.round(v * 100) / 100), n.address,
                  n.links.map(([peer, pp]) => [peer, pp, peer === null ? null : 0]), extra]);
    }
    nodes.sort((a, b) => a[0] - b[0]);
    return { types: TYPES, nodes };
  }
  function live() {
    const packets = [];
    for (const [e, P] of B.net.state) P.forEach((s, k) => s.forEach((p, slot) => {
      if (p) packets.push([e, k, slot, p.color, p.src, p.dst, p.payload]);
    }));
    return { status: "ok", offline: true, pid: "offline", name: B.name, story: B.story, rev: B.rev,
      tick: B.net.tick, ticked: true, tick_period: TICK_S / B.speed, read_ms: 0, time: Date.now() / 1000, seq: B.seq,
      packets, drops: B.drops.slice(-200).map(pub), drop_total: B.dropTotal, drop_missed: 0, counts: Object.assign({}, B.counts),
      speed: B.speed, paused: B.paused };
  }

  function summarise(rows, peerKey, period) {
    if (!rows || !rows.length) return { count: 0 };
    const ticks = rows.map(r => r[0]), gaps = ticks.slice(1).map((t, i) => t - ticks[i]);
    const span = ticks.length > 1 ? Math.max(1, ticks[ticks.length - 1] - ticks[0]) : 1;
    const cnt = i => { const c = {}; for (const r of rows) c[r[i]] = (c[r[i]] || 0) + 1;
      return Object.entries(c).sort((a, b) => b[1] - a[1]).slice(0, 12); };
    const gs = gaps.slice().sort((a, b) => a - b);
    let schedule = null;
    if (gaps.length && !rows.some(r => r[4])) {
      const p = gs[0], phases = new Set(ticks.map(t => t % p));
      if (p > 0 && phases.size === 1) schedule = { period: p, phase: [...phases][0], skipped: gaps.reduce((s, g) => s + Math.floor(g / p) - 1, 0) };
    }
    return { schedule, count: rows.length, spam: rows.filter(r => r[4]).length,
      per_min: rows.length > 1 ? Math.round(600 * (rows.length - 1) / (span * period)) / 10 : null,
      gap_ticks: gaps.length ? { min: gs[0], median: gs[Math.floor(gaps.length / 2)], max: gs[gs.length - 1] } : null,
      [peerKey]: cnt(2), kinds: cnt(3) };
  }
  function rulesSummary(address, tick) {   // port of server.rules_summary
    const r = B.data.endpoint_rules[address];
    if (!r) return null;
    const slots = r.slots, dc = {}, msgs = [];
    for (const s of Object.values(slots)) { dc[s.dst] = (dc[s.dst] || 0) + 1; for (const m of s.messages) if (!msgs.includes(m)) msgs.push(m); }
    const upcoming = [];
    for (let k = 1; k <= r.cycle && upcoming.length < 6; k++) {
      const s = slots[String((tick + k) % r.cycle)];
      if (s) upcoming.push({ in: k, tick: tick + k, dst: s.dst, messages: s.messages, no_bounce: !!s.no_bounce, bounce_budget: s.bounce_budget ?? null });
    }
    return { cycle: r.cycle, sends_per_cycle: r.sends_per_cycle, color: r.color,
      destinations: Object.entries(dc).sort((a, b) => b[1] - a[1]), messages: msgs,
      no_bounce: Object.values(slots).some(s => s.no_bounce),
      bounce_budgets: [...new Set(Object.values(slots).map(s => s.bounce_budget).filter(v => v != null))].sort(), upcoming };
  }
  function traffic(e) {
    const n = B.net.nodes.get(e), a = n && n.address, per = TICK_S;
    return { entity: e, since_tick: 1, sent: summarise(B.sent.get(e), "to", per), received: summarise(B.recv.get(e), "from", per),
      rules: a ? rulesSummary(a, B.net.tick) : null, replies: (a && B.data.replies[a]) || [], incoming: (a && B.data.incoming[a]) || [] };
  }

  // edits to the simulated "game"
  function writeConfig(kind, body) {
    const n = B.net.nodes.get(+body.e);
    if (!n) throw new Error("no such node");
    const get = { tester: () => n.tester, filter: () => n.filter, hub: () => ({ hub_dir: n.hub_dir }) }[kind];
    const old = JSON.parse(JSON.stringify(get()));
    if (body.expect && JSON.stringify(body.expect) !== JSON.stringify(old)) throw new Error("changed since it was read; reload and retry");
    S.applyEdits(B.net, [{ kind, e: +body.e, config: body.config || {} }]);
    B.rev++;
    return { old, new: JSON.parse(JSON.stringify(get())) };
  }
  function link(body) {
    const N = B.net.nodes;
    if (body.op === "disconnect") {
      const n = N.get(+body.e), l = n && n.links[+body.p];
      if (!l || l[0] === null) throw new Error(`node ${body.e} port ${body.p} is not connected`);
      S.applyEdits(B.net, [{ kind: "link", op: "disconnect", e: +body.e, p: +body.p }]);
      B.rev++; return { op: "disconnect", a: [+body.e, +body.p], b: l.slice() };
    }
    if (body.op === "connect") {
      const [a, ap] = body.a.map(Number), [b, bp] = body.b.map(Number);
      if (a === b) throw new Error("cannot connect a node to itself");
      for (const [e, p] of [[a, ap], [b, bp]]) {
        const n = N.get(e);
        if (!n || !n.links[p]) throw new Error(`node ${e} has no port ${p}`);
        if (n.links[p][0] !== null) throw new Error(`node ${e} port ${p} is already connected; disconnect it first`);
      }
      if (N.get(a).links.some(l => l[0] === b)) throw new Error(`node ${a} already has a link to node ${b}`);
      S.applyEdits(B.net, [{ kind: "link", op: "connect", a: [a, ap], b: [b, bp] }]);
      B.rev++; return { op: "connect", a: [a, ap], b: [b, bp] };
    }
    throw new Error("op must be connect or disconnect");
  }
  function exportSave(body) {
    const net = B.net.clone();
    S.applyEdits(net, body.edits || []);
    const { save, report } = S.exportSave(B.base, net);
    const res = { report, base: "imported", slot: body.slot };
    if (body.write) {
      const name = `slot_${body.slot}.json`;
      const url = URL.createObjectURL(new Blob([JSON.stringify(save, null, 2)], { type: "application/json" }));
      const a = Object.assign(document.createElement("a"), { href: url, download: name });
      document.body.appendChild(a); a.click(); a.remove();
      setTimeout(() => URL.revokeObjectURL(url), 30000);
      res.written = `${name} (downloaded)`;
    }
    return res;
  }

  B.handle = async function (url, opts) {
    const u = new URL(url, location.href), q = u.searchParams, path = u.pathname.replace(/^.*\/api\//, "/api/");
    let body = {};
    if (opts && opts.body) try { body = JSON.parse(opts.body); } catch (e) {}
    try {
      switch (path) {
        case "/api/structure": return ok(structure());
        case "/api/live": {
          const after = +(q.get("after") ?? -1);
          if (B.seq <= after && !B.paused) await new Promise(r => { B.waiters.push(r); setTimeout(r, 5000); });
          if (B.paused && B.seq <= after) await new Promise(r => setTimeout(r, 1000));
          return ok(live());
        }
        case "/api/drops": return ok({ total: B.dropTotal, missed: 0, drops: B.drops.map(pub) });
        case "/api/drop": return ok(B.drops.find(d => d.id === +q.get("id")) || null);
        case "/api/traffic": return ok(traffic(+q.get("e")));
        case "/api/tester": case "/api/filter": case "/api/hub": return ok(writeConfig(path.slice(5), body));
        case "/api/link": return ok(link(body));
        case "/api/sim": {
          const t0 = performance.now();
          const ticks = Math.max(1, Math.min(+(body.ticks || 200), 1000));
          const r = S.whatIf(B.net, body.edits || [], ticks, +(body.seed || 1));
          return ok(Object.assign(r, { start_tick: B.net.tick, seconds: Math.round(performance.now() - t0) / 1000 }));
        }
        case "/api/export": return ok(exportSave(body));
        case "/api/visited": {          // the save's story.visited_chunks
          const v = B.base && B.base.story && B.base.story.visited_chunks;
          return ok({ rev: 1, chunks: v ? v.map(c => [c.x, c.y, c.z]) : null });
        }
        case "/api/slots": return ok([0, 1, 2, 3].map(k => ({ slot: k, size: 0, modified: null })));
      }
      return ok({ error: "unknown " + path }, 404);
    } catch (err) {
      return ok({ error: String(err.message || err) }, 400);
    }
  };

  // route /api/ requests here once a save is loaded (or when there is no server at all)
  const realFetch = window.fetch.bind(window);
  window.fetch = (url, opts) => (B.active && String(url).includes("/api/")) ? B.handle(String(url), opts) : realFetch(url, opts);
})();
