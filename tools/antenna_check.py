"""Antenna rule checks for sim.py and viewer/sim.js, and Python/JavaScript parity.

1. Hand-built antenna cases (closest sender wins, losers and untargeted antennas drop,
   tie -> lowest entity, removed target), checked against the expected result in BOTH
   simulators.
2. Parity: a save (default %APPDATA%/tunnet/slot_0.json) simulated in both, comparing a
   fingerprint of every slot and every drop each tick, with the default antenna targets
   and with edited targets (one antenna untargeted, both aimed at one).

    python tools/antenna_check.py [save] [ticks]
"""
import hashlib
import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import sim as S            # noqa: E402
import save_import as I    # noqa: E402

JS = r"""
const S = require(process.argv[1]), fs = require("fs"), crypto = require("crypto");
const job = JSON.parse(fs.readFileSync(0, "utf8"));
const data = JSON.parse(fs.readFileSync(process.argv[2], "utf8"));
const net = new S.Net(job.snap, data, job.seed);
const fp = () => { const rows = [];
  for (const [e, P] of net.state) P.forEach((s, k) => s.forEach((p, i) => { if (p)
    rows.push([e, k, i, p.color, p.src, p.dst, p.payload, p.x, p.f3a, p.f3b]); }));
  rows.sort((a, b) => a[0] - b[0] || a[1] - b[1] || a[2] - b[2]);
  const d = net.drops.map(r => [r[0], r[1], r[2], r[3].color, r[3].src, r[3].dst]);
  return crypto.createHash("md5").update(JSON.stringify([rows, d])).digest("hex"); };
const out = { fps: [], drops: null, state: null };
if (job.mode === "updates") {
  net.nodeUpdates(job.tick);
} else for (let t = 1; t <= job.ticks; t++) { net.step(t); out.fps.push(fp()); }
out.drops = net.drops.map(r => [r[0], r[1], r[2]]);
out.state = Object.fromEntries([...net.state].map(([e, P]) => [e, P.map(s => s.map(p => p && p.payload))]));
console.log(JSON.stringify(out));
"""


def fp(net):
    rows = []
    for e, P in net.state.items():
        for k, s in enumerate(P):
            for i, p in enumerate(s):
                if p:
                    rows.append([e, k, i, p["color"], p["src"], p["dst"], p["payload"], p["x"], p["f3a"], p["f3b"]])
    rows.sort(key=lambda r: (r[0], r[1], r[2]))
    d = [[t, e, r, p["color"], p["src"], p["dst"]] for t, e, r, p in net.drops]
    # same text as JSON.stringify (no spaces; non-ASCII kept)
    txt = json.dumps([rows, d], separators=(",", ":"), ensure_ascii=False)
    return hashlib.md5(txt.encode("utf-8")).hexdigest()


def run_js(job):
    r = subprocess.run(["node", "-e", JS, os.path.join(HERE, "viewer", "sim.js"),
                        os.path.join(HERE, "viewer", "sim_data.json")],
                       input=json.dumps(job), capture_output=True, text=True, encoding="utf-8")
    if r.returncode:
        raise RuntimeError(r.stderr)
    return json.loads(r.stdout)


def antenna(e, pos, target, packet=None):
    n = {"entity": e, "type": "antenna", "pos": pos,
         "ports": [{"peer": None, "peer_port": None, "cable": None, "slots": [packet, None]}]}
    if target != "default":
        n["antenna_target"] = target
    return n


def live_pkt(text):
    return {"color": "ffffff", "src": "0.0.0.0", "dst": "0.0.0.1", "payload": text, "x": 0, "state": 0, "f3b": 0}


def js_pkt(text):
    return {"color": "ffffff", "src": "0.0.0.0", "dst": "0.0.0.1", "payload": text, "x": 0, "f3a": 0, "f3b": 0}


