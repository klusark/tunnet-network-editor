# Tunnet live network — reverse-engineering notes

Game: Steam `tunnet.exe` (Aug 8 2025 build), Rust + vendored Bevy ~0.7, 64-bit.
All findings below are from reading live memory of the running game (slot 0 loaded),
via the read-only scripts in `tools/`. Heap addresses change every run; structure
layouts and the method to find them do not.

## Process
- Steam launches TWO `tunnet.exe`: a ~160 MB launcher and the real game (~1.5 GB).
  Attach to the one with the most private memory (`memscan.find_pid` does this).

## Bevy component registry (`Components.components: Vec<ComponentInfo>`)
- Record stride 0x50. Fields (qwords): +0x00 drop fn, +0x08 storage/flags,
  +0x10 id, +0x18 layout.size, +0x20 layout.align, +0x28 Some(1), +0x30 TypeId,
  +0x38 name cap, +0x40 name ptr, +0x48 name len.
- Find it by locating the heap string `tunnet::net::transport::NetNode` and a
  pointer to it followed by len 0x1f; record start = pointer - 0x40.
- 554 components/resources registered. Relevant ids (this build):
  - 0x115 `tunnet::net::transport::NetNode` — 24 B (a Vec)
  - 0x0cc `GlobalTransform` — 48 B align 16 (quat, translation, scale)
  - 0x12d Relay, 0x132 Hub, 0x134 Endpoint, 0x13a Filter, 0x15e Bridge, 0x14e Antenna (markers)
  - 0x118 HubDirection (1 B), 0x139 FilterConfig (24 B), 0x119 TesterConfig (16 B),
    0x150 Tester (56 B), 0x133 proto::Address (5 B), 0x135 Infection (1 B),
    0x14c AntennaInbound (24 B), 0x14f AntennaOutbound (12 B), 0x197 Cable (1 B, colour)
  - 0x99 `State<NetworkState>` — just a run/pause state, NOT the network data.

## Tables (`Tables.tables: Vec<Table>`, stride 0x60)
Table = 4 Vecs of {cap, ptr, len}: dense `Vec<Column>`, indices `Vec<ComponentId>`,
sparse array, entities `Vec<Entity>`. Tables are contiguous; walk ±0x60 from any one.
Entity as u64 = generation (low u32) | index (high u32).

## Table columns (`Column`, stride 0x58, contiguous per table)
qwords: +0x00 component id, +0x08 ticks cap, +0x10 ticks ptr, +0x18 ticks len,
+0x20 item size, +0x28 item align, +0x30 capacity, +0x38 len (rows),
+0x40 data ptr, +0x48 swap scratch, +0x50 drop fn.
- Several tables per node type (one per archetype). Slot 0: 1206 nodes =
  934 relays, 96 hubs, 100 filters, 69 endpoints, 4 bridges, 2 antennas, 1 tester.
- Cables are separate entities (1 per edge) with only render data + `Cable` (colour);
  they do NOT hold the wiring.

## NetNode = Vec<Port>, Port = 0x98 bytes  (confirmed from `connect_nodes`)
Vec header {cap, ptr, len}; len = port count (endpoint 1, relay 2, hub 3).
Port index = the save file's edge port number (verified 1197/1197 edges).
| off  | field |
|------|-------|
| 0x00 | INBOUND packet: Option<Packet> (0x40) — just arrived over this port's cable |
| 0x40 | OUTBOUND packet: Option<Packet> (0x40) — leaving over this port's cable |
| 0x80 | u32 tag: 1 = connected |
| 0x84 | peer node Entity (u32 generation, u32 index) — 0x80..0x8b is Option<Entity> peer |
| 0x8c | u32 tag: 1 = has cable — 0x8c..0x97 is Option<Entity> cable |
| 0x90 | cable Entity (u32 generation, u32 index) |
The peer's port is not stored: find the peer port that points back (same cable).
Code: `connect_nodes` body FUN_1403adfc0 (auto-connects within 6.0 units with line
of sight, picks the first port whose +0x80 != 1).

