"""Export the network as a Tunnet save file.

The network part of the save (nodes, edges, relays, filters, hubs, testers, endpoints,
antennas, bridges) is rebuilt from a simulator network: the live game's current network
plus any what-if edits (added/removed nodes, links, configs). Everything else (player,
story, credits, map chunks, toolboxes, pages) is copied from a base save file.

Save format (slot_N.json):
  nodes:   [{pos, up, angle}]                         index = node id used below
  edges:   [[[a, port], [b, port], kind]]             kind 0..3 (cable style?; new = 0)
  relays:  [{node, fixed, light}]   filters: [{node, config, fixed}]   hubs: [{node, fixed, dir}]
  testers: [{node, config}]   endpoints: [{node, address, infection, disinfection}]
  antennas / bridges: [{node}]
Every saved edge is <= 6.0 units long (the game's auto-connect range); longer links are
exported but flagged, since the game never makes them itself.
"""
import collections
import datetime
import json
import math
import os
import shutil

import sim as S

SAVE_DIR = os.path.join(os.environ.get("APPDATA", ""), "tunnet")
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DIGIT_NAME = {"0": "Zero", "1": "One", "2": "Two", "3": "Three", "*": "Wildcard"}
NAME_DIGIT = {v: k for k, v in DIGIT_NAME.items()}
ACTION = {"Drop": "DropPacket", "SendBack": "SendBackPacket"}
TYPE_LIST = {"relay": "relays", "filter": "filters", "hub": "hubs", "tester": "testers",
             "endpoint": "endpoints", "antenna": "antennas", "bridge": "bridges"}


def save_path(slot):
    return os.path.join(SAVE_DIR, f"slot_{int(slot)}.json")


def addr_json(text, typ):
    return {"elements": [DIGIT_NAME[d] for d in text.split(".")], "address_type": typ}


def filter_json(f):
    return {"port": int(f["port"]), "mask": addr_json(f["mask"], f["mask_type"]), "addr": f["addr"],
            "action": ACTION[f["action"]], "op": f["op"], "collision": f["collision"]}


def tester_json(t):
    return {"address": addr_json(t["address"], t["address_type"]),
            "destination": addr_json(t["destination"], t["destination_type"]),
            "mode": t["mode"], "freq": int(t["freq"])}


# ---------- rotation: live quaternion -> save {up, angle} ----------
def _qmul(a, b):
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return (aw * bx + ax * bw + ay * bz - az * by, aw * by - ax * bz + ay * bw + az * bx,
            aw * bz + ax * by - ay * bx + az * bw, aw * bw - ax * bx - ay * by - az * bz)


def _rot(q, v):
    x, y, z, w = q
    return _qmul(_qmul(q, (v[0], v[1], v[2], 0.0)), (-x, -y, -z, w))[:3]


def _arc(u, v):
    d = sum(a * b for a, b in zip(u, v))
    if d < -0.9999:
        return (1.0, 0.0, 0.0, 0.0)
    c = (u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0])
    w = 1 + d
    n = math.sqrt(sum(x * x for x in c) + w * w)
    return (c[0] / n, c[1] / n, c[2] / n, w / n)


def up_angle_raw(q):
    """up = q * Y; angle = twist about up after aligning Y to up (my convention). The game's
    convention differs by a constant per up direction, learned from the base save."""
    up = _rot(q, (0.0, 1.0, 0.0))
    q0 = _arc((0.0, 1.0, 0.0), up)
    r = _qmul((-q0[0], -q0[1], -q0[2], q0[3]), q)
    return [round(c, 7) for c in up], 2 * math.atan2(r[1], r[3])


def _upkey(up):
    return tuple(int(round(c * 2)) for c in up)


def _wrap(a):
    return (a + math.pi) % (2 * math.pi) - math.pi


