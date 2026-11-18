"""Import a Tunnet save file as a network the simulator and viewer can use (no game needed).

Produces the same shape as tunnet_live.LiveNet.snapshot(): {entity: node}, where entity
is the node's index in the save. The save stores no packets, so every slot starts empty
and the simulator fills the network from the endpoints' send schedules.

    python tools/save_import.py slot_0.json [ticks]   # import, simulate, print a summary
"""
import json
import sys

NAME_DIGIT = {"Zero": "0", "One": "1", "Two": "2", "Three": "3", "Wildcard": "*"}
ACTION = {"DropPacket": "Drop", "SendBackPacket": "SendBack"}
PORTS = {"relay": 2, "filter": 2, "hub": 3, "bridge": 2, "endpoint": 1, "antenna": 1, "tester": 1}
INFECTION = {"Hack": 5, "MainframeBio": 8}
LISTS = {"relays": "relay", "filters": "filter", "hubs": "hub", "testers": "tester",
         "endpoints": "endpoint", "antennas": "antenna", "bridges": "bridge"}


def addr(a):
    return ".".join(NAME_DIGIT[d] for d in a["elements"])


def load(save):
    """save: parsed save JSON. Returns a snapshot-shaped dict keyed by save node index."""
    typ, entry = {}, {}
    for lst, t in LISTS.items():
        for r in save[lst]:
            typ[r["node"]], entry[r["node"]] = t, r
    snap = {}
    for i, n in enumerate(save["nodes"]):
        t = typ[i]
        r = entry[i]
        node = {"entity": i, "type": t, "pos": list(n["pos"]), "up": n["up"], "angle": n["angle"],
                "ports": [{"peer": None, "cable": None, "peer_port": None, "slots": [None, None]}
                          for _ in range(PORTS[t])]}
        if t == "endpoint":
            node["address"] = addr(r["address"])
            if r.get("infection"):
                node["infection"] = INFECTION.get(r["infection"], 1)
        elif t == "filter":
            c = r["config"]
            node["filter"] = {"port": c["port"], "mask": addr(c["mask"]), "mask_type": c["mask"]["address_type"],
                              "collision": c["collision"], "addr": c["addr"], "action": ACTION[c["action"]],
                              "op": c["op"]}
        elif t == "hub":
            node["hub_dir"] = 1 if r["dir"] else 0
        elif t == "tester":
            c = r["config"]
            node["tester"] = {"freq": c["freq"], "mode": c["mode"], "address": addr(c["address"]),
                              "address_type": c["address"]["address_type"],
                              "destination": addr(c["destination"]),
                              "destination_type": c["destination"]["address_type"]}
        snap[i] = node
    for k, ((a, pa), (b, pb), kind) in enumerate(save["edges"]):
        snap[a]["ports"][pa].update(peer=b, peer_port=pb, cable=-(k + 1))
        snap[b]["ports"][pb].update(peer=a, peer_port=pa, cable=-(k + 1))
    return snap


def main():
    import os
    import sim as S
    path = sys.argv[1]
    if not os.path.exists(path):
        path = os.path.join(os.environ["APPDATA"], "tunnet", path)
    ticks = int(sys.argv[2]) if len(sys.argv) > 2 else 200
    save = json.load(open(path, encoding="utf-8"))
    snap = load(save)
    net = S.Net(snap)
    S.run(net, 0, ticks)
    s = S.summarize(net, ticks)
    print(f"{len(snap)} nodes, {sum(len(n['ports']) for n in snap.values())} ports; story {save['story']['state']}")
    for k in ("sent", "delivered", "dropped", "spam_delivered", "spam_dropped"):
        print(f"  {k}: {s[k]}")
    print("  drop reasons:", s["drop_reasons"])


if __name__ == "__main__":
    main()
