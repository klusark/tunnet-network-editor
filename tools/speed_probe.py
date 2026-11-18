"""Why do some packets move further per tick? Read-only analysis.

Captures N consecutive network ticks (synced to the NetTockEvent counter), rebuilds
each packet's route between ticks with the same backwards search the viewer uses, and
tabulates route length against candidate causes.

    python tools/speed_probe.py [ticks]
"""
import sys
import time
from collections import Counter, defaultdict

import tunnet_live as T

IN, OUT = T.INBOUND, T.OUTBOUND


def capture(net, n):
    ticks = []
    last = net.tick_count()
    while len(ticks) < n:
        c = net.tick_count()
        if c == last:
            time.sleep(0.003)
            continue
        snap = net.snapshot()
        ticks.append((c, snap))
        last = c
    return ticks


def sig(pk):
    return (pk["color"], pk["src"], pk["dst"], pk["payload"])


def packets(snap):
    for e, n in snap.items():
        for p, port in enumerate(n["ports"]):
            for k, pk in enumerate(port["slots"]):
                if pk:
                    yield (e, p, k), pk


def route(snap_prev, snap_cur, max_steps=8):
    """Yield (prev_state, cur_state, steps(list of states), pk_prev, pk_cur) for matched packets."""
    pool = defaultdict(list)
    for st, pk in packets(snap_prev):
        pool[(st, sig(pk))].append(pk)
    cur = list(packets(snap_cur))
    rest = []
    for st, pk in cur:
        if pool.get((st, sig(pk))):
            yield st, st, [st], pool[(st, sig(pk))].pop(), pk
        else:
            rest.append((st, pk))
    for st, pk in rest:
        s = sig(pk)
        seen = {st}
        frontier = [(st, None)]
        found = None
        for _ in range(max_steps):
            nxt = []
            for node in frontier:
                (e, port, slot) = node[0]
                n = snap_cur.get(e)
                if not n:
                    continue
                if slot == IN:
                    c = n["ports"][port] if port < len(n["ports"]) else None
                    preds = [(c["peer"], c["peer_port"], OUT)] if c and c["peer"] is not None and c["peer_port"] is not None else []
                else:
                    preds = [(e, q, IN) for q in range(len(n["ports"]))]
                for p2 in preds:
                    if p2 in seen:
                        continue
                    seen.add(p2)
                    link = (p2, node)
                    if pool.get((p2, s)):
                        found = link
                        break
                    nxt.append(link)
                if found:
                    break
            if found:
                break
            frontier = nxt
        if not found:
            continue
        states = []
        l = found
        while l:
            states.append(l[0])
            l = l[1]
        yield states[0], st, states, pool[(states[0], s)].pop(), pk


def main():
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 8
    net = T.LiveNet.attach()
    ticks = capture(net, n)
    print(f"captured ticks {ticks[0][0]}..{ticks[-1][0]}")
    by_steps = Counter()
    by_x = defaultdict(Counter)            # previous x -> steps
    by_dx = Counter()                      # (x_prev, x_cur) pairs
    by_state = defaultdict(Counter)
    by_start = defaultdict(Counter)
    by_relays = defaultdict(Counter)       # steps -> how many of the nodes passed were relays
    stop_reason = Counter()                # what is in the next slot where the packet stopped
    examples = defaultdict(list)
    for (t0, a), (t1, b) in zip(ticks, ticks[1:]):
        if t1 != t0 + 1:
            continue
        for s0, s1, states, pk0, pk1 in route(a, b):
            steps = len(states) - 1
            by_steps[steps] += 1
            by_x[pk0["x"]][steps] += 1
            by_dx[(pk0["x"], pk1["x"])] += 1
            by_state[pk0["state"]][steps] += 1
            by_start["IN" if s0[2] == IN else "OUT"][steps] += 1
            passed = [b[st[0]]["type"] for i, st in enumerate(states[1:], 1) if states[i - 1][0] == st[0]]
            by_relays[steps][tuple(sorted(Counter(passed).items()))] += 1
            # where it stopped: what is the next slot ahead (for OUT: peer inbound; for IN: unknown output)
            e, p, k = s1
            if k == OUT:
                c = b[e]["ports"][p]
                nxt = b.get(c["peer"], {}).get("ports", [{}] * 8)[c["peer_port"]] if c["peer"] is not None else None
                stop_reason[("stopped at OUT", "peer IN occupied" if nxt and nxt["slots"][IN] else "peer IN free")] += 1
            else:
                stop_reason[("stopped at IN", b[e]["type"])] += 1
            if len(examples[steps]) < 2:
                examples[steps].append([(b[st[0]]["type"], st[1], "IN" if st[2] == IN else "OUT") for st in states])

    print("\nsteps per tick:", dict(sorted(by_steps.items())))
    print("\nstart slot -> steps:", {k: dict(sorted(v.items())) for k, v in by_start.items()})
    print("\nstate byte -> steps:", {k: dict(sorted(v.items())) for k, v in by_state.items()})
    print("\npacket x (+0x10) before -> steps:")
    for x in sorted(by_x):
        print(f"   x={x}: {dict(sorted(by_x[x].items()))}")
    print("\nx before -> x after (top):", by_dx.most_common(12))
    print("\nnode types passed through, per step count:")
    for s in sorted(by_relays):
        print(f"   {s} steps:", by_relays[s].most_common(4))
    print("\nwhere packets stopped:", stop_reason.most_common())
    print("\nexample routes:")
    for s in sorted(examples):
        for ex in examples[s]:
            print(f"   {s}: " + " -> ".join(f"{t}:{p}{d}" for t, p, d in ex))


if __name__ == "__main__":
    main()
