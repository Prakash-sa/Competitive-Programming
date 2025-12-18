# Recursion & Backtracking

This section captures the search templates used across combinations, permutations, subsets, grids, and classic recursion exercises.

## Folder breakdown
- `combinations` - choose k elements; emphasise pruning with remaining count.
- `permutations` - swap-in-place or build path with a visited boolean array.
- `subset` - power set generation; standard two-branch recursion (include/exclude).
- `path on grid` - DFS with bounds checks and optional visited matrix (or bitmask for faster copies).
- `palindrome` - backtracking with palindrome checks / expand from center.
- `recursion` - base cases, factorial, exponentiation, and template problems.

## KPI reminders
- Build answers with `path[:]` to snapshot the current state; appending the mutable list itself causes every record to change later.
- Track constraints (length remaining, sum remaining) to prune early.
- Use ordered loops to avoid duplicates; when input contains duplicates, sort first and skip identical choices when `i > start`.
- Depth can reach `n`, so Python's recursion limit might need bumping for large grids or permutations (`sys.setrecursionlimit`).

## Interview tips
- Communicate the recursion tree shape (branching factor, depth) before coding; helps justify complexity.
- Note when memoisation converts exponential recursion into polynomial time (e.g., word break vs brute-force).
- For puzzles (N-Queens, Sudoku), detail board representation (bitmasks vs arrays) and constraint propagation.
