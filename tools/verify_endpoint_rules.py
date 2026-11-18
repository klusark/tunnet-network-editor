"""Check re/endpoint_rules.json (the emulated generator) against live sends. Read-only.

    python tools/verify_endpoint_rules.py [seconds]

A live "send" is a new packet in an endpoint's outbound slot whose source address is that
endpoint (bounces of other packets are excluded). Each is checked against the rules for
tick % cycle: destination, message list and colour must all match.
"""
import collections
import json
import os
import sys
import time

import tunnet_live as T
import tracker as TR

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    secs = float(sys.argv[1]) if len(sys.argv) > 1 else 60
    sys.setrecursionlimit(20000)
    rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    net = T.LiveNet.attach()
    trk = TR.Tracker()
    last = start = None
    res = collections.Counter()
    bad = collections.defaultdict(list)
    t0 = time.time()
    while time.time() - t0 < secs:
        tick = net.tick_count()
        if tick == last:
            time.sleep(0.003)
            continue
        snap = net.snapshot()
        trk.update(tick, snap)
        last = tick
        if start is None:
            start = tick
            continue
        for st, t in trk.active.items():
            if not (t.born_tick == tick and len(t.states) == 1 and st[2] == TR.OUT):
                continue
            n = snap.get(st[0], {})
            if n.get("type") != "endpoint":
                continue
            color, src, dst, payload = t.sig
            a = n["address"]
            if src != a:
                res["skip: not its own packet (bounce/tracking)"] += 1
                continue
            r = rules.get(a)
            if not r or not r["slots"]:
                res["skip: reply (receive path, not the generator)"] += 1
                continue
            e = r["slots"].get(str(tick % r["cycle"]))
            if not e:
                k = "no generator send at this tick"
            elif e["dst"] != dst:
                k = "different destination"
            elif not (payload in e["messages"] or any("{}" in m for m in e["messages"])):
                k = "message not in list"
            elif e["color"] != color:
                k = "colour differs"
            else:
                k = "MATCH"
            res[k] += 1
            if k != "MATCH" and len(bad[k]) < 5:
                bad[k].append((a, tick, dst, payload[:30], e and e["dst"]))
    checked = sum(v for k, v in res.items() if not k.startswith("skip"))
    for k, v in res.most_common():
        print(f"{v:6}  {k}")
    print(f"generator sends matching exactly: {res['MATCH']}/{checked}")
    for k, lst in bad.items():
        print(" ", k, lst)


if __name__ == "__main__":
    main()
