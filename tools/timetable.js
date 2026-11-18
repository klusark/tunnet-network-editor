// Timetable solver for the direct-wired network (tools/directgen.py).
//
// In direct wiring nothing waits and every (sender, destination) pair has its own line, so
// a packet's trip is fixed: it reaches its destination a constant number of ticks after it
// leaves. That makes the whole network an endpoint-only TIMETABLE:
//   - two packets due at the same endpoint on the same tick collide at its merge chain
//     (the one from the line farther up the chain survives, DropOutbound);
//   - an endpoint that receives on one of its scheduled send ticks skips that send.
// Each extra relay on a line moves its arrivals one tick later. This tool
//   1. measures every route once in the full simulator (latency, merge position, and what
//      the packet looks like on arrival, e.g. after a bridge),
//   2. replays the network as endpoints + travel times only (same endpoint rules and the
//      same random numbers, which are drawn per endpoint and tick),
//   3. searches extra relays per line to maximise delivery, counting skipped sends as lost.
//
//   node tools/timetable.js base_save.json lines.json out_delays.json [ticks]
// base_save.json must be generated with NO extra delays; lines.json is
// {"a -> d": merge position} (written by tools/timetable.py, which drives all of this).
const fs = require("fs"), path = require("path");
const S = require(path.join(__dirname, "viewer", "sim.js"));
const data = JSON.parse(fs.readFileSync(path.join(__dirname, "viewer", "sim_data.json")));
const norm = a => (a && a[0] === "1" ? "0" + a.slice(1) : a);   // network-0 view of an address
const lineOf = (src, dst) => norm(src) + " -> " + norm(dst);

// ---------- lines ----------
// lines.json is either directgen's {"a -> d": merge position} (every flow its own line into
// d's merge chain) or hybridgen's {paths, markers, feeders}: a flow's path is a list of
// [sink, merge position, feeder cable]; sinks are trunks ("bus:...", collision point = the
// trunk's arrival hub, markers[sink] = its node) and finally the endpoint ("end:d").
// Delays are per feeder cable and shift everything after it.
class Lines {
  constructor(j) {
    this.hybrid = !!j.paths;
    this.paths = j.paths || {}; this.markers = j.markers || {}; this.merge = this.hybrid ? {} : j;
    this.feeders = j.feeders || Object.fromEntries(Object.keys(j).map(k => [k, "end:" + norm(k.split(" -> ")[1])]));
  }
  path(flow) {
    return this.paths[flow] || [["end:" + norm(flow.split(" -> ")[1]), this.merge[flow] ?? 0, flow]];
  }
}

// ---------- 1. measure routes in the full simulator ----------
// Per route (sender | destination as sent): receiving endpoint, travel time to it and to
// every trunk on the way (at the trunk's arrival hub), without the feeder delays (so runs
// with different delays agree), and how the packet looks on arrival.
function measure(save, ticks, delay = {}, routes = new Map(), clash = new Set(), lines = new Lines({})) {
  const net = new S.Net(S.importSave(save), data, 1);
  const origin = new Map();
  const markers = Object.entries(lines.markers).map(([st, e]) => [st, +e]);
  let id = 1;
  for (let t = 1; t <= ticks; t++) {
    net.step(t);
    for (const [tk, e, p] of net.sent) {
      p._id = id++;
      origin.set(p._id, { tk, src: net.nodes.get(e).address, p: Object.assign({}, p), passes: [] });
    }
    for (const [st, e] of markers) {               // packets arriving at a trunk's end
      const P = net.state.get(e), q = P && P[0][0];
      if (q && q._id) { const o = origin.get(q._id); if (o) o.passes.push([st, t]); }
    }
    for (const [tk, e, p] of net.delivered) {
      const o = origin.get(p._id);
      if (!o) continue;
      const key = o.src + "|" + o.p.dst, path = lines.path(lineOf(o.src, o.p.dst));
      const cum = []; let c = 0;
      for (const [, , f] of path) { c += delay[f] || 0; cum.push(c); }
      const buses = path.slice(0, -1);
      if (o.passes.length !== buses.length || o.passes.some(([st], k) => st !== buses[k][0])) { clash.add(key + " (trunks)"); continue; }
      const r = { to: e, lat: tk - o.tk - cum[cum.length - 1], stages: o.passes.map(([, pt], k) => pt - o.tk - cum[k]),
                  src: p.src, dst: p.dst, f3a: p.f3a, f3b: p.f3b, dx: o.p.f3a ? o.p.x - p.x : null, x: o.p.f3a ? null : p.x };
      const old = routes.get(key);
      if (old && (old.lat !== r.lat || old.to !== r.to)) clash.add(key);
      else routes.set(key, r);
    }
    net.sent.length = net.delivered.length = net.drops.length = 0;
  }
  return { routes, clash: [...clash] };
}

