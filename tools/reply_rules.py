"""Endpoint reply rules, read from the receive path of endpoint::update (FUN_1402f5840).

When a packet ADDRESSED TO an endpoint arrives, the game dispatches on the receiving
endpoint's address digits (jump table at 0x1402f99c4 on the first digit) and may write a
reply into that endpoint's OUTBOUND slot. Defaults (common writer at 0x1402f74f5):
reply goes to the delivered packet's source, in the delivered packet's colour.

Verified live (tools/reply_probe3.py): the reply is in the outbound slot in the SAME tick
the request sits in the inbound slot, so a reply costs no extra tick. Every observed reply
matched a rule (BLK, Search result, Re:, crypto, all four Token hops); catalog, boss and
PING were not exercised. A delivery never destroyed a packet already waiting in the
endpoint's outbound slot (713 cases, tools/reply_probe2.py).

Addresses use x for "any digit, must equal the receiver's own second digit".
"""
import re

RULES = [
    # (receiver pattern, condition, reply text, destination, extra)
    {"receiver": "0.x.3.0", "when": "sender is 0.x.3.2 (its transaction partner)", "match_src": "0.x.3.2",
     "reply": "BLK {received text}", "to": "sender", "code": "0x1402f6a01",
     "example": "TX 3e524b8d -> BLK TX 3e524b8d"},
    {"receiver": "0.x.2.0", "when": 'text is exactly "Search query"', "match_text": "Search query",
     "reply": "Search result", "to": "sender", "code": "0x1402f6df2"},
    {"receiver": "0.x.1.1", "when": "sender is 0.x.3.2 (its INVEST NOW! ads)", "match_src": "0.x.3.2",
     "reply": "I wanna buy {random number} crypto coins", "to": "sender", "code": "0x1402f6eea"},
    {"receiver": "0.0.3.1", "when": 'text is exactly "GET /catalog"', "match_text": "GET /catalog",
     "reply": "the shop catalogue", "to": "sender", "code": "0x1402f748e"},
    {"receiver": "1.x.1.0", "when": "any packet",
     "reply": "Re: {received text}", "to": "sender", "bounce_budget": 4, "code": "0x1402f6cd5"},
    {"receiver": "2.1.2.0", "when": "any packet (Token ring)", "reply": "Token", "to": "2.1.2.3",
     "no_bounce": True, "keep_src": True, "code": "0x1402f6b72"},
    {"receiver": "2.1.2.3", "when": "any packet (Token ring)", "reply": "Token", "to": "2.1.2.1",
     "no_bounce": True, "keep_src": True, "code": "0x1402f707b"},
    {"receiver": "2.1.2.1", "when": "any packet (Token ring)", "reply": "Token", "to": "2.1.2.2",
     "no_bounce": True, "keep_src": True, "code": "0x1402f7208"},
    {"receiver": "2.1.2.2", "when": "any packet (Token ring)", "reply": "Token", "to": "0.3.0.0",
     "no_bounce": True, "keep_src": True, "color": "ffaeb6", "code": "0x1402f6fc3"},
    {"receiver": "3.0.1.0", "boss": True, "when": "final boss phase only; sender is 3.0.1.1",
     "reply": "Fw: {received text}", "to": "see code", "code": "0x1402f6c1c"},
    {"receiver": "3.0.1.1", "boss": True, "when": "final boss phase only; sender is 3.0.1.2",
     "reply": "Fw: {received text}", "to": "see code", "code": "0x1402f7383"},
    {"receiver": "3.0.1.2", "boss": True, "when": "final boss phase only; sender is 3.0.1.3",
     "reply": "Fw: {received text}", "to": "see code", "code": "0x1402f70f6"},
    {"receiver": "3.0.1.3", "boss": True, "when": "final boss phase only; sender is 3.0.0.0",
     "reply": "Fw: {received text}", "to": "see code", "code": "0x1402f72d1"},
    {"receiver": "*.*.*.*", "when": 'text is exactly "PING"', "match_text": "PING", "reply": "PONG", "to": "sender",
     "code": "PING/PONG check in endpoint::update"},
]


def _pattern(receiver, address):
    """Does `address` match a receiver pattern like 0.x.3.0? Returns the x digit or True."""
    p, a = receiver.split("."), address.split(".")
    x = None
    for pd, ad in zip(p, a):
        if pd == "*":
            continue
        if pd == "x":
            x = ad
            continue
        if pd != ad:
            return None
    return x if x is not None else True


