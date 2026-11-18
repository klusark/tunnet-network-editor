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
import terrain as TER
import tunnels as TU
import dig as DG

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
        self.delay = {}            # (sender, destination) -> extra relays on that line
        self.line_keys = set()
        self.merge_index = {}      # (sender, destination) -> position in d's merge chain
        self.edge_extra = {}

        self.dead_masks = []
        self.terrain = TER.Terrain(base) if base.get("chunks") else None
        # routes around rock that is not dirt; found routes are cached on disk (same map)
        self.router = TU.Router(base, cache=os.path.join(ROOT, "out", "route_cache.json")) if self.terrain else None
        self.dig = bool(self.terrain)     # dig the dirt the nodes and cables need
        self.gap = 1.5             # spacing between neighbouring nodes in an endpoint's cluster
        self.col = 3.0             # spacing between split taps / merge hubs along the cluster
        self.max_cells = 5000      # floor spots (open or diggable) searched per endpoint
        self.occupied = {}         # floor bucket -> node positions already placed
        self.fallbacks = 0         # nodes that found no open floor
        self.dug_spots = set()     # cluster spots that need digging (dirt)

    # ---------- cluster layout: a strip on the floor in front of each endpoint ----------
    def frame(self, pos, up):
        """(floor height, forward, right) for an endpoint's cluster. Forward is the
        horizontal direction with the most open floor at the endpoint's floor height
        (a wall endpoint's own facing is tried first)."""
        T = self.terrain
        if not T:
            return pos[1], (1.0, 0.0), (0.0, 1.0)
        y0 = T.level(pos[0], pos[2], pos[1])
        dirs = [(math.cos(k * math.pi / 4), math.sin(k * math.pi / 4)) for k in range(8)]
        h = math.hypot(up[0], up[2])
        if h > 0.5:
            dirs.insert(0, (up[0] / h, up[2] / h))

        def open_floor(d):
            n = 0
            for k in range(1, 25):
                x, z = pos[0] + d[0] * k, pos[2] + d[1] * k
                if T.solid(x, y0 + 0.25, z) or abs(T.level(x, z, y0) - y0) > 0.75:
                    break
                n += 1
            return n
        best = max(dirs, key=lambda d: (open_floor(d), d is dirs[0]))
        return y0, best, (-best[1], best[0])

    def floor_cells(self, a):
        """Floor spots for endpoint a's cluster, nearest first: a breadth-first walk over the
        router's grid (1-unit cells, air or dirt only; level steps need a floor, vertical
        steps do not, so the walk can go up or down shafts), keeping every cell that has a
        floor under it. Spots in dirt need digging (dug_spots)."""
        R, e = self.router, self.ends[a]
        start = R.snap([e["pos"][0], e["y0"], e["pos"][2]])
        seen = {start}
        order, q = [], collections.deque([start])
        while q and len(seen) < self.max_cells:
            c = q.popleft()
            dig = R.open_cell(c)
            if dig is not None and R.supported(c):
                p = (c[0] + 0.5, c[1] * TER.VOX, c[2] + 0.5)
                order.append(p)
                if dig:
                    self.dug_spots.add((round(p[0], 3), round(p[1], 3), round(p[2], 3)))
            for dx, dy, dz in TU.DIRS:
                n = (c[0] + dx, c[1] + dy, c[2] + dz)
                if n in seen or R.open_cell(n) is None:
                    continue
                if dy == 0 and not R.supported(n) and not R.supported(c):
                    continue          # one step off a ledge is fine, walking on air is not
                seen.add(n)
                q.append(n)
        return order

    def diggable_spot(self, x, y, z):
        """Room for a node at (x, y, z) can be dug: its box is air or dirt only, and the
        voxel under it is solid."""
        if self.router is None:
            return False
        for v in DG.node_box([x, y, z]):
            val = self.router.v(v)
            if val != 0 and val not in DG.DIRT:
                return False
        vy = math.floor(y / TER.VOX) - 1
        return self.router.v((math.floor(x / TER.VOX), vy, math.floor(z / TER.VOX))) != 0

    def free(self, p):
        key = (math.floor(p[0]), math.floor(p[2]))
        for dx in (-1, 0, 1):
            for dz in (-1, 0, 1):
                for q in self.occupied.get((key[0] + dx, key[1] + dz), ()):
                    if math.hypot(q[0] - p[0], q[2] - p[2]) < 1.2 and abs(q[1] - p[1]) < 2:
                        return False
        return True

    def take(self, p):
        self.occupied.setdefault((math.floor(p[0]), math.floor(p[2])), []).append(p)
        return [float(v) for v in p]

    def place(self, a, near, fwd, right):
        """Floor spot for a node of endpoint a's cluster: the free open-floor spot nearest
        `near` (the node it links to). With no open floor left, fall back to the strip
        layout (`fwd` ahead, `right` beside the endpoint), which may be inside rock."""
        if self.terrain:
            cells = self.ends[a].setdefault("cells", None)
            if cells is None:
                cells = self.ends[a]["cells"] = self.floor_cells(a)
            best = None
            for c in cells:
                if self.free(c):
                    d = math.dist(c, near) + 0.01 * math.dist(c, self.ends[a]["pos"])
                    if (round(c[0], 3), round(c[1], 3), round(c[2], 3)) in self.dug_spots:
                        d += 3.0                      # open floor first, digging second
                    if best is None or d < best[0]:
                        best = (d, c)
            if best:
                return self.take(best[1])
            self.fallbacks += 1
        return self.take(self.at(a, fwd, right))

    def at(self, a, fwd, right):
        """Floor position `fwd` ahead of and `right` beside endpoint a."""
        e = self.ends[a]
        (fx, fz), (rx, rz) = e["f"], e["r"]
        x = e["pos"][0] + fx * fwd + rx * right
        z = e["pos"][2] + fz * fwd + rz * right
        y = self.terrain.level(x, z, e["y0"]) if self.terrain else e["y0"]
        return [x, y, z]

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
        ends = self.ends = {}
        G, W = self.gap, self.col
        for n in self.snap.values():
            if n.get("pos"):
                self.take(n["pos"])
        P = lambda ref: self.pos_of(ref)
        for a, (ref, port, pos) in sorted(self.leaves.items()):
            up = self.snap[ref[1]].get("up", [0, 1, 0]) if ref[0] == "old" else [0, 1, 0]
            y0, f, r = self.frame(pos, up)
            ends[a] = {"pos": pos, "y0": y0, "f": f, "r": r, "lines_in": []}
            hub = self.new("hub", self.place(a, pos, G, 0), label=f"splitter {a}", hub_dir=0)
            self.link(hub, 0, ref, port)
            ends[a]["hub"] = hub
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
                    tap = self.new("hub", self.place(a, P(prev), G + W * col, G), label=f"split {a} -> {cl}.*", hub_dir=0)
                    f = self.filt(self.place(a, P(tap), G + W * col, 2 * G), cl + ".*", "Differ", "SendBack", "DropInbound",
                                  label=f"split {a} -> {cl}.*")
                    self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                    prev, pport = tap, 2
                    sub, sport = f, 1
                    # a cluster whose four addresses are all destinations needs no filter for
                    # the last one: whatever the other three bounce can only be for it. That
                    # saves a TTL packet one bounce on the deepest line.
                    full = {d.split(".")[3] for d in ds} == {"0", "1", "2", "3"}
                    for j, d in enumerate(ds):
                        if full and j == len(ds) - 1:
                            lines.append((a, d, (sub, sport), dsts[d], (a, d) in limited))
                            sub = None
                            break
                        t2 = self.new("hub", self.place(a, P(sub), G + W * col, G * (3 + j)), label=f"split {a} -> {d}", hub_dir=0)
                        f2 = self.filt(self.place(a, P(t2), 2 * G + W * col, G * (3 + j)), d, "Differ", "SendBack",
                                       "DropInbound", label=f"split {a} -> {d}")
                        self.link(sub, sport, t2, 0); self.link(t2, 1, f2, 0)
                        sub, sport = t2, 2
                        lines.append((a, d, (f2, 1), dsts[d], (a, d) in limited))
                    if sub is None:
                        continue
                    end_ = self.filt(self.place(a, P(sub), G + W * col, G * (3 + len(ds))), "*.*.*.*", "Match", "Drop",
                                     "DropInbound", label=f"end of {a}'s {cl}.* lines")
                    self.link(sub, sport, end_, 0)
                    continue
                for d in ds:
                    col += 1
                    tap = self.new("hub", self.place(a, P(prev), G + W * col, G), label=f"split {a} -> {d}", hub_dir=0)
                    f = self.filt(self.place(a, P(tap), G + W * col, 2 * G), d, "Differ", "SendBack", "DropInbound",
                                  label=f"split {a} -> {d}")
                    self.link(prev, pport, tap, 0); self.link(tap, 1, f, 0)
                    prev, pport = tap, 2
                    lines.append((a, d, (f, 1), dsts[d], (a, d) in limited))
            drop = self.filt(self.place(a, P(prev), G + W * (col + 1), G), "*.*.*.*", "Match", "Drop", "DropInbound",
                             label=f"end of {a}'s lines (drops spam / unknown addresses)")
            self.link(prev, pport, drop, 0)
        # merge chains: bounce-limited lines and the heaviest closest to the endpoint (packets
        # coming down the chain bounce once per merge they pass)
        into = collections.defaultdict(list)
        for a, d, f, w, lim in lines:
            into[d].append((a, f, w, lim))
        for d, ins in into.items():
            ins.sort(key=lambda x: (budget.get((x[0], d), 99), -x[2]))   # first = closest to the endpoint
            prev, pport = ends[d]["hub"], 2
            for i, (a, f, w, lim) in enumerate(ins):
                if i == len(ins) - 1:
                    self.link(prev, pport, *f)                     # the farthest line joins directly
                    self.mark_line(a, d, i)
                    break
                m = self.new("hub", self.place(d, P(prev), G + W * i, -G), label=f"merge {a} -> {d}", hub_dir=0)
                mf = self.filt(self.place(d, P(m), G + W * i, -2 * G), d, "Match", "SendBack", self.merge_collision,
                               label=f"merge {a} -> {d}")
                self.link(prev, pport, m, 0)
                self.link(m, 2, mf, 0)
                self.link(mf, 1, *f)
                self.mark_line(a, d, i)
                prev, pport = m, 1
        self.n_lines = len(lines)
        if self.relay_spacing or self.delay:
            self.route_relays(self.relay_spacing or 6.0, self.terrain, router=self.router)
            if self.router:
                self.router.save_cache()
        save = self.to_save()
        if self.dig:
            self.dig_report = DG.plan(save)
            save = DG.apply(save, self.dig_report["dig"])
        return save

    def mark_line(self, a, d, i):
        """The link just added is the line a -> d, joining d's merge chain at position i
        (0 = closest to d); give it the extra delay asked for."""
        self.line_keys.add((a, d))
        self.merge_index[(a, d)] = i
        if self.delay.get((a, d)):
            self.edge_extra[len(self.edges) - 1] = self.delay[(a, d)]


