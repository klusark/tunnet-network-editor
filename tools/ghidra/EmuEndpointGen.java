// Run tunnet's endpoint packet generator (FUN_1402f9a40) in Ghidra's emulator for every
// endpoint address x tick, with stubs for allocation / RNG / string helpers, and write
// what each call would send to a JSON-lines file.
// Args: <out.jsonl> <story.bin> <tick_from> <tick_to> <addr,addr,...> [story_heap.bin]
//   addr like 0.1.2.3; story_heap.bin = records [u64 addr][u32 len][bytes] of the heap
//   data the live Story resource points to (some rules read story strings/lists)
//@category Tunnet
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import ghidra.pcode.memstate.MemoryFaultHandler;
import ghidra.program.model.address.Address;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.*;

public class EmuEndpointGen extends GhidraScript {
    static final long GEN = 0x1402f9a40L, SENTINEL = 0x30000000L;
    static final long HEAP = 0x10000000L, STACK = 0x20000000L, STORY = 0x28000000L, RNG = 0x18000000L,
                      ADDR = 0x2a000000L, OUT = 0x2b000000L, PLACEHOLDER = 0x2c000000L;
    EmulatorHelper emu;
    long heap;
    List<String> notes = new ArrayList<>();

    long reg(String r) { return emu.readRegister(r).longValue(); }
    void setReg(String r, long v) { emu.writeRegister(r, BigInteger.valueOf(v)); }
    Address a(long x) { return toAddr(x); }
    long q(long addr) { byte[] b = emu.readMemory(a(addr), 8); long v = 0; for (int i = 7; i >= 0; i--) v = (v << 8) | (b[i] & 0xff); return v; }
    void wq(long addr, long v) { byte[] b = new byte[8]; for (int i = 0; i < 8; i++) b[i] = (byte) (v >>> (8 * i)); emu.writeMemory(a(addr), b); }
    String str(long p, long n) { if (p == 0 || n <= 0 || n > 4096) return ""; return new String(emu.readMemory(a(p), (int) n), java.nio.charset.StandardCharsets.UTF_8); }
    void ret(long rax) { long ra = q(reg("RSP")); setReg("RSP", reg("RSP") + 8); setReg("RAX", rax); emu.writeRegister(emu.getPCRegister(), BigInteger.valueOf(ra)); }
    long alloc(long size) { long p = heap; heap += (size + 15) & ~15L; emu.writeMemory(a(p), new byte[(int) Math.max(1, Math.min(size, 1 << 16))]); return p; }
    static String esc(String s) { StringBuilder b = new StringBuilder(); for (char c : s.toCharArray()) { if (c == '"' || c == '\\') b.append('\\').append(c); else if (c < 32) b.append(String.format("\\u%04x", (int) c)); else b.append(c); } return b.toString(); }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(args[0]), "UTF-8"));
        byte[] story = Files.readAllBytes(Paths.get(args[1]));
        int t0 = Integer.parseInt(args[2]), t1 = Integer.parseInt(args[3]);
        String[] addrs = args[4].split(",");
        emu = new EmulatorHelper(currentProgram);
        emu.setMemoryFaultHandler(new MemoryFaultHandler() {
            public boolean uninitializedRead(Address address, int size, byte[] buf, int bufOffset) { return true; }
            public boolean unknownAddress(Address address, boolean write) { return false; }
        });
        long[] stubs = {0x140819290L, 0x140293650L, 0x1408192a0L, 0x14204d800L, 0x140441990L, 0x140673b40L,
                0x140673660L, 0x140275e80L, 0x14067a670L, 0x1423a0360L, 0x1423a1210L, 0x1423b2600L, 0x140673c60L,
                0x1423ab4f0L, 0x1423ab9f0L, 0x14239ef70L, SENTINEL};
        for (long s : stubs) emu.setBreakpoint(a(s));
        List<long[]> heapAddrs = new ArrayList<>();
        List<byte[]> heapData = new ArrayList<>();
        if (args.length > 5) {  // live heap blocks referenced by Story, mapped at their real addresses
            java.nio.ByteBuffer bb = java.nio.ByteBuffer.wrap(Files.readAllBytes(Paths.get(args[5]))).order(java.nio.ByteOrder.LITTLE_ENDIAN);
            while (bb.remaining() >= 12) {
                long ha = bb.getLong(); int hl = bb.getInt();
                byte[] hd = new byte[hl]; bb.get(hd);
                heapAddrs.add(new long[]{ha}); heapData.add(hd);
            }
            println("loaded " + heapData.size() + " story heap blocks");
        }
        emu.writeMemory(a(PLACEHOLDER), "{formatted}".getBytes());
        int n = 0;
        for (String ad : addrs) {
            String[] d = ad.split("\\.");
            byte[] ab = {(byte) (Integer.parseInt(d[0]) + 1), (byte) (Integer.parseInt(d[1]) + 1),
                    (byte) (Integer.parseInt(d[2]) + 1), (byte) (Integer.parseInt(d[3]) + 1), 0};
            for (int tick = t0; tick < t1; tick++) {
                if (monitor.isCancelled()) break;
                heap = HEAP; notes.clear();
                emu.writeMemory(a(STORY), story);
                for (int hi = 0; hi < heapData.size(); hi++) emu.writeMemory(a(heapAddrs.get(hi)[0]), heapData.get(hi));
                emu.writeMemory(a(RNG), new byte[0x400]);
                emu.writeMemory(a(ADDR), ab);
                byte[] o = new byte[0x80]; o[0x3a] = (byte) 0xEE;  // 0xEE = generator wrote nothing
                emu.writeMemory(a(OUT), o);
                long sp = STACK - 0x1000;
                wq(sp, SENTINEL);
                setReg("RSP", sp); setReg("RCX", OUT); setReg("RDX", STORY); setReg("R8", ADDR); setReg("R9", tick);
                emu.writeRegister(emu.getPCRegister(), BigInteger.valueOf(GEN));
                String err = null;
                int steps = 0;
                while (true) {
                    if (!emu.run(monitor)) { err = "emu: " + emu.getLastError(); break; }
                    long pc = emu.getExecutionAddress().getOffset();
                    if (pc == SENTINEL) break;
                    if (++steps > 2000) { err = "too many stub calls"; break; }
                    if (pc == 0x140819290L) ret(alloc(reg("RCX")));               // alloc(size, align)
                    else if (pc == 0x140293650L) ret(alloc(reg("RCX")));          // exchange_malloc(size)
                    else if (pc == 0x1408192a0L || pc == 0x140441990L || pc == 0x140673c60L) ret(0);
                    else if (pc == 0x14204d800L) ret(RNG);                        // thread_rng()
                    else if (pc == 0x140673b40L) {                                // slice.choose(rng) -> &item
                        long p = reg("RCX"), len = reg("RDX");
                        StringBuilder b = new StringBuilder("choose:[");
                        for (int i = 0; i < len; i++) { if (i > 0) b.append("|"); b.append(str(q(p + 16L * i), q(p + 16L * i + 8))); }
                        notes.add(b.append("]").toString());
                        ret(len > 0 ? p : 0);
                    } else if (pc == 0x140673660L) {                              // gen_range(lo, hi)
                        notes.add("range:" + reg("RDX") + ".." + reg("R8"));
                        ret(reg("RDX"));
                    } else if (pc == 0x140275e80L || pc == 0x14067a670L) {        // String::from(ptr, len)
                        long o2 = reg("RCX"), p = reg("RDX"), len = reg("R8");
                        wq(o2, len); wq(o2 + 8, p); wq(o2 + 16, len); ret(o2);
                    } else if (pc == 0x1423a0360L) {                              // format!(args)
                        long o2 = reg("RCX"), argp = reg("RDX");
                        StringBuilder b = new StringBuilder("format:");          // best effort: pieces &[&str]
                        for (int k = 0; k < 6; k++) b.append(k == 0 ? "" : ",").append(Long.toHexString(q(argp + 8L * k)));
                        notes.add(b.toString());
                        wq(o2, 11); wq(o2 + 8, PLACEHOLDER); wq(o2 + 16, 11); ret(o2);
                    } else if (pc == 0x1423a1210L || pc == 0x1423b2600L) { notes.add("strbuild"); ret(0); }
                    else { err = "panic/alloc-failure at " + Long.toHexString(pc); break; }
                }
                byte[] p = emu.readMemory(a(OUT), 0x40);
                StringBuilder line = new StringBuilder();
                line.append("{\"addr\":\"").append(ad).append("\",\"tick\":").append(tick);
                int st = p[0x3a] & 0xff;
                if (err != null) line.append(",\"error\":\"").append(esc(err)).append("\"");
                if (st == 2) line.append(",\"send\":false");
                else if (st == 0xEE) line.append(",\"send\":null");
                else {
                    long cp = q(OUT), cl = q(OUT + 8), pp = q(OUT + 0x20), pl = q(OUT + 0x28);
                    line.append(",\"send\":true,\"color\":\"").append(esc(str(cp, cl))).append("\"");
                    line.append(",\"payload\":\"").append(esc(str(pp, pl))).append("\"");
                    line.append(",\"budget\":").append(q(OUT + 0x10));
                    line.append(",\"src\":[");
                    for (int i = 0x30; i < 0x35; i++) line.append(i > 0x30 ? "," : "").append(p[i] & 0xff);
                    line.append("],\"dst\":[");
                    for (int i = 0x35; i < 0x3a; i++) line.append(i > 0x35 ? "," : "").append(p[i] & 0xff);
                    line.append("],\"f3a\":").append(p[0x3a]).append(",\"f3b\":").append(p[0x3b]).append(",\"f3c\":").append(p[0x3c]);
                }
                line.append(",\"notes\":[");
                for (int i = 0; i < notes.size(); i++) line.append(i > 0 ? "," : "").append("\"").append(esc(notes.get(i))).append("\"");
                line.append("]}");
                out.println(line);
                n++;
            }
        }
        out.close();
        emu.dispose();
        println("emulated " + n + " calls");
    }
}
