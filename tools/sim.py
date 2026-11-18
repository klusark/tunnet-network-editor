"""Tunnet network simulator, built from the game's code and checked against the live game.

One network tick, as the game does it:
  1. transport (FUN_14074aa00): every inbound slot is cleared; every outbound packet on a
     connected port moves to the peer port's inbound slot (verified 17052/17052 ports);
     an outbound packet on an unconnected port is dropped (drop event, flag 0).
  2. node updates (relay/hub/filter/endpoint/... systems, run once per tick on the
     NetTock event): each node reads its inbound slots and writes outbound slots. Writes
     overwrite (the old outbound packet is lost); inbound slots are not cleared (they are
     cleared by the next transport).

A packet is a tuple-like dict: color, src, dst, payload, x (bounce budget), f3a (budget
applies), f3b (never bounce). Addresses are strings like "0.2.1.1" ('*' = wildcard).

State = {entity: [[in, out], ...]} per port. Topology and configs come from a live
snapshot (tunnet_live.LiveNet.snapshot) and can be edited before simulating.
"""
import copy
import json
import os
import random

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IN, OUT = 0, 1
SPAM_COLOR = "a93b3b"
SPAM_RATE = {"0.0.1.1": 0.26, "0.2.1.3": 0.11}   # spam sends per free tick, measured over 150 ticks


def addr_match(addr, mask):
    """FUN_1406b6550: per digit, mask '*' matches anything, else digits must be equal."""
    return all(m == "*" or a == m for a, m in zip(addr.split("."), mask.split(".")))


def pkt(color, src, dst, payload, x=0, f3a=0, f3b=0):
    return {"color": color, "src": src, "dst": dst, "payload": payload, "x": x, "f3a": f3a, "f3b": f3b}


def from_live(pk):
    if pk is None:
        return None
    return {"color": pk["color"], "src": pk["src"], "dst": pk["dst"], "payload": pk["payload"],
            "x": pk["x"], "f3a": pk["state"], "f3b": pk["f3b"]}


def key(p):
    return None if p is None else (p["color"], p["src"], p["dst"], p["payload"])


