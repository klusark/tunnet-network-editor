"""Follow individual packets across network ticks, and recover the path of dropped ones.

Packets have no stable id in memory (they are copied per hop), so each tick we match
every packet to where it was on the previous tick, by content (colour, src, dst,
payload) and by what the wiring allows. Measured movement rule (speed_probe.py): per
tick a packet crosses at most one cable, and passes through nodes for free, so going
backwards from a slot:
    inbound  at (X, p) <- outbound at the peer's port      (cable crossing)
    outbound at (X, p) <- inbound at any port of X          (through the node)

Identical packets (same content) can swap tracks; `ambiguous` counts matches where more
than one previous packet could have been the source.
"""
import collections
import itertools

import tunnet_live as T

IN, OUT = T.INBOUND, T.OUTBOUND
MAX_STATES = 3000      # per track; older states are discarded (track marked truncated)
ENDED_KEEP_TICKS = 4   # how long an ended track waits to be claimed by a drop event


def sig_of(pk):
    return (pk["color"], pk["src"], pk["dst"], pk["payload"])


class Track:
    __slots__ = ("id", "sig", "born_tick", "states", "truncated", "end_tick")

    def __init__(self, tid, sig, tick, state):
        self.id, self.sig, self.born_tick = tid, sig, tick
        self.states = [(tick, *state)]  # (tick reached, entity, port, slot)
        self.truncated = False
        self.end_tick = None

    def add(self, tick, state):
        self.states.append((tick, *state))
        if len(self.states) > MAX_STATES:
            del self.states[: len(self.states) - MAX_STATES]
            self.truncated = True

    @property
    def last(self):
        return self.states[-1][1:]