Packet slot (64 B):
| off  | field |
|------|-------|
| 0x00 | colour: &'static str ptr (6 hex chars, e.g. "28ccdf") |
| 0x08 | colour len (6) |
| 0x10 | u64, 0..8 — unknown (hop count / priority?) |
| 0x18 | payload Vec cap |
| 0x20 | payload ptr (ASCII text: "PING", "Track #1", "Join us!") |
| 0x28 | payload len |
| 0x30 | src Address: 4 element bytes + address_type byte |
| 0x35 | dst Address |
| 0x3a | u8 flag "bounce budget applies" (0/1); **2 = None (empty slot)** via niche |
| 0x3b | u8 flag "never bounce": dropped at a wrong endpoint (Token, TOP SECRET, CONFIDENTIAL, supply requests, some replies) |
| 0x3c | u8 flag, meaning unknown (rare) |
The u64 at 0x10 is a bounce budget: each bounce off a wrong endpoint subtracts the 0x3a flag
(so only flagged packets count down); at 1 the packet is dropped instead.
Address element bytes: 0 = Wildcard?, 1 = "0", 2 = "1", 3 = "2", 4 = "3"
(i.e. Zero=1 … Three=4 — off by one from the save's names).

Slot semantics measured over 9 ticks: outbound(X:p) -> inbound(peer:pp) 3951 times
across cables; inbound(X:p) -> outbound(X:q) 2914 times within nodes. The payload heap pointer is NOT a stable packet id (packets are
copied per hop and freed memory reused).

## Network tick
- Resource `Events<NetTockEvent>` (component id 0x97, 80 B) lives in a 1-row Column
  outside the Tables. Its first u64 (event_count) increments once per network tick,
  at the END of the tick (after port writes): ~0.51 s per tick (~1.9 Hz).
- Watching those 8 bytes every 5 ms and reading the network once right after each
  bump gives one consistent read per tick (no half-written state). The viewer does this.
- Snapshots taken across a tick boundary show half-written state; earlier "3 ticks/s"
  estimates were inflated by that.
- Tick model (from the code, verified live; this replaces the earlier "packets wait"
  theory, which came from IN slots not being cleared after a node copies them):
  1. transport FUN_14074aa00: clear EVERY inbound slot; every outbound packet on a
     connected port moves to the peer port's inbound slot (the first peer port whose peer
     is the sender); outbound on an unconnected port -> drop event flag 0. Outbound slots
     are always emptied. Verified: IN(t+1) == peer OUT(t) on 17052/17052 ports.
  2. node systems, once per tick (they run when an Events<NetTockEvent> is pending):
     each copies inbound -> outbound by its rules and OVERWRITES the outbound slot; the
     inbound slot is left (the next transport clears it).
  So every packet crosses exactly one cable and one node per tick; nothing ever waits.
- Packet +0x10 is not speed: constant per packet, occasionally decrements by 1;
  value 8 correlates with blocked packets. Meaning still unknown.

## Dropped packets
- Resource `Events<tunnet::particle::PacketDropEvent>` (id 0xb9). All 223 resources
  are 1-row Columns stored contiguously; walk ±0x58 from the NetTockEvent column.
- Events<T> (80 B): +0x00 event_count, +0x08 a_start, +0x10 b_start, +0x18 Vec A
  {cap, ptr, len}, +0x30 Vec B, +0x48 state. Events live ~2 frames, so poll every few ms.
- EventInstance (0x58 B): +0x00 Packet (same 0x40 layout as port slots), +0x40 world
  pos f32x3, +0x4c u8 flag, +0x50 u64 event id (sequential).
- The game writes events into the buffer BEFORE bumping event_count, so never use
  event_count as an upper bound on ids (that bug lost ~40% of drops).
- Classification by nearest node (all drops so far are exactly at a node):
  filter + flag 1 = filter rule (~78%); relay + flag 0 = probably a collision (~11%,
  unconfirmed); endpoint + flag 1 (~11%), rule from the game's code below.
- Endpoint rule (endpoint::update body FUN_1402f5840; vtable PTR_14241ea18, run_unsafe
  FUN_1405b8160). For a packet in an endpoint's inbound slot:
    src == me and dst != me            -> drop ("returned to sender")
    dst != me and flag 0x3b            -> drop ("no-bounce" packet)
    dst != me and flag 0x3a and x == 1 -> drop (bounce budget used up)
    dst != me otherwise                -> BOUNCE back out the same port, x -= flag 0x3a
  Verified live: 67/67 endpoint drops in 40 s matched (61 no-bounce, 6 returned).
- SILENT LOSS: the bounce writes into the outbound slot WITHOUT checking it is empty
  (Rust assignment drops the old value), so a packet waiting there (e.g. just sent) is
  destroyed with NO drop event. Verified live: 11 packets vanished from endpoint outbound
  slots with no event, all on ticks when that endpoint bounced, 0 otherwise. The server
  synthesises these as drops (negative ids, reason "overwritten by a bounce").
- All PacketDropEvent senders (callers of Events<PacketDropEvent>::send FUN_140516d40):
    FUN_1402f5840 endpoint::update  flag 1  (rules above)
    FUN_1404f3a90 filter (src/net/filter.rs)  flag 1
    FUN_14074aa00 transport tick  flag 0: outbound packet on a port whose connection
                  tag (+0x80) != 1, i.e. no cable. Verified: 92/92 flag-0 relay drops
                  were at relays with an unconnected port (dead-end wires), not collisions.
    FUN_1403a7a00 antenna (src/net/antenna.rs)  flag 0
    FUN_14044eae0 tester (src/net/tester.rs)
    FUN_1404f0910 debug "Dummy packet" spawner  flag 0
  Endpoints mostly bounce misaddressed packets (~9.7k bounces vs ~5.7k drops in one log).
  Earlier "wrong address" labels in logs/drops.jsonl were wrong.
- Server logs every drop to `logs/drops.jsonl`; 0 missed over 30 s / 475 drops.

