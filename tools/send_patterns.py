"""Who sends what, how often, and to where? Read-only analysis.

Runs the packet tracker for N seconds; every packet first seen in an endpoint's (or
bridge's) outbound slot is a send. Writes re/send_patterns.json and prints a summary.

    python tools/send_patterns.py [seconds]
"""
import collections
import json
import os
import statistics
import sys
import time

import tunnet_live as T
import tracker as TR

SPAM_COLOR = "a93b3b"  # endpoint::update: infected endpoints send spam in this colour only


def kind_of(payload):
    if payload.startswith("Re:"):
        return "Re: (reply)"
    return payload if len(payload) <= 24 else payload[:24] + "…"


def main():
    secs = float(sys.argv[1]) if len(sys.argv) > 1 else 180
    sys.setrecursionlimit(20000)
    net = T.LiveNet.attach()
    trk = TR.Tracker()
    sends = []  # (tick, src node entity, src node type, src address, packet sig)
    last = None
    start_tick = None
    t0 = time.time()
    snap = None
    while time.time() - t0 < secs:
        tick = net.tick_count()
        if tick == last:
            time.sleep(0.003)
            continue
        snap = net.snapshot()
        trk.update(tick, snap)
        last = tick
        if start_tick is None:
            start_tick = tick
            continue
        for st, t in trk.active.items():
            if t.born_tick == tick and len(t.states) == 1 and st[2] == TR.OUT:
                n = snap.get(st[0], {})
                if n.get("type") in ("endpoint", "bridge"):
                    sends.append((tick, st[0], n["type"], n.get("address"), t.sig))
    ticks = last - start_tick
    per = collections.defaultdict(list)
    for s in sends:
        per[(s[1], s[2], s[3])].append(s)
    report = {"ticks": ticks, "seconds": secs, "tick_period_s": secs / max(1, ticks), "sources": []}
    for (e, typ, addr), lst in sorted(per.items(), key=lambda x: -len(x[1])):
        tk = [s[0] for s in lst]
        gaps = [b - a for a, b in zip(tk, tk[1:])]
        dsts = collections.Counter(s[4][2] for s in lst)
        kinds = collections.Counter(kind_of(s[4][3]) for s in lst)
        colors = collections.Counter(s[4][0] for s in lst)
        report["sources"].append({
            "entity": e, "type": typ, "address": addr, "sends": len(lst),
            "per_min": round(len(lst) / (ticks * report["tick_period_s"] / 60), 1),
            "gap_ticks": {"min": min(gaps) if gaps else None, "median": statistics.median(gaps) if gaps else None,
                          "max": max(gaps) if gaps else None},
            "gap_hist": dict(sorted(collections.Counter(gaps).items())[:12]),
            "destinations": dsts.most_common(), "kinds": kinds.most_common(), "colors": colors.most_common(),
            "spam": colors.get(SPAM_COLOR, 0),
        })
    out = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "re", "send_patterns.json")
    json.dump(report, open(out, "w"), indent=1)
    print(f"{len(sends)} sends from {len(per)} sources over {ticks} ticks ({secs:.0f} s) -> {out}")
    for s in report["sources"]:
        print(f"{s['type']:8} {str(s['address']):8} {s['sends']:4} sends {s['per_min']:5}/min  gap(ticks) "
              f"min {s['gap_ticks']['min']} med {s['gap_ticks']['median']} max {s['gap_ticks']['max']}  "
              f"dst {len(s['destinations'])}: {[d for d, _ in s['destinations'][:4]]}  kinds {[k for k, _ in s['kinds'][:3]]}"
              + (f"  SPAM {s['spam']}" if s['spam'] else ""))


if __name__ == "__main__":
    main()