// ---------- 2. endpoint-only replay ----------
class Model {
  constructor(save, routes, lines, ticks, settle) {
    this.net = new S.Net(S.importSave(save), data, 1);
    this.routes = routes; this.lines = lines; this.ticks = ticks; this.settle = settle;
    this.ends = [...this.net.nodes].filter(([, n]) => n.type === "endpoint").map(([e]) => e).sort((a, b) => a - b);
    this.addr = new Map(this.ends.map(e => [e, this.net.nodes.get(e).address]));
    // reply rules, pre-filtered per receiver (same logic as Net.replyTo, minus the scan)
    const pattern = (rec, addr) => {
      const p = rec.split("."), q = addr.split("."); let x = null;
      for (let i = 0; i < Math.min(p.length, q.length); i++) {
        if (p[i] === "*") continue;
        if (p[i] === "x") { x = q[i]; continue; }
        if (p[i] !== q[i]) return null;
      }
      return x !== null ? x : true;
    };
    const byReceiver = new Map();
    this.net.replyTo = function (receiver, src, text, color) {
      let rules = byReceiver.get(receiver);
      if (!rules) {
        const x = receiver.split(".")[1];
        rules = data.reply_rules.filter(r => !r.boss && pattern(r.receiver, receiver) !== null)
          .map(r => ({ r, src: r.match_src ? r.match_src.replace("x", x) : null }));
        byReceiver.set(receiver, rules);
      }
      for (const { r, src: ms } of rules) {
        if (ms && src !== ms) continue;
        if (r.match_text && text !== r.match_text) continue;
        const body = r.reply === "the shop catalogue" ? "(shop catalogue)"
          : r.reply.replace("{received text}", text).replace("{random number}", "{n}");
        return { src: r.keep_src ? src : receiver, dst: r.to === "sender" ? src : r.to, text: body,
                 color: r.color || color, no_bounce: !!r.no_bounce, bounce_budget: r.bounce_budget ?? null };
      }
      return null;
    };
    // endpoints that can act with nothing arriving: infected ones (spam) and scheduled senders
    this.idle = new Map(this.ends.map(e => {
      const n = this.net.nodes.get(e), r = data.endpoint_rules[n.address];
      return [e, n.infected ? null : r ? r : false];
    }));
    // required flows and how many scheduled sends each has in the scored window
    this.expected = new Map();
    for (const [a, r] of Object.entries(data.endpoint_rules))
      for (const [slot, s] of Object.entries(r.slots)) {
        const k = a + " -> " + s.dst;
        let n = 0;
        for (let t = 1; t <= ticks - settle; t++) if (t % r.cycle === +slot) n++;
        this.expected.set(k, (this.expected.get(k) || 0) + n);
      }
  }
  run(delay) {
    const net = this.net, T = this.ticks, cutoff = T - this.settle;
    const due = new Array(T + 2);                // tick -> [[to, merge idx, packet, send tick, flow, spam]]
    const per = new Map(), loss = { collision: 0, ttl: 0, unrouted: 0, skipped: 0 };
    const trouble = new Map();                   // sink ("end:a" / "bus:...") -> collisions + skipped sends there
    const hurt = a => trouble.set(a, (trouble.get(a) || 0) + 1);
    const busDue = new Array(T + 2);             // tick -> packets arriving at a trunk's end
    // a packet on its way: path, route, send tick, cumulative feeder delays, next stage k
    const next = (x, k) => {
      if (k < x.path.length - 1) {               // a trunk
        const at = x.t + x.r.stages[k] + x.cum[k];
        if (at <= T) (busDue[at] = busDue[at] || []).push([x.path[k][0], x.path[k][1], x, k]);
      } else {                                   // the endpoint
        const at = x.t + x.r.lat + x.cum[k];
        if (at <= T) (due[at] = due[at] || []).push([x.r.to, x.path[k][1], x.p, x.t, x.flow, x.isSpam]);
      }
    };
    let delivered = 0;
    const port = [[null, null]];
    const senders = this.ends.filter(e => this.idle.get(e));
    const always = this.ends.filter(e => this.idle.get(e) === null);
    for (let t = 1; t <= T; t++) {
      // trunks first: packets reaching a trunk's end in the same tick collided on the way in;
      // the one that joined farthest upstream survives (DropOutbound)
      if (busDue[t]) {
        const byBus = new Map();
        for (const e of busDue[t]) { if (!byBus.has(e[0])) byBus.set(e[0], []); byBus.get(e[0]).push(e); }
        for (const [st, q] of byBus) {
          q.sort((x, y) => y[1] - x[1]);
          for (let i = 1; i < q.length; i++) if (q[i][2].t <= cutoff && !q[i][2].isSpam) { loss.collision++; hurt(st); }
          next(q[0][2], q[0][3] + 1);
        }
        busDue[t] = null;
      }
      const now = new Map();
      for (const x of due[t] || []) {
        if (!now.has(x[0])) now.set(x[0], []);
        now.get(x[0]).push(x);
      }
      due[t] = null;
      const act = new Set(now.keys());
      for (const e of always) act.add(e);
      for (const e of senders) { const r = this.idle.get(e); if (r.slots[t % r.cycle]) act.add(e); }
      for (const e of act) {
        let a = null, meta = null;
        const q = now.get(e);
        if (q) {
          q.sort((x, y) => y[1] - x[1]);           // farthest merge position wins
          meta = q[0]; a = meta[2];
          for (let i = 1; i < q.length; i++) if (q[i][3] <= cutoff && !q[i][5]) { loss.collision++; hurt("end:" + norm(this.addr.get(e))); }
          const r = this.idle.get(e);
          if (r && r.slots[t % r.cycle] && t <= cutoff) { loss.skipped++; hurt("end:" + norm(this.addr.get(e))); }
        }
        port[0][0] = a; port[0][1] = null;
        net.delivered.length = 0; net.sent.length = 0;
        net.rng = new S.Rng(net.seed, e, t);
        net.upd_endpoint(e, port, t);
        if (net.delivered.length && meta && meta[4] && meta[3] <= cutoff) {
          per.set(meta[4], (per.get(meta[4]) || 0) + 1); delivered++;
        }
        const o = port[0][1];
        if (!o) continue;
        const me = this.addr.get(e), isSpam = o.color === S.SPAM_COLOR;
        const flow = !isSpam && net.sent.length ? me + " -> " + o.dst : null;
        const r = this.routes.get(me + "|" + o.dst);
        if (!r) { if (!isSpam && t <= cutoff) loss.unrouted++; continue; }
        const p = { color: o.color, src: r.src, dst: r.dst, payload: o.payload, f3a: r.f3a, f3b: r.f3b,
                    x: r.dx === null ? r.x : o.x - r.dx };
        if (o.f3a && p.x < 1) { if (!isSpam && t <= cutoff) loss.ttl++; continue; }
        const path = this.lines.path(lineOf(me, o.dst));
        const cum = []; let c = 0;
        for (const [, , f] of path) { c += delay[f] || 0; cum.push(c); }
        if ((r.stages || []).length !== path.length - 1) { if (!isSpam && t <= cutoff) loss.unrouted++; continue; }
        next({ path, r, p, t, cum, flow: flow && this.expected.has(flow) ? flow : null, isSpam }, 0);
      }
    }
    let sum = 0, covered = 0;
    for (const [k, n] of this.expected) {
      const d = per.get(k) || 0;
      sum += n ? Math.min(1, d / n) : 0; if (d) covered++;
    }
    return { mean: sum / this.expected.size, covered, delivered, loss, per, trouble };
  }
}

