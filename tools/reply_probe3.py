"""Direct reply check, read-only: when an endpoint's inbound slot holds a packet addressed to
it, the reply (if any) is already in the same port's outbound slot in that same snapshot.

    python tools/reply_probe3.py [seconds]
"""
import collections, json, os, re, sys, time
import tunnet_live as T
import reply_rules as RR

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def shape(t):
    return re.sub(r"\d+", "<n>", re.sub(r"[0-9a-f]{6,8}", "<hex>", t))

def main():
    secs = float(sys.argv[1]) if len(sys.argv) > 1 else 120
    net = T.LiveNet.attach()
    last = None; prev = {}
    res = collections.Counter(); bad = collections.Counter(); ex = {}
    t0 = time.time()
    while time.time() - t0 < secs:
        tick = net.tick_count()
        if tick == last:
            time.sleep(0.003); continue
        last = tick
        snap = net.snapshot()
        for e, n in snap.items():
            if n["type"] != "endpoint":
                continue
            a = n["address"]
            for pi, p in enumerate(n["ports"]):
                i, o = p["slots"]
                key = (e, pi)
                was = prev.get(key)
                prev[key] = (i and (i["src"], i["payload"]), o and (o["src"], o["dst"], o["payload"]))
                if not i or i["dst"] != a or (was and was[0] == (i["src"], i["payload"])):
                    continue
                req = (i["src"], i["dst"], i["payload"])
                if o is None:
                    res[(a, shape(req[2]), "no reply")] += 1
                    continue
                rep = (o["src"], o["dst"], o["payload"])
                if was and was[1] == rep:
                    res[(a, shape(req[2]), "outbound already held a packet, kept")] += 1
                    continue
                rule = RR.explains(a, req, rep)
                if rule and (rule["to"] != "sender" or rep[1] == req[0]) and \
                        (rule["to"] in ("sender", "see code") or rep[1] == rule["to"]):
                    res[(rule["receiver"], shape(req[2]), "-> " + shape(rep[2]), "to " + ("sender" if rep[1] == req[0] else rep[1]), "col " + o["color"] + (" same" if o["color"] == i["color"] else ""), f"budget {o.get('x')}")] += 1
                else:
                    bad[(a, "from " + req[0], shape(req[2]), "->", shape(rep[2]), "to " + rep[1])] += 1
                    ex.setdefault((a, shape(req[2])), (req, rep))
    out = {"results": [[list(k), v] for k, v in res.most_common()],
           "unexplained": [[list(k), v] for k, v in bad.most_common()],
           "examples": [[list(k), [list(v[0]), list(v[1])]] for k, v in ex.items()]}
    json.dump(out, open(os.path.join(ROOT, "re", "reply_check.json"), "w"), indent=1)
    for k, v in res.most_common(60): print(f"{v:5}  {k}")
    print("UNEXPLAINED:")
    for k, v in bad.most_common(30): print(f"{v:5}  {k}")

if __name__ == "__main__":
    main()
