"""Turn the emulated endpoint generator runs (re/gen_a.jsonl, re/gen_b.jsonl, produced by
tools/ghidra/EmuEndpointGen.java running FUN_1402f9a40 for every endpoint address x tick)
into an exact per-address rules table: re/endpoint_rules.json.

For each address: the cycle length after which its behaviour repeats, and for each tick
in the cycle what it sends (destination, possible messages, flags, colour, bounce budget).
"""
import json
import os
import re
import struct
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Tunnet\tunnet.exe"
D = {0: "*", 1: "0", 2: "1", 3: "2", 4: "3"}

exe = open(EXE, "rb").read()


def rd(va, n):
    """Read n bytes of the exe at a virtual address (.rdata / .data only)."""
    for vbase, vsize, raw in ((0x2404000, 0x2ED82C0, 0x2403000), (0x2400000, 0x3DA0, 0x23FE600)):
        rva = va - 0x140000000
        if vbase <= rva < vbase + vsize:
            o = rva - vbase + raw
            return exe[o:o + n]
    return None


def fmt_template(note):
    """format:<6 qwords of core::fmt::Arguments> -> template text with {} for each argument."""
    qs = [int(x, 16) for x in note.split(":", 1)[1].split(",")]
    # Find a (ptr, len) pair pointing at an array of &str pieces in the exe.
    for i in range(len(qs) - 1):
        p, n = qs[i], qs[i + 1]
        if 0x140000000 <= p < 0x146000000 and 0 < n <= 8:
            raw = rd(p, 16 * n)
            if not raw:
                continue
            pieces = []
            ok = True
            for k in range(n):
                sp, sl = struct.unpack_from("<QQ", raw, 16 * k)
                s = rd(sp, sl) if 0x140000000 <= sp < 0x146000000 and sl < 200 else None
                if s is None:
                    ok = False
                    break
                pieces.append(s.decode("utf-8", "replace"))
            if ok:
                return "{}".join(pieces) if len(pieces) > 1 else pieces[0] + "{}"
    return "{formatted}"


def addr(b):
    return ".".join(D.get(x, "?") for x in b[:4])


def entry(r):
    if not r.get("send"):
        return None
    choices = None
    template = None
    rng = None
    for n in r["notes"]:
        if n.startswith("choose:["):
            choices = n[len("choose:["):-1].split("|")
        elif n.startswith("format:"):
            template = fmt_template(n)
        elif n.startswith("range:"):
            rng = n[len("range:"):]
    msgs = choices if choices else ([template] if template else [r["payload"]])
    if template and choices:  # a formatted message chosen from a list
        msgs = [template if c == "{formatted}" else c for c in choices]
    e = {"dst": addr(r["dst"]), "messages": msgs, "color": r["color"]}
    if r["f3b"]:
        e["no_bounce"] = True
    if r["f3a"] == 1:
        e["bounce_budget"] = r["budget"]
    if rng:
        e["random_number"] = rng
    if any(n == "strbuild" for n in r["notes"]):
        e["generated_text"] = True
    return e


def main():
    rows = defaultdict(dict)
    errors = Counter()
    for f in ("gen_a.jsonl", "gen_b.jsonl", "gen_c.jsonl"):  # gen_c: long-cycle endpoints, 8192 ticks
        if not os.path.exists(os.path.join(ROOT, "re", f)):
            continue
        for line in open(os.path.join(ROOT, "re", f), encoding="utf-8"):
            r = json.loads(line)
            if r.get("error"):
                errors[r["error"]] += 1
            rows[r["addr"]][r["tick"]] = entry(r)
    table = {}
    for a, by_tick in sorted(rows.items()):
        n = max(by_tick) + 1
        key = lambda e: None if e is None else (e["dst"], tuple(e["messages"]), e.get("no_bounce"), e.get("bounce_budget"))
        keys = [key(by_tick[t]) for t in range(n)]
        # Smallest repeat length of ANY size: some endpoints cycle through 3 messages
        # (period 3 x 2^k), so the cycle is not always a power of two.
        cycle = next((L for L in range(1, n // 2 + 1) if keys[L:] == keys[:-L]), None)
        if cycle is None:  # no full repeat inside the emulated window
            cycle = n
        slots = {t: by_tick[t] for t in range(cycle) if by_tick[t] is not None}
        colors = {e["color"] for e in slots.values()}
        table[a] = {"cycle": cycle, "sends_per_cycle": len(slots),
                    "color": colors.pop() if len(colors) == 1 else sorted(colors),
                    "slots": {str(t): e for t, e in slots.items()}}
    out = os.path.join(ROOT, "re", "endpoint_rules.json")
    json.dump({"source": "FUN_1402f9a40 emulated in Ghidra, story state from live game",
               "ticks_emulated": 2048, "errors": dict(errors), "endpoints": table}, open(out, "w"), indent=1)
    print("errors:", dict(errors) or "none", "->", out)
    for a, t in table.items():
        dsts = Counter(e["dst"] for e in t["slots"].values())
        msgs = Counter(m for e in t["slots"].values() for m in e["messages"])
        extra = []
        if any(e.get("no_bounce") for e in t["slots"].values()):
            extra.append("no-bounce")
        b = {e.get("bounce_budget") for e in t["slots"].values()} - {None}
        if b:
            extra.append(f"budget {sorted(b)}")
        print(f"{a:8} cycle {t['cycle']:4} sends {t['sends_per_cycle']:4}  colour {t['color']}  "
              f"dst {len(dsts)} {list(dsts)[:3]}  msgs {list(msgs)[:3]} {' '.join(extra)}")


if __name__ == "__main__":
    sys.exit(main())
