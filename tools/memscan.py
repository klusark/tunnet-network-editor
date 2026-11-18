"""Read-only memory scanner for a running tunnet.exe.

Finds where the game keeps its network nodes by searching process memory for
node positions taken from a save file, then reports the stride between
consecutive nodes (= size of the in-memory node struct) and dumps the bytes
around the first hit so the struct layout can be worked out.

Usage:  python -I memscan.py <slot.json> [count]
The game must be running with that same save loaded.
Reading is read-only. write() is the single exception, used only for explicit edits
(LiveNet.write_tester); it opens its own handle with write access.
"""
import ctypes as C
import ctypes.wintypes as W
import json
import struct
import sys

PROCESS_QUERY_INFORMATION = 0x0400
PROCESS_VM_READ = 0x0010
MEM_COMMIT = 0x1000
READABLE = {0x02, 0x04, 0x08, 0x20, 0x40, 0x80}  # RO, RW, WC, XR, XRW, XWC
PAGE_GUARD = 0x100

k32 = C.WinDLL("kernel32", use_last_error=True)
psapi = C.WinDLL("psapi", use_last_error=True)


class MBI(C.Structure):
    _fields_ = [("BaseAddress", C.c_void_p), ("AllocationBase", C.c_void_p),
                ("AllocationProtect", W.DWORD), ("PartitionId", W.WORD),
                ("RegionSize", C.c_size_t), ("State", W.DWORD),
                ("Protect", W.DWORD), ("Type", W.DWORD)]


class PMC(C.Structure):
    _fields_ = [("cb", W.DWORD), ("PageFaultCount", W.DWORD)] + [
        (n, C.c_size_t) for n in ("PeakWorkingSetSize", "WorkingSetSize",
                                  "QuotaPeakPagedPoolUsage", "QuotaPagedPoolUsage",
                                  "QuotaPeakNonPagedPoolUsage", "QuotaNonPagedPoolUsage",
                                  "PagefileUsage", "PeakPagefileUsage")]


def find_pid(name="tunnet.exe"):
    """Return (pid, handle) of the real game process.

    Steam starts a small launcher tunnet.exe that spawns the real game as a
    second tunnet.exe, so pick the matching process with the most private memory.
    """
    arr = (W.DWORD * 4096)()
    needed = W.DWORD()
    psapi.EnumProcesses(arr, C.sizeof(arr), C.byref(needed))
    best = None
    for pid in arr[: needed.value // 4]:
        h = k32.OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, False, pid)
        if not h:
            continue
        buf = C.create_unicode_buffer(260)
        if psapi.GetModuleBaseNameW(h, None, buf, 260) and buf.value.lower() == name:
            pmc = PMC(cb=C.sizeof(PMC))
            psapi.GetProcessMemoryInfo(h, C.byref(pmc), pmc.cb)
            if best is None or pmc.PagefileUsage > best[2]:
                if best:
                    k32.CloseHandle(best[1])
                best = (pid, h, pmc.PagefileUsage)
                continue
        k32.CloseHandle(h)
    if best is None:
        sys.exit(f"{name} is not running")
    return best[0], best[1]


def regions(h):
    addr, mbi = 0, MBI()
    while k32.VirtualQueryEx(h, C.c_void_p(addr), C.byref(mbi), C.sizeof(mbi)):
        if (mbi.State == MEM_COMMIT and mbi.Protect & 0xFF in READABLE
                and not mbi.Protect & PAGE_GUARD):
            yield mbi.BaseAddress, mbi.RegionSize
        addr = (mbi.BaseAddress or 0) + mbi.RegionSize


def read(h, addr, size):
    buf = C.create_string_buffer(size)
    n = C.c_size_t()
    if k32.ReadProcessMemory(h, C.c_void_p(addr), buf, size, C.byref(n)):
        return buf.raw[: n.value]
    return b""


PROCESS_VM_WRITE = 0x0020
PROCESS_VM_OPERATION = 0x0008


def open_writer(pid):
    h = k32.OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
                        False, pid)
    if not h:
        raise OSError(f"OpenProcess for writing failed: {C.get_last_error()}")
    return h


def write(h, addr, data):
    n = C.c_size_t()
    if not k32.WriteProcessMemory(h, C.c_void_p(addr), data, len(data), C.byref(n)) or n.value != len(data):
        raise OSError(f"WriteProcessMemory failed: {C.get_last_error()}")


def main():
    save = json.load(open(sys.argv[1]))
    count = int(sys.argv[2]) if len(sys.argv) > 2 else 8
    nodes = save["nodes"]
    pats = [struct.pack("<3f", *n["pos"]) for n in nodes[:count]]
    pid, h = find_pid()
    print(f"pid {pid}; searching for the first {count} node positions")

    hits = {i: [] for i in range(len(pats))}
    for base, size in regions(h):
        if size > 512 * 1024 * 1024:
            continue
        data = read(h, base, size)
        for i, p in enumerate(pats):
            off = data.find(p)
            while off != -1:
                hits[i].append(base + off)
                off = data.find(p, off + 1)

    for i, addrs in hits.items():
        print(f"node {i} pos={nodes[i]['pos']}: {[hex(a) for a in addrs[:12]]}"
              + (" ..." if len(addrs) > 12 else ""))

    # Look for an array: node0 hit followed by node1 hit at constant stride.
    print("\ncandidate node arrays (start, stride, run length):")
    s1 = set(hits.get(1, []))
    for a0 in hits.get(0, []):
        for a1 in sorted(s1):
            stride = a1 - a0
            if not 0 < stride <= 4096:
                continue
            run = 2
            while run < len(pats) and a0 + run * stride in set(hits[run]):
                run += 1
            if run >= 3:
                print(f"  {hex(a0)} stride {stride:#x} ({stride}) run {run}/{len(pats)}")
                blob = read(h, a0 - 0x40, stride * 2 + 0x40)
                for o in range(0, len(blob), 16):
                    chunk = blob[o:o + 16]
                    fl = " ".join(f"{v:10.3f}" for v in struct.unpack("<4f", chunk.ljust(16, b"\0")))
                    print(f"    {a0 - 0x40 + o:#014x}  {chunk.hex(' ')}  | {fl}")


if __name__ == "__main__":
    main()
