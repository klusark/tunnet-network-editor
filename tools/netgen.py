"""Generate a routing network that carries every flow, from a base save.

Logical design only (stage 1): node positions are rough (centres of the endpoints each
part serves) and cables may be any length. Digging tunnels and placing relays to make it
buildable is a later stage. The result is a save file, so the simulator, tools/flows.py
and the offline viewer can all load it.

Design: an address tree. Each group of endpoints that share an address prefix gets a
SPINE of hubs; each child (sub-group or endpoint) hangs off the spine behind a CHILD
FILTER that only lets in packets for that child and sends everything else back into the
hub. A group's ROOT FILTER, at the top of its spine, turns back packets that are going up
but belong inside the group. Bridges are leaves with address 0.y.1.0 (a bridge turns
0.y into 1.y), with their outer endpoint 1.y.1.0 attached on the far side. At the top of
the tree, packets for addresses that don't exist are dropped and the rest are reflected.

Hub legs: port 0 = up, 1 = child, 2 = down. Spine direction (hub_dir) is an option:
  "up"   (dir 1): up->down, down->child, child->up. Packets from above run to the bottom
                  and then try the children from the bottom up.
  "down" (dir 0): up->child, child->down, down->up. Packets from above try the children
                  from the top down.

    python tools/netgen.py slot_0.json out.json [--spine up|down] [--ticks 2000]
"""
import argparse
import collections
import copy
import json
import math
import os

import save_import as I

TYPE_LISTS = ("relays", "filters", "hubs", "testers", "endpoints", "antennas", "bridges")


