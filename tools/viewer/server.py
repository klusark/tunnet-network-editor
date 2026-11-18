"""Live Tunnet network viewer: local web server.

    python tools/viewer/server.py            # then open http://127.0.0.1:8765
    HOST=127.0.0.1 python tools/viewer/server.py   # only this PC (default: all interfaces)

Tick-synced and read-only: a background thread watches the game's network tick
counter (Events<NetTockEvent>.event_count, 8 bytes) every few ms and reads the
network once right after each tick, when the tick's writes are complete.

  /api/live?after=N   long-poll: returns as soon as tick > N (or after ~2 s)
  /api/structure      nodes + wiring; the client re-fetches it when `rev` changes
  /api/drops          every dropped packet seen since the server started (no paths)
  /api/drop?id=N      one drop with the full path of the packet up to where it was dropped
  /api/traffic?e=N    what endpoint N sent and received (rates, gaps, destinations, spam)

Packets are tracked across ticks (tracker.py) so a dropped packet's route can be replayed.

Dropped packets come from the game's own Events<PacketDropEvent> queue, polled every
few ms (Bevy keeps events for only ~2 frames). Each drop is also appended to
logs/drops.jsonl in the project folder.
"""
import collections
import datetime
import hashlib
import json
import math
import os
import sys
import threading
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import tunnet_live as T  # noqa: E402
import tracker as TR  # noqa: E402
import reply_rules as RR  # noqa: E402
import sim as SIM  # noqa: E402
import save_export as SX  # noqa: E402

DROP_CLAIM_TICKS = 4  # how long a drop waits for its packet's track before giving up

TYPES = ["endpoint", "relay", "hub", "filter", "bridge", "antenna", "tester", "other"]
WATCH_S = 0.005    # how often to check the 8-byte tick counter
IDLE_READ_S = 1.0  # still re-read this often when no tick happens (paused network, building)
LONGPOLL_S = 2.0
LOG_DIR = os.path.join(os.path.dirname(os.path.dirname(HERE)), "logs")
DROPS_KEEP = 5000      # in memory, for /api/drops
DROPS_PER_PUBLISH = 200


class State:
    def __init__(self):
        self.cond = threading.Condition()
        self.seq = 0  # bumps on every publish (ticks and idle refreshes)
        self.live = json.dumps({"status": "starting", "seq": 0}).encode()
        self.structure = b"{}"
        self.rev = ""
        self.drops = collections.deque(maxlen=DROPS_KEEP)
        self.drop_total = 0
        self.drop_missed = 0  # gaps in event ids: drops that came and went between polls
        # Drop ids are the server's own, always increasing (they start at the current time in
        # ms so they also keep increasing across server restarts). The game's event ids start
        # again from 1 when the game restarts, and the page treats ids it has passed as old.
        self.next_id = int(time.time() * 1000)
        # traffic per endpoint/bridge entity: deques of (tick, time, peer address, kind, spam)
        self.sent = collections.defaultdict(lambda: collections.deque(maxlen=1000))
        self.recv = collections.defaultdict(lambda: collections.deque(maxlen=1000))
        self.counts = collections.Counter()  # sent, delivered, spam_sent, spam_dropped, spam_delivered, ...
        self.tracking_since = None


STATE = State()


def drop_reason(node, flag, pk):
    """Why the game dropped this packet. Endpoint rules come from the game's code
    (endpoint::update, FUN_1402f5840): an endpoint BOUNCES packets addressed to someone
    else, except it drops (1) its own packet coming back, (2) packets flagged "no bounce"
    (packet byte 0x3b: e.g. Token, TOP SECRET, supply requests), (3) packets whose bounce
    budget (+0x10, only counted when byte 0x3a is set) is used up. Other reasons measured."""
    if node is None:
        return "unknown location"
    t = node["type"]
    if t == "filter":
        return "filter rule"
    if t == "endpoint":
        me = node.get("address")
        if pk["src"] == me and pk["dst"] != me:
            return "returned to sender"
        if pk["dst"] != me and pk.get("f3b"):
            return "no-bounce packet at wrong endpoint"
        if pk["dst"] != me and pk.get("state") == 1 and pk.get("x") == 1:
            return "out of bounces at wrong endpoint"
        return "at endpoint (unexplained)"
    if flag == 0 and t != "antenna" and any(p["peer"] is None for p in node["ports"]):
        # transport tick (FUN_14074aa00): an outbound packet on a port with no cable is dropped
        return "sent out an unconnected port"
    return f"at {t} (flag {flag})"


