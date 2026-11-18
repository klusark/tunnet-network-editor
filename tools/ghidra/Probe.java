// Headless probe for the tunnet Ghidra project.
// Args (any number, processed in order):
//   out@<file>          write results to this file (default: probe_out.txt in cwd)
//   str:<text>          find every occurrence of <text> in memory, list referencing functions
//   strdec:<text>       same, and decompile each referencing function
//   fn:<addr>           decompile the function containing <addr>
//   callers:<addr>      list callers of the function containing <addr>
//   callees:<addr>      list callees of the function containing <addr>
//   bytes:<addr>:<n>    hex dump n bytes at addr
// Read-only: makes no changes to the program.
//@category Tunnet

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Probe extends GhidraScript {
    private PrintWriter out;
    private DecompInterface dec;
    private final Set<Function> decompiled = new HashSet<>();

    @Override
    protected void run() throws Exception {
        // Note: cmd.exe splits batch args on '=' and ';', so options use '@' / ':'.
        String outPath = "probe_out.txt";
        for (String a : getScriptArgs()) if (a.startsWith("out@")) outPath = a.substring(4);
        out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(outPath), StandardCharsets.UTF_8));
        dec = new DecompInterface();
        dec.openProgram(currentProgram);
        try {
            for (String a : getScriptArgs()) {
                if (a.startsWith("out@")) continue;
                int c = a.indexOf(':');
                if (c < 0) { out.println("skipping arg without command: " + a); continue; }
                String cmd = a.substring(0, c), arg = a.substring(c + 1);
                out.println("\n######## " + a);
                switch (cmd) {
                    case "str": strRefs(arg, false); break;
                    case "strdec": strRefs(arg, true); break;
                    case "fn": decompile(fnAt(arg)); break;
                    case "callers": callers(fnAt(arg)); break;
                    case "callees": callees(fnAt(arg)); break;
                    case "bytes": { String[] p = arg.split(":"); dump(toAddr(p[0]), Integer.parseInt(p[1])); break; }
                    default: out.println("unknown command " + cmd);
                }
                out.flush();
            }
        } finally {
            dec.dispose();
            out.close();
        }
    }

    private Function fnAt(String s) {
        Address a = toAddr(s);
        Function f = getFunctionContaining(a);
        if (f == null) out.println("no function at " + s);
        return f;
    }

    private void strRefs(String text, boolean decomp) throws Exception {
        byte[] pat = text.getBytes(StandardCharsets.UTF_8);
        Memory mem = currentProgram.getMemory();
        Address start = mem.getMinAddress();
        int found = 0;
        while (true) {
            Address hit = mem.findBytes(start, pat, null, true, monitor);
            if (hit == null || found++ > 200) break;
            ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(hit);
            List<Address> froms = new ArrayList<>();
            while (it.hasNext()) froms.add(it.next().getFromAddress());
            if (!froms.isEmpty()) {
                out.println("string @" + hit + " refs " + froms.size());
                for (Address f : froms) {
                    Function fn = getFunctionContaining(f);
                    out.println("   from " + f + " in " + (fn == null ? "?" : fn.getName() + " @" + fn.getEntryPoint()
                            + " size " + fn.getBody().getNumAddresses()));
                    if (decomp && fn != null) decompile(fn);
                }
            }
            start = hit.add(1);
        }
        out.println("occurrences scanned: " + found);
    }

    private void decompile(Function f) {
        if (f == null || !decompiled.add(f)) return;
        out.println("\n=== " + f.getName() + " @" + f.getEntryPoint() + " (" + f.getBody().getNumAddresses() + " bytes)");
        DecompileResults r = dec.decompileFunction(f, 180, monitor);
        if (r.decompileCompleted()) out.println(r.getDecompiledFunction().getC());
        else out.println("decompile failed: " + r.getErrorMessage());
    }

    private void callers(Function f) {
        if (f == null) return;
        for (Function c : f.getCallingFunctions(monitor))
            out.println("   caller " + c.getName() + " @" + c.getEntryPoint() + " size " + c.getBody().getNumAddresses());
    }

    private void callees(Function f) {
        if (f == null) return;
        for (Function c : f.getCalledFunctions(monitor))
            out.println("   callee " + c.getName() + " @" + c.getEntryPoint() + " size " + c.getBody().getNumAddresses());
    }

    private void dump(Address a, int n) throws Exception {
        byte[] b = new byte[n];
        currentProgram.getMemory().getBytes(a, b);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i % 16 == 0) sb.append(String.format("%n   %s ", a.add(i)));
            sb.append(String.format("%02x ", b[i]));
        }
        out.println(sb);
    }
}
