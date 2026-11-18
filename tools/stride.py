"""Find arrays in tunnet.exe memory whose consecutive elements contain known byte patterns.

Usage: python -I stride.py <slot.json> endpoints [n]
  Looks for the endpoint addresses (Address.elements as one byte each,
  Zero=0..Three=3) laid out at a constant stride, i.e. an array of
  Endpoint components in save order.

Read-only; prints candidate arrays with a hex dump of the first two elements.
"""
import json
import sys

import memscan as M

ELEM = {"Zero": 0, "One": 1, "Two": 2, "Three": 3, "Wildcard": 4}


def addr_bytes(a):
    return bytes(ELEM[e] for e in a["elements"])


def find_arrays(h, pats, max_stride=4096, need=None):
    need = need or len(pats)
    out = []
    for base, size in M.regions(h):
        if size > 512 * 1024 * 1024:
            continue
        data = M.read(h, base, size)
        if not data:
            continue
        off = data.find(pats[0])
        while off != -1:
            # candidate strides come from where pattern 1 occurs after this hit
            o1 = data.find(pats[1], off + 1, off + max_stride + len(pats[1]))
            while o1 != -1:
                s = o1 - off
                run = 2
                while run < len(pats):
                    p = off + run * s
                    if data[p:p + len(pats[run])] != pats[run]:
                        break
                    run += 1
                if run >= need:
                    out.append((base + off, s, run, data[off - 32: off + 2 * s]))
                o1 = data.find(pats[1], o1 + 1, off + max_stride + len(pats[1]))
            off = data.find(pats[0], off + 1)
    return out


def dump(addr, blob):
    for o in range(0, len(blob), 16):
        print(f"    {addr - 32 + o:#014x}  {blob[o:o + 16].hex(' ')}")


def main():
    save = json.load(open(sys.argv[1]))
    n = int(sys.argv[3]) if len(sys.argv) > 3 else 8
    eps = save["endpoints"][:n]
    pats = [addr_bytes(e["address"]) for e in eps]
    pid, h = M.find_pid()
    print(f"pid {pid}; endpoint address patterns: {[p.hex() for p in pats]}")
    for addr, s, run, blob in find_arrays(h, pats):
        print(f"  array @ {addr:#x} stride {s:#x} ({s}) run {run}")
        dump(addr, blob[: 32 + min(2 * s, 256)])


if __name__ == "__main__":
    main()
