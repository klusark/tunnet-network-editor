"""Routing requirements and how well a network meets them, measured in the simulator.

A requirement is a flow: packets an endpoint sends (its schedule, replies, token ring)
to a destination address. A packet counts as DELIVERED when it reaches the endpoint
whose address equals its destination at that moment (bridges rewrite 0.y -> 1.y, so
packets for 0.y.1.0 are delivered to 1.y.1.0 behind a bridge). Spam should be dropped.

    python tools/flows.py slot_0.json [ticks]     # score a save's network
"""
import collections
import json
import os
import sys

import save_import as I
import sim as S


class TrackedNet(S.Net):
    """sim.Net that gives every new packet an id and records where each one ends."""
    def __init__(self, *a, **kw):
        super().__init__(*a, **kw)
        self.next_id = 1
        self.origin = {}       # id -> (tick, sender entity, sender address, dst, payload kind, spam)
        self.outcome = {}      # id -> ("delivered", entity) | ("dropped", reason, entity)

    def step(self, tick):
        s0, d0, r0 = len(self.sent), len(self.drops), len(self.delivered)
        super().step(tick)
        for t, e, p in self.sent[s0:]:
            if "id" not in p:
                p["id"] = self.next_id
                self.next_id += 1
            self.origin[p["id"]] = (t, e, self.nodes[e]["address"], p["dst"], kind(p["payload"]),
                                    p["color"] == S.SPAM_COLOR)
        for t, e, p in self.delivered[r0:]:
            if "id" in p:
                self.outcome.setdefault(p["id"], ("delivered", e))
        for t, e, reason, p in self.drops[d0:]:
            if "id" in p:
                self.outcome.setdefault(p["id"], ("dropped", reason, e))


def kind(payload):
    if payload.startswith("Re:"):
        return "Re:"
    if payload.startswith("TX ") or payload.startswith("BLK "):
        return payload.split(" ")[0]
    return payload


def score(net, start, ticks, settle=60):
    """Run `ticks` ticks; packets sent in the last `settle` ticks are not judged."""
    S.run(net, start, ticks)
    per = collections.defaultdict(collections.Counter)
    spam = collections.Counter()
    judge_until = start + ticks - settle
    for pid, (t, e, src, dst, k, is_spam) in net.origin.items():
        if t > judge_until:
            continue
        out = net.outcome.get(pid)
        if is_spam:
            spam["delivered" if out and out[0] == "delivered" else "dropped" if out else "in flight"] += 1
            continue
        if out is None:
            per[(src, dst)]["lost (in flight or overwritten)"] += 1
        elif out[0] == "delivered":
            per[(src, dst)]["delivered"] += 1
        else:
            per[(src, dst)][f"dropped: {out[1]}"] += 1
    total = collections.Counter()
    for c in per.values():
        total.update(c)
    sent = sum(total.values())
    return {"sent": sent, "delivered": total["delivered"],
            "rate": round(total["delivered"] / max(1, sent), 4),
            "flows": len(per), "flows_fully_delivered": sum(1 for c in per.values() if c["delivered"] == sum(c.values())),
            "flows_never_delivered": sorted(f"{a} -> {b}" for (a, b), c in per.items() if c["delivered"] == 0),
            "outcomes": dict(total.most_common()), "spam": dict(spam), "per_flow": per}


def main():
    path = sys.argv[1]
    if not os.path.exists(path):
        path = os.path.join(os.environ["APPDATA"], "tunnet", path)
    ticks = int(sys.argv[2]) if len(sys.argv) > 2 else 2000
    save = json.load(open(path, encoding="utf-8"))
    net = TrackedNet(I.load(save))
    r = score(net, 0, ticks)
    print(f"{ticks} ticks: {r['delivered']}/{r['sent']} legit packets delivered ({100 * r['rate']:.1f}%), "
          f"{r['flows_fully_delivered']}/{r['flows']} flows always delivered")
    print("outcomes:", r["outcomes"])
    print("spam:", r["spam"])
    print(f"flows never delivered ({len(r['flows_never_delivered'])}):", ", ".join(r["flows_never_delivered"][:40]))


if __name__ == "__main__":
    main()
