"""Hybrid wiring: direct lines where they are short or must stay direct, shared trunks for
the long routes between groups and regions of endpoints.

Groups are address prefixes a.b.c.* (filters can only tell addresses apart by prefix), and
regions a.b.*. Each group has a hub endpoint (its medoid), each region a hub group. A flow
s -> d takes one of these paths (each arrow is one cable, each [..] a shared trunk):
  direct            s -> d                       same group, TTL-limited senders, overflow
  group trunk       s -> [Gs>Gd] -> d            same region, different group
  region (lean)     s -> [Gs>Rd] -> [Rs>Rd] -> [Rs>Gd] -> d
  region (middle)   s -> [Rs>Rd] -> d            shares only the long haul between regions

A trunk is a COLLECTOR (merge chain: hub + filter Match <trunk mask> SendBack per input, as
in an endpoint's merge chain) at its start, a cable, and a DISTRIBUTOR (split chain: hub +
filter Differ <next mask> SendBack per output, drop at the end) at its end. A trunk carries
at most one packet per tick, so its load (packets/tick) is capped: the heaviest flows of an
overfull trunk go direct instead.

Everything else (endpoint split / merge chains, floor placement, routing around rock, digging,
relays) is directgen's. g.timetable_lines() describes every flow's path for timetable.js.

    python tools/hybridgen.py slot_0.json out.json [--mode lean|middle] [--cap 0.35]
"""
import argparse
import collections
import json
import math
import os

import directgen as D
import netgen as NG

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
SWAP = lambda a: {"0": "1", "1": "0"}.get(a[0], a[0]) + a[1:]
GRP = lambda a: ".".join(a.split(".")[:3])
REG = lambda a: ".".join(a.split(".")[:2])


