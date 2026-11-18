"""The digging a generated save needs, for the viewer's 3D voxel layer (/api/digplan).

Given a generated save (e.g. out/direct_final.json, already dug by tools/dig.py) and the
map it was made from (the base, e.g. slot_0.json):
  dug      voxels that are solid in the base and air in the save (what the dig removed),
           per chunk as local indices (z*32 + y)*32 + x
  filled   voxels that are air in the base and solid in the save (should be none)
  blocked  nodes and cables (tools/dig.py corridor / node_box) that still touch something
           that is not dirt or air in the save: hard rock, stone, metal, wood, water, or a
           chunk the save does not store; with the voxels that block them
If the save has no chunks of its own (a network not dug yet) the plan is computed with
tools/dig.py plan() on the base map instead, and dug = what it would dig.

    python tools/viewer/digplan.py out/direct_final.json slot_0.json   # summary
"""
import collections
import gzip
import json
import os
import sys
import threading
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import dig as DIG  # noqa: E402
import voxel_data as VD  # noqa: E402

N, V = 32, 32768
NAMES = {0: "air", 1: "dirt", 3: "dirt", 10: "dirt", 43: "hard rock", 44: "hard rock", 14: "wood",
         6: "metal", 8: "metal", 16: "metal", 18: "water", 19: "water", 20: "water", 21: "water"}
_cache, _lock = {}, threading.Lock()


def decode(save):
    out = {}
    for c, rle in save.get("chunks") or []:
        counts = np.fromiter((n for n, _ in rle), dtype=np.int64, count=len(rle))
        vals = np.fromiter((min(v, 255) for _, v in rle), dtype=np.uint8, count=len(rle))
        a = np.repeat(vals, counts)
        if a.size == V:
            out[(c["x"], c["y"], c["z"])] = a
    return out


def blocked_items(save, chunks):
    """Like dig.plan's check, on the given voxels: items touching non-dirt, and by what."""
    nodes = save["nodes"]
    built = set()
    for lst in ("relays", "hubs", "filters"):
        built.update(r["node"] for r in save.get(lst, []))

    def value(v):
        a = chunks.get((v[0] // N, v[1] // N, v[2] // N))
        if a is None:
            return None
        return int(a[((v[2] % N) * N + (v[1] % N)) * N + (v[0] % N)])

    out, ok = [], 0

    def check(vox, what, a, b):
        nonlocal ok
        bad, where = collections.Counter(), []
        for v in vox:
            val = value(v)
            if val is None:
                bad["unstored chunk"] += 1
            elif val == 0 or val in DIG.DIRT:
                continue
            else:
                bad[NAMES.get(val, f"stone / other ({val})")] += 1
                where.append(list(v))
        if not bad:
            ok += 1
            return
        out.append({"what": what[0], "ids": list(what[1:]), "a": a, "b": b,
                    "by": dict(bad), "vox": where[:400]})

    for i in sorted(built):
        p = [round(x, 3) for x in nodes[i]["pos"]]
        check(DIG.node_box(nodes[i]["pos"]), ("node", i), p, p)
    for (a, _), (b, _), *_ in save["edges"]:
        check(DIG.corridor(nodes[a]["pos"], nodes[b]["pos"]), ("cable", a, b),
              [round(x, 3) for x in nodes[a]["pos"]], [round(x, 3) for x in nodes[b]["pos"]])
    return out, ok


def compute(save_path, base_path):
    t0 = time.time()
    save = json.load(open(save_path, encoding="utf-8"))
    base = json.load(open(base_path, encoding="utf-8"))
    S, B = decode(save), decode(base)
    dug, filled, n_dug, n_filled, mode = [], 0, 0, 0, "diff"
    if S:
        for key, b in B.items():
            s = S.get(key)
            if s is None:
                continue
            m = (b != 0) & (s == 0)
            idx = np.nonzero(m)[0]
            if idx.size:
                dug.append([*key, idx.tolist()])
                n_dug += int(idx.size)
            filled += int(np.count_nonzero((b == 0) & (s != 0)))
        blocked, ok = blocked_items(save, S)
    else:                                  # not dug yet: what dig.plan would do on the base
        mode = "plan"
        save = dict(save, chunks=base["chunks"])
        r = DIG.plan(save)
        by = collections.defaultdict(list)
        for vx, vy, vz in r["dig"]:
            by[(vx // N, vy // N, vz // N)].append(((vz % N) * N + (vy % N)) * N + (vx % N))
        dug = [[*k, sorted(v)] for k, v in by.items()]
        n_dug = len(r["dig"])
        blocked, ok = blocked_items(save, B)
    kinds = collections.Counter(max(b["by"], key=b["by"].get).split(" (")[0] for b in blocked)
    res = {
        "save": os.path.basename(save_path), "base": os.path.basename(base_path), "mode": mode,
        "dug_voxels": n_dug, "dug_chunks": len(dug), "filled_voxels": filled,
        "items_ok": ok, "items_blocked": len(blocked), "blocked_by": dict(kinds),
        "dug": dug, "blocked": blocked, "seconds": round(time.time() - t0, 1),
    }
    return res


def payload(save_name, base_name):
    """gzip JSON for /api/digplan (cached by file times). Raises ValueError for bad names."""
    sp, bp = VD.resolve(save_name), VD.resolve(base_name)
    if not sp:
        raise ValueError(f"no such save: {save_name}")
    if not bp:
        raise ValueError(f"no such base save: {base_name}")
    key = (sp, os.path.getmtime(sp), bp, os.path.getmtime(bp))
    with _lock:                            # one at a time: each needs a few GB while parsing
        if key not in _cache:
            res = compute(sp, bp)
            _cache.clear()
            _cache[key] = gzip.compress(json.dumps(res, separators=(",", ":")).encode(), compresslevel=5)
        return _cache[key]


if __name__ == "__main__":
    r = compute(VD.resolve(sys.argv[1]) or sys.argv[1], VD.resolve(sys.argv[2] if len(sys.argv) > 2 else "slot_0.json"))
    print({k: v for k, v in r.items() if k not in ("dug", "blocked")})
    for b in r["blocked"][:5]:
        print(b["what"], b["ids"], b["by"], len(b["vox"]))