class Net:
    def __init__(self, snap, rules=None, seed=1):
        """snap: LiveNet.snapshot(). Copies topology, configs and packets."""
        self.nodes = {}
        for e, n in snap.items():
            self.nodes[e] = {
                "type": n["type"], "address": n.get("address"), "pos": n.get("pos"),
                "filter": dict(n["filter"]) if n.get("filter") else None,
                "hub_dir": n.get("hub_dir"), "tester": dict(n["tester"]) if n.get("tester") else None,
                "links": [(p["peer"], p["peer_port"]) for p in n["ports"]],
                "infected": n.get("infection") == 5,
            }
        self.state = {e: [[from_live(p["slots"][0]), from_live(p["slots"][1])] for p in n["ports"]]
                      for e, n in snap.items()}
        if rules is None:
            rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))["endpoints"]
        self.rules = rules
        self.drops = []      # (tick, entity, reason, packet)
        self.delivered = []  # (tick, endpoint entity, packet)
        self.sent = []       # (tick, endpoint entity, packet) new packets (schedule/reply/spam)
        self.seed = seed
        self.rng = random.Random(seed)

    # ---------- step ----------
    def transport(self, tick):
        new = {e: [[None, ports[k][OUT] and None] for k in range(len(ports))] for e, ports in self.state.items()}
        for e, ports in self.state.items():
            for k, (i, o) in enumerate(ports):
                if o is None:
                    continue
                peer, pp = self.nodes[e]["links"][k]
                if peer is None or pp is None or peer not in new:
                    self.drops.append((tick, e, "sent out an unconnected port", o))
                    continue
                new[peer][pp][IN] = o
        self.state = new

    def node_updates(self, tick):
        for e, ports in self.state.items():
            # Randomness per (seed, node, tick): a what-if run and its baseline draw the same
            # numbers wherever the network is unchanged.
            self.rng = random.Random(hash((self.seed, e, tick)))
            fn = getattr(self, "upd_" + self.nodes[e]["type"], None)
            if fn:
                fn(e, ports, tick)

    def step(self, tick):
        """Advance to `tick` (the NetTock count after this tick)."""
        self.transport(tick)
        self.node_updates(tick)

    def drop(self, tick, e, reason, p):
        self.drops.append((tick, e, reason, p))

    # ---------- node rules ----------
    def upd_relay(self, e, P, tick):
        # relay::update -> FUN_1402fc350(ports, 0, 1) then (ports, 1, 0): copy, overwrite
        if len(P) >= 2:
            if P[0][IN] is not None:
                P[1][OUT] = dict(P[0][IN])
            if P[1][IN] is not None:
                P[0][OUT] = dict(P[1][IN])

    def upd_bridge(self, e, P, tick):
        """bridge::update -> FUN_1406b6bb0(ports, 0, 1) then (1, 0), read from the code:
        the first digit of src and dst swaps 0 <-> 1. Then, on the NEW destination: if its
        first digit is '1' or '*' the packet gets a bounce limit (budget 6 if the second
        digit is '3' or '*', else 4); otherwise the limit is removed and, if the second
        digit is '1' or '*', the packet becomes no-bounce. Written only if the target port
        is connected (else it vanishes, no drop event)."""
        swap = {"0": "1", "1": "0"}
        for frm, to in ((0, 1), (1, 0)):
            pk = P[frm][IN] if frm < len(P) else None
            if pk is None or to >= len(P):
                continue
            pk = dict(pk)
            for f in ("src", "dst"):
                pk[f] = swap.get(pk[f][0], pk[f][0]) + pk[f][1:]
            d0, d1 = pk["dst"][0], pk["dst"][2]
            if d0 in ("1", "*"):
                pk["f3a"] = 1
                pk["x"] = 6 if d1 in ("3", "*") else 4
            else:
                pk["f3a"] = 0
                if d1 in ("1", "*"):
                    pk["f3b"] = 1
            if self.nodes[e]["links"][to][0] is not None:
                P[to][OUT] = pk

    def upd_antenna(self, e, P, tick):
        """An antenna sends out what its partner antenna received this tick (measured live;
        with two antennas the partner is the other one)."""
        partner = self.nodes[e].get("partner")
        if partner is None:
            others = [x for x, n in self.nodes.items() if n["type"] == "antenna" and x != e]
            partner = self.nodes[e]["partner"] = others[0] if len(others) == 1 else -1
        pp = self.state.get(partner)
        if pp and pp[0][IN] is not None:
            P[0][OUT] = dict(pp[0][IN])

    def upd_hub(self, e, P, tick):
        d = self.nodes[e]["hub_dir"]
        n = len(P)
        for i in range(n):
            if P[i][IN] is not None:
                P[(i + (n - 1 if d else 1)) % n][OUT] = dict(P[i][IN])

    def upd_filter(self, e, P, tick):
        f = self.nodes[e]["filter"]
        p = f["port"]
        q = 1 - p
        a = P[p][IN]
        if a is not None:
            a = dict(a)
            if a["f3a"] == 1:
                if a["x"] <= 1:
                    self.drop(tick, e, "out of bounces at a filter", a)
                    a = None
                else:
                    a["x"] -= 1
        if a is not None:
            field = a["dst"] if f["addr"] == "Dst" else a["src"]
            hit = addr_match(field, f["mask"]) == (f["op"] == "Match")
            if hit and f["action"] == "Drop":
                self.drop(tick, e, "filter rule", a)
            elif hit:
                P[p][OUT] = a
            else:
                P[q][OUT] = a
        b = P[q][IN]
        if b is not None:
            b = dict(b)
            if P[p][OUT] is None:
                P[p][OUT] = b
            elif f["collision"] == "DropInbound":
                self.drop(tick, e, "filter collision: waiting packet replaced", P[p][OUT])
                P[p][OUT] = b
            elif f["collision"] == "DropOutbound":
                self.drop(tick, e, "filter collision: arriving packet dropped", b)
            else:
                P[q][OUT] = b

    def upd_endpoint(self, e, P, tick):
        me = self.nodes[e]["address"]
        port = P[0]
        a = port[IN]
        received = a is not None and a["dst"] == me
        if a is not None:
            if a["dst"] == me:
                self.delivered.append((tick, e, a))
                port[OUT] = self.reply(me, a, tick)
                if port[OUT] is not None:
                    self.sent.append((tick, e, port[OUT]))
            elif a["src"] == me:
                self.drop(tick, e, "returned to sender", a)
            elif a["f3b"]:
                self.drop(tick, e, "no-bounce packet at wrong endpoint", a)
            elif a["f3a"] and a["x"] <= 1:
                self.drop(tick, e, "out of bounces at wrong endpoint", a)
            else:
                b = dict(a)
                b["x"] -= b["f3a"]
                port[OUT] = b
        if port[OUT] is None and not received:   # no scheduled send on a tick it received mail
            g = self.generate(me, tick)
            if g is not None:
                port[OUT] = g
                self.sent.append((tick, e, g))
            elif self.nodes[e]["infected"] and self.rng.random() < SPAM_RATE.get(me, 0.2):
                # infected endpoints spam a random address in their region (rate measured live)
                d = me.split(".")
                port[OUT] = pkt(SPAM_COLOR, me, f"{d[0]}.{d[1]}.{self.rng.randint(0, 3)}.{self.rng.randint(0, 3)}",
                                "spam")
                self.sent.append((tick, e, port[OUT]))

    def reply(self, me, a, tick):
        import reply_rules as RR
        r = RR.reply_to(me, a["src"], a["payload"], a["color"])
        if r is None:
            return None
        text = r["text"].replace("{n}", str(self.rng.randint(1, 99)))
        return pkt(r["color"] or a["color"], r["src"], r["dst"], text,
                   x=r["bounce_budget"] or 0, f3a=1 if r["bounce_budget"] else 0, f3b=1 if r["no_bounce"] else 0)

    def generate(self, me, tick):
        r = self.rules.get(me)
        if not r:
            return None
        s = r["slots"].get(str(tick % r["cycle"]))
        if not s:
            return None
        msg = self.rng.choice(s["messages"]).replace("{}", "%08x" % self.rng.getrandbits(32))
        budget = s.get("bounce_budget")
        return pkt(s.get("color", r["color"]), me, s["dst"], msg, x=budget or 0,
                   f3a=1 if budget is not None else 0, f3b=1 if s.get("no_bounce") else 0)


