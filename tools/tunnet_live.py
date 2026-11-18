"""Read the live Tunnet network (nodes, wiring, packets) from a running tunnet.exe.

Read-only. Layouts are documented in NOTES.md. Usage:

    python tunnet_live.py            # locate structures, print a summary + a few nodes
    python tunnet_live.py --json f   # also write a full snapshot to f

As a module:
    net = LiveNet.attach()           # slow first time (scans memory), cached per pid
    snap = net.snapshot()            # fast: re-reads only the tables
"""
import json
import os
import struct
import sys
import tempfile

import memscan as M

NETNODE = "tunnet::net::transport::NetNode"
GLOBAL_TRANSFORM = "bevy_transform::components::global_transform::GlobalTransform"
TYPE_MARKERS = {  # marker component -> node type
    "tunnet::net::relay::Relay": "relay",
    "tunnet::net::hub::Hub": "hub",
    "tunnet::net::endpoint::Endpoint": "endpoint",
    "tunnet::net::filter::Filter": "filter",
    "tunnet::net::bridge::Bridge": "bridge",
    "tunnet::net::antenna::Antenna": "antenna",
    "tunnet::net::tester::Tester": "tester",
}
TOCK_EVENTS = "bevy_ecs::event::Events<tunnet::net::transport::NetTockEvent>"
DROP_EVENTS = "bevy_ecs::event::Events<tunnet::particle::PacketDropEvent>"
DROP_SIZE = 0x58   # EventInstance<PacketDropEvent>: Packet (0x40), pos f32x3, flag u8 @0x4c, event id u64 @0x50
ADDRESS = "tunnet::net::proto::Address"
HUB_DIR = "tunnet::net::hub::HubDirection"
FILTER_CONFIG = "tunnet::net::filter::FilterConfig"
# FilterConfig (24 B), verified 100/100 against the save; behaviour from filter code FUN_1404f3a90
MASK_TYPE = {0: "Endpoint", 1: "Filter", 2: "UnrestrictedFilter"}
COLLISION = {0: "DropInbound", 1: "DropOutbound", 2: "SendBackOutbound"}
FILTER_ADDR = {0: "Src", 1: "Dst"}
FILTER_ACTION = {0: "SendBack", 1: "Drop"}
FILTER_OP = {0: "Differ", 1: "Match"}
TESTER_CONFIG = "tunnet::net::tester::TesterConfig"
TESTER_SIZE = 16
# TesterConfig (16 B), from the save (slot_0.json testers[].config) and tester::update
# (FUN_14044eae0, switch on +4): +0 i32 freq (Repeat: send every freq ticks, <1 reset to 1),
# +4 u8 mode, +5 address (4 digits + type), +10 destination (4 digits + type), +15 padding.
TESTER_MODE = {0: "Single", 1: "Repeat", 2: "Spoof", 3: "Snoop"}


def decode_filter(b):
    return {"port": struct.unpack_from("<Q", b, 0)[0], "mask": fmt_addr(b[8:12]),
            "mask_type": MASK_TYPE.get(b[0xC], b[0xC]), "collision": COLLISION.get(b[0xD], b[0xD]),
            "addr": FILTER_ADDR.get(b[0xE], b[0xE]), "action": FILTER_ACTION.get(b[0xF], b[0xF]),
            "op": FILTER_OP.get(b[0x10], b[0x10])}

def decode_tester(b):
    return {"freq": struct.unpack_from("<i", b, 0)[0], "mode": TESTER_MODE.get(b[4], b[4]),
            "address": fmt_addr(b[5:9]), "address_type": MASK_TYPE.get(b[9], b[9]),
            "destination": fmt_addr(b[10:14]), "destination_type": MASK_TYPE.get(b[14], b[14])}


def _enc_addr(text, typ):
    rev = {v: k for k, v in DIGIT.items()}
    parts = text.split(".")
    if len(parts) != 4 or any(p not in rev for p in parts):
        raise ValueError(f"bad address {text!r}: four digits 0-3 or *, e.g. 0.2.1.1")
    t = {v: k for k, v in MASK_TYPE.items()}.get(typ)
    if t is None:
        raise ValueError(f"bad address type {typ!r}")
    return bytes(rev[p] for p in parts) + bytes([t])


