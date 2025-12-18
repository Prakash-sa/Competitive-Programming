#!/bin/bash
# Run a Python program taking input from file `in` and writing stdout to `out`.
# Usage: ./run.sh [script.py] [in-file] [out-file]
# Defaults: script.py=main.py, in-file=in, out-file=out

SCRIPT=${1:-main.py}
IN_FILE=${2:-in}
OUT_FILE=${3:-out}

python3 "$SCRIPT" < "$IN_FILE" > "$OUT_FILE"
