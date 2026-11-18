// Fast per-flow scoring of a save with the JavaScript simulator (same rules and random
// numbers as tools/flows.py, which uses sim.py).
//   node tools/flowscore.js save.json [ticks] [settle]
// Prints JSON: mean flow delivery over the required flows, flows covered, packets, and
// per-flow outcome counts.
const fs = require("fs"), path = require("path");
const S = require(path.join(__dirname, "viewer", "sim.js"));
const data = JSON.parse(fs.readFileSync(path.join(__dirname, "viewer", "sim_data.json")));

function score(save, ticks = 8192, settle = 300) {
  const net = new S.Net(S.importSave(save), data, 1);
  let nextId = 1;
  const origin = new Map(), outcome = new Map();
  for (let t = 1; t <= ticks; t++) {
    const s0 = net.sent.length, d0 = net.drops.length, r0 = net.delivered.length;
    net.step(t);
    for (const [tk, e, p] of net.sent.slice(s0)) {
      if (!p._id) p._id = nextId++;
      origin.set(p._id, [tk, net.nodes.get(e).address, p.dst, p.color === S.SPAM_COLOR]);
    }
    for (const [tk, e, p] of net.delivered.slice(r0)) if (p._id && !outcome.has(p._id)) outcome.set(p._id, "delivered");
    for (const [tk, e, reason, p] of net.drops.slice(d0)) if (p._id && !outcome.has(p._id)) outcome.set(p._id, "dropped: " + reason);
    net.sent.length = 0; net.delivered.length = 0; net.drops.length = 0;
  }
  const per = {};
  let delivered = 0, sent = 0, spam = { delivered: 0, dropped: 0 };
  for (const [id, [tk, src, dst, isSpam]] of origin) {
    if (tk > ticks - settle) continue;
    const out = outcome.get(id) || "lost (in flight or overwritten)";
    if (isSpam) { spam[out === "delivered" ? "delivered" : "dropped"]++; continue; }
    const k = src + " -> " + dst;
    (per[k] = per[k] || {})[out] = (per[k][out] || 0) + 1;
    sent++; if (out === "delivered") delivered++;
  }
  // required flows, and how many sends each is scheduled for (a send the endpoint skips,
  // because it received on that tick, counts as lost in mean_sched but not in mean_flow)
  const req = new Map();
  for (const [a, r] of Object.entries(data.endpoint_rules))
    for (const [slot, s] of Object.entries(r.slots)) {
      let n = 0;
      for (let t = 1; t <= ticks - settle; t++) if (t % r.cycle === +slot) n++;
      req.set(a + " -> " + s.dst, (req.get(a + " -> " + s.dst) || 0) + n);
    }
  let sum = 0, sumSched = 0, covered = 0;
  for (const [k, sched] of req) {
    const c = per[k];
    const n = c ? Object.values(c).reduce((x, y) => x + y, 0) : 0;
    const d = c ? (c.delivered || 0) : 0;
    sum += n ? d / n : 0; sumSched += sched ? Math.min(1, d / sched) : 0; if (d) covered++;
  }
  return { ticks, mean_flow: sum / req.size, mean_sched: sumSched / req.size, covered, required: req.size,
           delivered, sent, spam, per_flow: per };
}

if (require.main === module) {
  const save = JSON.parse(fs.readFileSync(process.argv[2]));
  const r = score(save, +(process.argv[3] || 8192), +(process.argv[4] || 300));
  process.stdout.write(JSON.stringify(r, null, 2) + "\n");
}
module.exports = { score };
