"""Test transport hypotheses on consecutive live snapshots (read-only).

H1: IN(t+1) of a port == OUT(t) of its peer port (transport moves every outbound packet).
"""
import collections, sys, time
import tunnet_live as T, tracker as TR

def snaps(n):
    net = T.LiveNet.attach(); last = None; out = []
    while len(out) < n:
        tk = net.tick_count()
        if tk == last: time.sleep(0.002); continue
        if last is not None and tk != last + 1: out = []  # need consecutive ticks
        last = tk; out.append((tk, net.snapshot()))
    return out

def sig(p): return TR.sig_of(p) if p else None

if __name__ == "__main__":
    S = snaps(int(sys.argv[1]) if len(sys.argv) > 1 else 6)
    c = collections.Counter(); ex = collections.defaultdict(list)
    for (t0, a), (t1, b) in zip(S, S[1:]):
        if t1 != t0 + 1: c["non-consecutive"] += 1; continue
        for e, n in b.items():
            if e not in a: continue
            for p, port in enumerate(n["ports"]):
                peer, pp = port["peer"], port["peer_port"]
                got = sig(port["slots"][0])
                exp = sig(a[peer]["ports"][pp]["slots"][1]) if peer in a and pp is not None else None
                k = ("match" if got == exp else "IN but peer OUT was empty" if exp is None
                     else "peer OUT not delivered" if got is None else "different packet")
                c[(k, n["type"])] += 1
                if k != "match" and len(ex[k]) < 4: ex[k].append((t1, e, n["type"], p, got and got[3], exp and exp[3]))
    for k, v in sorted(c.items(), key=lambda x: -x[1]): print(v, k)
    for k, v in ex.items(): print(k, v)
