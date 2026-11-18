"""Solve line delays for the direct-wired network with the timetable model (tools/timetable.js).

1. generate the direct network with no extra delays,
2. let timetable.js measure every route and search extra relays per line,
3. regenerate with those delays and score the result in the full simulator.

    python tools/timetable.py slot_0.json out/direct_final.json [--delays tools/direct_delays.json] [--rounds 3]
"""
import argparse
import json
import os
import subprocess

import directgen as D

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)


GEN = {"kind": "direct", "mode": "middle", "cap": 0.5}


def build(base, delay):
    if GEN["kind"] == "hybrid":
        import hybridgen as H
        g = H.Hybrid(base, GEN["mode"], GEN["cap"])
        g.relay_spacing = 6.0
        g.delay = {(k if isinstance(k, str) else " -> ".join(k)): v for k, v in delay.items()}
    else:
        g = D.Direct(base, "DropOutbound")
        g.relay_spacing = 6.0
        g.delay = dict(delay)
    return g, g.generate_direct()


def lines_of(g):
    if hasattr(g, "timetable_lines"):
        return g.timetable_lines()
    return {f"{s} -> {d}": i for (s, d), i in sorted(g.merge_index.items())}


def read_delays(path):
    d = json.load(open(path))
    return d if GEN["kind"] == "hybrid" else {tuple(k.split(" -> ")): v for k, v in d.items()}


def dump(obj, path):
    with open(path, "w", encoding="utf-8") as f:
        json.dump(obj, f, indent=2)
        f.write("\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("base"); ap.add_argument("out")
    ap.add_argument("--delays", default=os.path.join(HERE, "direct_delays.json"))
    ap.add_argument("--ticks", type=int, default=8192)
    ap.add_argument("--rounds", type=int, default=3)
    ap.add_argument("--hybrid", choices=["lean", "middle"], help="hybridgen network (shared trunks) instead of direct")
    ap.add_argument("--cap", type=float, default=0.5, help="hybrid: max trunk load, packets per tick")
    a = ap.parse_args()
    if a.hybrid:
        GEN.update(kind="hybrid", mode=a.hybrid, cap=a.cap)
        if a.delays == os.path.join(HERE, "direct_delays.json"):
            a.delays = os.path.join(HERE, f"hybrid_{a.hybrid}_delays.json")
    path = a.base if os.path.exists(a.base) else os.path.join(os.environ["APPDATA"], "tunnet", a.base)
    base = json.load(open(path, encoding="utf-8"))
    work = os.path.join(ROOT, "out", "tt_" + (GEN["mode"] if GEN["kind"] == "hybrid" else "direct"))
    os.makedirs(work, exist_ok=True)
    # round 1 measures the undelayed network; each later round also measures the last
    # result, so packet types that only appear with the new timing get real routes too
    g, save = build(base, {})
    dump(save, os.path.join(work, "timetable_r0.json"))
    dump({}, os.path.join(work, "timetable_r0_delays.json"))
    dump(lines_of(g), os.path.join(work, "timetable_lines.json"))
    pairs = [os.path.join(work, "timetable_r0.json"), os.path.join(work, "timetable_r0_delays.json")]
    for rnd in range(1, a.rounds + 1):
        dpath = os.path.join(work, f"timetable_r{rnd}_delays.json")
        model = subprocess.run(["node", os.path.join(HERE, "timetable.js"), os.path.join(work, "timetable_lines.json"),
                                dpath, str(a.ticks)] + pairs, stdout=subprocess.PIPE, text=True, check=True).stdout
        print(f"round {rnd} model:", json.dumps(json.loads(model)), flush=True)
        delay = read_delays(dpath)
        g, save = build(base, delay)
        spath = os.path.join(work, f"timetable_r{rnd}.json")
        dump(save, spath)
        pairs += [spath, dpath]
    dump(json.load(open(dpath)), a.delays)
    dump(save, a.out)
    full = json.loads(subprocess.run(["node", os.path.join(HERE, "flowscore.js"), a.out, str(a.ticks), "300"],
                                     stdout=subprocess.PIPE, text=True, check=True).stdout)
    print(f"full simulator, {a.ticks} ticks: mean flow {100 * full['mean_flow']:.2f}%, "
          f"counting skipped sends {100 * full['mean_sched']:.2f}%, covered {full['covered']}, "
          f"packets {full['delivered']}/{full['sent']}, spam {full['spam']}, "
          f"extra relays {sum(delay.values())} on {len(delay)} lines -> {a.out}")


if __name__ == "__main__":
    main()