def encode_tester(cfg, old):
    """New 16 bytes from a decoded config dict; keys missing from cfg keep their old value."""
    cur = decode_tester(old)
    cur.update({k: v for k, v in cfg.items() if v is not None})
    freq = int(cur["freq"])
    if not 1 <= freq <= 100000:
        raise ValueError("freq must be 1..100000 ticks")
    mode = {v: k for k, v in TESTER_MODE.items()}.get(cur["mode"])
    if mode is None:
        raise ValueError(f"bad mode {cur['mode']!r}")
    return (struct.pack("<iB", freq, mode) + _enc_addr(cur["address"], cur["address_type"])
            + _enc_addr(cur["destination"], cur["destination_type"]) + old[15:16])


COMP_REC = 0x50   # ComponentInfo stride
COL_SIZE = 0x58   # Column stride; fields below are qword indexes
C_ID, C_ISIZE, C_IALIGN, C_LEN, C_DATA, C_DROP = 0, 4, 5, 7, 8, 10
TABLE_SIZE = 0x60  # Table: dense Vec<Column>, indices Vec<ComponentId>, sparse, entities Vec<Entity>
PORT_SIZE = 0x98   # NetNode port: 2 x Option<Packet> (0x40 each) + connection
INBOUND, OUTBOUND = 0, 1  # packet slot order within a port (measured from tick-to-tick movement)
DIGIT = {1: "0", 2: "1", 3: "2", 4: "3", 0: "*"}


def is_code(v):
    return 0x7FF000000000 <= v <= 0x7FFFFFFFFFFF


def fmt_addr(b):
    return ".".join(DIGIT.get(x, "?") for x in b[:4])


