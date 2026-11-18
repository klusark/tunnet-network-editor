"""Search per-group settings of the generated network (tools/netgen.py) to deliver the most
packets in the simulator. Hill climbing with random tweaks; a fixed seed keeps runs
comparable. Writes the best settings and its save file.

    python tools/netopt.py slot_0.json out_prefix [evaluations] [ticks]
"""
import copy, json, os, random, sys, time
import netgen as G, flows as F, save_import as I

COLL = ["DropInbound", "DropOutbound", "SendBackOutbound"]
_rules = json.load(open(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "re", "endpoint_rules.json")))["endpoints"]
REQ = {(a, s["dst"]) for a, r in _rules.items() for s in r["slots"].values()}


def evaluate(base, dsts, cfg, ticks, spine="up"):
    g = G.Gen(base, spine, "DropOutbound", "DropInbound", "DropOutbound")
    g.cfg = cfg
    save = g.generate(dsts)
    r = F.score(F.TrackedNet(I.load(save)), 0, ticks)
    pf = r["per_flow"]
    covered = sum(1 for f in REQ if pf.get(f, {}).get("delivered", 0) > 0)
    r["covered"] = covered
    # requirements first (each flow delivered at least once), then packets; spam that gets
    # through is penalised
    return 1000 * covered + r["delivered"] - 5 * r["spam"].get("delivered", 0), r, save, g


def tweak(cfg, groups, rnd):
    c = copy.deepcopy(cfg)
    p = rnd.choice(list(groups))
    gc = c.setdefault(p, {})
    kids = groups[p]
    what = rnd.choice(["dir", "order", "bare", "cc", "rc"])
    if what == "dir":
        gc["dir"] = "down" if gc.get("dir", "up") == "up" else "up"
    elif what == "order":
        o = gc.get("order") or [d for d, _ in kids]
        i, j = rnd.randrange(len(o)), rnd.randrange(len(o))
        o[i], o[j] = o[j], o[i]
        gc["order"] = o
    elif what == "bare":
        leaves = [d for d, leaf in kids if leaf]
        if not leaves:
            return tweak(cfg, groups, rnd)
        b = set(gc.get("bare", []))
        b ^= {rnd.choice(leaves)}
        gc["bare"] = sorted(b)
    else:
        gc[what] = rnd.choice(COLL)
    return c


def main():
    base_path = sys.argv[1] if os.path.exists(sys.argv[1]) else os.path.join(os.environ["APPDATA"], "tunnet", sys.argv[1])
    out = sys.argv[2]
    evals = int(sys.argv[3]) if len(sys.argv) > 3 else 300
    ticks = int(sys.argv[4]) if len(sys.argv) > 4 else 800
    base = json.load(open(base_path, encoding="utf-8"))
    dsts = G.flow_destinations()
    rnd = random.Random(7)
    best_cfg = {}
    best, r, save, g = evaluate(base, dsts, best_cfg, ticks)
    groups = g.group_children
    print(f"start: score {best}, covered {r['covered']}, delivered {r['delivered']}, rate {r['rate']}, spam {r['spam']}", flush=True)
    t0 = time.time()
    for n in range(evals):
        cand = tweak(best_cfg, groups, rnd)
        for _ in range(rnd.choice([0, 0, 1, 2])):
            cand = tweak(cand, groups, rnd)
        sc, r2, s2, _ = evaluate(base, dsts, cand, ticks)
        if sc >= best:
            if sc > best:
                print(f"[{n}] {time.time() - t0:.0f}s score {sc}: flows covered {r2['covered']}/{len(REQ)}, delivered {r2['delivered']}/{r2['sent']} "
                      f"({100 * r2['rate']:.1f}%), never {len(r2['flows_never_delivered'])}", flush=True)
            best, best_cfg, r, save = sc, cand, r2, s2
    json.dump(best_cfg, open(out + "_cfg.json", "w"), indent=1)
    json.dump(save, open(out + ".json", "w", encoding="utf-8"), separators=(",", ":"))
    print(f"best score {best}: covered {r['covered']}/{len(REQ)}, spam {r['spam']}, delivered {r['delivered']}/{r['sent']} ({100 * r['rate']:.1f}%), "
          f"never delivered: {r['flows_never_delivered']}", flush=True)


if __name__ == "__main__":
    main()
