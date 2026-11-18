"""Check the decoded reply rules (tools/reply_rules.py) against live traffic. Read-only.

Deliveries are detected one hop early as well: a packet can enter an endpoint's inbound slot
and be consumed in the same tick, so its track often ends in the neighbour's outbound slot
facing the endpoint. Every new non-generator send from an endpoint is matched to the
most recent delivery that a rule explains (by text), not just the most recent delivery.

Also checks the "delivery replaces the outbound slot" claim: when a delivery lands on an
endpoint that had a packet waiting in its outbound slot, does that packet survive?

    python tools/reply_probe2.py [seconds]
"""
import collections
import json
import os
import re
import sys
import time

import tunnet_live as T
import tracker as TR
import reply_rules as RR

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WINDOW = 40


def shape(text):
    t = re.sub(r"[0-9a-f]{6,8}", "<hex>", text)
    return re.sub(r"\d+", "<n>", t)


def main():
    secs = float(sys.argv[1]) if len(sys.argv) > 1 else 180
    sys.setrecursionlimit(20000)
    gen = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    net = T.LiveNet.attach()
    trk = TR.Tracker()
    last = start = None
    prev_out = {}                                # endpoint e -> sig waiting in its outbound slot
    deliveries = collections.defaultdict(list)   # address -> [(tick, sig)]
    sends = []                                   # (tick, address, sig)
    wipe = collections.Counter()
    dwell = {}
    t0 = time.time()
    while time.time() - t0 < secs:
        tick = net.tick_count()
        if tick == last:
            time.sleep(0.003)
            continue
        snap = net.snapshot()
        ended = trk.update(tick, snap)
        last = tick
        if start is None:
            start = tick
        delivered_to = set()
        for t in ended:
            e, port, slot = t.last
            n = snap.get(e) or {}
            target = None
            if n.get("type") == "endpoint" and n.get("address") == t.sig[2]:
                target = e
            elif slot == TR.OUT:
                peer = n["ports"][port]["peer"] if port < len(n.get("ports", [])) else None
                pn = snap.get(peer) or {}
                if pn.get("type") == "endpoint" and pn.get("address") == t.sig[2]:
                    target = peer
            if target is not None:
                deliveries[snap[target]["address"]].append((tick, t.sig))
                delivered_to.add(target)
        # outbound slot survival on endpoints that just got a delivery
        cur_out = {}
        for e, n in snap.items():
            if n["type"] != "endpoint":
                continue
            for p in n["ports"]:
                pk = p["slots"][TR.OUT]
                if pk:
                    cur_out[e] = TR.sig_of(pk)
        for e in delivered_to:
            if e in prev_out:
                moved = any(t.sig == prev_out[e] and t.last[0] != e for t in trk.active.values())
                if moved:
                    wipe["waiting packet left normally"] += 1
                elif cur_out.get(e) == prev_out[e]:
                    wipe["waiting packet still there"] += 1
                else:
                    wipe["waiting packet vanished"] += 1
            else:
                wipe["no packet was waiting"] += 1
        prev_out = cur_out
        for e, n in snap.items():
            if n["type"] != "endpoint":
                continue
            for pi, p in enumerate(n["ports"]):
                pk = p["slots"][TR.IN]
                if pk and pk["dst"] == n["address"]:
                    k = (e, pi, TR.sig_of(pk))
                    dwell.setdefault(k, [tick, tick])[1] = tick
        for st, t in trk.active.items():
            if t.born_tick != tick or len(t.states) != 1 or st[2] != TR.OUT:
                continue
            n = snap.get(st[0], {})
            a = n.get("address")
            if n.get("type") != "endpoint" or t.sig[1] != a:
                continue
            r = gen.get(a)
            g = r and r["slots"].get(str(tick % r["cycle"]))
            if g and g["dst"] == t.sig[2] and (t.sig[3] in g["messages"] or any("{}" in m for m in g["messages"])):
                continue
            sends.append((tick, a, t.sig))
    explained = collections.Counter()
    unexplained = collections.Counter()
    delays = collections.defaultdict(collections.Counter)
    for tick, a, sig in sends:
        best = None
        for tk, req in reversed(deliveries[a]):
            if not 0 <= tick - tk <= WINDOW:
                continue
            rule = RR.explains(a, (req[1], req[2], req[3]), (sig[1], sig[2], sig[3]))
            if rule and (rule["to"] != "sender" or sig[2] == req[1]):
                best = (tk, req, rule)
                break
        if best:
            tk, req, rule = best
            key = (rule["receiver"], a, shape(req[3]), shape(sig[3]))
            explained[key] += 1
            delays[rule["receiver"]][tick - tk] += 1
        else:
            unexplained[(a, shape(sig[3]), "to " + sig[2])] += 1
    out = {"explained": [[list(k), v] for k, v in explained.most_common()],
           "unexplained": [[list(k), v] for k, v in unexplained.most_common()],
           "delays": {k: dict(v) for k, v in delays.items()},
           "delivery_vs_waiting_outbound": dict(wipe),
           "ticks": last - start}
    json.dump(out, open(os.path.join(ROOT, "re", "reply_check.json"), "w"), indent=1)
    print(f"{last - start} ticks, {len(sends)} non-generator sends")
    print("explained by a reply rule:")
    for k, v in explained.most_common(30):
        print(f"  {v:4}  {k}")
    print("NOT explained:")
    for k, v in unexplained.most_common(20):
        print(f"  {v:4}  {k}")
    print("delays (ticks):", {k: dict(v) for k, v in delays.items()})
    dw = collections.Counter(min(b - a + 1, 20) for a, b in dwell.values())
    out["inbound_dwell_ticks"] = dict(sorted(dw.items()))
    json.dump(out, open(os.path.join(ROOT, "re", "reply_check.json"), "w"), indent=1)
    print("ticks a delivered packet sat in the endpoint inbound slot:", dict(sorted(dw.items())))
    print("delivery onto an endpoint with a waiting outbound packet:", dict(wipe))


if __name__ == "__main__":
    main()