class Gen:
    def __init__(self, base, spine="up", child_collision="DropInbound", root_collision="DropInbound",
                 leaf_collision=None, bare_leaves=False, order=None):
        self.base = base
        self.bare_leaves = bare_leaves     # endpoints hang straight off the hub (they bounce wrong packets)
        self.order = order or {}          # group prefix (e.g. "0.2.0") -> child digits in spine order
        self.cfg = {}                     # group prefix -> {"dir", "order", "bare": [digits], "cc", "rc"}
        self.leaf_collision = leaf_collision or child_collision
        self.spine = spine
        self.child_collision = child_collision
        self.root_collision = root_collision
        snap = I.load(base)
        self.snap = snap
        self.nodes = []        # generated: {"type", "pos", "filter"/"hub_dir"}
        self.edges = []        # [((ref, port), (ref, port))]; ref = ("old", index) | ("new", index)
        self.leaves = {}       # address -> (ref, port, pos)
        self.dead_count = 0
        self.group_children = {}          # prefix -> [(digit, is_endpoint_leaf)]
        self.shortcuts = []               # [(prefix A, prefix B)]: one-way bypass from part A to part B
        self.sc_ends = collections.defaultdict(dict)
        self.sc_exit_collision = "SendBackOutbound"   # packets bounced back off a busy entry retry
        self.notes = []
        bridges = {e: n for e, n in snap.items() if n["type"] == "bridge"}
        outer = {n["address"]: e for e, n in snap.items() if n.get("address", "").startswith("1.")}
        for e, n in snap.items():
            a = n.get("address")
            if n["type"] == "endpoint" and a and not a.startswith("1."):
                self.leaves[a] = (("old", e), 0, n["pos"])
        # spam guards: infected endpoints only send spam on their own; their legit traffic is
        # replies. A filter in front of each drops what they send except to reply targets.
        import reply_rules as RR
        for e, n in snap.items():
            if n.get("infection") == 5 and n["address"] in self.leaves:
                me = n["address"]; x = me.split(".")[1]
                targets = sorted({r["match_src"].replace("x", x) for r in RR.rules_for(me) if r.get("match_src")})
                if len(targets) > 1:
                    continue                        # can't express with one mask
                mask, op = (targets[0], "Differ") if targets else ("*.*.*.*", "Match")
                g = self.filt(n["pos"], mask, op, "Drop", "DropInbound", label=f"spam guard {me}")
                self.link(g, 0, ("old", e), 0)      # filtered side faces the endpoint
                self.leaves[me] = (g, 1, n["pos"])
                self.notes.append(f"spam guard on {me}: drop what it sends {'except to ' + targets[0] if targets else '(all)'}")
        for a, oe in sorted(outer.items()):   # bridge y <-> 1.y.1.0: the nearest bridge
            b = min(bridges, key=lambda x: math.dist(bridges[x]["pos"], snap[oe]["pos"]))
            y = a.split(".")[1]
            self.leaves[f"0.{y}.1.0"] = (("old", b), 0, bridges[b]["pos"])
            self.edges.append(((("old", b), 1), (("old", oe), 0)))
            self.notes.append(f"bridge #{b} carries 0.{y}.1.0 <-> {a}")

    # ---------- building blocks ----------
    def new(self, typ, pos, label="", **cfg):
        self.nodes.append(dict(type=typ, pos=[float(v) for v in pos], label=label, **cfg))
        return ("new", len(self.nodes) - 1)

    def link(self, a, pa, b, pb):
        self.edges.append(((a, pa), (b, pb)))

    def filt(self, pos, mask, op, action, collision, label=""):
        return self.new("filter", pos, label=label or f"{op} {mask} {action}", filter={"port": 0, "mask": mask, "mask_type": "Filter", "collision": collision,
                                               "addr": "Dst", "action": action, "op": op})

    @staticmethod
    def mask(prefix):
        d = prefix + ["*"] * (4 - len(prefix))
        return ".".join(d)

    @staticmethod
    def centre(points):
        return [sum(p[i] for p in points) / len(points) for i in range(3)]

    # ---------- the tree ----------
    def build(self, prefix, addrs, root=False):
        """Returns (ref, port, pos): where the parent connects to this part."""
        if len(addrs) == 1 and not root:
            ref, port, pos = self.leaves[addrs[0]]
            return self.finish(addrs[0].split("."), (ref, port, pos))
        groups = collections.OrderedDict()
        for a in sorted(addrs):
            groups.setdefault(a.split(".")[len(prefix)], []).append(a)
        if len(groups) > 1 or root:
            self.group_children[".".join(prefix)] = [(d, len(v) == 1 and self.snap[self.leaves[v[0]][0][1]]["type"] == "endpoint"
                                                      if len(v) == 1 else False) for d, v in groups.items()]
        if len(groups) == 1 and not root:          # nothing to choose at this digit
            d, sub = next(iter(groups.items()))
            return self.finish(prefix, self.build(prefix + [d], sub))
        gc = self.cfg.get(".".join(prefix), {})
        digits = list(groups)
        want = gc.get("order") or self.order.get(".".join(prefix))
        if want:
            digits = [d for d in want if d in groups] + [d for d in digits if d not in want]
        kids = [(prefix + [d], self.build(prefix + [d], groups[d])) for d in digits]
        pos = self.centre([self.leaves[a][2] for a in addrs])
        hub_dir = 1 if gc.get("dir", self.spine) == "up" else 0
        k = len(kids)
        # spine: one hub per child (child on the hub's child leg), and a reflector at the
        # bottom that sends everything back up. The reflector's other side is unconnected,
        # so its sendbacks never collide.
        hubs = [self.new("hub", [pos[0], pos[1] + 0.5 * i, pos[2]], label=f"hub {self.mask(prefix)} #{i + 1}",
                         hub_dir=hub_dir) for i in range(k)]
        for i in range(1, k):
            self.link(hubs[i - 1], 2, hubs[i], 0)
        refl = self.filt([pos[0], pos[1] - 1, pos[2]], "*.*.*.*", "Match", "SendBack", "DropInbound",
                         label=f"reflector {self.mask(prefix)}")
        self.link(hubs[-1], 2, refl, 0)
        for i, (kp, (ref, port, kpos)) in enumerate(kids):
            fpos = [pos[c] + (kpos[c] - pos[c]) * 0.15 for c in range(3)]
            coll = gc.get("cc") or (self.leaf_collision if ref[0] == "old" else self.child_collision)
            bare = (kp[-1] in gc["bare"]) if "bare" in gc else self.bare_leaves
            if bare and ref[0] == "old" and self.snap[ref[1]]["type"] == "endpoint":
                self.link(hubs[i], 1, ref, port)
                continue
            cf = self.filt(fpos, self.mask(kp), "Differ", "SendBack", coll)
            self.link(hubs[i], 1, cf, 0)
            self.link(cf, 1, ref, port)
        top, top_port = hubs[0], 0
        if root:
            # drop packets for addresses that don't exist, reflect everything else back down
            chain_top, chain_port = self.dead_drops(prefix, groups, pos, top, top_port)
            refl = self.filt([pos[0], pos[1] + 3, pos[2]], "*.*.*.*", "Match", "SendBack", self.root_collision)
            self.link(chain_top, chain_port, refl, 0)
            return refl, 1, pos
        # drop packets that belong to this group but to none of its children (an address that
        # doesn't exist, e.g. spam to a random address); otherwise they would circle forever
        top, top_port = self.dead_drops(prefix, groups, pos, top, top_port)
        rf = self.filt([pos[0], pos[1] + 1, pos[2]], self.mask(prefix), "Match", "SendBack", gc.get("rc", self.root_collision))
        self.link(top, top_port, rf, 0)
        return self.finish(prefix, (rf, 1, pos))

    def finish(self, prefix, att):
        """Stack shortcut taps between a part and its parent.
        Exit tap (part is a shortcut source): hub legs 0 part, 1 shortcut, 2 parent, dir 0:
          the part's outgoing packets try the shortcut filter (Differ <dest>, SendBack): packets
          for the destination take the shortcut, the rest bounce back and go to the parent.
          Nothing arrives from the shortcut side, so this filter never collides.
        Entry tap (part is a shortcut destination): hub legs 0 part, 1 parent, 2 shortcut,
          dir 0: packets from the parent bounce off the shortcut filter (Match <part>,
          SendBack) into the part; shortcut arrivals pass into the part. On a collision the
          arriving shortcut packet is sent back up the shortcut (SendBackOutbound) and takes
          the normal route from the source instead."""
        p = ".".join(prefix)
        ref, port, pos = att
        for a, b in self.shortcuts:
            for role, mine, other in (("out", a, b), ("in", b, a)):
                if mine != p or role in self.sc_ends[(a, b)]:
                    continue
                tap = self.new("hub", [pos[0], pos[1] + 2, pos[2]], label=f"shortcut {role} {a}->{b}", hub_dir=0)
                if role == "out":
                    f = self.filt([pos[0] + 0.5, pos[1] + 2, pos[2]], self.mask(b.split(".")), "Differ", "SendBack",
                                  self.sc_exit_collision, label=f"shortcut exit {a}->{b}")
                    self.link(ref, port, tap, 0); self.link(tap, 1, f, 0)
                    ref, port = tap, 2
                else:
                    f = self.filt([pos[0] + 0.5, pos[1] + 2, pos[2]], self.mask(prefix), "Match", "SendBack",
                                  "SendBackOutbound", label=f"shortcut entry {a}->{b}")
                    self.link(ref, port, tap, 0); self.link(tap, 2, f, 0)
                    ref, port = tap, 1
                self.sc_ends[(a, b)][role] = f
        return ref, port, pos

    def link_shortcuts(self):
        for (a, b), ends in self.sc_ends.items():
            if "out" in ends and "in" in ends:
                self.link(ends["out"], 1, ends["in"], 1)
                self.notes.append(f"shortcut {a} -> {b}")
            else:
                self.notes.append(f"shortcut {a} -> {b} skipped (no such part)")

    def dead_drops(self, prefix, groups, pos, top, top_port):
        """Chain Drop filters (filtered port facing down) above the spine for every digit at
        this level that has no child. Returns the new top."""
        for d in "0123":
            if d in groups:
                continue
            m = self.mask(prefix + [d])
            f = self.filt([pos[0], pos[1] + 1.5, pos[2]], m, "Match", "Drop", "DropInbound")
            self.link(top, top_port, f, 0)
            top, top_port = f, 1
            self.dead_count += 1
        return top, top_port

    def generate(self, flows_dsts):
        """flows_dsts: every destination address that is sent to."""
        dead = sorted(d for d in flows_dsts if d not in self.leaves and not d.startswith("1."))
        self.dead_masks = sorted({self.mask(d.split(".")[:3]) for d in dead})
        if dead:
            self.notes.append(f"no endpoint for {', '.join(dead)}: dropped at the top ({', '.join(self.dead_masks)})")
        self.build([], sorted(self.leaves), root=True)
        self.link_shortcuts()
        return self.to_save()

    # ---------- output ----------
    def to_save(self):
        base = self.base
        old_type, old_entry = {}, {}
        for lst in TYPE_LISTS:
            for r in base[lst]:
                old_type[r["node"]], old_entry[r["node"]] = lst, r
        keep = [i for i in range(len(base["nodes"])) if old_type[i] in ("endpoints", "bridges", "antennas", "testers")]
        idx = {("old", i): k for k, i in enumerate(keep)}
        out = copy.copy(base)
        out["nodes"] = [base["nodes"][i] for i in keep]
        lists = {lst: [] for lst in TYPE_LISTS}
        for i in keep:
            lists[old_type[i]].append(dict(old_entry[i], node=idx[("old", i)]))
        for j, n in enumerate(self.nodes):
            k = len(out["nodes"])
            idx[("new", j)] = k
            out["nodes"].append({"pos": n["pos"], "up": [0.0, 1.0, 0.0], "angle": 0.0})
            if n["type"] == "hub":
                lists["hubs"].append({"node": k, "fixed": False, "dir": bool(n["hub_dir"])})
            else:
                f = n["filter"]
                names = {"0": "Zero", "1": "One", "2": "Two", "3": "Three", "*": "Wildcard"}
                lists["filters"].append({"node": k, "fixed": False, "config": {
                    "port": f["port"], "mask": {"elements": [names[d] for d in f["mask"].split(".")],
                                                "address_type": f["mask_type"]},
                    "addr": f["addr"], "action": {"Drop": "DropPacket", "SendBack": "SendBackPacket"}[f["action"]],
                    "op": f["op"], "collision": f["collision"]}})
        out.update(lists)
        out["edges"] = [[[idx[a], pa], [idx[b], pb], 0] for (a, pa), (b, pb) in self.edges]
        self.labels = {idx[("new", j)]: n["label"] for j, n in enumerate(self.nodes)}
        return out