def rules_for(address):
    """Reply rules that apply to an endpoint, with x filled in."""
    out = []
    for r in RULES:
        m = _pattern(r["receiver"], address)
        if m is None:
            continue
        rr = dict(r)
        if isinstance(m, str):
            rr["when"] = r["when"].replace("0.x.", f"0.{m}.")
        out.append(rr)
    return out


def explains(receiver, request, reply):
    """Is (request -> reply) at `receiver` explained by a rule? request/reply: (src, dst, text)."""
    for r in rules_for(receiver):
        text = r["reply"]
        pat = "^" + re.escape(text).replace(re.escape("{received text}"), re.escape(request[2])) \
                                   .replace(re.escape("{random number}"), r"\d+") + "$"
        if text == "the shop catalogue":
            pat = ".*"
        if re.match(pat, reply[2]):
            return r
    return None


def _fill(pat, x):
    return pat.replace("x", x) if x else pat


def reply_to(receiver, src, text, color=None):
    """The reply `receiver` makes to a packet (src, text), or None. Boss rules are skipped."""
    for r in rules_for(receiver):
        if r.get("boss"):
            continue
        x = receiver.split(".")[1]
        if "match_src" in r and src != _fill(r["match_src"], x):
            continue
        if "match_text" in r and text != r["match_text"]:
            continue
        if r["reply"] == "the shop catalogue":
            body = "(shop catalogue)"
        else:
            body = r["reply"].replace("{received text}", text).replace("{random number}", "{n}")
        return {"src": src if r.get("keep_src") else receiver, "sent_by": receiver, "dst": src if r["to"] == "sender" else r["to"], "text": body,
                "color": r.get("color", color), "no_bounce": r.get("no_bounce", False),
                "bounce_budget": r.get("bounce_budget"), "rule": r["receiver"]}
    return None


def incoming(address, gen):
    """What arrives addressed to `address`: scheduled sends from other endpoints plus the
    replies the game makes to them (followed through reply chains such as the Token ring).
    gen: re/endpoint_rules.json "endpoints". Returns [{from, messages, per_cycle, cycle, kind, ...}]."""
    flows = []   # (src, dst, text, rate_per_tick, cycle, per_cycle, kind, color, no_bounce, budget, via)
    for s_addr, r in gen.items():
        per = {}
        for slot in r["slots"].values():
            for m in slot["messages"]:
                k = (slot["dst"], m)
                per[k] = per.get(k, [0, slot])
                per[k][0] += 1 / len(slot["messages"])
        for (dst, m), (n, slot) in per.items():
            flows.append((s_addr, dst, m, n / r["cycle"], r["cycle"], n, "scheduled", slot.get("color", r["color"]),
                          slot.get("no_bounce", False), slot.get("bounce_budget"), None, s_addr))
    frontier = list(flows)
    for _ in range(6):   # follow replies to replies (Token ring is 4 hops)
        nxt = []
        for f in frontier:
            rep = reply_to(f[1], f[0], f[2], f[7])
            if rep:
                nxt.append((rep["src"], rep["dst"], rep["text"], f[3], f[4], f[5], "reply", rep["color"],
                            rep["no_bounce"], rep["bounce_budget"], f[11], rep["sent_by"]))
        flows += nxt
        frontier = nxt
        if not nxt:
            break
    out = {}
    for f in flows:
        if f[1] != address:
            continue
        key = (f[0], f[6], f[11])
        o = out.setdefault(key, {"from": f[0], "sent_by": f[11], "kind": f[6], "messages": [], "rate": 0.0,
                                 "color": f[7], "no_bounce": False, "bounce_budgets": set(), "reply_to": f[10]})
        if f[2] not in o["messages"]:
            o["messages"].append(f[2])
        o["rate"] += f[3]
        o["no_bounce"] |= bool(f[8])
        if f[9] is not None:
            o["bounce_budgets"].add(f[9])
    res = []
    for o in out.values():
        o["bounce_budgets"] = sorted(o["bounce_budgets"])
        o["every_ticks"] = round(1 / o["rate"], 1) if o["rate"] else None
        o["reply"] = reply_to(address, o["from"], o["messages"][0], o["color"]) if o["messages"] else None
        res.append(o)
    res.sort(key=lambda o: -o["rate"])
    return res