def cases():
    """(name, nodes as [(e, pos, target, packet text or None)], expected OUT payload per
    antenna, expected drops as {sender: reason word})"""
    return [
        ("pair", [(1, [0, 0, 0], 2, "a"), (2, [5, 0, 0], 1, "b")],
         {1: "b", 2: "a"}, {}),
        ("closest of three wins", [(1, [0, 0, 0], 4, "a"), (2, [40, 0, 0], 4, "b"), (3, [3, 0, 0], 4, "c"),
                                   (4, [50, 0, 0], None, "d")],
         {1: None, 2: None, 3: None, 4: "b"}, {1: "closer", 3: "closer", 4: "no target"}),
        ("only senders with a packet compete", [(1, [0, 0, 0], 3, None), (2, [-9, 0, 0], 3, "b"), (3, [1, 0, 0], 2, None)],
         {1: None, 2: None, 3: "b"}, {}),
        ("tie -> lowest entity", [(5, [-2, 0, 0], 7, "x"), (6, [2, 0, 0], 7, "y"), (7, [0, 0, 0], 5, None)],
         {5: None, 6: None, 7: "x"}, {6: "closer"}),
        ("target missing", [(1, [0, 0, 0], 99, "a"), (2, [1, 0, 0], 1, None)],
         {1: None, 2: None}, {1: "no target"}),
        ("default = nearest other", [(1, [0, 0, 0], "default", "a"), (2, [10, 0, 0], "default", "b"),
                                     (3, [4, 0, 0], "default", "c")],
         # 1 -> 3, 2 -> 3, 3 -> 1: 3 gets the closer of 1 (d 4) and 2 (d 6)
         {1: "c", 2: None, 3: "a"}, {2: "closer"}),
    ]


def check_cases():
    bad = 0
    for name, spec, want_out, want_drop in cases():
        py_snap = {e: antenna(e, pos, t, live_pkt(txt) if txt else None) for e, pos, t, txt in spec}
        js_snap = {e: antenna(e, pos, t, js_pkt(txt) if txt else None) for e, pos, t, txt in spec}
        net = S.Net(py_snap, rules={})
        for P in net.state.values():
            P[0][S.OUT] = None
        net.node_updates(1)
        py_out = {e: (P[0][S.OUT] or {}).get("payload") for e, P in net.state.items()}
        py_drop = {e: r for _, e, r, _ in net.drops}
        js = run_js({"snap": js_snap, "seed": 1, "mode": "updates", "tick": 1})
        js_out = {int(e): P[0][1] for e, P in js["state"].items()}
        js_drop = {e: r for _, e, r in js["drops"]}
        ok_out = py_out == want_out == js_out
        ok_drop = py_drop == js_drop and set(py_drop) == set(want_drop) and \
            all(w in py_drop[e] for e, w in want_drop.items())
        bad += not (ok_out and ok_drop)
        print(f"  {'ok ' if ok_out and ok_drop else 'BAD'} {name}: out {py_out}, drops {py_drop}"
              + ("" if ok_out and ok_drop else f"\n      want {want_out} {want_drop}; js {js_out} {js_drop}"))
    return bad


def parity(snap, ticks, label):
    py = S.Net(snap, seed=1)
    pf = []
    for t in range(1, ticks + 1):
        py.step(t)
        pf.append(fp(py))
    js = run_js({"snap": snap, "seed": 1, "mode": "run", "ticks": ticks})
    same = sum(a == b for a, b in zip(pf, js["fps"]))
    first = next((k + 1 for k, (a, b) in enumerate(zip(pf, js["fps"])) if a != b), None)
    ant = [r for _, e, r, _ in py.drops if r.startswith("antenna")]
    print(f"  {label}: {same}/{ticks} ticks identical" + (f" (first difference at tick {first})" if first else "")
          + f"; {len(py.drops)} drops ({len(ant)} at antennas), {len(py.delivered)} delivered")
    return ticks - same


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.environ["APPDATA"], "tunnet", "slot_0.json")
    ticks = int(sys.argv[2]) if len(sys.argv) > 2 else 200
    print("antenna cases (Python and JavaScript):")
    bad = check_cases()
    save = json.load(open(path, encoding="utf-8"))
    snap = I.load(save)
    ants = sorted(e for e, n in snap.items() if n["type"] == "antenna")
    print(f"parity on {os.path.basename(path)} ({len(snap)} nodes, antennas {ants}, "
          f"targets {[snap[e]['antenna_target'] for e in ants]}):")
    bad += parity(snap, ticks, "default targets")
    if len(ants) >= 2:
        import copy
        s2 = copy.deepcopy(snap)
        s2[ants[0]]["antenna_target"] = None
        bad += parity(s2, ticks, f"antenna {ants[0]} untargeted")
        s3 = copy.deepcopy(snap)
        s3[ants[1]]["antenna_target"] = ants[1]   # aims at itself: competes with ants[0] for itself
        bad += parity(s3, ticks, f"antenna {ants[1]} aimed at itself")
    print("FAILED" if bad else "all ok")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