def flow_destinations():
    rules = json.load(open(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                                        "re", "endpoint_rules.json")))["endpoints"]
    d = {s["dst"] for r in rules.values() for s in r["slots"].values()}
    return d | {"2.1.2.0", "2.1.2.1", "2.1.2.2", "2.1.2.3", "0.3.0.0"}   # token ring hops


def main():
    import flows as F
    ap = argparse.ArgumentParser()
    ap.add_argument("base"); ap.add_argument("out")
    ap.add_argument("--spine", default="up", choices=["up", "down"])
    ap.add_argument("--child-collision", default="DropInbound")
    ap.add_argument("--root-collision", default="DropInbound")
    ap.add_argument("--leaf-collision", default=None)
    ap.add_argument("--bare-leaves", action="store_true")
    ap.add_argument("--ticks", type=int, default=2000)
    a = ap.parse_args()
    path = a.base if os.path.exists(a.base) else os.path.join(os.environ["APPDATA"], "tunnet", a.base)
    base = json.load(open(path, encoding="utf-8"))
    g = Gen(base, a.spine, a.child_collision, a.root_collision, a.leaf_collision, a.bare_leaves)
    save = g.generate(flow_destinations())
    json.dump(save, open(a.out, "w", encoding="utf-8"), separators=(",", ":"))
    c = collections.Counter(n["type"] for n in g.nodes)
    print(f"generated {dict(c)}, {len(save['edges'])} links -> {a.out}")
    for n in g.notes:
        print("  " + n)
    r = F.score(F.TrackedNet(I.load(save)), 0, a.ticks)
    print(f"{a.ticks} ticks: {r['delivered']}/{r['sent']} legit packets delivered ({100 * r['rate']:.1f}%), "
          f"{r['flows_fully_delivered']}/{r['flows']} flows always delivered")
    print("outcomes:", r["outcomes"])
    print("spam:", r["spam"])
    print(f"flows never delivered ({len(r['flows_never_delivered'])}):", ", ".join(r["flows_never_delivered"][:30]))


if __name__ == "__main__":
    main()
