"""Dig tunnels in a save so every node and cable of a generated network has room.

Only DIRT is dug: voxel values the game's dig tool removes with the dirt sound (dig code
in FUN_140352fc0: diggable = {1, 3, 10, 43, 44}, sound table at 0x14242e5e8 gives 1, 3,
10 the "digging" sound; 43/44 sound like stone and take two hits, so they count as rock
here). Air (0) needs nothing. Anything else (stone, wood, metal, water, hard rock) and
chunks the save does not store (the game generates those) block the dig.

Room cut for each node and each cable: a corridor 1.0 wide and 1.5 tall standing on the
cable's height (level cables), or a 1.0 x 1.0 shaft (vertical cables), plus 1.5 above the
top. The floor under a level corridor is left in place, so nodes stay on the floor.

    python tools/dig.py network.json out.json      # report, then write the dug save
    python tools/dig.py network.json               # report only
"""
import collections
import json
import math
import sys

import terrain as TR

VOX = TR.VOX
DIRT = {1, 3, 10}
NAMES = {0: "air", 1: "dirt", 3: "dirt", 10: "dirt", 43: "hard rock", 44: "hard rock"}
HALF = 0.5          # corridor half width
HEIGHT = 1.5        # corridor height


def voxel_range(a, b):
    """Voxel indices covering world interval [a, b)."""
    return range(math.floor(a / VOX), math.floor((b - 1e-6) / VOX) + 1)


def corridor(P, Q):
    """Voxels to clear for a cable P -> Q (level or vertical)."""
    out = set()
    if abs(P[1] - Q[1]) < 1e-6:                   # level
        n = max(1, math.ceil(math.dist(P, Q) / 0.25))
        y = P[1]
        for i in range(n + 1):
            x = P[0] + (Q[0] - P[0]) * i / n
            z = P[2] + (Q[2] - P[2]) * i / n
            for vx in voxel_range(x - HALF, x + HALF):
                for vz in voxel_range(z - HALF, z + HALF):
                    for vy in voxel_range(y, y + HEIGHT):
                        out.add((vx, vy, vz))
    else:                                         # vertical (or a short slope: treat as box)
        lo, hi = min(P[1], Q[1]), max(P[1], Q[1])
        for x, z in ((P[0], P[2]), (Q[0], Q[2])):
            for vx in voxel_range(x - HALF, x + HALF):
                for vz in voxel_range(z - HALF, z + HALF):
                    for vy in voxel_range(lo, hi + HEIGHT):
                        out.add((vx, vy, vz))
    return out


def node_box(p):
    return corridor(p, p)


class Map:
    def __init__(self, save):
        self.T = TR.Terrain(save)

    def value(self, v):
        """Voxel value, or None for a chunk the save does not store."""
        vx, vy, vz = v
        c = self.T.chunk((vx // 32, vy // 32, vz // 32))
        if c is False:
            return None
        return c[((vz % 32) * 32 + (vy % 32)) * 32 + (vx % 32)]


def plan(save):
    """Which voxels to dig, and which cables/nodes are blocked (and by what)."""
    M = Map(save)
    nodes = save["nodes"]
    built = set()
    for lst in ("relays", "hubs", "filters"):
        built.update(r["node"] for r in save[lst])
    dig, blocked, clear, need = set(), collections.Counter(), 0, 0
    blocked_items = []

    def check(vox, what):
        nonlocal clear, need
        todo, bad = set(), collections.Counter()
        for v in vox:
            val = M.value(v)
            if val is None:
                bad["unstored chunk"] += 1
            elif val == 0:
                continue
            elif val in DIRT:
                todo.add(v)
            else:
                bad[NAMES.get(val, f"material {val}")] += 1
        if bad:
            blocked[max(bad, key=bad.get)] += 1
            blocked_items.append((what, dict(bad)))
            dig.update(todo)          # dig what can be dug anyway
        elif todo:
            need += 1
            dig.update(todo)
        else:
            clear += 1

    for i in sorted(built):
        check(node_box(nodes[i]["pos"]), ("node", i))
    for (a, pa), (b, pb), _ in save["edges"]:
        check(corridor(nodes[a]["pos"], nodes[b]["pos"]), ("cable", a, b))
    return {"dig": dig, "clear": clear, "need_dig": need, "blocked": blocked, "blocked_items": blocked_items}


def apply(save, dig):
    """Return a copy of save with the given voxels set to air (stored chunks only)."""
    by_chunk = collections.defaultdict(list)
    for vx, vy, vz in dig:
        by_chunk[(vx // 32, vy // 32, vz // 32)].append(((vz % 32) * 32 + (vy % 32)) * 32 + (vx % 32))
    chunks = []
    for c, rle in save["chunks"]:
        key = (c["x"], c["y"], c["z"])
        if key in by_chunk:
            flat = bytearray()
            for n, v in rle:
                flat += bytes([v]) * n
            for i in by_chunk[key]:
                flat[i] = 0
            rle = []
            for v in flat:
                if rle and rle[-1][1] == v:
                    rle[-1][0] += 1
                else:
                    rle.append([1, v])
        chunks.append([c, rle])
    out = dict(save)
    out["chunks"] = chunks
    return out


def main():
    save = json.load(open(sys.argv[1], encoding="utf-8"))
    r = plan(save)
    total = r["clear"] + r["need_dig"] + sum(r["blocked"].values())
    print(f"{total} nodes + cables: {r['clear']} already have room, {r['need_dig']} need digging, "
          f"{sum(r['blocked'].values())} blocked {dict(r['blocked'])}; {len(r['dig'])} dirt voxels to dig "
          f"({len(r['dig']) * VOX ** 3:.0f} cubic units)")
    if len(sys.argv) > 2:
        with open(sys.argv[2], "w", encoding="utf-8") as f:
            json.dump(apply(save, r["dig"]), f, indent=2)
        print("wrote", sys.argv[2])


if __name__ == "__main__":
    main()
