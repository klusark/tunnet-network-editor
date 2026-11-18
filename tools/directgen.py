"""Direct wiring: a dedicated line for every (sender, destination) pair.

Each endpoint's single port goes to a SPLITTER hub (legs 0 endpoint, 1 out, 2 in, dir 0:
endpoint -> out line, in line -> endpoint). The out line runs through a SPLIT CHAIN: one
tap per destination (hub legs 0 in, 1 filter, 2 onward, dir 0; filter Differ <dest>,
SendBack): packets for that destination pass onto its own line, the rest bounce and go
on. Whatever reaches the end of the chain (spam, addresses that don't exist) is dropped.
Nothing comes back up a line, so split taps never collide.

The in line is fed by a MERGE CHAIN that joins the lines from every sender (hub legs 0
toward the endpoint, 1 upstream, 2 line, dir 0; filter Match <me>, SendBack): packets
coming down the chain bounce off each merge filter toward the endpoint; line arrivals
pass in. Two packets meeting at a merge in the same tick is the only collision left.

Bridges act as the endpoint 0.y.1.0 (their outer endpoint 1.y.1.0's traffic comes out of
them translated to 0.y addresses).

    python tools/directgen.py slot_0.json out.json [--merge-collision DropOutbound] [--ticks 2100]
"""
import argparse
import collections
import json
import math
import os

import netgen as G
import reply_rules as RR
import save_import as I

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def flow_rates():
    """(sender address, destination address) -> packets per tick, schedule + replies."""
    rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    rate = collections.Counter()
    swap = lambda a: {"0": "1", "1": "0"}.get(a[0], a[0]) + a[1:]
    bridged = {"0.0.1.0", "0.1.1.0", "0.2.1.0", "0.3.1.0"}

    def reply(receiver, sender, text):
        if receiver in bridged:   # really answered by 1.y.1.0 on the far side of the bridge
            r = RR.reply_to(swap(receiver), swap(sender), text)
            return r and dict(r, src=swap(r["src"]), dst=swap(r["dst"]))
        return RR.reply_to(receiver, sender, text)

    for a, x in rules.items():
        for s in x["slots"].values():
            for m in s["messages"]:
                w = 1 / x["cycle"] / len(s["messages"])
                rate[(a, s["dst"])] += w
                rep = reply(s["dst"], a, m)
                if rep:
                    rate[(s["dst"], rep["dst"])] += w
                    # chained replies (Token ring): follow up to 5 hops
                    src, text, cur = rep["src"], rep["text"], rep
                    for _ in range(5):
                        nxt = reply(cur["dst"], cur["src"], cur["text"])
                        if not nxt:
                            break
                        rate[(cur["dst"], nxt["dst"])] += w
                        cur = nxt
    return rate


def bounce_budgets():
    """(sender, destination) -> smallest bounce budget of its scheduled packets (TTL)."""
    rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    out = {}
    for a, x in rules.items():
        for s in x["slots"].values():
            if s.get("bounce_budget") is not None:
                k = (a, s["dst"])
                out[k] = min(out.get(k, 99), s["bounce_budget"])
    return out


def bounce_limited():
    """(sender, destination) pairs whose packets carry a bounce limit (filters cost them)."""
    rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
    return {(a, s["dst"]) for a, x in rules.items() for s in x["slots"].values() if s.get("bounce_budget") is not None}


