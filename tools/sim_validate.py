"""Validate sim.py node rules against the live game, one tick at a time (read-only).

For consecutive live snapshots S(t), S(t+1): seed the simulator's ports with the REAL
inbound slots of S(t+1) (transport is exact), run only the node updates for tick t+1,
and compare every predicted outbound slot with S(t+1). Mismatches are grouped by node
type and kind.
    python tools/sim_validate.py [ticks]
"""
import collections, sys, time
import tunnet_live as T
import sim as S

def fullkey(p):
    # x (+0x10) only matters while the bounce-limit flag is set
    return None if p is None else (p["color"], p["src"], p["dst"], p["payload"], p["x"] if p["f3a"] else None, p["f3a"], p["f3b"])

def main():
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 20
    net = T.LiveNet.attach(); last = None; got = 0
    res = collections.Counter(); ex = collections.defaultdict(list)
    while got < n:
        tk = net.tick_count()
        if tk == last: time.sleep(0.002); continue
        first = last is None
        last = tk; snap = net.snapshot()
        if first: continue  # may have started mid-tick
        got += 1
        sim = S.Net(snap)
        for e, ports in sim.state.items():
            for p in ports: p[S.OUT] = None
        sim.node_updates(tk)
        for e, n_ in snap.items():
            for k, port in enumerate(n_["ports"]):
                real = fullkey(S.from_live(port["slots"][1])); pred = fullkey(sim.state[e][k][S.OUT])
                t = n_["type"]
                if real == pred: res[(t, "ok" if real else "ok-empty")] += 1; continue
                if real and pred and real[:3] == pred[:3] and real[4:] == pred[4:] and t == "endpoint": res[(t, "ok-text-random")] += 1; continue
                kind = "missing" if pred is None else "extra" if real is None else "different"
                res[(t, kind)] += 1
                if len(ex[(t, kind)]) < 5:
                    ex[(t, kind)].append(dict(tick=tk, e=e, port=k, addr=n_.get("address"), cfg=n_.get("filter") or n_.get("tester"),
                        ins=[fullkey(S.from_live(p["slots"][0])) for p in n_["ports"]], real=real, pred=pred))
    for k, v in sorted(res.items()): print(f"{v:7}  {k}")
    for k, v in ex.items():
        print("==", k)
        for x in v: print("  ", x)

if __name__ == "__main__":
    main()
