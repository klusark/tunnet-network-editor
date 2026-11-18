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
    g.cfg = {k: v for k, v in cfg.items() if not k.startswith("_")}
    g.shortcuts = [tuple(x) for x in cfg.get("_shortcuts", [])]
    if cfg.get("_relay_spacing"):
        g.relay_spacing = cfg["_relay_spacing"]
    if "_sc_exit" in cfg:
        g.sc_exit_collision = cfg["_sc_exit"]
    save = g.generate(dsts)
    r = F.score(F.TrackedNet(I.load(save)), 0, ticks)
    pf = r["per_flow"]
    covered = sum(1 for f in REQ if pf.get(f, {}).get("delivered", 0) > 0)
    r["covered"] = covered
    # how well each requirement is met: per-flow delivery ratio, averaged over every
    # required flow (a flow that was never sent counts as 0). Then packets; spam that gets
    # through is penalised.
    ratios = [pf[f]["delivered"] / sum(pf[f].values()) if f in pf and sum(pf[f].values()) else 0.0 for f in REQ]
    r["mean_flow"] = sum(ratios) / len(ratios)
    return round(40000 * r["mean_flow"]) + r["delivered"] - 5 * r["spam"].get("delivered", 0), r, save, g


def candidates(n=16):
    """Heaviest group-to-group traffic (packets per tick) from the send table + replies."""
    import collections, reply_rules as RR
    rate = collections.Counter()
    for a, x in _rules.items():
        for s in x["slots"].values():
            for m in s["messages"]:
                w = 1 / x["cycle"] / len(s["messages"])
                rate[(a, s["dst"])] += w
                rep = RR.reply_to(s["dst"], a, m)
                if rep:
                    rate[(s["dst"], rep["dst"])] += w
    pre = lambda a, n: ".".join(a.split(".")[:n])
    g = collections.Counter()
    for (s, d), w in rate.most_common(40):   # heaviest endpoint-to-endpoint flows
        if s != d and not s.startswith("1.") and not d.startswith("1.") and d in ENDPOINTS:
            g[(s, d)] += w
    for (s, d), w in rate.items():
        for L in (2, 3):
            if pre(s, L) != pre(d, L) and not d.startswith("1."):
                g[(pre(s, L), pre(d, L))] += w
    return [list(k) for k, _ in g.most_common(n)]


ENDPOINTS = set(_rules) | {"0.0.1.0", "0.1.1.0", "0.2.1.0", "0.3.1.0"}
CANDS = candidates(28)


def tweak(cfg, groups, rnd):
    c = copy.deepcopy(cfg)
    if rnd.random() < 0.3:
        if rnd.random() < 0.15:
            c["_sc_exit"] = rnd.choice(COLL)
            return c
        sc = c.setdefault("_shortcuts", [])
        cand = rnd.choice(CANDS)
        if cand in sc:
            sc.remove(cand)
        else:
            sc.append(cand)
        return c
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
    start = sys.argv[5] if len(sys.argv) > 5 else None
    best_cfg = json.load(open(start)) if start else {}
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
                print(f"[{n}] {time.time() - t0:.0f}s score {sc}: mean flow delivery {100 * r2['mean_flow']:.1f}%, flows covered {r2['covered']}/{len(REQ)}, delivered {r2['delivered']}/{r2['sent']} "
                      f"({100 * r2['rate']:.1f}%), never {len(r2['flows_never_delivered'])}", flush=True)
            best, best_cfg, r, save = sc, cand, r2, s2
    json.dump(best_cfg, open(out + "_cfg.json", "w"), indent=1)
    json.dump(save, open(out + ".json", "w", encoding="utf-8"), separators=(",", ":"))
    print(f"best score {best}: mean flow delivery {100 * r['mean_flow']:.1f}%, covered {r['covered']}/{len(REQ)}, spam {r['spam']}, delivered {r['delivered']}/{r['sent']} ({100 * r['rate']:.1f}%), "
          f"never delivered: {r['flows_never_delivered']}", flush=True)


if __name__ == "__main__":
    main()
