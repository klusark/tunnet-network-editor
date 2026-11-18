"""Fix timing clashes in the direct-wired network by adding delay (extra relays) to lines.

Two kinds of flow fail for timing reasons, not routing:
- sent but always lost: its packets reach a merge on the same tick as another packet,
  every time. Fix: delay its own line (1-6 extra relays, one tick each).
- never sent: the sender receives a packet on its scheduled send tick every cycle, and the
  game skips a send on a tick the endpoint receives. Fix: delay a line INTO that sender.
Greedy: try each candidate, keep a change only if the mean flow delivery improves.
Scored with the JavaScript simulator (tools/flowscore.js).

    python tools/delayopt.py slot_0.json out_prefix [ticks]
"""
import json
import os
import subprocess
import sys
import tempfile

import directgen as D

HERE = os.path.dirname(os.path.abspath(__file__))
SCRATCH = os.path.join(tempfile.gettempdir(), "tunnet_delayopt.json")


def build(base, delay):
    g = D.Direct(base, "DropOutbound")
    g.relay_spacing = 6.0
    g.delay = dict(delay)
    return g, g.generate_direct()


def score(save, ticks):
    with open(SCRATCH, "w", encoding="utf-8") as f:
        json.dump(save, f, indent=2)   # scratch file for the scorer only, not kept
    out = subprocess.run(["node", os.path.join(HERE, "flowscore.js"), SCRATCH, str(ticks), "300"],
                         capture_output=True, text=True, check=True).stdout
    return json.loads(out)


def main():
    path = sys.argv[1] if os.path.exists(sys.argv[1]) else os.path.join(os.environ["APPDATA"], "tunnet", sys.argv[1])
    prefix = sys.argv[2]
    ticks = int(sys.argv[3]) if len(sys.argv) > 3 else 3000
    base = json.load(open(path, encoding="utf-8"))
    delay = {}
    g, save = build(base, delay)
    r = score(save, ticks)
    best = r["mean_flow"]
    print(f"start: mean flow {100 * best:.2f}%, covered {r['covered']}", flush=True)
    rules = json.load(open(os.path.join(HERE, "viewer", "sim_data.json")))["endpoint_rules"]
    flows = {f"{a} -> {s['dst']}" for a, x in rules.items() for s in x["slots"].values()}
    long = score(save, 8192)        # which flows fail even in a long run
    failing = [k for k in sorted(flows) if not k.split(" -> ")[1].startswith("0.0.2.")
               and (long["per_flow"].get(k, {}).get("delivered", 0) == 0)]
    print("failing:", failing, flush=True)
    for k in failing:
        a, d = k.split(" -> ")
        sent = k in long["per_flow"]
        # sent but lost: delay this line; never sent: delay lines into the sender a
        cands = [(a, d)] if sent else sorted(l for l in g.line_keys if l[1] == a)
        for line in cands:
            for n in ((1, 2, 3, 4, 5, 6) if sent else (1, 2, 3)):
                trial = dict(delay)
                trial[line] = trial.get(line, 0) + n
                _, s2 = build(base, trial)
                r2 = score(s2, ticks)
                if r2["mean_flow"] > best:
                    print(f"  {k}: +{n} relays on {line[0]} -> {line[1]}: mean {100 * r2['mean_flow']:.2f}%, "
                          f"covered {r2['covered']}", flush=True)
                    best, delay, r = r2["mean_flow"], trial, r2
                    break
            if r["per_flow"].get(k, {}).get("delivered", 0):
                break
    json.dump({f"{a} -> {d}": n for (a, d), n in delay.items()}, open(prefix + "_delays.json", "w"), indent=2)
    _, save = build(base, delay)
    json.dump(save, open(prefix + ".json", "w", encoding="utf-8"), indent=2)
    print(f"done: mean flow {100 * best:.2f}%, covered {r['covered']}, delays {len(delay)}", flush=True)


if __name__ == "__main__":
    main()
