"""Which deliveries trigger a reply, and what is the reply? Read-only.

For every packet delivered to an endpoint (gone from the inbound slot of the endpoint it is
addressed to), look for a new packet from that endpoint in the next few ticks that is NOT
explained by the exact generator schedule (re/endpoint_rules.json). Pairs the two and
tabulates (endpoint, request) -> (reply text, reply destination, delay).

    python tools/reply_probe.py [seconds]
"""
import collections
import json
import os
import sys
import time

import tunnet_live as T
import tracker as TR

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WINDOW = 3  # ticks after a delivery in which a reply may appear


def shape(text):
    """Collapse variable parts so similar messages group together."""
    import re
    t = re.sub(r"[0-9a-f]{6,8}", "<hex>", text)
    t = re.sub(r"\d+", "<n>", t)
    return t


def main():
    secs = float(sys.argv[1]) if len(sys.argv) > 1 else 180
    sys.setrecursionlimit(20000)
    rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    net = T.LiveNet.attach()
    trk = TR.Tracker()
    last = start = None
    deliveries = collections.defaultdict(list)  # endpoint address -> [(tick, sig)]
    extra_sends = []                            # (tick, endpoint address, sig) not from the generator
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
            continue
        for t in ended:
            e, port, slot = t.last
            n = snap.get(e)
            if n and n["type"] == "endpoint" and slot == TR.IN and n.get("address") == t.sig[2]:
                deliveries[n["address"]].append((tick, t.sig))
        for st, t in trk.active.items():
            if t.born_tick == tick and len(t.states) == 1 and st[2] == TR.OUT:
                n = snap.get(st[0], {})
                a = n.get("address")
                if n.get("type") != "endpoint" or t.sig[1] != a:
                    continue
                r = rules.get(a)
                gen = r and r["slots"].get(str(tick % r["cycle"]))
                if gen and gen["dst"] == t.sig[2] and (t.sig[3] in gen["messages"] or any("{}" in m for m in gen["messages"])):
                    continue  # explained by the generator
                extra_sends.append((tick, a, t.sig))
    pairs = collections.Counter()
    unpaired = collections.Counter()
    examples = {}
    for tick, a, sig in extra_sends:
        cands = [(tk, s) for tk, s in deliveries[a] if 0 <= tick - tk <= WINDOW]
        if not cands:
            unpaired[(a, shape(sig[3]), sig[2])] += 1
            continue
        tk, req = max(cands, key=lambda x: x[0])
        key = (a, shape(req[3]), "from " + req[1], "->", shape(sig[3]), "to " + sig[2],
               "(to sender)" if sig[2] == req[1] else "", f"+{tick - tk}")
        pairs[key] += 1
        examples.setdefault(key[:6], (req[3], sig[3]))
    no_reply = collections.Counter()
    replied_ticks = {(a, tk) for tick, a, sig in extra_sends for tk, s in deliveries[a] if 0 <= tick - tk <= WINDOW}
    for a, lst in deliveries.items():
        for tk, s in lst:
            if (a, tk) not in replied_ticks:
                no_reply[(a, shape(s[3]))] += 1
    out = {"pairs": [[list(k), v] for k, v in pairs.most_common()],
           "unpaired_extra_sends": [[list(k), v] for k, v in unpaired.most_common()],
           "deliveries_without_reply": [[list(k), v] for k, v in no_reply.most_common()],
           "examples": [[list(k), list(v)] for k, v in examples.items()]}
    json.dump(out, open(os.path.join(ROOT, "re", "reply_pairs.json"), "w"), indent=1)
    print("request -> reply pairs:")
    for k, v in pairs.most_common(40):
        print(f"  {v:4}  {' '.join(k)}")
    print("extra sends with no delivery just before (not generator, not reply?):")
    for k, v in unpaired.most_common(12):
        print(f"  {v:4}  {k}")
    print("deliveries with no reply (top):")
    for k, v in no_reply.most_common(12):
        print(f"  {v:4}  {k}")


if __name__ == "__main__":
    main()