OVERWRITE_REASON = {"endpoint": "overwritten by a bounce (no game drop event)",
                    "hub": "overwritten at a hub (no game drop event)"}
SPAM_COLOR = "a93b3b"  # endpoint::update: infected endpoints send spam in this colour, nothing else does


def is_spam(color):
    return color == SPAM_COLOR


def kind_of(payload):
    return "Re: (reply)" if payload.startswith("Re:") else payload


def account_traffic(trk, snap, tick, ended):
    """Sends (new packet in an endpoint/bridge outbound slot) and deliveries (packet gone
    from the inbound slot of the endpoint it is addressed to), from the tracker."""
    now = time.time()
    sent, delivered = [], []
    for st, t in trk.active.items():
        if t.born_tick == tick and len(t.states) == 1 and st[2] == TR.OUT:
            n = snap.get(st[0])
            if n and n["type"] in ("endpoint", "bridge"):
                sent.append((st[0], t))
    for t in ended:
        e, port, slot = t.last
        n = snap.get(e)
        if n and n["type"] == "endpoint" and slot == TR.IN and n.get("address") == t.sig[2]:
            delivered.append((e, t))
    with STATE.cond:
        for e, t in sent:
            spam = is_spam(t.sig[0])
            STATE.sent[e].append((tick, now, t.sig[2], kind_of(t.sig[3]), spam))
            STATE.counts["sent"] += 1
            STATE.counts["spam_sent"] += spam
        for e, t in delivered:
            spam = is_spam(t.sig[0])
            STATE.recv[e].append((tick, now, t.sig[1], kind_of(t.sig[3]), spam))
            STATE.counts["delivered"] += 1
            STATE.counts["spam_delivered"] += spam


RULES_PATH = os.path.join(os.path.dirname(os.path.dirname(HERE)), "re", "endpoint_rules.json")
try:  # exact per-endpoint send rules: the game's generator (FUN_1402f9a40) emulated in Ghidra
    RULES = json.load(open(RULES_PATH))["endpoints"]
except (OSError, ValueError, KeyError):
    RULES = {}


def rules_summary(address, tick):
    r = RULES.get(address)
    if r is None:
        return None
    slots = r["slots"]
    dsts = collections.Counter(e["dst"] for e in slots.values())
    msgs = []
    for e in slots.values():
        for m in e["messages"]:
            if m not in msgs:
                msgs.append(m)
    upcoming = []
    if slots and tick is not None:
        c = r["cycle"]
        for k in range(1, c + 1):
            e = slots.get(str((tick + k) % c))
            if e:
                upcoming.append({"in": k, "tick": tick + k, "dst": e["dst"], "messages": e["messages"],
                                 "no_bounce": e.get("no_bounce", False), "bounce_budget": e.get("bounce_budget")})
                if len(upcoming) >= 6:
                    break
    return {"cycle": r["cycle"], "sends_per_cycle": r["sends_per_cycle"], "color": r["color"],
            "destinations": dsts.most_common(), "messages": msgs,
            "no_bounce": any(e.get("no_bounce") for e in slots.values()),
            "bounce_budgets": sorted({e["bounce_budget"] for e in slots.values() if e.get("bounce_budget") is not None}),
            "upcoming": upcoming}


_INCOMING = {}


def incoming_for(address):
    """Static: what other endpoints send to this address, plus the game's replies to them."""
    if not address:
        return []
    if address not in _INCOMING:
        _INCOMING[address] = RR.incoming(address, RULES)
    return _INCOMING[address]