def main():
    import flows as F
    import netopt as O
    ap = argparse.ArgumentParser()
    ap.add_argument("base"); ap.add_argument("out")
    ap.add_argument("--merge-collision", default="DropOutbound")
    ap.add_argument("--ticks", type=int, default=2100)
    ap.add_argument("--relay-spacing", type=float, default=6.0, help="relays every N units (0 = none)")
    ap.add_argument("--delays", default=os.path.join(os.path.dirname(os.path.abspath(__file__)), "direct_delays.json"),
                    help="extra relays per line, from tools/delayopt.py ('' = none)")
    a = ap.parse_args()
    path = a.base if os.path.exists(a.base) else os.path.join(os.environ["APPDATA"], "tunnet", a.base)
    base = json.load(open(path, encoding="utf-8"))
    g = Direct(base, a.merge_collision)
    g.relay_spacing = a.relay_spacing or None
    if a.delays and os.path.exists(a.delays):
        g.delay = {tuple(k.split(" -> ")): v for k, v in json.load(open(a.delays)).items()}
    save = g.generate_direct()
    json.dump(save, open(a.out, "w", encoding="utf-8"), indent=2)
    c = collections.Counter(n["type"] for n in g.nodes)
    print(f"{g.n_lines} lines; generated {dict(c)}, {len(save['edges'])} links -> {a.out}")
    if g.terrain:
        print(f"cluster nodes: {g.fallbacks} found no floor spot (placed in a strip, may be in rock); "
              f"{len(g.dug_spots)} spots need digging")
    if g.router:
        print("cable routes:", g.router.stats)
        why = collections.Counter(w for _, _, w in g.router.failures)
        if why:
            print("  no route found:", dict(why))
    if g.dig:
        r = g.dig_report
        print(f"digging: {len(r['dig'])} dirt voxels; {r['clear']} nodes/cables had room, {r['need_dig']} dug, "
              f"{sum(r['blocked'].values())} still blocked {dict(r['blocked'])}")
    r = F.score(F.TrackedNet(I.load(save)), 0, a.ticks)
    pf = r["per_flow"]
    mean = sum((pf[f]["delivered"] / sum(pf[f].values()) if f in pf and sum(pf[f].values()) else 0) for f in O.REQ) / len(O.REQ)
    cov = sum(1 for f in O.REQ if pf.get(f, {}).get("delivered", 0) > 0)
    print(f"{a.ticks} ticks: mean flow delivery {100 * mean:.1f}%, flows covered {cov}/{len(O.REQ)}, "
          f"packets {r['delivered']}/{r['sent']} ({100 * r['rate']:.1f}%), spam {r['spam']}")
    print("outcomes:", r["outcomes"])


if __name__ == "__main__":
    main()