# ---------- export ----------
def build(base, snap, net):
    """base: parsed base save. snap: live snapshot the Net was made from. net: sim.Net with
    edits applied. Returns (new save dict, report)."""
    report = collections.defaultdict(list)
    grid = collections.defaultdict(list)   # coarse grid for tolerant position matching
    for i, n in enumerate(base["nodes"]):
        grid[tuple(int(math.floor(v)) for v in n["pos"])].append(i)

    def near(pos, typ):
        best = None
        cx = [int(math.floor(v)) for v in pos]
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                for dz in (-1, 0, 1):
                    for i in grid.get((cx[0] + dx, cx[1] + dy, cx[2] + dz), ()):
                        d = math.dist(base["nodes"][i]["pos"], pos)
                        if d < 0.05 and old_type.get(i) == typ and (best is None or d < best[0]):
                            best = (d, i)
        return best and best[1]
    old_type, old_entry = {}, {}
    for k, lst in ((k, base[v]) for k, v in TYPE_LIST.items()):
        for r in lst:
            old_type[r["node"]], old_entry[r["node"]] = k, r
    # live entity -> base save index (same position and type)
    match = {}
    for e, n in net.nodes.items():
        if n.get("added") or not n.get("pos"):
            continue
        i = near(n["pos"], n["type"])
        if i is not None and i not in match.values():
            match[e] = i
    # Game-owned nodes (endpoints, antennas, bridges, testers) that the live game doesn't
    # show (not loaded right now) are kept as they are in the base save, with their links.
    kept = [i for i in range(len(base["nodes"])) if i not in set(match.values())
            and old_type[i] not in S.PORTS]
    # learn the angle offset per up direction from matched nodes
    offs = collections.defaultdict(collections.Counter)
    for e, i in match.items():
        q = net.nodes[e].get("rot")
        if q:
            up, a = up_angle_raw(q)
            offs[_upkey(up)][round(_wrap(base["nodes"][i]["angle"] - a), 3)] += 1
    offset = {k: c.most_common(1)[0][0] for k, c in offs.items()}

    # node order: surviving base nodes in their old order, then new ones
    KEPT = lambda i: ("kept", i)     # pseudo entity ids for kept base nodes
    order = sorted([e for e in net.nodes if e in match] + [KEPT(i) for i in kept],
                   key=lambda e: e[1] if isinstance(e, tuple) else match[e])
    order += sorted(e for e in net.nodes if e not in match)
    new_index = {e: k for k, e in enumerate(order)}
    out = {k: v for k, v in base.items()}
    out["nodes"] = []
    lists = {v: [] for v in TYPE_LIST.values()}
    for e in order:
        k = new_index[e]
        if isinstance(e, tuple):
            i = e[1]
            out["nodes"].append(dict(base["nodes"][i]))
            lists[TYPE_LIST[old_type[i]]].append(dict(old_entry[i], node=k))
            report["kept_not_loaded"].append(f"{old_type[i]} {old_entry[i].get('address') and '.'.join(NAME_DIGIT[d] for d in old_entry[i]['address']['elements']) or ''} at {[round(c, 1) for c in base['nodes'][i]['pos']]}")
            continue
        n = net.nodes[e]
        if e in match:
            old = base["nodes"][match[e]]
            out["nodes"].append({"pos": old["pos"], "up": old["up"], "angle": old["angle"]})
            prev = dict(old_entry[match[e]])
        else:
            if n.get("added"):
                like = n.get("like")
                if n.get("up") is not None:
                    up, angle = n["up"], float(n.get("angle") or 0.0)
                elif like in match:          # orient like the node it was placed next to
                    old = base["nodes"][match[like]]
                    up, angle = old["up"], old["angle"]
                elif like in net.nodes and net.nodes[like].get("rot"):
                    up, a = up_angle_raw(net.nodes[like]["rot"])
                    angle = _wrap(a + offset.get(_upkey(up), 0.0))
                else:
                    up, angle = [0, 1, 0], 0.0
                report["added"].append(f"{n['type']} at {[round(c, 1) for c in n['pos']]}")
            else:
                if n["type"] not in S.PORTS:
                    raise ValueError(f"live {n['type']} #{e} is not in the base save; only relays, "
                                     "filters and hubs can be created")
                up, a = up_angle_raw(n["rot"]) if n.get("rot") else ([0, 1, 0], 0.0)
                angle = _wrap(a + offset.get(_upkey(up), 0.0))
                report["new_in_game"].append(f"{n['type']} #{e} at {[round(c, 1) for c in n['pos']]}")
            out["nodes"].append({"pos": [float(c) for c in n["pos"]], "up": [float(c) for c in up],
                                 "angle": float(angle)})
            prev = {}
        t = n["type"]
        if t == "relay":
            entry = {"node": k, "fixed": prev.get("fixed", False), "light": prev.get("light", False)}
        elif t == "filter":
            entry = {"node": k, "config": filter_json(n["filter"]), "fixed": prev.get("fixed", False)}
        elif t == "hub":
            entry = {"node": k, "fixed": prev.get("fixed", False), "dir": bool(n["hub_dir"])}
        elif t == "tester":
            entry = {"node": k, "config": tester_json(n["tester"]) if n.get("tester") else prev["config"]}
        else:
            entry = dict(prev, node=k)
        lists[TYPE_LIST[t]].append(entry)
    out.update(lists)
    removed = [i for i in range(len(base["nodes"])) if i not in set(match.values()) and i not in kept]
    for i in removed:
        report["removed"].append(f"{old_type.get(i)} at {[round(c, 1) for c in base['nodes'][i]['pos']]}")

    # edges from links; keep the old cable kind where the same edge existed
    old_kind = {}
    for (a, pa), (b, pb), kind in base["edges"]:
        old_kind[frozenset([(a, pa), (b, pb)])] = kind
    edges, seen = [], set()
    for e in order:
        if isinstance(e, tuple):
            continue
        for p, (peer, pp) in enumerate(net.nodes[e]["links"]):
            if peer is None or pp is None:
                continue
            if net.nodes[peer]["links"][pp] != (e, p):
                raise ValueError(f"link {e}:{p} -> {peer}:{pp} is not symmetric")
            A, B = (new_index[e], p), (new_index[peer], pp)
            key = frozenset([A, B])
            if key in seen:
                continue
            seen.add(key)
            oldkey = frozenset([(match[e], p), (match[peer], pp)]) if e in match and peer in match else None
            kind = old_kind.get(oldkey, 0)
            edges.append([list(A), list(B), kind])
            d = math.dist(net.nodes[e]["pos"], net.nodes[peer]["pos"])
            if d > 6.0:
                report["long_links"].append(f"{t_name(net, e)} - {t_name(net, peer)}: {d:.1f} units")
            if oldkey is None or oldkey not in old_kind:
                report["new_links"].append(f"{t_name(net, e)}:{p} - {t_name(net, peer)}:{pp}")
    # base links of kept nodes, where the other port is still free
    used = {tuple(x) for ed in edges for x in ed[:2]}
    base_to_new = {i: new_index[e] for e, i in match.items()}
    base_to_new.update({i: new_index[KEPT(i)] for i in kept})
    for (a, pa), (b, pb), kind in base["edges"]:
        if a in kept or b in kept:
            if a in base_to_new and b in base_to_new:
                A, B = (base_to_new[a], pa), (base_to_new[b], pb)
                if A not in used and B not in used:
                    edges.append([list(A), list(B), kind])
                    used |= {A, B}
    for key in old_kind:
        (a, pa), (b, pb) = tuple(key)
        inv = {i: e for e, i in match.items()}
        if a in inv and b in inv:
            ea, eb = inv[a], inv[b]
            if net.nodes[ea]["links"][pa] != (eb, pb):
                report["removed_links"].append(f"{t_name(net, ea)}:{pa} - {t_name(net, eb)}:{pb}")
    out["edges"] = edges
    report["counts"] = [f"{len(out['nodes'])} nodes, {len(edges)} links "
                        f"(base save: {len(base['nodes'])} nodes, {len(base['edges'])} links)"]
    return out, {k: v for k, v in report.items()}