def traffic_summary(e, period):
    """Per-endpoint traffic for the viewer."""
    def summarise(rows, peer_key):
        if not rows:
            return {"count": 0}
        ticks = [r[0] for r in rows]
        gaps = [b - a for a, b in zip(ticks, ticks[1:])]
        span = max(1, ticks[-1] - ticks[0]) if len(ticks) > 1 else 1
        peers = collections.Counter(r[2] for r in rows)
        kinds = collections.Counter(r[3] for r in rows)
        gaps_sorted = sorted(gaps)
        # Measured: regular endpoints send when tick % period == phase, period a power of two.
        # The smallest gap is the period (larger gaps are skipped sends while blocked).
        schedule = None
        if gaps and not any(r[4] for r in rows):
            p = gaps_sorted[0]
            phases = collections.Counter(tk % p for tk in ticks) if p > 0 else {}
            if p > 0 and len(phases) == 1:
                schedule = {"period": p, "phase": next(iter(phases)),
                            "skipped": sum(g // p - 1 for g in gaps)}
        return {
            "schedule": schedule,
            "count": len(rows), "spam": sum(r[4] for r in rows),
            "per_min": round(60 * (len(rows) - 1) / (span * period), 1) if len(rows) > 1 else None,
            "gap_ticks": {"min": gaps_sorted[0], "median": gaps_sorted[len(gaps) // 2], "max": gaps_sorted[-1]} if gaps else None,
            peer_key: peers.most_common(12), "kinds": kinds.most_common(12),
            "last": [{"tick": r[0], "peer": r[2], "kind": r[3], "spam": r[4]} for r in list(rows)[-8:]][::-1],
        }
    with STATE.cond:
        sent, recv = list(STATE.sent.get(e, ())), list(STATE.recv.get(e, ()))
    snap = SHARED.snap or {}
    address = snap.get(e, {}).get("address")
    return {"entity": e, "since_tick": STATE.tracking_since, "sent": summarise(sent, "to"),
            "received": summarise(recv, "from"), "rules": rules_summary(address, SHARED.tick),
            "replies": [r for r in RR.rules_for(address) if not r.get("boss")] if address else [],
            "incoming": incoming_for(address)}


def find_overwrites(trk, snap, tick, ended, tracking_since):
    """Packets the game destroys WITHOUT a drop event. Endpoint bounce code writes the
    bounced packet into the outbound slot without checking it is empty, so a packet that
    was waiting there (e.g. just sent) is silently freed. Detected from tracking: a packet
    vanishes from an endpoint's outbound slot on a tick when that endpoint bounced one."""
    # (node, outbound port) that another packet was written into this tick. Endpoint bounces
    # and hub rotation (hub::update FUN_140179ef0 -> FUN_1401d42e0) both overwrite the
    # target outbound slot without checking it is empty.
    written = set()
    for t in trk.active.values():
        for a, b in zip(t.states, t.states[1:]):
            if b[0] == tick and a[1] == b[1] and a[3] == TR.IN and b[3] == TR.OUT:
                n = snap.get(a[1])
                if n and ((n["type"] == "endpoint" and n.get("address") != t.sig[2]) or n["type"] == "hub"):
                    written.add((a[1], b[2]))
    rows = []
    for t in ended:
        e, port, slot = t.last
        if slot != TR.OUT or (e, port) not in written or t not in trk.ended:  # claimed by a real drop
            continue
        trk.ended.remove(t)
        n = snap[e]
        rec = TR.drop_record(t, [], tick, snap, tracking_since)
        rows.append({
            "id": new_drop_id(), "time": time.time(), "tick": tick,
            "reason": OVERWRITE_REASON.get(n["type"], "overwritten (no game drop event)"),
            "flag": None, "synthetic": True, "node": [e, n["type"], n.get("address")],
            "pos": [round(v, 2) for v in n.get("pos", (0, 0, 0))],
            "color": t.sig[0], "src": t.sig[1], "dst": t.sig[2], "payload": t.sig[3],
            "spam": is_spam(t.sig[0]), "origin": rec["origin"], "born_tick": rec["born_tick"], "path": rec["path"],
            "path_len": len(rec["path"]),
        })
    if rows:
        with STATE.cond:
            STATE.drops.extend(rows)
            STATE.drop_total += len(rows)
            STATE.counts["spam_dropped"] += sum(r["spam"] for r in rows)
            STATE.counts["legit_dropped"] += sum(not r["spam"] for r in rows)
        log_drops(rows)


def new_drop_id():
    STATE.next_id += 1
    return STATE.next_id


def enrich_drop(d, snap, tick):
    pos = d["pos"]
    best, bd = None, 1e9
    for e, n in snap.items():
        p = n.get("pos")
        if p:
            dist = math.dist(p, pos)
            if dist < bd:
                best, bd = (e, n), dist
    node = best[1] if best and bd < 2.0 else None
    pk = d["packet"]
    return {
        "id": new_drop_id(), "event": d["id"], "time": time.time(), "tick": tick,
        "reason": drop_reason(node, d["flag"], pk), "flag": d["flag"],
        "node": [best[0], node["type"], node.get("address")] if node else None,
        "pos": [round(v, 2) for v in pos],
        "color": pk["color"], "src": pk["src"], "dst": pk["dst"], "payload": pk["payload"],
        "spam": is_spam(pk["color"]),
    }


def log_drops(drops):
    os.makedirs(LOG_DIR, exist_ok=True)
    with open(os.path.join(LOG_DIR, "drops.jsonl"), "a", encoding="utf-8") as f:
        for d in drops:
            row = dict(d, time=datetime.datetime.fromtimestamp(d["time"]).isoformat(timespec="milliseconds"))
            f.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")


def public(d):
    """A drop row without its (possibly long) path, for list views."""
    return {k: v for k, v in d.items() if k != "path"}


def resolve_drops(trk, snap, tick, tracking_since):
    """Attach tracked paths to pending drops; log each drop once it is resolved."""
    done, keep = [], []
    with STATE.cond:
        pending, SHARED.pending = SHARED.pending, []
    for row, sig, age in pending:
        node_e = row["node"][0] if row["node"] else None
        t, fwd = trk.claim_drop(sig, node_e, snap) if node_e is not None else (None, None)
        if t is not None:
            rec = TR.drop_record(t, fwd, tick, snap, tracking_since)
            upd = {"origin": rec["origin"], "born_tick": rec["born_tick"], "path": rec["path"],
                   "path_len": len(rec["path"])}
        elif age + 1 >= DROP_CLAIM_TICKS:
            upd = {"origin": "none", "path_len": 0}
        else:
            keep.append((row, sig, age + 1))
            continue
        with STATE.cond:
            row.update(upd)
        done.append(row)
    with STATE.cond:
        SHARED.pending = keep + SHARED.pending
    if done:
        log_drops(done)


def log_edit(rec):
    """Every memory edit is appended to logs/edits.jsonl (old and new values), so it can be undone."""
    rec = {"time": datetime.datetime.now().isoformat(timespec="seconds"), "tick": SHARED.tick, **rec}
    path = os.path.join(os.path.dirname(os.path.dirname(HERE)), "logs", "edits.jsonl")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "a", encoding="utf-8") as f:
        f.write(json.dumps(rec) + "\n")
    print("edit:", rec, flush=True)


def publish(payload):
    with STATE.cond:
        STATE.seq += 1
        payload["seq"] = STATE.seq
        STATE.live = json.dumps(payload, separators=(",", ":")).encode()
        STATE.cond.notify_all()


def build(snap):
    nodes = []
    for e, n in snap.items():
        extra = {}
        if "filter" in n:
            extra["filter"] = n["filter"]
        if "hub_dir" in n:
            extra["hub_dir"] = n["hub_dir"]
        if "tester" in n:
            extra["tester"] = n["tester"]
        nodes.append([e, TYPES.index(n["type"]) if n["type"] in TYPES else 7,
                      *[round(v, 2) for v in n.get("pos", (0, 0, 0))],
                      n.get("address"),
                      [[p["peer"], p["peer_port"], p["cable"]] for p in n["ports"]],
                      extra])
    nodes.sort(key=lambda r: r[0])
    sbytes = json.dumps({"types": TYPES, "nodes": nodes}, separators=(",", ":")).encode()
    packets = [[e, p, k, pk["color"], pk["src"], pk["dst"], pk["payload"]]
               for e, n in snap.items() for p, port in enumerate(n["ports"])
               for k, pk in enumerate(port["slots"]) if pk]
    return sbytes, hashlib.md5(sbytes).hexdigest()[:12], packets


def poller():
    net = None
    pending_rev = None   # a topology must be seen in 2 consecutive reads before we publish it
    last_tick = None
    last_read = 0.0
    tick_times = []
    trk, tracking_since = None, None
    while True:
        try:
            if net is None:
                SHARED.net = SHARED.snap = None
                publish({"status": "attaching", "msg": "Scanning game memory (about a minute on first attach)..."})
                net = T.LiveNet.attach(verbose=False)
                last_tick = None
                trk, tracking_since = TR.Tracker(), None
                SHARED.net = net
            tick = net.tick_count()
            now = time.time()
            if tick == last_tick and now - last_read < IDLE_READ_S:
                time.sleep(WATCH_S)
                continue
            ticked = tick != last_tick
            snap = net.snapshot()
            last_read = time.time()
            if not snap:
                raise RuntimeError("empty snapshot")
            SHARED.snap, SHARED.tick = snap, tick
            if ticked:  # follow every packet; then give pending drops their paths
                ended = trk.update(tick, snap)
                if tracking_since is None:
                    tracking_since = STATE.tracking_since = tick + 2
                elif tick > tracking_since:  # skip the first ticks: everything looks "new"
                    account_traffic(trk, snap, tick, ended)
                resolve_drops(trk, snap, tick, tracking_since)
                find_overwrites(trk, snap, tick, ended, tracking_since)
        except SystemExit:
            net = None
            publish({"status": "no_game", "msg": "tunnet.exe is not running"})
            time.sleep(2)
            continue
        except Exception as ex:  # game closed, memory moved, etc. -> re-attach
            net = None
            publish({"status": "error", "msg": f"{type(ex).__name__}: {ex}"})
            time.sleep(2)
            continue

        if ticked and last_tick is not None:
            tick_times = [t for t in tick_times if now - t < 10] + [now]
        last_tick = tick
        sbytes, rev, packets = build(snap)
        # Bevy moves entities between archetype tables (marker components come and go), and
        # our ~40 ms read can miss a node mid-move. Real topology changes persist.
        with STATE.cond:
            if rev != STATE.rev and (rev == pending_rev or not STATE.rev):
                STATE.structure, STATE.rev = sbytes, rev
            pending_rev = rev
            published_rev = STATE.rev
        period = (tick_times[-1] - tick_times[0]) / (len(tick_times) - 1) if len(tick_times) > 2 else None
        with STATE.cond:
            recent = [public(d) for d in list(STATE.drops)[-DROPS_PER_PUBLISH:]]
            drop_total, drop_missed = STATE.drop_total, STATE.drop_missed
            counts = dict(STATE.counts)
        publish({"status": "ok", "pid": net.pid, "rev": published_rev, "tick": tick, "ticked": ticked,
                 "tick_period": period, "read_ms": round((last_read - now) * 1000),
                 "time": now, "packets": packets, "drops": recent, "drop_total": drop_total,
                 "drop_missed": drop_missed, "counts": counts})


class Shared:  # handed between the network poller and the drop watcher
    net = None
    snap = None
    tick = None
    pending = []  # (row, packet signature, ticks waited): drops waiting for their path


SHARED = Shared()
DROP_POLL_S = 0.003


def drop_watcher():
    """Poll Events<PacketDropEvent> every few ms; Bevy clears events after ~2 frames."""
    net, last = None, None
    while True:
        try:
            if SHARED.net is not net:  # (re)attached
                net, last = SHARED.net, None
            if net is None or SHARED.snap is None:
                time.sleep(0.05)
                continue
            new, count = net.drop_events(-1 if last is None else last)
            if last is None:  # start fresh: skip events from before we were watching
                last = count - 1
                continue
            if new:
                missed = new[0]["id"] - (last + 1) + sum(b["id"] - a["id"] - 1 for a, b in zip(new, new[1:]))
                last = new[-1]["id"]
                rows = [enrich_drop(d, SHARED.snap, SHARED.tick) for d in new]
                for r in rows:
                    r["origin"], r["path_len"] = "pending", 0
                with STATE.cond:
                    STATE.drops.extend(rows)
                    STATE.drop_total += len(rows)
                    STATE.drop_missed += max(0, missed)
                    STATE.counts["spam_dropped"] += sum(r["spam"] for r in rows)
                    STATE.counts["legit_dropped"] += sum(not r["spam"] for r in rows)
                    # logged once the poller has attached the packet's path (resolve_drops)
                    SHARED.pending.extend((r, TR.sig_of(d["packet"]), 0) for r, d in zip(rows, new))
            elif count - 1 > last:  # events came and went between two polls
                with STATE.cond:
                    STATE.drop_missed += count - 1 - last
                last = count - 1
        except Exception:
            net = None  # the poller will re-attach; pick it up again
        time.sleep(DROP_POLL_S)


class Handler(SimpleHTTPRequestHandler):
    def __init__(self, *a, **kw):
        super().__init__(*a, directory=HERE, **kw)

    def log_message(self, *a):
        pass

    def _send(self, body, ctype="application/json"):
        self.send_response(200)
        self.send_header("Content-Type", ctype)
        self.send_header("Cache-Control", "no-store")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        url = urlparse(self.path)
        if url.path == "/api/slots":
            out = []
            for k in range(4):
                p = SX.save_path(k)
                if os.path.exists(p):
                    st = os.stat(p)
                    out.append({"slot": k, "size": st.st_size,
                                "modified": datetime.datetime.fromtimestamp(st.st_mtime).isoformat(timespec="minutes")})
                else:
                    out.append({"slot": k, "size": 0, "modified": None})
            return self._send(json.dumps(out).encode())
        if url.path == "/api/live":
            after = int(parse_qs(url.query).get("after", ["-1"])[0])
            with STATE.cond:
                STATE.cond.wait_for(lambda: STATE.seq > after, timeout=LONGPOLL_S)
                body = STATE.live
            return self._send(body)
        if url.path == "/api/structure":
            with STATE.cond:
                body = STATE.structure
            return self._send(body)
        if url.path == "/api/drops":
            with STATE.cond:
                body = json.dumps({"total": STATE.drop_total, "missed": STATE.drop_missed,
                                   "drops": [public(d) for d in STATE.drops]},
                                  separators=(",", ":")).encode()
            return self._send(body)
        if url.path == "/api/traffic":
            e = int(parse_qs(url.query).get("e", ["-1"])[0])
            period = json.loads(STATE.live).get("tick_period") or 0.51
            return self._send(json.dumps(traffic_summary(e, period), separators=(",", ":")).encode())
        if url.path == "/api/drop":
            want = int(parse_qs(url.query).get("id", ["-1"])[0])
            with STATE.cond:
                row = next((d for d in reversed(STATE.drops) if d["id"] == want), None)
                body = json.dumps(row, separators=(",", ":")).encode()
            return self._send(body)
        if url.path == "/":
            self.path = "/index.html"
        return super().do_GET()

    def _reply(self, code, obj):
        body = json.dumps(obj, separators=(",", ":")).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_POST(self):
        """Edits to the running game: tester and filter configs, hub direction, links. EDIT=0 disables.
        /api/sim runs the simulator (no game writes)."""
        url = urlparse(self.path)
        if url.path == "/api/export":
            # Build a save from the live network (+ staged edits) on top of a base save; write
            # it only when "write" is true. EDIT=0 also disables writing saves.
            try:
                req = json.loads(self.rfile.read(int(self.headers.get("Content-Length", "0") or 0)) or b"{}")
                snap = SHARED.snap
                if not snap:
                    return self._reply(503, {"error": "no live snapshot yet"})
                base_slot, slot = int(req.get("base", 0)), int(req.get("slot", 1))
                if not (0 <= base_slot <= 3 and 0 <= slot <= 3):
                    raise ValueError("slots are 0..3")
                base = json.load(open(SX.save_path(base_slot), encoding="utf-8"))
                net = SIM.Net(snap)
                SIM.apply_edits(net, req.get("edits") or [])
                save, report = SX.build(base, snap, net)
                SX.check(save)
                res = {"report": report, "base": base_slot, "slot": slot}
                if req.get("write"):
                    if os.environ.get("EDIT", "1") == "0":
                        return self._reply(403, {"error": "writing is disabled (EDIT=0)"})
                    path, backup = SX.write(save, slot)
                    res.update(written=path, backup=backup)
                    log_edit({"what": "export", "base": base_slot, "slot": slot, "backup": backup,
                              "edits": len(req.get("edits") or []), "from": self.client_address[0]})
                return self._reply(200, res)
            except Exception as ex:
                import traceback
                traceback.print_exc()
                return self._reply(400, {"error": f"{type(ex).__name__}: {ex}"})
        if url.path == "/api/sim":
            try:
                req = json.loads(self.rfile.read(int(self.headers.get("Content-Length", "0") or 0)) or b"{}")
                snap, tick = SHARED.snap, SHARED.tick
                if not snap:
                    return self._reply(503, {"error": "no live snapshot yet"})
                ticks = max(1, min(int(req.get("ticks", 200)), 1000))
                t0 = time.time()
                res = SIM.what_if(snap, tick, req.get("edits") or [], ticks, int(req.get("seed", 1)))
                res["start_tick"], res["seconds"] = tick, round(time.time() - t0, 2)
                return self._reply(200, res)
            except Exception as ex:
                import traceback
                traceback.print_exc()
                return self._reply(400, {"error": f"{type(ex).__name__}: {ex}"})
        if os.environ.get("EDIT", "1") == "0":
            return self._reply(403, {"error": "editing is disabled (EDIT=0)"})
        what = {"/api/tester": "tester", "/api/filter": "filter", "/api/hub": "hub", "/api/link": "link"}.get(url.path)
        if what is None:
            return self._reply(404, {"error": "unknown"})
        try:
            req = json.loads(self.rfile.read(int(self.headers.get("Content-Length", "0") or 0)) or b"{}")
            net = SHARED.net
            if net is None:
                return self._reply(503, {"error": "not attached to the game"})
            if what == "link":
                if req.get("op") == "disconnect":
                    res = net.disconnect(int(req["e"]), int(req["p"]))
                elif req.get("op") == "connect":
                    res = net.connect(int(req["a"][0]), int(req["a"][1]), int(req["b"][0]), int(req["b"][1]))
                else:
                    raise ValueError("op must be connect or disconnect")
                res["op"] = req["op"]
                log_edit({"what": "link", **res, "from": self.client_address[0]})
                return self._reply(200, res)
            fn = {"tester": net.write_tester, "filter": net.write_filter, "hub": net.write_hub}[what]
            res = fn(int(req["e"]), req.get("config") or {}, req.get("expect"))
            log_edit({"what": what, "e": int(req["e"]), **res, "from": self.client_address[0]})
            return self._reply(200, res)
        except (ValueError, KeyError, RuntimeError, OSError) as ex:
            return self._reply(400, {"error": str(ex)})
        except Exception as ex:  # never drop the connection on a bug; say what failed
            import traceback
            traceback.print_exc()
            return self._reply(500, {"error": f"server error: {type(ex).__name__}: {ex}"})


def main():
    port = int(os.environ.get("PORT", "8765"))
    # The drop watcher must run every few ms even while the poller is busy parsing a
    # snapshot; switch threads more often than CPython's 5 ms default.
    sys.setswitchinterval(0.001)
    sys.setrecursionlimit(20000)  # tracker's augmenting-path matching recurses along packet queues
    threading.stack_size(64 * 1024 * 1024)  # ...so give worker threads room for that depth
    threading.Thread(target=poller, daemon=True).start()
    threading.Thread(target=drop_watcher, daemon=True).start()
    class Server(ThreadingHTTPServer):
        daemon_threads = True

        def handle_error(self, request, client_address):
            # A reloaded page abandons its pending long-poll; that's expected, not an error.
            if isinstance(sys.exc_info()[1], (ConnectionAbortedError, ConnectionResetError, BrokenPipeError)):
                return
            super().handle_error(request, client_address)

    # 0.0.0.0 = listen on every network interface, so other devices on the LAN can open
    # the viewer. The server is read-only (it never writes to the game).
    host = os.environ.get("HOST", "0.0.0.0")
    srv = Server((host, port), Handler)
    print(f"Tunnet live viewer on http://127.0.0.1:{port}", flush=True)
    if host == "0.0.0.0":
        import socket
        try:
            ips = sorted({a[4][0] for a in socket.getaddrinfo(socket.gethostname(), None, socket.AF_INET)
                          if not a[4][0].startswith("127.")})
        except OSError:
            ips = []
        for ip in ips:
            print(f"  from other devices: http://{ip}:{port}", flush=True)
    srv.serve_forever()


if __name__ == "__main__":
    main()
