"""Bundle the data the JavaScript simulator needs into tools/viewer/sim_data.json:
the exact endpoint send table, the reply rules and the measured spam rates."""
import json, os
import reply_rules as RR
import sim as S
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
rules = json.load(open(os.path.join(ROOT, "re", "endpoint_rules.json")))
import save_import as I
addrs = set(rules["endpoints"])
try:  # every endpoint address in the world (from slot 0), so the panel covers silent ones too
    save = json.load(open(os.path.join(os.environ["APPDATA"], "tunnet", "slot_0.json"), encoding="utf-8"))
    addrs |= {I.addr(e["address"]) for e in save["endpoints"]}
except OSError:
    pass
incoming = {a: RR.incoming(a, rules["endpoints"]) for a in sorted(addrs)}
replies = {a: [r for r in RR.rules_for(a) if not r.get("boss")] for a in sorted(addrs)}
out = {"incoming": incoming, "replies": replies, "endpoint_rules": rules["endpoints"], "reply_rules": RR.RULES, "spam_rate": S.SPAM_RATE,
       "story_state": "DestroyCorruptedMainframe",
       "note": "Endpoint send table emulated from the game's generator at this story stage."}
json.dump(out, open(os.path.join(ROOT, "tools", "viewer", "sim_data.json"), "w"), indent=2)
print("wrote sim_data.json")
