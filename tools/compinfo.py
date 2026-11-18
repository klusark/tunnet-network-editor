"""Find Bevy ComponentInfo records for named types in a running tunnet.exe.

Bevy keeps, per component type, a descriptor holding the type name
(std::any::type_name) plus the type's Layout (size, align). We find every copy
of the exact name string, then every pointer to those copies that is followed by
the string length (a &str / String / Cow fat pointer), and dump the memory around
each such reference so the size/align fields can be read off.

Usage: python -I compinfo.py tunnet::net::transport::NetNode [more names...]
Read-only.
"""
import struct
import sys

import memscan as M


def scan(h, names):
    targets = {n: n.encode() for n in names}
    chunks = []
    for base, size in M.regions(h):
        if size > 512 * 1024 * 1024:
            continue
        data = M.read(h, base, size)
        if data:
            chunks.append((base, data))

    for name, nb in targets.items():
        # Exact matches only: the byte after the name must not continue an identifier.
        locs = []
        for base, data in chunks:
            o = data.find(nb)
            while o != -1:
                nxt = data[o + len(nb): o + len(nb) + 1]
                if not (nxt.isalnum() or nxt in (b"_", b":", b"<")):
                    locs.append(base + o)
                o = data.find(nb, o + 1)
        print(f"\n=== {name}: {len(locs)} exact string copies")
        ptrs = {struct.pack("<Q", a): a for a in locs}
        for base, data in chunks:
            for pb, target in ptrs.items():
                o = data.find(pb)
                while o != -1:
                    ln = struct.unpack_from("<Q", data, o + 8)[0] if o + 16 <= len(data) else -1
                    ln2 = struct.unpack_from("<Q", data, o + 16)[0] if o + 24 <= len(data) else -1
                    if len(nb) in (ln, ln2):
                        at = base + o
                        print(f"  ref @ {at:#x} -> str {target:#x} (len field ok)")
                        lo = max(0, o - 64)
                        blob = data[lo: o + 96]
                        for i in range(0, len(blob), 16):
                            q = [struct.unpack_from("<Q", blob, i + j)[0] if i + j + 8 <= len(blob) else 0 for j in (0, 8)]
                            print(f"    {base + lo + i:#014x}  {blob[i:i + 16].hex(' ')}   {q[0]:#x} {q[1]:#x}")
                    o = data.find(pb, o + 1)


if __name__ == "__main__":
    pid, h = M.find_pid()
    print("pid", pid)
    scan(h, sys.argv[1:])
