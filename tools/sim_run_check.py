"""Free-running check: seed sim.py from one live snapshot, run it on its own and compare
with the live game after each tick (read-only).
Packets are compared by (colour, src, dst) per slot; payload text may be random.
    python tools/sim_run_check.py [ticks]
"""
import sys, time, collections
import tunnet_live as T
import sim as S

def k3(p): return None if p is None else (p["color"], p["src"], p["dst"])

def main():
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 20
    net = T.LiveNet.attach(); last = None; sim = None; k = 0
    print(" k   live  matched  missing  extra   | excluding spam")
    while k <= n:
        tk = net.tick_count()
        if tk == last: time.sleep(0.002); continue
        first = last is None; last = tk; snap = net.snapshot()
        if first: continue
        if sim is None:
            sim = S.Net(snap); t0 = prev = tk; k = 1; continue
        if tk != prev + 1:
            print(f"  (missed a tick: {prev} -> {tk}, stopping)"); break
        prev = tk
        sim.step(tk)
        live = collections.Counter(); pred = collections.Counter()
        for e, nn in snap.items():
            for pi, port in enumerate(nn["ports"]):
                for si in (0, 1):
                    a = k3(S.from_live(port["slots"][si])); b = k3(sim.state[e][pi][si])
                    if a: live[(e, pi, si, a)] += 1
                    if b: pred[(e, pi, si, b)] += 1
        m = sum((live & pred).values()); L = sum(live.values()); P = sum(pred.values())
        ns = lambda c: sum(v for kk, v in c.items() if kk[3][0] != S.SPAM_COLOR)
        print(f"{tk - t0:2}  {L:5}  {m:5} ({100*m/max(L,1):5.1f}%)  {L-m:5}  {P-m:5}   | {100*ns(live & pred)/max(ns(live),1):5.1f}%")
        k += 1

if __name__ == "__main__":
    main()