class Tracker:
    def __init__(self):
        self.active = {}            # state (e, port, slot) -> Track
        self.ended = collections.deque()  # (Track) in end order
        self.tick = None
        self.ids = itertools.count(1)
        self.stats = collections.Counter()

    # ---------- wiring helpers ----------
    @staticmethod
    def _preds(snap, state):
        e, p, k = state
        n = snap.get(e)
        if not n:
            return []
        if k == IN:
            c = n["ports"][p] if p < len(n["ports"]) else None
            if c and c["peer"] is not None and c["peer_port"] is not None:
                return [((c["peer"], c["peer_port"], OUT), 1)]  # 1 = crosses a cable
            return []
        return [((e, q, IN), 0) for q in range(len(n["ports"]))]

    @staticmethod
    def _succs(snap, state):
        e, p, k = state
        n = snap.get(e)
        if not n:
            return []
        if k == OUT:
            c = n["ports"][p] if p < len(n["ports"]) else None
            if c and c["peer"] is not None and c["peer_port"] is not None:
                return [((c["peer"], c["peer_port"], IN), 1)]
            return []
        return [((e, q, OUT), 0) for q in range(len(n["ports"]))]

    def _search_all(self, snap, start, accept, max_steps, max_cross):
        """Backwards BFS from `start`; every accepting state within the limits, as paths
        (states ordered from start outward, start excluded), nearest first. Searches through
        matches too, so a packet that loses its nearest source still sees the next one."""
        seen = {start}
        frontier = [(start, None, 0)]
        found = []
        for _ in range(max_steps):
            nxt = []
            for node in frontier:
                for st, cross in self._preds(snap, node[0]):
                    if st in seen or node[2] + cross > max_cross:
                        continue
                    seen.add(st)
                    link = (st, node, node[2] + cross)
                    if accept(st):
                        path, l2 = [], link
                        while l2[1] is not None:
                            path.append(l2[0])
                            l2 = l2[1]
                        found.append(path[::-1])
                    nxt.append(link)
            frontier = nxt
        return found

    def _search(self, snap, start, accept, max_steps, max_cross, backwards=True):
        """BFS from `start`; returns (path, n_candidates): the path (states, start
        excluded, ordered from start outward) to the nearest state for which accept(state)
        is true, and how many accepting states were equally near (>1 = ambiguous)."""
        step = self._preds if backwards else self._succs
        seen = {start}
        frontier = [(start, None, 0)]
        for _ in range(max_steps):
            nxt, found = [], []
            for node in frontier:
                for st, cross in step(snap, node[0]):
                    if st in seen or node[2] + cross > max_cross:
                        continue
                    seen.add(st)
                    link = (st, node, node[2] + cross)
                    (found if accept(st) else nxt).append(link)
            if found:
                link, path = found[0], []
                while link[1] is not None:
                    path.append(link[0])
                    link = link[1]
                return path[::-1], len(found)
            frontier = nxt
        return None, 0

    # ---------- per tick ----------
    def update(self, tick, snap):
        """Advance all tracks to this snapshot. Returns tracks that ended this tick."""
        delta = 1 if self.tick is None else max(1, tick - self.tick)
        self.tick = tick
        cur = [((e, p, k), sig_of(pk)) for e, n in snap.items() for p, port in enumerate(n["ports"])
               for k, pk in enumerate(port["slots"]) if pk]
        pool = {}  # (state, sig) -> Track from the previous tick
        for st, t in self.active.items():
            pool[(st, t.sig)] = t
        # Candidate sources per current packet, nearest first: staying put (path []) or a
        # route back through the wiring. Identical packets often queue on the same wire,
        # so pick sources with a maximum bipartite matching (augmenting paths) that tries
        # each packet's nearest sources first; greedy matching strands queue-mates.
        cands = []
        for st, sig in cur:
            c = [[]] if (st, sig) in pool else []
            c += self._search_all(snap, st, lambda s, sig=sig: (s, sig) in pool, 3 * delta, delta)
            cands.append(c)
            if len(c) > 1 and len(c[0]) == len(c[1]):
                self.stats["ambiguous"] += 1  # two identical packets were equally good sources
        owner, choice = {}, {}

        def assign(i, seen):
            st, sig = cur[i]
            for path in cands[i]:
                key = ((path[-1] if path else st), sig)
                if key in seen:
                    continue
                seen.add(key)
                if key not in owner or assign(owner[key], seen):
                    owner[key], choice[i] = i, path
                    return True
            return False

        for i in sorted(range(len(cur)), key=lambda i: len(cands[i][0]) if cands[i] else 99):
            if cands[i]:
                assign(i, set())
        active = {}
        for i, (st, sig) in enumerate(cur):
            path = choice.get(i)
            if path is None:
                t = Track(next(self.ids), sig, tick, st)  # new packet (sent, or lost track)
                self.stats["born"] += 1
            else:
                t = pool.pop(((path[-1] if path else st), sig))
                if path:
                    for s in reversed(path[:-1]):  # intermediate states, oldest first
                        t.add(tick, s)
                    t.add(tick, st)
                    self.stats["moved"] += 1
                else:
                    self.stats["stayed"] += 1
            active[st] = t
        ended = list(pool.values())
        for t in ended:
            t.end_tick = tick
        # Antennas relay packets wirelessly to a partner antenna, and the packet usually
        # stays in the sending antenna's inbound slot meanwhile (measured), so a packet that
        # appears at an antenna is a copy: fork the history of the identical packet at (or
        # just gone from) another antenna. (Bridges are NOT like this: packets appearing at
        # a bridge come from the off-map network behind it, so those tracks start there.)
        for st, t in list(active.items()):
            if t.born_tick != tick or len(t.states) != 1 or snap.get(st[0], {}).get("type") != "antenna":
                continue
            src = next((tt for s, tt in active.items() if tt is not t and tt.sig == t.sig and s[0] != st[0]
                        and snap.get(s[0], {}).get("type") == "antenna"), None)
            if src is None:
                src = next((o for o in itertools.chain(ended, reversed(self.ended)) if o.sig == t.sig
                            and o.last[0] != st[0] and snap.get(o.last[0], {}).get("type") == "antenna"), None)
            if src is None:
                continue
            fork = Track(t.id, t.sig, src.born_tick, src.last)
            fork.states = list(src.states) + [(tick, *st)]
            fork.truncated = src.truncated
            active[st] = fork
            self.stats["born"] -= 1
            self.stats["antenna_fork"] += 1
        for t in ended:
            self.ended.append(t)
        self.stats["ended"] += len(ended)
        while self.ended and self.ended[0].end_tick < tick - ENDED_KEEP_TICKS:
            self.ended.popleft()
        self.active = active
        return ended

    # ---------- drops ----------
    def claim_drop(self, sig, node_e, snap):
        """Find the track of a dropped packet: same content, ended recently, last seen at
        or just before the drop node. Returns (track, path to the drop node) or (None, None)."""
        best = None
        for t in self.ended:
            if t.sig != sig:
                continue
            last = t.last
            if last[0] == node_e:
                cand = (0, -t.end_tick, t, [])
            else:
                fwd, _ = self._search(snap, last, lambda s: s[0] == node_e, 4, 1, backwards=False)
                if fwd is None:
                    continue
                cand = (len(fwd), -t.end_tick, t, fwd)
            if best is None or cand[:2] < best[:2]:
                best = cand
        if best is None:
            # Filters often leave a dropped packet's data in their slot, so its track never
            # ends. Fall back to a live packet with the same content at the drop node.
            live = [t for st, t in self.active.items() if st[0] == node_e and t.sig == sig]
            if not live:
                return None, None
            return max(live, key=lambda t: len(t.states)), []
        t, fwd = best[2], best[3]
        self.ended.remove(t)
        return t, fwd


def drop_record(track, fwd, drop_tick, snap, tracking_since):
    """Path of a dropped packet for the viewer: [[tick, entity, port, slot], ...], plus
    where its history starts: sent by an endpoint, entered via a bridge, or partial."""
    path = [list(s) for s in track.states] + [[drop_tick, *s] for s in fwd]
    first = snap.get(path[0][1], {})
    kind = first.get("type")
    if track.truncated:
        origin = "truncated"
    elif kind == "endpoint":
        origin = "sent"          # complete: from the sending endpoint
    elif kind == "bridge":
        origin = "bridge"        # complete: entered from the network behind a bridge
    elif track.born_tick <= tracking_since:
        origin = "before_tracking"
    else:
        origin = "lost"          # tracking lost it (e.g. identical packets swapped)
    return {"track": track.id, "born_tick": track.born_tick, "origin": origin, "path": path}
