"""Compact voxel data for the voxel viewer (tools/viewer/voxels.html).

Binary layout (served gzip-compressed by the viewer server at /api/voxels?save=NAME):
  u32 little-endian header length, then the header as UTF-8 JSON:
    {"chunks": [[cx, cy, cz], ...], "nodes": [[x, y, z, type], ...], "edges": [[a, b], ...],
     "labels": {"node index": "endpoint address", ...}}
  then 32768 bytes per chunk in header order (index (z*32 + y)*32 + x, value 0 = air).
type: 0 relay, 1 hub, 2 filter, 3 endpoint, 4 bridge, 5 antenna, 6 tester.

Saves: NAME is a file in the game's save folder (e.g. slot_0.json) or out/NAME.json in this
project (generated networks).
"""
import gzip
import json
import os
import struct

import numpy as np

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SAVE_DIR = os.path.join(os.environ.get("APPDATA", ""), "tunnet")
OUT_DIR = os.path.join(ROOT, "out")
TYPES = {"relays": 0, "hubs": 1, "filters": 2, "endpoints": 3, "bridges": 4, "antennas": 5, "testers": 6}
_cache = {}


def list_saves():
    out = []
    for d, prefix in ((SAVE_DIR, ""), (OUT_DIR, "out/")):
        if os.path.isdir(d):
            for f in sorted(os.listdir(d)):
                skip = ("route_cache", "timetable_lines", "_delays", "_cfg", "_score", "formatted")
                if f.endswith(".json") and not any(t in f for t in skip):
                    out.append(prefix + f)
    return out


def resolve(name):
    """Path of a save NAME, or None if it is not one we serve (no other files)."""
    if name.startswith("out/"):
        base, d = name[4:], OUT_DIR
    else:
        base, d = name, SAVE_DIR
    if not base or base != os.path.basename(base) or not base.endswith(".json"):
        return None
    p = os.path.join(d, base)
    return p if os.path.isfile(p) else None


def build(path):
    """gzip-compressed voxel payload for the save at path (cached by file time)."""
    key = (path, os.path.getmtime(path))
    if key in _cache:
        return _cache[key]
    save = json.load(open(path, encoding="utf-8"))
    keys, raw = [], []
    for c, rle in save["chunks"]:
        counts = np.fromiter((n for n, _ in rle), dtype=np.int64, count=len(rle))
        vals = np.fromiter((min(v, 255) for _, v in rle), dtype=np.uint8, count=len(rle))
        a = np.repeat(vals, counts)
        if a.size != 32768:
            continue
        keys.append([c["x"], c["y"], c["z"]])
        raw.append(a.tobytes())
    typ = {}
    for lst, t in TYPES.items():
        for r in save.get(lst, []):
            typ[r["node"]] = t
    nodes = [[round(n["pos"][0], 3), round(n["pos"][1], 3), round(n["pos"][2], 3), typ.get(i, 0)]
             for i, n in enumerate(save["nodes"])]
    edges = [[a, b] for (a, _), (b, _), *_ in save["edges"]]
    digit = {"Zero": "0", "One": "1", "Two": "2", "Three": "3", "Wildcard": "*"}
    labels = {str(r["node"]): ".".join(digit[d] for d in r["address"]["elements"]) for r in save.get("endpoints", [])}
    head = json.dumps({"chunks": keys, "nodes": nodes, "edges": edges, "labels": labels},
                      separators=(",", ":")).encode()
    body = struct.pack("<I", len(head)) + head + b"".join(raw)
    gz = gzip.compress(body, compresslevel=5)
    _cache.clear()
    _cache[key] = gz
    return gz