// ---------- 3. search ----------
function solve(model, feeders, maxDelay, log, start = {}) {
  const lines = Object.keys(feeders);
  const delay = Object.assign({}, start);
  // a small bonus per flow that gets through at all, so a flow that is always lost is
  // worth rescuing even at a little cost elsewhere
  const score = r => r.mean + (+(process.env.COVER_BONUS || 0.001)) * r.covered + 1e-7 * r.delivered;
  let best = model.run(delay), bestS = score(best);
  log(`start: mean ${(100 * best.mean).toFixed(2)}%, covered ${best.covered}, lost ${JSON.stringify(best.loss)}`);
  for (let pass = 1; pass <= 4; pass++) {
    let changed = 0;
    // only cables into sinks (endpoints, trunks) that lose packets or skip sends can help;
    // the most troubled sinks first
    const tr = best.trouble, sink = l => feeders[l];
    const todo = lines.filter(l => tr.get(sink(l)))
      .sort((x, y) => (tr.get(sink(y)) || 0) - (tr.get(sink(x)) || 0));
    log(`pass ${pass}: trying ${todo.length} lines`);
    for (const line of todo) {
      const cur = delay[line] || 0;
      let pick = cur, pickR = null, pickS = bestS;
      for (let n = 0; n <= maxDelay; n++) {
        if (n === cur) continue;
        delay[line] = n;
        const r = model.run(delay), s = score(r);
        if (s > pickS + 1e-12) { pick = n; pickR = r; pickS = s; }
      }
      if (pick) delay[line] = pick; else delete delay[line];
      if (pickR) { best = pickR; bestS = pickS; changed++; }
    }
    log(`pass ${pass}: mean ${(100 * best.mean).toFixed(2)}%, covered ${best.covered}, ` +
        `lost ${JSON.stringify(best.loss)}, lines delayed ${Object.keys(delay).length}, changed ${changed}`);
    if (!changed) break;
  }
  return { delay, best };
}

