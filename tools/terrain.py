"""Map voxels from a save, for placing nodes on the floor.

save["chunks"]: [{x,y,z}, rle] with rle = [[count, value], ...] over 32^3 voxels; a chunk is
16 world units, a voxel 0.5 units, index (z*32 + y)*32 + x; value 0 = air. Chunks missing
from the save are treated as solid (the game generates them as rock when needed).
"""
import math

VOX = 0.5
N = 32


class Terrain:
    def __init__(self, save, floor_offset=None):
        self.raw = {(c["x"], c["y"], c["z"]): rle for c, rle in save["chunks"]}
        self.cache = {}
        # height of a floor-mounted node's centre above the floor surface (measured from
        # the save's own floor nodes unless given)
        # (measured: 0, they sit right on the surface; tiny values are rounding)
        off = floor_offset if floor_offset is not None else self.measure_offset(save)
        self.offset = 0.0 if abs(off) < 0.05 else off

    def chunk(self, key):
        c = self.cache.get(key)
        if c is None:
            rle = self.raw.get(key)
            if rle is None:
                c = False
            else:
                c = bytearray()
                for n, v in rle:
                    c += bytes([min(v, 255)]) * n
            self.cache[key] = c
        return c

    def solid_v(self, vx, vy, vz):
        c = self.chunk((vx // N, vy // N, vz // N))
        if c is False:
            return True
        return c[((vz % N) * N + (vy % N)) * N + (vx % N)] != 0

    def solid(self, x, y, z):
        return self.solid_v(math.floor(x / VOX), math.floor(y / VOX), math.floor(z / VOX))

    def floor_below(self, x, y, z, reach=30.0):
        """Floor surface height under (x, y, z) if (x, y, z) is air, else None."""
        vx, vz = math.floor(x / VOX), math.floor(z / VOX)
        vy = math.floor(y / VOX)
        if self.solid_v(vx, vy, vz):
            return None
        for k in range(int(reach / VOX)):
            if self.solid_v(vx, vy - k - 1, vz):
                return (vy - k) * VOX
        return None

    def level(self, x, z, y, climb=8.0, reach=30.0):
        """Where a floor node near height y should go at (x, z): on the floor below if y is
        in air, on the nearest floor above if y is inside rock (within `climb`), otherwise
        stay at y (no floor reachable: buried in rock, or over a deep shaft)."""
        s = self.floor_below(x, y, z, reach)
        if s is not None:
            return s + self.offset
        if self.solid(x, y, z):
            vx, vz, vy = math.floor(x / VOX), math.floor(z / VOX), math.floor(y / VOX)
            for k in range(1, int(climb / VOX) + 1):
                if not self.solid_v(vx, vy + k, vz):
                    s = (vy + k) * VOX
                    if s + self.offset - y <= climb and not self.solid(x, s + self.offset, z):
                        return s + self.offset
                    break
        return y

    def measure_offset(self, save):
        """Median height above the floor surface of the save's floor-mounted nodes."""
        offs = []
        for n in save["nodes"]:
            if [round(v, 3) for v in n["up"]] != [0.0, 1.0, 0.0]:
                continue
            x, y, z = n["pos"]
            vx, vz, vy = math.floor(x / VOX), math.floor(z / VOX), math.floor(y / VOX)
            for k in range(0, 12):
                if self.solid_v(vx, vy - k, vz):
                    offs.append(round(y - (vy - k + 1) * VOX, 3))
                    break
        offs.sort()
        return offs[len(offs) // 2] if offs else 0.25