def clone(net):
    return copy.deepcopy(net)

    def upd_tester(self, e, P, tick):
        """Tester (FUN_14044eae0). Repeat: every freq ticks sends PING from `address` to the
        destination, stepping wildcard digits through every match. NOT validated live (the
        tester was in Single mode); the wildcard order is a guess (last digit fastest)."""
        t = self.nodes[e]["tester"]
        if not t or t["mode"] != "Repeat" or tick % max(1, t["freq"]) != 0:
            return
        d = t["destination"].split(".")
        wild = [i for i, x in enumerate(d) if x == "*"]
        n = tick // max(1, t["freq"])
        for i in reversed(wild):
            d[i] = str(n % 4)
            n //= 4
        P[0][OUT] = pkt("a0938e", t["address"], ".".join(d), "PING")


# ---------- what-if ----------
def apply_edits(net, edits):
    """edits: [{"kind": "filter"|"hub"|"tester", "e": entity, "config": {...}},
               {"kind": "link", "op": "connect"|"disconnect", ...}] (same shapes as the
    live-edit API). Changes the simulated network only."""
    for ed in edits:
        k = ed["kind"]
        if k == "filter":
            net.nodes[ed["e"]]["filter"].update(ed["config"])
        elif k == "hub":
            net.nodes[ed["e"]]["hub_dir"] = int(ed["config"]["hub_dir"])
        elif k == "tester":
            net.nodes[ed["e"]]["tester"].update(ed["config"])
        elif k == "link" and ed["op"] == "disconnect":
            e, p = ed["e"], ed["p"]
            peer, pp = net.nodes[e]["links"][p]
            net.nodes[e]["links"][p] = (None, None)
            if peer is not None and pp is not None:
                net.nodes[peer]["links"][pp] = (None, None)
        elif k == "link" and ed["op"] == "connect":
            (a, ap), (b, bp) = ed["a"], ed["b"]
            net.nodes[a]["links"][ap] = (b, bp)
            net.nodes[b]["links"][bp] = (a, ap)
        else:
            raise ValueError(f"unknown edit {ed}")


def run(net, start_tick, ticks):
    for t in range(start_tick + 1, start_tick + ticks + 1):
        net.step(t)
    return net


def summarize(net, ticks):
    import collections
    addr = lambda e: net.nodes[e]["address"] or f"{net.nodes[e]['type']} #{e}"
    spam = lambda p: p["color"] == SPAM_COLOR
    dl = collections.Counter(addr(e) for _, e, p in net.delivered if not spam(p))
    sd = collections.Counter(addr(e) for _, e, p in net.delivered if spam(p))
    snt = collections.Counter(addr(e) for _, e, p in net.sent if not spam(p))
    dr = collections.Counter(r for _, e, r, p in net.drops if not spam(p))
    drs = collections.Counter(r for _, e, r, p in net.drops if spam(p))
    where = collections.Counter(f"{addr(e)}: {r}" for _, e, r, p in net.drops if not spam(p))
    return {"ticks": ticks,
            "delivered": sum(dl.values()), "sent": sum(snt.values()),
            "spam_delivered": sum(sd.values()), "spam_dropped": sum(drs.values()),
            "dropped": sum(dr.values()), "drop_reasons": dict(dr), "drop_places": dict(where.most_common(15)),
            "delivered_by_endpoint": dict(dl), "sent_by_endpoint": dict(snt),
            "spam_delivered_to": dict(sd)}


def what_if(snap, tick, edits, ticks=200, seed=1):
    """Run the baseline and the edited network from the same live state and seed."""
    base = run(Net(snap, seed=seed), tick, ticks)
    alt = Net(snap, seed=seed)
    apply_edits(alt, edits)
    run(alt, tick, ticks)
    return {"baseline": summarize(base, ticks), "what_if": summarize(alt, ticks)}