class LiveNet:
    def __init__(self, pid, h, cbase, ncomp, tables_start, ntables, tock=0, res_start=0, nres=0):
        self.pid, self.h = pid, h
        self.cbase, self.ncomp = cbase, ncomp
        self.tables_start, self.ntables = tables_start, ntables
        self.tock = tock  # address of Events<NetTockEvent>; its first u64 counts network ticks
        # Resources are 1-row Columns stored contiguously (the resource archetype's columns).
        self.res_start, self.nres = res_start, nres
        self.names = {i: self._cname(i) for i in range(ncomp)}
        self.by_name = {n: i for i, n in self.names.items()}

    # ---------- low level ----------
    def q(self, addr, n=1):
        return struct.unpack(f"<{n}Q", M.read(self.h, addr, 8 * n))

    def _cname(self, cid):
        f = self.q(self.cbase + cid * COMP_REC, 10)
        return M.read(self.h, f[8], min(f[9], 300)).decode(errors="replace")

    def comp_layout(self, cid):
        f = self.q(self.cbase + cid * COMP_REC, 10)
        return f[3], f[4]

    # ---------- discovery (slow, cached) ----------
    @classmethod
    def attach(cls, verbose=True):
        pid, h = M.find_pid()
        cache = os.path.join(tempfile.gettempdir(), f"tunnet_live_{pid}.json")
        if os.path.exists(cache):
            c = json.load(open(cache))
            net = cls(pid, h, c["cbase"], c["ncomp"], c["tables_start"], c["ntables"], c.get("tock", 0),
                      c.get("res_start", 0), c.get("nres", 0))
            if net._tables_ok() and net._tock_ok() and net.nres:
                return net
        if verbose:
            print("scanning game memory (first attach for this game process)...", file=sys.stderr)
        chunks = [(b, M.read(h, b, s)) for b, s in M.regions(h) if s <= 512 << 20]
        cbase, ncomp = cls._find_registry(h, chunks)
        net = cls(pid, h, cbase, ncomp, 0, 0)
        net._find_tables(chunks)
        net._find_tock(chunks)
        json.dump({"cbase": net.cbase, "ncomp": net.ncomp, "tables_start": net.tables_start,
                   "ntables": net.ntables, "tock": net.tock, "res_start": net.res_start,
                   "nres": net.nres}, open(cache, "w"))
        return net

    def _find_tock(self, chunks):
        """Locate the Events<NetTockEvent> resource (a 1-row Column outside the tables)."""
        cid = self.by_name[TOCK_EVENTS]
        size, align = self.comp_layout(cid)
        for base, d in chunks:
            n = len(d) // 8
            qv = memoryview(d)[: n * 8].cast("Q")
            for i in range(n - 11):
                if qv[i] == cid and qv[i + 4] == size and qv[i + 5] == align and qv[i + 7] == 1 \
                        and is_code(qv[i + 10]):
                    self.tock = qv[i + 8]
                    col = base + i * 8
                    first = last = col  # neighbours are the other resources
                    while self._col_ok(first - COL_SIZE):
                        first -= COL_SIZE
                    while self._col_ok(last + COL_SIZE):
                        last += COL_SIZE
                    self.res_start, self.nres = first, (last - first) // COL_SIZE + 1
                    return
        raise RuntimeError("Events<NetTockEvent> resource not found")

    def resource(self, name):
        """Data address of a resource (e.g. an Events<...> queue), or None."""
        cid = self.by_name.get(name)
        for k in range(self.nres):
            c = self.q(self.res_start + k * COL_SIZE, 11)
            if c[C_ID] == cid:
                return c[C_DATA]
        return None

    def drop_events(self, after_id=-1):
        """PacketDropEvents with event id > after_id, oldest first.

        Bevy keeps events for ~2 frames (double buffer), so call this every few ms.
        Returns (events, event_count). Each event: id, packet, pos, flag.
        """
        if not getattr(self, "_drop_addr", None):
            self._drop_addr = self.resource(DROP_EVENTS)
        f = self.q(self._drop_addr, 10)  # event_count, a_start, b_start, Vec A, Vec B, state
        out = []
        # Don't trust event_count as an upper bound: the game pushes events into the
        # buffers before it bumps the count, so a read can see events with id >= count.
        for cap, ptr, ln in ((f[3], f[4], f[5]), (f[6], f[7], f[8])):
            if not 0 < ln <= cap < 1 << 16:
                continue
            raw = M.read(self.h, ptr, ln * DROP_SIZE)
            for i in range(len(raw) // DROP_SIZE):
                s = raw[i * DROP_SIZE:(i + 1) * DROP_SIZE]
                eid = struct.unpack_from("<Q", s, 0x50)[0]
                if eid <= after_id or eid > f[0] + 100000:
                    continue
                pk = self._packet(s[:0x40])
                if pk:
                    out.append({"id": eid, "packet": pk, "pos": list(struct.unpack_from("<3f", s, 0x40)),
                                "flag": s[0x4C]})
        out.sort(key=lambda d: d["id"])
        return out, max(f[0], out[-1]["id"] + 1 if out else 0)

    def _tock_ok(self):
        if not self.tock:
            return False
        try:
            a, b, c = self.q(self.tock, 3)  # event_count + the two buffer start counts
        except struct.error:
            return False
        return a >= b and a >= c and a - min(b, c) < 16

    def tick_count(self):
        """Network tick counter (NetTockEvent event_count). Bumps at the end of each tick."""
        return self.q(self.tock)[0]

    @staticmethod
    def _find_registry(h, chunks):
        nb = NETNODE.encode()
        locs = []
        for base, d in chunks:
            o = d.find(nb)
            while o != -1:
                if d[o + len(nb): o + len(nb) + 1] not in (b"_", b":", b"<") and not d[o + len(nb): o + len(nb) + 1].isalnum():
                    locs.append(base + o)
                o = d.find(nb, o + 1)
        want = {struct.pack("<QQ", a, len(nb)) for a in locs}
        for base, d in chunks:
            for w in want:
                o = d.find(w)
                while o != -1:
                    rec = base + o - 0x40
                    cid = struct.unpack_from("<Q", d, o - 0x30)[0]
                    size, align = struct.unpack_from("<QQ", d, o - 0x28)
                    if (size, align) == (24, 8) and cid < 4096:
                        cbase = rec - cid * COMP_REC
                        n = 0
                        while True:  # count records whose id field matches their index
                            f = struct.unpack("<3Q", M.read(h, cbase + n * COMP_REC, 24))
                            if f[2] != n:
                                break
                            n += 1
                        if n > cid:
                            return cbase, n
                    o = d.find(w, o + 1)
        raise RuntimeError("component registry not found")

    def _col_ok(self, a):
        try:
            c = self.q(a, 11)
        except struct.error:
            return False
        return c[C_ID] < self.ncomp and c[C_IALIGN] in (1, 2, 4, 8, 16) and is_code(c[C_DROP]) \
            and (c[C_ISIZE], c[C_IALIGN]) == self.comp_layout(c[C_ID])

    def _table_ok(self, t):
        try:
            f = self.q(t, 12)
        except struct.error:
            return False
        dcap, dptr, dlen, icap, iptr, ilen, _, _, _, ecap, eptr, elen = f
        if not (0 <= dlen <= dcap < 4096 and dlen == ilen and elen <= ecap < 1 << 24):
            return False
        if dlen == 0:
            return True
        return self._col_ok(dptr)

    def _tables_ok(self):
        return self.ntables > 0 and self._table_ok(self.tables_start)

    def _find_tables(self, chunks):
        nn = self.by_name[NETNODE]
        # 1) any Column of NetNode (component id, item layout 24/8, code ptr for drop)
        col = None
        for base, d in chunks:
            n = len(d) // 8
            qv = memoryview(d)[: n * 8].cast("Q")
            for i in range(n - 11):
                if qv[i] == nn and qv[i + 4] == 24 and qv[i + 5] == 8 and is_code(qv[i + 10]):
                    col = base + i * 8
                    break
            if col:
                break
        if not col:
            raise RuntimeError("no NetNode column found")
        # 2) walk back to the start of that table's column array
        start = col
        while self._col_ok(start - COL_SIZE):
            start -= COL_SIZE
        # 3) the Table record holds a pointer to that array
        table = None
        ptr = struct.pack("<Q", start)
        for base, d in chunks:
            o = d.find(ptr)
            while o != -1:
                if o >= 8 and self._table_ok(base + o - 8):
                    table = base + o - 8
                    break
                o = d.find(ptr, o + 1)
            if table:
                break
        if not table:
            raise RuntimeError("Table record not found")
        # 4) tables are contiguous in Tables.tables: walk both ways
        first = table
        while self._table_ok(first - TABLE_SIZE):
            first -= TABLE_SIZE
        last = table
        while self._table_ok(last + TABLE_SIZE):
            last += TABLE_SIZE
        self.tables_start, self.ntables = first, (last - first) // TABLE_SIZE + 1

    # ---------- snapshot (fast) ----------
    def tables(self):
        for t in range(self.ntables):
            rec = self.tables_start + t * TABLE_SIZE
            f = self.q(rec, 12)
            cols = {}
            for k in range(f[2]):
                c = self.q(f[1] + k * COL_SIZE, 11)
                cols[c[C_ID]] = (c[C_DATA], c[C_ISIZE], c[C_LEN])
            ents = struct.unpack(f"<{f[11]}Q", M.read(self.h, f[10], 8 * f[11])) if f[11] else ()
            yield rec, cols, [e >> 32 for e in ents]

    def _tester_slot(self, entity):
        tc = self.by_name[TESTER_CONFIG]
        for rec, cols, ents in self.tables():
            if tc in cols and entity in ents:
                return cols[tc][0] + TESTER_SIZE * ents.index(entity)
        raise KeyError(f"entity {entity} has no TesterConfig")

    def write_tester(self, entity, cfg, expect=None):
        """Edit one tester's config in the running game. cfg: any of freq, mode, address,
        address_type, destination, destination_type. If `expect` (the decoded config the
        caller last saw) is given and memory no longer matches it, nothing is written."""
        addr = self._tester_slot(entity)
        old = M.read(self.h, addr, TESTER_SIZE)
        if len(old) != TESTER_SIZE:
            raise OSError("could not read the tester config")
        if expect is not None and decode_tester(old) != expect:
            raise RuntimeError("tester config changed in the game since it was read; reload and retry")
        new = encode_tester(cfg, old)
        if new != old:
            if not getattr(self, "hw", None):
                self.hw = M.open_writer(self.pid)
            M.write(self.hw, addr, new)
        back = M.read(self.h, addr, TESTER_SIZE)
        if back != new:
            raise OSError("write did not stick (read back differs)")
        return {"old": decode_tester(old), "new": decode_tester(back)}

    def _packet(self, s):
        if s[0x3A] == 2:  # Option::None niche
            return None
        cptr, clen, x, pcap, pptr, plen = struct.unpack_from("<6Q", s, 0)
        color = M.read(self.h, cptr, min(clen, 16)).decode(errors="replace") if is_code(cptr) or cptr > 0x10000 else ""
        payload = M.read(self.h, pptr, min(plen, 256)) if plen else b""
        # From endpoint::update (FUN_1402f5840): +0x10 is a bounce budget, decremented on each
        # bounce off a wrong endpoint when flag 0x3a is set (drop when it reaches 1); a set
        # 0x3b flag means "drop instead of bouncing". 0x3c meaning unknown.
        return {"id": pptr, "color": color, "src": fmt_addr(s[0x30:0x35]), "dst": fmt_addr(s[0x35:0x3A]),
                "payload": payload.decode("utf-8", errors="replace"), "x": x, "state": s[0x3A],
                "f3b": s[0x3B], "f3c": s[0x3C]}

    def snapshot(self):
        nn = self.by_name[NETNODE]
        gt = self.by_name[GLOBAL_TRANSFORM]
        markers = {self.by_name[n]: t for n, t in TYPE_MARKERS.items() if n in self.by_name}
        addr_c = self.by_name.get(ADDRESS)
        fc_c = self.by_name.get(FILTER_CONFIG)
        hub_c = self.by_name.get(HUB_DIR)
        tc_c = self.by_name.get(TESTER_CONFIG)
        nodes = {}
        for rec, cols, ents in self.tables():
            if nn not in cols or not ents:
                continue
            kind = next((t for c, t in markers.items() if c in cols), "other")
            nn_data = M.read(self.h, cols[nn][0], 24 * len(ents))
            pos_data = M.read(self.h, cols[gt][0], 48 * len(ents)) if gt in cols else None
            adr_data = M.read(self.h, cols[addr_c][0], 5 * len(ents)) if addr_c in cols else None
            fc_data = M.read(self.h, cols[fc_c][0], 24 * len(ents)) if fc_c in cols else None
            hub_data = M.read(self.h, cols[hub_c][0], len(ents)) if hub_c in cols else None
            tc_data = M.read(self.h, cols[tc_c][0], TESTER_SIZE * len(ents)) if tc_c in cols else None
            if len(nn_data) < 24 * len(ents):
                continue  # table moved/reallocated mid-read; next snapshot will catch it
            for r, e in enumerate(ents):
                cap, ptr, ln = struct.unpack_from("<3Q", nn_data, 24 * r)
                # The game mutates these while we read (no lock), so tolerate torn reads.
                raw = M.read(self.h, ptr, PORT_SIZE * ln) if 0 < ln < 16 else b""
                ports = []
                for p in range(len(raw) // PORT_SIZE):
                    s = raw[PORT_SIZE * p: PORT_SIZE * (p + 1)]
                    w = struct.unpack_from("<6I", s, 0x80)
                    ports.append({
                        "peer": w[2] if w[0] == 1 else None,
                        "cable": w[5] if w[0] == 1 else None,
                        "slots": [self._packet(s[0:0x40]), self._packet(s[0x40:0x80])],
                    })
                node = {"entity": e, "type": kind, "ports": ports}
                if pos_data:
                    node["pos"] = list(struct.unpack_from("<3f", pos_data, 48 * r + 16))
                if adr_data:
                    node["address"] = fmt_addr(adr_data[5 * r: 5 * r + 5])
                if fc_data and len(fc_data) >= 24 * (r + 1):
                    node["filter"] = decode_filter(fc_data[24 * r: 24 * r + 24])
                if tc_data and len(tc_data) >= TESTER_SIZE * (r + 1):
                    node["tester"] = decode_tester(tc_data[TESTER_SIZE * r: TESTER_SIZE * (r + 1)])
                if hub_data and len(hub_data) > r:
                    node["hub_dir"] = hub_data[r]  # matches the save's `dir` bool
                nodes[e] = node
        # resolve the peer's port index by finding the port that points back
        for e, n in nodes.items():
            for p in n["ports"]:
                peer = nodes.get(p["peer"])
                p["peer_port"] = next((k for k, q in enumerate(peer["ports"]) if q["peer"] == e
                                       and q["cable"] == p["cable"]), None) if peer else None
        return nodes


def main():
    net = LiveNet.attach()
    snap = net.snapshot()
    from collections import Counter
    kinds = Counter(n["type"] for n in snap.values())
    ports = sum(len(n["ports"]) for n in snap.values())
    wired = sum(1 for n in snap.values() for p in n["ports"] if p["peer"] is not None)
    unresolved = sum(1 for n in snap.values() for p in n["ports"] if p["peer"] is not None and p["peer"] not in snap)
    pkts = sum(1 for n in snap.values() for p in n["ports"] for s in p["slots"] if s)
    print(f"pid {net.pid}: {len(snap)} nodes {dict(kinds)}")
    print(f"ports {ports}, wired {wired}, peers not found among nodes {unresolved}, packets in flight {pkts}")
    for n in list(snap.values())[:3]:
        print(json.dumps(n)[:400])
    if "--json" in sys.argv:
        out = sys.argv[sys.argv.index("--json") + 1]
        json.dump(snap, open(out, "w"), indent=1)
        print("wrote", out)


if __name__ == "__main__":
    main()