def t_name(net, e):
    n = net.nodes[e]
    return n.get("address") or f"{n['type']} #{e}"


def check(save):
    """Structural checks the game relies on."""
    n = len(save["nodes"])
    nodes = collections.Counter()
    for k in TYPE_LIST.values():
        for r in save[k]:
            nodes[r["node"]] += 1
    assert all(nodes[i] == 1 for i in range(n)), "every node must have exactly one type entry"
    ports = {}
    for k, t in TYPE_LIST.items():
        for r in save[t]:
            ports[r["node"]] = {"relay": 2, "filter": 2, "hub": 3}.get(k, 2 if k == "bridge" else 1)
    used = set()
    for (a, pa), (b, pb), kind in save["edges"]:
        for x, px in ((a, pa), (b, pb)):
            assert 0 <= x < n and 0 <= px < ports[x], f"bad port {x}:{px}"
            assert (x, px) not in used, f"port {x}:{px} used twice"
            used.add((x, px))
    return True


def write(save, slot):
    """Write slot_N.json, backing up any existing file into backups/ first."""
    path = save_path(slot)
    backup = None
    if os.path.exists(path):
        os.makedirs(os.path.join(ROOT, "backups"), exist_ok=True)
        stamp = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
        backup = os.path.join(ROOT, "backups", f"slot_{slot}.{stamp}.json")
        shutil.copy2(path, backup)
    tmp = path + ".tmp"
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(save, f, separators=(",", ":"))
    os.replace(tmp, path)
    return path, backup
