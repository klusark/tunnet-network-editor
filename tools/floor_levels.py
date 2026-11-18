"""Floor levels of the map's prefab structures (bunker rooms), as height-range presets for the
viewer (tools/viewer/floor_levels.json).

A floor is a voxel row inside a BunkerRoom chunk (save["chunk_types"]) with solid ground
under it and 1.5 units of air over it. Rows within 1 unit of each other merge into one level
(raised platforms, steps); a level needs at least MIN_AREA floor voxels. Each level is named
by the rooms and endpoints on it. The preset range runs from just under the floor to
ABOVE units over it, so the cut looks into the rooms (and only that level's nodes show).

    python tools/floor_levels.py [slot_0.json]
"""
import collections
import json
import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
MIN_AREA = 900
ABOVE = 3.0
BELOW = 0.5
DIGIT = {"Zero": "0", "One": "1", "Two": "2", "Three": "3", "Wildcard": "*"}


def room_name(t):
    """BunkerRoom entry -> (room kind, endpoint address or None)."""
    for part in t.get("BunkerRoom", []):
        if isinstance(part, str):
            return part, None
        if isinstance(part, dict):
            kind, addr = next(iter(part.items()))
            a = ".".join(DIGIT[d] for d in addr["elements"]) if isinstance(addr, dict) else None
            return kind, a
    return "room", None


def levels(save):
    chunks = {(c["x"], c["y"], c["z"]): rle for c, rle in save["chunks"]}
    area = collections.Counter()
    rooms = collections.defaultdict(collections.Counter)
    for c, t in save.get("chunk_types", []):
        key = (c["x"], c["y"], c["z"])
        rle = chunks.get(key)
        if rle is None:
            continue
        a = np.repeat(np.array([v for _, v in rle], np.uint8), [n for n, _ in rle]).reshape(32, 32, 32)  # z, y, x
        kind, _ = room_name(t)
        for y in range(1, 29):
            f = int(((a[:, y - 1, :] != 0) & (a[:, y, :] == 0) & (a[:, y + 1, :] == 0) & (a[:, y + 2, :] == 0)).sum())
            if f >= 60:
                h = (key[1] * 32 + y) * 0.5
                area[h] += f
                rooms[h][kind] += f
    # merge rows within 1 unit into levels; a level's height is its biggest floor row
    groups, cur = [], []
    for h in sorted(area):
        if cur and h - cur[-1] > 1.0:
            groups.append(cur)
            cur = []
        cur.append(h)
    if cur:
        groups.append(cur)
    ends = [(save["nodes"][e["node"]]["pos"][1], ".".join(DIGIT[d] for d in e["address"]["elements"]))
            for e in save.get("endpoints", [])]
    out = []
    for g in groups:
        total = sum(area[h] for h in g)
        if total < MIN_AREA:
            continue
        floor = max(g, key=lambda h: area[h])
        kinds = collections.Counter()
        for h in g:
            kinds.update(rooms[h])
        here = sorted(a for y, a in ends if g[0] - 1.0 <= y <= g[-1] + 1.0)
        groups_of = collections.Counter(".".join(a.split(".")[:2]) + ".*" for a in here)
        name_rooms = [k for k, _ in kinds.most_common(3)]
        label = f"y {floor:g} · " + (", ".join(k for k, _ in groups_of.most_common(3)) if groups_of
                                     else ", ".join(name_rooms[:2]))
        out.append({"floor": floor, "lo": round(min(g) - BELOW, 1), "hi": round(max(g) + ABOVE, 1),
                    "label": label, "rooms": name_rooms, "endpoints": len(here), "floor_area": total})
    return sorted(out, key=lambda l: -l["floor"])


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else "slot_0.json"
    path = name if os.path.exists(name) else os.path.join(os.environ["APPDATA"], "tunnet", name)
    save = json.load(open(path, encoding="utf-8"))
    lv = levels(save)
    for l in lv:
        print(f"{l['label']:40s} range {l['lo']:6.1f} .. {l['hi']:6.1f}  rooms {', '.join(l['rooms'])}  "
              f"({l['endpoints']} endpoints, {l['floor_area']} floor voxels)")
    out = os.path.join(HERE, "viewer", "floor_levels.json")
    with open(out, "w", encoding="utf-8") as f:
        json.dump({"source": os.path.basename(path), "levels": lv}, f, indent=2)
        f.write("\n")
    print("->", out)


if __name__ == "__main__":
    main()