if (require.main === module) {
  // node tools/timetable.js lines.json out_delays.json ticks save.json delays.json [save delays ...]
  // Every save is measured (its delays subtracted) and the routes are merged; the search
  // starts from the LAST pair's delays. Saves must be the same network with other delays.
  const [linesPath, outPath, ticksArg, ...pairs] = process.argv.slice(2);
  const ticks = +ticksArg, settle = 300;
  const lines = new Lines(JSON.parse(fs.readFileSync(linesPath)));
  const log = s => process.stderr.write(s + "\n");
  const routes = new Map(), clash = new Set();
  let save, start = {};
  for (let i = 0; i < pairs.length; i += 2) {
    const sp = pairs[i], dp = pairs[i + 1];
    save = JSON.parse(fs.readFileSync(sp));
    start = dp && fs.existsSync(dp) ? JSON.parse(fs.readFileSync(dp)) : {};
    const t0 = Date.now();
    measure(save, ticks, start, routes, clash, lines);
    log(`measured ${sp}: ${routes.size} routes so far (${((Date.now() - t0) / 1000).toFixed(1)} s)`);
  }
  if (clash.size) log(`routes with more than one travel time: ${[...clash].join(", ")}`);
  const model = new Model(save, routes, lines, ticks, settle);
  const { delay, best } = solve(model, lines.feeders, +(process.env.MAX_DELAY || 7), log, start);
  const sorted = Object.fromEntries(Object.keys(delay).sort().map(k => [k, delay[k]]));
  fs.writeFileSync(outPath, JSON.stringify(sorted, null, 2) + "\n");
  process.stdout.write(JSON.stringify({ mean: best.mean, covered: best.covered, delivered: best.delivered,
                                        loss: best.loss, delays: Object.keys(sorted).length }, null, 2) + "\n");
}
module.exports = { measure, Model, solve, Lines };
