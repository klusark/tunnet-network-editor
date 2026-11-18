# Tunnet Network Editor

View, debug, edit and simulate a [Tunnet](https://store.steampowered.com/app/2286390/Tunnet/) network
without walking around the tunnels.

**Use it online:** https://klusark.github.io/tunnet-network-editor/

Open (or drop) a save file from `%APPDATA%\tunnet\slot_N.json`. It is simulated in your
browser; nothing is uploaded. You can then:

- watch packets move on a map of the whole network (top, side and front views; relay
  chains collapsed into single lines), with pan and zoom on desktop and touch;
- see every dropped packet with the reason and replay its route;
- read each endpoint's send, receive and reply rules;
- edit filters, hubs and testers, rewire connections and plan new relays, filters and hubs;
- compare a what-if run against the unchanged network (deliveries, drops, spam);
- download the result as a save file to load in the game.

This is an unofficial fan tool, not affiliated with the developer of Tunnet. Back up your
own saves before replacing one with an exported file.

## With the game running (Windows)

`python tools/viewer/server.py` serves the same editor at http://localhost:8765 and reads the
running game's memory instead of a save: live packets, the game's own drop events, and edits
written straight into the game (filters, hubs, testers, connections). It also exports saves
into your save folder (backing up the slot first).

## How it works

The simulator (`tools/sim.py`, ported to `tools/viewer/sim.js`) follows the game's network
tick as read from its code, and was checked against the live game tick by tick; the two
implementations produce identical results. `NOTES.md` documents the reverse engineering:
memory layouts, the tick model, node rules, the endpoint send and reply tables, and the save
format.

Endpoint send schedules were read from the game at one story stage
("DestroyCorruptedMainframe"); saves at other stages may send somewhat differently.
