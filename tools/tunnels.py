"""Route cables through air and diggable dirt only (see tools/dig.py for what counts as dirt).

Grid: cells 1 x 1 units in x/z (2 x 2 voxels), heights in voxels (0.5 units); a cell at
floor height vy needs voxels vy..vy+2 (1.5 units) to be air or dirt in a stored chunk.
Level moves also need something solid under the cell (the floor); vertical moves do not.
A* with a turn penalty (each turn costs a relay) and a cost per height step (so lines stay
level and change height in one straight drop rather than wandering up and down).
"""
import heapq
import json
import math
import os

import dig as DG

VOX = DG.VOX
DIRS = [(1, 0, 0), (-1, 0, 0), (0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0)]


class Router:
    def __init__(self, save, max_expand=300000, turn=3.0, climb=2.0, dig_cost=0.2, cache=None, air_cost=4.0):
        self.M = DG.Map(save)
        # routes found earlier (same map): {"A|B|spacing": points or {"fail": reason}}
        self.cache_path = cache
        self.disk = {}
        if cache and os.path.exists(cache):
            self.disk = json.load(open(cache, encoding="utf-8"))
        self.failures = []
        self.pass_cache, self.sup_cache, self.vox_cache = {}, {}, {}
        self.max_expand, self.turn, self.climb, self.dig_cost = max_expand, turn, climb, dig_cost
        # a level step with no floor under it (off a ledge, over a gap) is allowed but costs
        # extra, so cables stay on floors and only leave them to drop straight down
        self.air_cost = air_cost
        self.memo = {}
        self.stats = {"straight": 0, "rerouted": 0, "failed": 0}

    def save_cache(self):
        if self.cache_path:
            with open(self.cache_path, "w", encoding="utf-8") as f:
                json.dump(self.disk, f, indent=2)

    def v(self, key):
        r = self.vox_cache.get(key)
        if r is None:
            r = self.vox_cache[key] = self.M.value(key)
            if r is None:
                r = -1
        return r

    def open_cell(self, c):
        """None if blocked, else the number of dirt voxels to dig."""
        if c in self.pass_cache:
            return self.pass_cache[c]
        cx, vy, cz = c
        n = 0
        for vx in (2 * cx, 2 * cx + 1):
            for vz in (2 * cz, 2 * cz + 1):
                for y in (vy, vy + 1, vy + 2):
                    val = self.v((vx, y, vz))
                    if val == 0:
                        continue
                    if val in DG.DIRT:
                        n += 1
                    else:
                        n = None
                        break
                if n is None:
                    break
            if n is None:
                break
        self.pass_cache[c] = n
        return n

    def supported(self, c):
        if c in self.sup_cache:
            return self.sup_cache[c]
        cx, vy, cz = c
        r = any(self.v((vx, vy - 1, vz)) != 0 for vx in (2 * cx, 2 * cx + 1) for vz in (2 * cz, 2 * cz + 1))
        self.sup_cache[c] = r
        return r

    def snap(self, P):
        """Grid cell for a node at P: its own height, or one voxel below/above when that is
        where the open, supported cell is (floors of prefab rooms are not always on the
        voxel grid)."""
        x, z, base = math.floor(P[0]), math.floor(P[2]), round(P[1] / VOX)
        for vy in (base, base - 1, base + 1, math.floor(P[1] / VOX)):
            c = (x, vy, z)
            if self.open_cell(c) is not None and self.supported(c):
                return c
        return (x, base, z)

    def ok(self, A, pts, B):
        """Every cable of A -> pts -> B diggable (dirt / air only)?"""
        chain = [A] + pts + [B]
        for P, Q in zip(chain, chain[1:]):
            for vox in DG.corridor(P, Q):
                val = self.v(vox)
                if val != 0 and val not in DG.DIRT:
                    return False
        return True

    def astar(self, A, B, spacing, weight=1.2, limit=None):
        key = "|".join(",".join(f"{v:.3f}" for v in P) for P in (A, B)) + f"|{spacing}"
        self.last_key = key
        if key in self.disk:
            r = self.disk[key]
            if isinstance(r, dict):
                if not (r["fail"] == "search limit" and weight > r.get("weight", 1.2)):
                    self.failures.append((A, B, r["fail"]))
                    return None
            else:
                return r
        limit = limit or self.max_expand
        s, g = self.snap(A), self.snap(B)
        h = lambda c: abs(c[0] - g[0]) + abs(c[2] - g[2]) + self.climb * abs(c[1] - g[1]) * VOX * 2
        start = (s, -1)
        best = {start: 0.0}
        prev = {}
        q = [(h(s), 0.0, start)]
        n = 0
        found = None
        while q:
            f, cost, st = heapq.heappop(q)
            if cost > best.get(st, 1e18):
                continue
            c, d = st
            if c == g:
                found = st
                break
            n += 1
            if n > limit:
                break
            for k, (dx, dy, dz) in enumerate(DIRS):
                nc = (c[0] + dx, c[1] + dy, c[2] + dz)
                dig = self.open_cell(nc) if nc != g else 0
                if dig is None:
                    continue
                if dy == 0:
                    step = 1.0
                    if nc != g and c != s and not self.supported(nc):
                        step += self.air_cost
                else:
                    step = self.climb * VOX * 2          # per voxel of height
                step += self.dig_cost * (dig or 0) / 12
                if d not in (-1, k):
                    step += self.turn
                ns = (nc, k)
                nb = cost + step
                if nb < best.get(ns, 1e18):
                    best[ns] = nb
                    prev[ns] = st
                    heapq.heappush(q, (nb + weight * h(nc), nb, ns))
        if found is None:
            why = "search limit" if n > limit else "no path (walled in by rock that is not dirt)"
            self.disk[key] = {"fail": why, "weight": weight}
            if why != "search limit" or weight >= 3:
                self.failures.append((A, B, why))
            return None
        cells = []
        st = found
        while st in prev:
            cells.append(st[0])
            st = prev[st]
        cells.append(s)
        cells.reverse()
        # corners only, then relays at most `spacing` apart along each straight run
        corner = [cells[0]]
        for i in range(1, len(cells) - 1):
            a, b, c = cells[i - 1], cells[i], cells[i + 1]
            if (b[0] - a[0], b[1] - a[1], b[2] - a[2]) != (c[0] - b[0], c[1] - b[1], c[2] - b[2]):
                corner.append(b)
        corner.append(cells[-1])
        P = lambda c: [c[0] + 0.5, c[1] * VOX, c[2] + 0.5]
        pts = [P(corner[0])]
        for a, b in zip(corner, corner[1:]):
            pa, pb = P(a), P(b)
            m = max(1, math.ceil(math.dist(pa, pb) / spacing))
            for j in range(1, m + 1):
                pts.append([pa[i] + (pb[i] - pa[i]) * j / m for i in range(3)])
        # the first and last cell centres stand in for A and B: keep A/B's own heights
        pts = [p for p in pts]
        if math.hypot(pts[0][0] - A[0], pts[0][2] - A[2]) < 0.01 and abs(pts[0][1] - A[1]) < 1e-6:
            pts = pts[1:]
        if pts and math.hypot(pts[-1][0] - B[0], pts[-1][2] - B[2]) < 0.01 and abs(pts[-1][1] - B[1]) < 1e-6:
            pts = pts[:-1]
        # A and B are not at cell centres: make the joins level (same height as A / B)
        if pts:
            if abs(pts[0][1] - A[1]) > 1e-6:
                pts.insert(0, [pts[0][0], A[1], pts[0][2]])
            if abs(pts[-1][1] - B[1]) > 1e-6:
                pts.append([pts[-1][0], B[1], pts[-1][2]])
        self.disk[key] = pts
        return pts
