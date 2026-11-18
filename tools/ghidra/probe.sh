#!/bin/sh
# Run Probe.java against ~/ghidra/tunnet (read-only, no re-analysis).
# Usage: tools/ghidra/probe.sh <out-file> <probe args...>
# The tunnet project must not be open in the Ghidra GUI at the same time.
set -e
here=$(cd "$(dirname "$0")" && pwd -W)
out=$1; shift
GHIDRA_HEADLESS_MAXMEM=8G /c/Users/Joel/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat \
  'C:\Users\Joel\ghidra' tunnet -process tunnet.exe -noanalysis -readOnly \
  -scriptPath "$here" -postScript Probe.java "out@$out" "$@" \
  > "${out%.txt}.log" 2>&1 || { tail -20 "${out%.txt}.log"; exit 1; }
grep -E "ERROR|Exception" "${out%.txt}.log" | grep -v -E "DataType|PngData|GifData" | head -5 || true