## Packet tracking and drop replays (tools/tracker.py)
- No stable packet id in memory, so each tick every packet is matched to its previous
  position by content (colour, src, dst, payload) within the movement rule (<= 1 cable
  crossing, <= 3 steps per tick). Identical packets queue on the same wires (PING floods),
  so sources are chosen with a maximum bipartite matching (augmenting paths, nearest
  candidates first); greedy matching stranded queue-mates (~16 false breaks/tick).
- ~14 ms per tick for ~1400 packets. Real ambiguity (two equally good identical sources)
  ~2-3% of moves.
- New tracks per tick: ~11 at endpoints (genuine sends), ~1.5 at bridges (packets
  entering from the off-map network behind the bridge; bridges are ordinary 2-port
  nodes, not wireless), ~12 at relays (unexplained breaks: the same content often sits
  in BOTH the inbound and outbound slot of one port, and the 0/1 state byte does not
  mark which copy is live).
- Antennas copy: when a packet leaves antenna B, the same packet is usually still in
  partner antenna A's inbound slot. Tracker forks A's history onto the new track.
- Filters often leave a dropped packet's data in their slot, so its track never ends;
  drops fall back to a live identical packet at the drop node.
- Drop routes (60 s live test, packets sent after tracking began): ~61% complete from
  the sending endpoint (first endpoint's address == packet src in 612/612 checked),
  ~13% complete from a bridge, ~25% partial (tracking lost it earlier). Every route
  ends at the node where the game reported the drop. A longer server run showed 58% /
  10% / 32%.
- Server: tracker runs per tick; drops wait up to 4 ticks for their route, then are
  logged to logs/drops.jsonl WITH the route; `/api/drop?id=N` serves one route.
- Viewer: click a drop to replay its route (amber line, start ring, drop cross, dashed
  antenna hops), with play/pause/step/seek/speed and a hop list.

## Send patterns (tools/send_patterns.py, 3 min / 354 ticks / 4329 sends; re/send_patterns.json)
- Regular endpoints send on a CLOCK: period P is a power of two (2, 4, 8, 32, 64, 128,
  256 ticks) and a fixed phase, sending when tick % P == phase (e.g. 0.1.0.0 PING:
  tick % 8 == 3). Longer gaps are multiples of P: a send is skipped when the outbound
  slot is still busy.
- Each endpoint has a fixed small destination set (often 1) and a themed message set:
  supply requests (0.1.2.2, 0.2.2.2, 0.3.2.2 -> CONFIDENTIAL / ammunition / rations),
  church broadcasts (0.2.0.0 -> 63 destinations), music tracks (0.2.0.3, 0.3.0.3),
  search (0.1.0.1 <-> 0.1.2.0), finance (0.3.3.2), tx pairs (0.1.3.0 <-> 0.1.3.2,
  0.3.3.0 <-> 0.3.3.2, 0.2.3.0 <-> 0.2.3.2), status reports, sales (period 64-128).
- Token ring: 0.3.0.0 -> 2.1.2.0 -> 2.1.2.3 -> 2.1.2.1 -> 2.1.2.2 -> 0.3.0.0, each every
  4 ticks at phases 0/3/3/1/2 (0.3.0.0 has a Payment component).
- Bridges inject traffic from the off-map network (incl. replies), 45-88 sends/min.
- Infected endpoints (0.0.1.1, 0.2.1.3) send spam at random times to random addresses.
- Replies ("Re:") are generated when a packet is received (1.1.1.0, 1.2.1.0 ...).

## Hubs (hub::update: vtable PTR_14240b230, run FUN_1405f69e0, body FUN_140179ef0)
- Each frame, for each hub, three moves via FUN_1401d42e0(ports, n, from, to):
    dir == 0 (false): 0->1, 1->2, 2->0   (to the NEXT port)
    dir == 1 (true):  0->2, 2->1, 1->0   (to the PREVIOUS port)
  Measured agrees (8664 vs 289/222 for dir 0; 865 vs 121/108 for dir 1; the rest are
  tracker mismatches on identical packets).
- FUN_1401d42e0 copies inbound[from] into outbound[to] WITHOUT checking outbound[to] is
  empty (the old packet is freed, no drop event) and does NOT clear inbound[from]
  (explains duplicate content in IN and OUT). Viewer logs these silent losses as
  "overwritten at a hub" (14 in 45 s).

## Endpoint packet generator (FUN_1402f9a40, called from endpoint::update)
- Signature ~ generate(out_packet, story/rng, endpoint_address, tick). A big hard-coded
  match on the endpoint's 4 address digits (raw 1..4) and the tick: period/phase tests
  (e.g. 0.0.0.0: skip odd ticks; every 32 ticks a mainframe broadcast; else one of
  "Firmware update"/"Test"/"Contribute to science"/"[PATCH] Fix netcode" to
  0.0.((tick/8)%4).((tick/2)%4)), destination formulas from the tick, message picked
  at random from a per-endpoint list (FUN_140673b40). Colour = hash of the source address
  digits mod 22 into the colour table at PTR_DAT_142424270.
- EXACT TABLE: instead of hand-translating, the generator is run in Ghidra's emulator
  (tools/ghidra/EmuEndpointGen.java) for every endpoint address x tick 0..2047 (8191 for
  the three 2048-cycle sales endpoints), with stubs for alloc/free, thread_rng, choose
  (records the whole message list), gen_range, String::from, format! and panics; the
  live Story resource and the heap blocks it points to are loaded at their real
  addresses. tools/build_endpoint_table.py -> re/endpoint_rules.json (cycle + per-tick
  slots: dst, message list, colour, no_bounce, bounce_budget).
- Verified (tools/verify_endpoint_rules.py, 90 s): 1376/1377 live generator sends match
  slot, destination, message and colour; the 1 miss is a reply. Tick passed to the
  generator == our NetTockEvent counter (offset 0).
- Story dependence: rules read Story +0x1c4 (stage, 14 now) and a byte list at
  Story +0x28/+0x30 (e.g. id 61 switches 0.1.2.1/0.2.2.1 from "spare screws" to "Online
  CNC Machining Service"). Re-extract after story progress: dump story.bin +
  story_heap.bin (see this session), rerun EmuEndpointGen in Ghidra, rebuild the table.
- Cycles: 4 (Token 0.3.0.0), 6 (supply endpoints, 3 messages), 8, 16, 32, 96
  (0.0.0.0), 128, 256 (church), 2048 (sales, CNC).
- Replies are decoded separately, see "Endpoint replies" below. 3.0.0.0 (final boss)
  panics in emulation (builds generated text); unknown.
- Correction: the earlier "0.1.0.0 sends PING every 8 ticks" was wrong; those PINGs come
  from the tester (address 0.0.1.2 -> 0.2.1.1) bouncing off 0.1.0.0. 0.1.0.0 itself sends
  TOP SECRET / CONFIDENTIAL / Emergency Announcement (cycle 128).

## Endpoint replies (receive path of endpoint::update FUN_1402f5840; tools/reply_rules.py)
Ghidra's decompile of this region is corrupt (mis-decoded jump table), so this was read
from the disassembly (re/reply_region.asm, 0x1402f6900-0x1402f7700).
- Dispatch at 0x1402f6913 when an inbound packet is addressed to the endpoint. EDI =
  story[+0x1c5] (boss phase). Jump table 0x1402f99c4 on the endpoint's first digit:
  0 -> 0x1402f69d5, 1 -> 0x1402f6cd5, 2 -> 0x1402f6b43, 3 -> 0x1402f6bed.
- Common writer 0x1402f74f5 puts the reply in the receiving port's OUTBOUND slot
  (+0x40..+0x7c). Defaults: dst = request src, colour = request colour.
- Rules (x = the receiver's own 2nd digit):
  | receiver | condition | reply |
  |---|---|---|
  | 0.x.3.0 | from 0.x.3.2 | "BLK " + request text, to sender (budget 1) |
  | 0.x.2.0 | text == "Search query" | "Search result", to sender |
  | 0.x.1.1 | from 0.x.3.2 (INVEST NOW!) | "I wanna buy {random} crypto coins", to sender |
  | 0.0.3.1 | text == "GET /catalog" | catalogue (0x1402f9427, not read) |
  | 1.x.1.0 | any | "Re: " + request text, to sender, bounce budget 4 |
  | 2.1.2.0 / .3 / .1 / .2 | any (Token ring) | Token to 2.1.2.3 / 2.1.2.1 / 2.1.2.2 / 0.3.0.0 (last one colour ffaeb6), no-bounce |
  | 3.0.1.0..3 | boss phase (EDI==1), from the next in chain (.1/.2/.3/3.0.0.0) | "Fw: " + text |
  | any | text == "PING" | "PONG", to sender |
- Verified live (tools/reply_probe3.py, 120 s): the reply is in the outbound slot in the
  same snapshot the request sits in the inbound slot, so it costs no tick. BLK, Search
  result, Re:, crypto and all four Token hops matched every time; 0 unexplained replies.
  Catalogue, boss and PING were not exercised. Endpoints not in the table never reply.
- A delivery does NOT destroy a packet already waiting in the endpoint's outbound slot
  (713/713 left normally, tools/reply_probe2.py), despite the no-reply path writing None.
- Token forwards KEEP the original src (0.3.0.0) on every hop (verified live); other
  replies use the replying endpoint as src.
- Receive rules per endpoint (viewer panel, RR.incoming): every scheduled send addressed
  to the endpoint from re/endpoint_rules.json, plus replies the game makes to them,
  followed through chains (Token ring), with the rate, flags and this endpoint's own
  reply. Boss rules are left out. Bridge/tester traffic isn't in the send tables.
- Pitfall: the request stays visible in the inbound slot during the tick of its reply,
  so the tracker sees it "stay" and ends it a tick later; pairing via tracks gives fake
  1-7 tick delays and mismatched texts (tools/reply_probe.py is superseded).

## Editing (first write support): tester settings
- TesterConfig (16 B), matched against the save (testers[].config) and tester::update
  (FUN_14044eae0, switch on +4):
  +0 i32 freq | +4 u8 mode (0 Single, 1 Repeat, 2 Spoof, 3 Snoop; names at 0x14243ab50)
  | +5 address: 4 digit bytes + type (0 Endpoint, 1 Filter, 2 UnrestrictedFilter)
  | +10 destination: same | +15 padding.
  - Single: PING on the in-game Send button, logs PONG from destination.
  - Repeat: when tick % freq == 0 sends PING (src = address) to FUN_1406b6400(destination,
    tick / freq), which steps wildcard digits through every match. freq < 1 is reset to 1.
  - Spoof: logs packets whose dst matches address. Snoop: logs packets address -> destination.
- LiveNet.write_tester(entity, cfg, expect): re-locates the column, refuses if memory no
  longer equals `expect`, writes 16 bytes with a separate write handle, reads back.
  Server: POST /api/tester {e, config, expect}; every edit appended to logs/edits.jsonl
  with old/new values and client IP. EDIT=0 env disables writes. The viewer shows an
  edit form above the info panel for testers, with Undo.
- Verified live: freq 1 -> 4 made the tester PING exactly every 4 ticks; restored to 1.
  The game's own tester screen isn't refreshed (no Bevy change detection on our write);
  whether an in-game save keeps the edit is not checked yet.

## Editing filters and hubs
- Same read-check-write-verify path (LiveNet._write_component): write_filter (24 B
  FilterConfig, padding bytes kept), write_hub (1 B HubDirection). POST /api/filter,
  /api/hub. Viewer: one form for tester/filter/hub with a live preview of the filter rule.
- All 100 filters round-trip byte-exactly through decode/encode.
- Verified live: hub 428 dir 1 -> same-tick copies 0->2 and 1->0; flipped to 0 -> 0->1 and
  1->2; restored. Filter 7022 action SendBack -> Drop: drops at it went from ~3 in 4 ticks
  to every tick (ticks 35830-35850); restored.

## Editing connections (LiveNet.disconnect / connect, POST /api/link)
- Transport (FUN_14074aa00) uses only the peer field: it looks up the peer entity and
  writes into the FIRST port on it whose peer is the sender. The cable field isn't read
  there. Free ports have tag 0 at +0x80 and +0x8c (rest is garbage).
- disconnect: clears the peer tag on both ports; cable fields kept so it can be restored.
- connect: both ports must be free; refuses a second link between the same two nodes
  (delivery would be ambiguous). Writes entity then tag. A port with no cable borrows the
  other port's cable entity, so nothing points at a missing cable; refuses if neither has
  one. The game's cable meshes don't move.
- Verified live: disconnect + reconnect; swap A-B, C-D -> A-D, C-B carried 22/23 packets
  over the new links in 17 ticks, swapped back; full rewire + undo through the viewer.
  Game kept running. Not tested: saving in the game after rewiring (saves backed up in
  backups/, which git ignores). Node removal next to a rewired link is also untested.
- Viewer: per-port connect… / rewire… / disconnect buttons; pick the other node on the map,
  then its free port; Undo. A failed step in a rewire puts back the steps already done.

## Simulator (tools/sim.py)
- Node rules: relay FUN_1402fc350 (0->1, 1->0, copy+overwrite); hub by HubDirection;
  filter (see Config components); endpoint (receive/reply/bounce/drop, then the exact
  generator table, then spam); bridge FUN_1406b6bb0: first digit of src/dst swaps 0<->1;
  new dst first digit '1' or '*' -> bounce limit (6 if 2nd digit '3'/'*', else 4), else
  limit removed and no-bounce if 2nd digit '1'/'*'; written only if the far port is
  connected. Antenna: outputs what its partner antenna received this tick. Address match
  FUN_1406b6550: per digit, mask '*' matches anything, else equal; type byte ignored.
- Endpoint details found by validation: no scheduled send on a tick the endpoint
  received a packet addressed to it; infected endpoints (proto::Infection == 5) spam a
  random 0.R.x.x address only when nothing else is sent (rate 0.26 for 0.0.1.1, 0.11 for
  0.2.1.3 per free tick). The x field (+0x10) only matters while flag 0x3a is set.
- Validation: tools/sim_validate.py (one tick, real inputs) -> 0 mismatches outside spam
  over 30 ticks, all fields incl. bounce flags; tools/sim_run_check.py (free-running from
  one snapshot) -> 100% of non-spam packets in the right slot after 25 ticks; drops per
  node type match the game's drop events (filters 161/161, relays 42/41).
- Not validated: tester Repeat (tester was in Single mode; wildcard order guessed),
  catalogue/boss replies, payload text where the game picks randomly.
- What-if: sim.what_if(snapshot, tick, edits, ticks, seed) runs baseline and edited
  network with per-(seed, node, tick) randomness; POST /api/sim; viewer "What-if
  simulator" panel ("Try in simulator" on editors, or route port edits there).

## Planned nodes and save export (tools/save_export.py, POST /api/export, GET /api/slots)
- Save network format: nodes [{pos, up, angle}]; edges [[[a,port],[b,port],kind]]
  (kind 0..3, meaning unknown, maybe cable style; new edges use 0; every edge in slot 0
  is <= 6.0 units, the auto-connect range); relays {node, fixed, light}; filters {node,
  config{port, mask{elements, address_type}, addr, action DropPacket/SendBackPacket, op,
  collision}, fixed}; hubs {node, fixed, dir}; testers {node, config{address,
  destination, mode, freq}}; endpoints {node, address, infection, disinfection};
  antennas/bridges {node}. Digits: Zero/One/Two/Three/Wildcard.
- Live -> save matching: same type within 0.05 units. Game-owned nodes (endpoints,
  antennas, bridges, testers) missing from the live game (not loaded) are kept with their
  links; missing relays/filters/hubs count as removed by the player.
- Orientation: up = rotation * Y matches the save exactly. Save `angle` = my twist angle
  + a constant per up direction, learned from matched nodes. Planned nodes copy the
  up/angle of the node they were placed next to.
- Export = base save with the network sections rebuilt from the live network + staged
  edits; other sections copied unchanged. Writing backs up the target slot to backups/.
  Checked on a scratch copy: all 1206 base nodes and all non-network sections identical,
  new filter + link appended. NOT yet tested: loading an exported save in the game.
- Simulator: edits {"kind": "add", "id": -n, "type", "pos", "like", "config"} and
  {"kind": "remove", "e"}. Viewer: "Add node…" places a planned node with a tap
  (height and orientation from the nearest node on screen); staged edits are drawn on
  the map (planned nodes have a dashed ring); links to planned nodes always go to the
  simulator.

## Offline editor (no game): save importer + JavaScript simulator
- tools/save_import.py: save -> snapshot-shaped network (entity = save node index,
  empty packet slots). `python tools/save_import.py slot_0.json 200` simulates a save.
- tools/viewer/sim.js: JavaScript port of sim.py + importSave/exportSave. sim.py and
  sim.js share a mulberry32 PRNG seeded per (seed, node, tick); a 100-tick run of slot 0
  gives IDENTICAL state fingerprints every tick in both (checking this found that the
  Python tester rule had never been attached to Net; fixed). JS export of an unedited
  import reproduces the save (same nodes, type lists, other sections; same edge set).
- tools/viewer/sim_data.json (tools/build_sim_data.py): send table, reply rules,
  per-endpoint receive/reply rules, spam rates, and the story stage the send table was
  read at (DestroyCorruptedMainframe); other stages may send differently (warned).
- tools/viewer/offline.js: an in-page backend answering the viewer's /api/... requests
  from the simulator (live, structure, drops with exact replay paths, traffic, edits,
  links, what-if, export as a download). Used when no server answers (static hosting, or
  ?offline), or after "Open save file" / dropping a save on the page. Speed 1-25x, pause,
  step. A 52 MB save imports in ~1.1 s; what-if 300 ticks ~0.4 s.
- Tested on a plain static server: load, ticking, traffic panel, filter edit, replay,
  added hub + link, what-if, export download (correct name and contents).
- Hosting: needs only index.html, sim.js, offline.js, sim_data.json on any static host.
  A claude.ai artifact would need changes (downloads and confirm() are blocked there).

## Network generator (tools/netgen.py, tools/netopt.py, tools/flows.py)
- Requirements (flows.py): every scheduled flow (sender, destination) plus replies and the
  Token ring. Delivered = reaches the endpoint with that address (bridges turn 0.y.1.0
  into 1.y.1.0; bridge y is the one 10.3 units from endpoint 1.y.1.0). 0.0.2.0-3 have
  no endpoint (undeliverable). Spam should be dropped.
- Baseline, the player's current network (slot 0, imported, 2000 ticks): 40.5% of legit
  packets delivered, 75/262 flows always delivered.
- Design: address tree. Each prefix group has a spine of hubs (legs 0 up, 1 child, 2
  down) ending in a REFLECTOR (Match *.*.*.* SendBack, other side unconnected, so it
  can't collide); each child sits behind a child filter (Differ <child>, SendBack); the
  group's top filter (Match <group>, SendBack) turns back packets that belong inside;
  Drop filters at the top remove packets for digits with no child (else they circle).
  Root: dead-address drops + reflector. Stage 1 is logical: no relays, rough positions.
- Losses are almost all FILTER COLLISIONS: a filter that sends a packet back and passes
  one from its other side in the same tick must lose one (a hub is a bijection, so two
  streams can only merge at a filter). Bare leaves (endpoint straight on the hub, it
  bounces wrong packets and skips its own send that tick) avoid leaf collisions but drop
  no-bounce packets at wrong endpoints and lower throughput.
- Results (1000 ticks): first tree 38-43%; + spine reflectors 56.5%; bare leaves 61.7%
  rate but fewer packets delivered (busy bare endpoints skip their own sends, so some
  flows were never even sent).
- Spam guards: infected endpoints have no scheduled sends (only replies), so a Drop
  filter in front of each (filtered side facing it) drops what it sends except to its
  reply target (0.0.1.1 -> 0.0.3.2 allowed; 0.2.1.3 everything). Spam delivered 880 -> ~20.
- netopt.py hill-climbs per-group spine direction, child order, bare/filtered leaves and
  collision modes. Score = 1000 x flows delivered at least once + packets delivered
  - 5 x spam delivered. Best (300 evaluations, 2100 ticks; tools/netgen_best_cfg.json):
  221/253 required flows delivered at least once (9 are impossible: 0.0.2.x), 12905
  packets (55.8%), 21 spam through. Player's network over the same run: 104 flows,
  ~9300 packets. 304 nodes: 92 hubs, 130 filters, no relays yet.
- Shortcuts (Gen.shortcuts, user's idea): one-way bypass from part A to part B. Exit tap
  at A: hub (legs 0 part, 1 shortcut, 2 parent, dir 0) + filter (Differ <B>, SendBack):
  A's outgoing packets for B take the shortcut, the rest bounce to the parent. Entry tap
  at B: hub (0 part, 1 parent, 2 shortcut, dir 0) + filter (Match <B>, SendBack,
  collision SendBackOutbound): parent packets bounce into B, shortcut arrivals pass in;
  on a collision the shortcut packet goes back and takes the tree route.
  Region/cluster shortcuts carried traffic but didn't help: the losses are at the
  endpoints' own merge points ("returned to sender" = a leaf collision bouncing an
  endpoint's packet back to it). Endpoint-to-endpoint shortcuts for the heaviest flows
  avoid those merges: +38% packets with the 12 heaviest.
- Objective changed to mean per-flow delivery ratio over all 253 required flows (unsent
  = 0): robust to rare flows, unlike "delivered at least once". Score = 40000 x mean +
  packets - 5 x spam delivered.
- Best (tools/netgen_best_cfg.json, 9 shortcuts, 2100 ticks): mean flow delivery 75.5%,
  18449 packets (71.0%), 18 spam through. Tree-only best: 72.0%, 12827. Player's
  current network: 33.7%, 9357.
- Relays (Gen.relay_spacing; split links into cables <= N units): relays do NOT buffer.
  Transport moves every packet every tick and a relay copies its input straight to its
  output, so a relay only adds one tick of travel. Measured with the tuned best network:
  spacing 12/6/3 dropped mean flow delivery to 44/42/45% (filter collisions 1707 ->
  3085: packets stay longer on spines and loops, so merge points see more traffic, and
  the per-group settings were tuned for relay-free timing). Re-tuned with relays every 6
  (200 evaluations, tools/netgen_relays6_cfg.json): 71.0% mean flow, 17129 packets
  (relay-free: 75.5%, 18449). Relay counts depend on the rough positions for now.

## Direct wiring (tools/directgen.py, user's idea)
- A dedicated line for every (sender, destination) pair, from the send table + replies
  (replies to 0.y.1.0 computed as 1.y.1.0's, across the bridge; Token ring followed hop
  by hop; self-addressed flows included: 1.3.1.0 answers its own "Re:" endlessly).
- Per endpoint: SPLITTER hub (0 endpoint, 1 out, 2 in, dir 0). Out line -> SPLIT CHAIN:
  per destination a hub (0 in, 1 filter, 2 onward, dir 0) + filter Differ <dest>
  SendBack; that destination's packets pass onto its line; the end of the chain drops
  everything left (spam, missing addresses). Split taps never collide. In line <- MERGE
  CHAIN: per extra incoming line a hub (0 toward endpoint, 1 upstream, 2 line, dir 0) +
  filter Match <me> SendBack (collision DropOutbound); the farthest line joins directly.
  Bounce-limited and heavy flows go first in split chains and nearest the endpoint in
  merge chains (each filter they pass costs a bounce-limited packet one bounce).
- Result (slot 0, 2100 ticks): 275 lines, 555 hubs + 532 filters; mean flow delivery
  78.6%, 22394 packets (91.6% of those sent), all spam dropped, nothing reaches a wrong
  endpoint. Remaining losses: merge collisions (1819), bounce limits (159). Tree +
  shortcuts: 75.5%, 18449; player's network: 33.7%, 9357. Some rare flows are never
  sent at all: an endpoint skips its scheduled send on a tick it receives a packet.
- With relays every 6 units (--relay-spacing 6, the default; 5795 relays along straight
  lines between the rough positions): 82.1% mean flow delivery, 23714 packets, 216 flows
  covered (no relays: 78.6%, 22394, 205). More merge collisions (2653 vs 1819), but more
  packets get sent: arrivals are spread out in time, so endpoints less often receive on
  their scheduled send tick and skip the send.
- TTL (bounce-limited) flows first: all 159 TTL losses came from 0.2.0.0, which has 15
  TTL destinations (budgets 5-8); in a linear split chain the k-th line costs k filter
  hits. Split chains now order TTL lines first by lowest budget; a sender whose linear
  chain would put a TTL line past its budget gets a split TREE (one filter per cluster
  a.b.c.*, then one per endpoint in it); TTL lines also join merge chains nearest the
  endpoint. Generated networks leave the old tester out (Gen.keep_testers).
  Result (relays every 6): 83.2% mean flow delivery, 219 flows covered, 23746 packets,
  zero TTL losses (was 82.1%, 216, 23714, 159 TTL losses).

## Map voxels in the save (digging)
- save["chunks"]: 4527 entries [{x,y,z}, rle]; rle = [[count, value], ...] covering 32^3
  voxels. Chunk = 16 world units, voxel = 0.5 units: voxel = floor(world * 2), chunk =
  voxel // 32, index inside a chunk = (z * 32 + y) * 32 + x (x fastest). Checked with node
  positions: 0.75 units off each node's wall (along `up`) is value 0 for 1187/1206 nodes.
- Value 0 = air; other values are materials (1 most common, then 43, 6, 18, 16, 8, 7, 15).
  Which materials the game lets you dig is not known yet.
- Chunk coords x -5..42, y -5..3, z -2..22; 4527 of the ~10800 possible chunks are
  stored (the rest are presumably generated when needed). save["chunk_types"]: 97 prefab
  BunkerRoom chunks (rooms with their endpoints).
- Not tested: whether the game accepts edited chunk data in a save.

## Config components
- HubDirection (1 B): 1 = save `dir: true`, 0 = false (96/96 hubs).
- FilterConfig (24 B), verified 100/100 filters against the save on every field:
  +0x00 u64 port (filtered port); +0x08 mask digits x4 (0 = wildcard, 1..4 = "0".."3");
  +0x0c mask type (0 Endpoint, 1 Filter, 2 UnrestrictedFilter); +0x0d collision
  (0 DropInbound, 1 DropOutbound, 2 SendBackOutbound); +0x0e address (0 Src, 1 Dst);
  +0x0f action (0 SendBack, 1 Drop); +0x10 op (0 Differ, 1 Match).
- Filter behaviour (filter code FUN_1404f3a90): packet arriving on the filtered port:
  bounce-limited packets lose 1 (dropped at 1); if (op Match ? addr matches mask :
  addr differs) -> action (Drop, or SendBack out the same port; if that outbound is busy
  one packet is dropped); else pass to the other port. Packet arriving on the other port
  passes to the filtered port; if that outbound is busy: DropInbound = the waiting
  outbound packet is dropped and replaced, DropOutbound = the arriving packet is dropped,
  SendBackOutbound = the arriving packet goes back out its own port.
- Spam (endpoint::update): infected endpoints, when their outbound slot is free and an
  RNG roll passes, send one of 14 hard-coded subjects ("Totally n0t a v1rus", "Free
  credits! $$$", ...) to a random address, ALWAYS colour a93b3b; no other packet uses
  that colour, so colour == a93b3b identifies spam. Viewer counts spam sent / dropped
  (good) / delivered (bad).

## Reader quirk
Bevy moves entities between archetype tables at runtime (marker components come
and go), so a ~40 ms snapshot occasionally misses a few nodes. The viewer only
accepts a topology after two identical snapshots in a row.

## Reader
`tools/tunnet_live.py` finds the registry and tables (~60 s memory scan, cached per
game pid in %TEMP%) and returns a full snapshot: per node entity, type, position,
address, ports (peer, peer_port, cable, both packet slots).

## Code locations (this build)
- PlayerSave serializer FUN_1404a81c0; save/load system FUN_140665240 (src/save.rs).
- NetBuildingPlugin::build FUN_1404352d0 (registers build systems + vtables).
- connect_nodes: system vtable PTR_14242fc90, run_unsafe FUN_1405e4000,
  body FUN_1403adfc0.

## Viewer
`python tools/viewer/server.py` → http://127.0.0.1:8765 . Tick-synced: reads once per
network tick, browser long-polls `/api/live?after=seq`. "Collapse relay chains" (on by
default) draws each run of relays as one line between the non-relay nodes it joins
(slot 0: 149 chains hide 924 of 934 relays; longest is 104 relays). Positions on a
chain line are spaced by cable count, so they read as ticks. Loose wires and dead ends
keep their free end relay visible with a red dot. Map with
top/side/front views, height filter, address search, click a node for its ports
and packets.

## Still unknown
- Meaning of packet +0x10 and the 0/1 state byte; the always-1 u32 at port +0x8c.
- Rarer FilterConfig values.
- Whether the save serializer derives `nodes`/`edges` from Transform + NetNode
  ports (if so, memory edits followed by an in-game save persist).

## Ghidra
The old `~/ghidra/tunnet` project (pre-Aug-2025 analysis) was deleted on 2026-11-17.
`~/ghidra/tunnet.gpr` + `tunnet.rep` now hold a fresh headless analysis of the
current Steam exe (finished 2026-11-17, ~38 min, analysis + save succeeded).
Log: `ghidra-headless.log` in this folder.
Headless tip: `analyzeHeadless.bat` breaks on paths with parentheses
(`Program Files (x86)`), so import a copy of the exe from a plain path.