class Hybrid(D.Direct):
    def __init__(self, base, mode="lean", cap=0.35, merge_collision="DropOutbound"):
        super().__init__(base, merge_collision)
        self.mode, self.cap = mode, cap
        self.feeder_edge = {}      # feeder key -> index of its cable in self.edges (delays)

    # ---------- which path each flow takes ----------
    def plan(self, out, budget):
        pos = {a: p for a, (_, _, p) in self.leaves.items()}
        groups, regions = collections.defaultdict(list), collections.defaultdict(list)
        for a in pos:
            groups[GRP(a)].append(a)
            regions[REG(a)].append(a)
        med = lambda v: min(v, key=lambda a: sum(math.dist(pos[a], pos[b]) for b in v))
        self.ghub = {g: med(v) for g, v in groups.items()}
        self.rhub = {r: min((self.ghub[g] for g in groups if REG(g + ".0") == r),
                            key=lambda h: sum(math.dist(pos[h], pos[b]) for b in v))
                     for r, v in regions.items()}
        paths = {}
        for s, dsts in out.items():
            for d, w in dsts.items():
                if d not in self.leaves:
                    continue
                if (s, d) in budget or GRP(s) == GRP(d):     # TTL-limited flows stay direct
                    paths[(s, d)] = ["end:" + d]
                elif REG(s) == REG(d):
                    paths[(s, d)] = [f"bus:{GRP(s)}>{GRP(d)}", "end:" + d]
                elif self.mode == "lean":
                    paths[(s, d)] = [f"bus:{GRP(s)}>{REG(d)}", f"bus:{REG(s)}>{REG(d)}", f"bus:{REG(s)}>{GRP(d)}", "end:" + d]
                else:
                    paths[(s, d)] = [f"bus:{REG(s)}>{REG(d)}", "end:" + d]
        # load cap: a trunk carries at most one packet a tick; the heaviest flows of an
        # overfull trunk go direct (repeat until every trunk is under the cap)
        while True:
            load = collections.Counter()
            on = collections.defaultdict(list)
            for f, p in paths.items():
                for st in p[:-1]:
                    load[st] += out[f[0]][f[1]]
                    on[st].append(f)
            over = [b for b in load if load[b] > self.cap]
            if not over:
                break
            for b in over:
                f = max(on[b], key=lambda f: out[f[0]][f[1]])
                paths[f] = ["end:" + f[1]]
        self.paths, self.load = paths, load
        return paths

    def bus_ends(self, b):
        """(start endpoint, end endpoint) of trunk b: whose cluster area holds its collector and
        its distributor."""
        a, z = b[4:].split(">")
        start = self.ghub.get(a) or self.rhub[a]
        if a.count(".") == 1 and z.count(".") == 1:     # region trunk: region hub to region hub
            return self.rhub[a], self.rhub[z]
        if a.count(".") == 2 and z.count(".") == 1:     # group to its own region hub (feeder)
            return self.ghub[a], self.rhub[REG(a + ".0")]
        if a.count(".") == 1 and z.count(".") == 2:     # region hub to a group (distributor)
            return self.rhub[REG(z + ".0")], self.ghub[z]
        return self.ghub[a], self.ghub[z]               # group to group

    @staticmethod
    def mask(stage):
        """Address mask of everything a sink takes in: a trunk's destinations, or an endpoint."""
        if stage.startswith("end:"):
            return stage[4:]
        z = stage[4:].split(">")[1]
        return z + ".*" * (4 - len(z.split(".")))

    # ---------- build ----------
    def generate_direct(self):
        rate = D.flow_rates()
        budget = D.bounce_budgets()
        out = collections.defaultdict(collections.Counter)
        for (s, d), w in rate.items():
            s2 = SWAP(s) if s.startswith("1.") else s
            d2 = SWAP(d) if d.startswith("1.") else d
            if s2 in self.leaves:
                out[s2][d2] += w
        paths = self.plan(out, budget)
        G, W = self.gap, self.col
        for n in self.snap.values():
            if n.get("pos"):
                self.take(n["pos"])
        P = lambda ref: self.pos_of(ref)
        ends = self.ends = {}
        for a, (ref, port, pos) in sorted(self.leaves.items()):
            up = self.snap[ref[1]].get("up", [0, 1, 0]) if ref[0] == "old" else [0, 1, 0]
            y0, f, r = self.frame(pos, up)
            ends[a] = {"pos": pos, "y0": y0, "f": f, "r": r}
            ends[a]["hub"] = self.new("hub", self.place(a, pos, G, 0), label=f"splitter {a}", hub_dir=0)
            self.link(ends[a]["hub"], 0, ref, port)
        # feeders: (source, sink) cables with the load they carry. A source is an endpoint
        # ("ep:a", its split chain) or a trunk ("bus:...", its distributor).
        feeders = collections.Counter()
        flow_feeders = {}
        for (s, d), p in paths.items():
            w = out[s][d]
            src, fl = "ep:" + s, []
            for st in p:
                feeders[(src, st)] += w
                fl.append((src, st))
                src = st
            flow_feeders[(s, d)] = fl
        outs = collections.defaultdict(list)        # source -> [(sink, load)]
        ins = collections.defaultdict(list)         # sink -> [(source, load)]
        for (src, st), w in feeders.items():
            outs[src].append((st, w))
            ins[st].append((src, w))
        port_of = {}                                # (source, sink) -> (filter ref, 1): where the cable starts
        bud = lambda src, st: budget.get((src[3:], st[4:]), 99) if src.startswith("ep:") and st.startswith("end:") else 99

        def split_chain(where, src, near, head, hport, label):
            """Taps for every output of src, at endpoint `where`'s area: TTL lines first, then
            exact destinations, then trunks, heaviest first; drop at the end."""
            prev, pport = head, hport
            order = sorted(outs[src], key=lambda x: (bud(src, x[0]), not x[0].startswith("end:"), -x[1]))
            for col, (st, w) in enumerate(order, 1):
                tap = self.new("hub", self.place(where, P(prev), G + W * col, G), label=f"{label} -> {st}", hub_dir=0)
                f = self.filt(self.place(where, P(tap), G + W * col, 2 * G), self.mask(st), "Differ", "SendBack",
                              "DropInbound", label=f"{label} -> {st}")
                self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                prev, pport = tap, 2
                port_of[(src, st)] = (f, 1)
            drop = self.filt(self.place(where, P(prev), G + W * (len(order) + 1), G), "*.*.*.*", "Match", "Drop",
                             "DropInbound", label=f"end of {label}")
            self.link(prev, pport, drop, 0)
            return prev

        def split_tree(a):
            """TTL-limited sender (all its flows are direct): directgen's split tree, one filter
            per group, then one per endpoint, TTL destinations first; a full group needs no
            filter for its last endpoint. Keeps every TTL line within its bounce budget."""
            src = "ep:" + a
            key = lambda st: (bud(src, st), -feeders[(src, st)])
            groups_ = collections.OrderedDict()
            rest = []                                    # trunk outputs: plain taps after the tree
            for st, _ in sorted(outs[src], key=lambda x: key(x[0])):
                if st.startswith("end:"):
                    groups_.setdefault(GRP(st[4:]), []).append(st)
                else:
                    rest.append(st)
            prev, pport, col = ends[a]["hub"], 1, 0
            for cl, sts in sorted(groups_.items(), key=lambda kv: min(key(s) for s in kv[1])):
                col += 1
                tap = self.new("hub", self.place(a, P(prev), G + W * col, G), label=f"split {a} -> {cl}.*", hub_dir=0)
                f = self.filt(self.place(a, P(tap), G + W * col, 2 * G), cl + ".*" if len(sts) > 1 else sts[0][4:],
                              "Differ", "SendBack", "DropInbound", label=f"split {a} -> {cl}.*")
                self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                prev, pport = tap, 2
                if len(sts) == 1:
                    port_of[(src, sts[0])] = (f, 1)
                    continue
                sub, sport = f, 1
                full = {s.split(".")[3] for s in sts} == {"0", "1", "2", "3"}
                for j, st in enumerate(sts):
                    if full and j == len(sts) - 1:
                        port_of[(src, st)] = (sub, sport)
                        sub = None
                        break
                    t2 = self.new("hub", self.place(a, P(sub), G + W * col, G * (3 + j)), label=f"split {a} -> {st}", hub_dir=0)
                    f2 = self.filt(self.place(a, P(t2), 2 * G + W * col, G * (3 + j)), st[4:], "Differ", "SendBack",
                                   "DropInbound", label=f"split {a} -> {st}")
                    self.link(sub, sport, t2, 0); self.link(t2, 1, f2, 0)
                    sub, sport = t2, 2
                    port_of[(src, st)] = (f2, 1)
                if sub is not None:
                    self.link(sub, sport, self.filt(self.place(a, P(sub), G + W * col, G * (3 + len(sts))), "*.*.*.*",
                                                    "Match", "Drop", "DropInbound", label=f"end of {a}'s {cl}.* lines"), 0)
            for st in rest:
                col += 1
                tap = self.new("hub", self.place(a, P(prev), G + W * col, G), label=f"split {a} -> {st}", hub_dir=0)
                f = self.filt(self.place(a, P(tap), G + W * col, 2 * G), self.mask(st), "Differ", "SendBack",
                              "DropInbound", label=f"split {a} -> {st}")
                self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                prev, pport = tap, 2
                port_of[(src, st)] = (f, 1)
            drop = self.filt(self.place(a, P(prev), G + W * (col + 1), G), "*.*.*.*", "Match", "Drop", "DropInbound",
                             label=f"end of split {a}")
            self.link(prev, pport, drop, 0)

        # sender split chains (a split tree where a straight chain would exceed a TTL budget)
        ttl_senders = {s for (s, _) in budget}
        for a in sorted(ends):
            if not outs.get("ep:" + a):
                continue
            ttl = sorted(budget[(a, st[4:])] for st, _ in outs["ep:" + a] if (a, st[4:]) in budget)
            if a in ttl_senders and any(i + 1 >= b for i, b in enumerate(ttl)):
                split_tree(a)
            else:
                split_chain(a, "ep:" + a, ends[a]["pos"], ends[a]["hub"], 1, f"split {a}")
        # trunk distributors (at the trunk's end); remember each one's first tap: the marker
        # where every packet of the trunk passes (timetable.js measures trunk timing there)
        self.markers = {}
        dist_head = {}
        buses = sorted(st for st in ins if st.startswith("bus:"))
        for b in buses:
            start, end = self.bus_ends(b)
            first = self.new("hub", self.place(end, ends[end]["pos"], G, -3 * G), label=f"trunk {b[4:]} arrives", hub_dir=0)
            dist_head[b] = first
            self.markers[b] = first
            # the arrival hub passes everything on (leg 0 -> 1) into the distributor taps
            split_chain(end, b, ends[end]["pos"], first, 1, f"trunk {b[4:]}")
            # its leg 2 is unused: close it with a drop filter so nothing leaks
        # collectors: endpoint merge chains and trunk collecting chains. Inputs nearest the
        # sink first (lowest priority in a collision); TTL lines, then the heaviest.
        self.entry = {}                              # (source, sink) -> merge position (0 = nearest)
        for st, srcs in ins.items():
            srcs.sort(key=lambda x: (bud(x[0], st), -x[1]))
            if st.startswith("end:"):
                d = st[4:]
                where, prev, pport, mk = d, ends[d]["hub"], 2, d
            else:
                start, _ = self.bus_ends(st)
                where, mk = start, self.mask(st)
                prev = None
            for i, (src, w) in enumerate(srcs):
                self.entry[(src, st)] = i
                key = f"{src} => {st}"
                if i == len(srcs) - 1:               # the farthest input joins directly
                    if prev is None:                 # single-input trunk: straight to the distributor
                        self.link(*port_of[(src, st)], dist_head[st], 0)
                    else:
                        self.link(prev, pport, *port_of[(src, st)])
                    self.feeder_edge[key] = len(self.edges) - 1
                    break
                near = P(prev) if prev is not None else ends[where]["pos"]
                m = self.new("hub", self.place(where, near, G + W * i, -G), label=f"merge {src} -> {st}", hub_dir=0)
                mf = self.filt(self.place(where, P(m), G + W * i, -2 * G), mk, "Match", "SendBack", self.merge_collision,
                               label=f"merge {src} -> {st}")
                if prev is None:                     # head of a trunk's collector: the trunk cable
                    self.link(m, 0, dist_head[st], 0)
                else:
                    self.link(prev, pport, m, 0)
                self.link(m, 2, mf, 0)
                self.link(mf, 1, *port_of[(src, st)])
                self.feeder_edge[key] = len(self.edges) - 1
                prev, pport = m, 1
        for b in buses:                              # unused leg of each arrival hub
            self.link(dist_head[b], 2, self.filt(self.place(self.bus_ends(b)[1], P(dist_head[b]), G, -4 * G),
                                                 "*.*.*.*", "Match", "Drop", "DropInbound",
                                                 label=f"trunk {b[4:]} spare leg"), 0)
        self.flow_feeders = flow_feeders
        self.n_lines = len(feeders)
        # delays: extra relays on a feeder cable
        self.edge_extra = {self.feeder_edge[k]: n for k, n in self.delay.items() if k in self.feeder_edge}
        self.line_keys = set(self.feeder_edge)
        self.route_relays(self.relay_spacing or 6.0, self.terrain, router=self.router)
        if self.router:
            self.router.save_cache()
        save = self.to_save()
        if self.dig:
            self.dig_report = D.DG.plan(save)
            save = D.DG.apply(save, self.dig_report["dig"])
        return save

    def timetable_lines(self):
        """For timetable.js: every flow's path (sink, merge position, feeder cable) and the
        node where each trunk's packets pass (its arrival hub)."""
        paths = {}
        for (s, d), fl in self.flow_feeders.items():
            paths[f"{s} -> {d}"] = [[st, self.entry[(src, st)], f"{src} => {st}"] for src, st in fl]
        return {"paths": paths, "markers": {b: self.idx[r] for b, r in self.markers.items()},
                "feeders": {k: k.split(" => ")[1] for k in self.feeder_edge}}

    def summary(self):
        buses = [b for b in self.load]
        kinds = collections.Counter(len(p) for p in self.paths.values())
        return {"mode": self.mode, "cap": self.cap, "trunks": len(buses),
                "busiest_trunk": round(max(self.load.values()), 3) if self.load else 0,
                "flows_direct": kinds.get(1, 0), "flows_shared": sum(v for k, v in kinds.items() if k > 1),
                "feeder_cables": self.n_lines}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("base"); ap.add_argument("out")
    ap.add_argument("--mode", default="lean", choices=["lean", "middle"])
    ap.add_argument("--cap", type=float, default=0.35)
    ap.add_argument("--delays", default="")
    a = ap.parse_args()
    path = a.base if os.path.exists(a.base) else os.path.join(os.environ["APPDATA"], "tunnet", a.base)
    base = json.load(open(path, encoding="utf-8"))
    g = Hybrid(base, a.mode, a.cap)
    g.relay_spacing = 6.0
    if a.delays and os.path.exists(a.delays):
        g.delay = json.load(open(a.delays))
    save = g.generate_direct()
    with open(a.out, "w", encoding="utf-8") as f:
        json.dump(save, f, indent=2)
    c = collections.Counter(n["type"] for n in g.nodes)
    print(json.dumps(g.summary(), indent=2))
    print(f"generated {dict(c)}, {len(save['edges'])} links -> {a.out}")
    if g.router:
        print("cable routes:", g.router.stats)
    if g.dig:
        r = g.dig_report
        print(f"digging: {len(r['dig'])} dirt voxels; {sum(r['blocked'].values())} nodes/cables still blocked")


if __name__ == "__main__":
    main()