class Direct(G.Gen):
    def __init__(self, base, merge_collision="DropOutbound"):
        super().__init__(base)
        self.merge_collision = merge_collision

        self.dead_masks = []

    def generate_direct(self):
        rate = flow_rates()
        limited = bounce_limited()
        swap = lambda a: {"0": "1", "1": "0"}.get(a[0], a[0]) + a[1:]
        # who sends where, as seen inside network 0 (outer endpoints speak through their bridge)
        out = collections.defaultdict(collections.Counter)
        for (s, d), w in rate.items():
            if s.startswith("1."):                 # outer endpoint: speaks through its bridge
                s = swap(s)
            if d.startswith("1."):
                d = swap(d)
            if s in self.leaves:
                out[s][d] += w
        # endpoint splitter hubs
        ends = {}
        for a, (ref, port, pos) in sorted(self.leaves.items()):
            hub = self.new("hub", [pos[0], pos[1] + 1, pos[2]], label=f"splitter {a}", hub_dir=0)
            self.link(hub, 0, ref, port)
            ends[a] = {"hub": hub, "pos": pos, "lines_in": []}
        # split chains. TTL (bounce-limited) destinations go first, lowest budget first, then
        # the heaviest: every filter a packet passes in the chain costs a TTL packet one
        # bounce. A sender with many destinations gets a split TREE: first one filter per
        # cluster (a.b.c.*), then one per endpoint inside the cluster, so the deepest line
        # is about (clusters + endpoints in a cluster) filters away instead of (all lines).
        budget = bounce_budgets()
        lines = []
        for a, dsts in sorted(out.items()):
            live = [d for d in dsts if d in self.leaves]
            key = lambda d: (budget.get((a, d), 99), -dsts[d])
            prev, pport = ends[a]["hub"], 1
            pos = ends[a]["pos"]
            # a linear chain would put some TTL line beyond its budget: use the split tree
            ttl = sorted(budget[(a, d)] for d in live if (a, d) in budget)
            needs_tree = any(i + 1 >= b for i, b in enumerate(ttl))
            if needs_tree:
                clusters = collections.OrderedDict()
                for d in sorted(live, key=key):
                    clusters.setdefault(".".join(d.split(".")[:3]), []).append(d)
                items = sorted(clusters.items(), key=lambda kv: min(key(d) for d in kv[1]))
            else:
                items = [(None, sorted(live, key=key))]
            col = 0
            for cl, ds in items:
                if cl is not None and len(ds) > 1:
                    # cluster tap: packets for this cluster leave on a sub-chain
                    col += 1
                    tap = self.new("hub", [pos[0] + 0.6 * col, pos[1] + 2, pos[2]], label=f"split {a} -> {cl}.*", hub_dir=0)
                    f = self.filt([pos[0] + 0.6 * col, pos[1] + 2.6, pos[2]], cl + ".*", "Differ", "SendBack", "DropInbound",
                                  label=f"split {a} -> {cl}.*")
                    self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                    prev, pport = tap, 2
                    sub, sport = f, 1
                    for j, d in enumerate(ds):
                        t2 = self.new("hub", [pos[0] + 0.6 * col, pos[1] + 3.2 + 0.6 * j, pos[2]], label=f"split {a} -> {d}", hub_dir=0)
                        f2 = self.filt([pos[0] + 0.6 * col + 0.3, pos[1] + 3.2 + 0.6 * j, pos[2]], d, "Differ", "SendBack",
                                       "DropInbound", label=f"split {a} -> {d}")
                        self.link(sub, sport, t2, 0); self.link(t2, 1, f2, 0)
                        sub, sport = t2, 2
                        lines.append((a, d, f2, dsts[d], (a, d) in limited))
                    end_ = self.filt([pos[0] + 0.6 * col, pos[1] + 3.2 + 0.6 * len(ds), pos[2]], "*.*.*.*", "Match", "Drop",
                                     "DropInbound", label=f"end of {a}'s {cl}.* lines")
                    self.link(sub, sport, end_, 0)
                    continue
                for d in ds:
                    col += 1
                    tap = self.new("hub", [pos[0] + 0.6 * col, pos[1] + 2, pos[2]], label=f"split {a} -> {d}", hub_dir=0)
                    f = self.filt([pos[0] + 0.6 * col, pos[1] + 2.6, pos[2]], d, "Differ", "SendBack", "DropInbound",
                                  label=f"split {a} -> {d}")
                    self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                    prev, pport = tap, 2
                    lines.append((a, d, f, dsts[d], (a, d) in limited))
            drop = self.filt([pos[0] + 0.6 * (col + 1), pos[1] + 2, pos[2]], "*.*.*.*", "Match", "Drop", "DropInbound",
                             label=f"end of {a}'s lines (drops spam / unknown addresses)")
            self.link(prev, pport, drop, 0)
        # merge chains: bounce-limited lines and the heaviest closest to the endpoint (packets
        # coming down the chain bounce once per merge they pass)
        into = collections.defaultdict(list)
        for a, d, f, w, lim in lines:
            into[d].append((a, f, w, lim))
        for d, ins in into.items():
            ins.sort(key=lambda x: (budget.get((x[0], d), 99), -x[2]))   # first = closest to the endpoint
            pos = ends[d]["pos"]
            prev, pport = ends[d]["hub"], 2
            for i, (a, f, w, lim) in enumerate(ins):
                if i == len(ins) - 1:
                    self.link(prev, pport, f, 1)                   # the farthest line joins directly
                    break
                m = self.new("hub", [pos[0] - 0.6 * (i + 1), pos[1] + 2, pos[2]], label=f"merge {a} -> {d}", hub_dir=0)
                mf = self.filt([pos[0] - 0.6 * (i + 1), pos[1] + 2.6, pos[2]], d, "Match", "SendBack", self.merge_collision,
                               label=f"merge {a} -> {d}")
                self.link(prev, pport, m, 0)
                self.link(m, 2, mf, 0)
                self.link(mf, 1, f, 1)
                prev, pport = m, 1
        self.n_lines = len(lines)
        if self.relay_spacing:
            self.add_relays(self.relay_spacing)
        return self.to_save()


def main():
    import flows as F
    import netopt as O
    ap = argparse.ArgumentParser()
    ap.add_argument("base"); ap.add_argument("out")
    ap.add_argument("--merge-collision", default="DropOutbound")
    ap.add_argument("--ticks", type=int, default=2100)
    ap.add_argument("--relay-spacing", type=float, default=6.0, help="relays every N units (0 = none)")
    a = ap.parse_args()
    path = a.base if os.path.exists(a.base) else os.path.join(os.environ["APPDATA"], "tunnet", a.base)
    base = json.load(open(path, encoding="utf-8"))
    g = Direct(base, a.merge_collision)
    g.relay_spacing = a.relay_spacing or None
    save = g.generate_direct()
    json.dump(save, open(a.out, "w", encoding="utf-8"), separators=(",", ":"))
    c = collections.Counter(n["type"] for n in g.nodes)
    print(f"{g.n_lines} lines; generated {dict(c)}, {len(save['edges'])} links -> {a.out}")
    r = F.score(F.TrackedNet(I.load(save)), 0, a.ticks)
    pf = r["per_flow"]
    mean = sum((pf[f]["delivered"] / sum(pf[f].values()) if f in pf and sum(pf[f].values()) else 0) for f in O.REQ) / len(O.REQ)
    cov = sum(1 for f in O.REQ if pf.get(f, {}).get("delivered", 0) > 0)
    print(f"{a.ticks} ticks: mean flow delivery {100 * mean:.1f}%, flows covered {cov}/{len(O.REQ)}, "
          f"packets {r['delivered']}/{r['sent']} ({100 * r['rate']:.1f}%), spam {r['spam']}")
    print("outcomes:", r["outcomes"])


if __name__ == "__main__":
    main()
