# Competitive Programming Reference Guide

## Time Complexity

- `n < 20`: consider exhaustive strategies such as `2^n` brute force or `n!` backtracking. Keep pruning aggressively.
- `n < 3000`: quadratic `O(n^2)` dynamic-programming solutions are usually safe.
- `3000 < n < 10^6`: aim for `O(n)` or `O(n log n)` via two pointers, greedy, heaps, divide and conquer, or sorting tricks.
- `n > 10^6`: target `O(log n)` or `O(1)` using binary search, arithmetic formulas, or bit hacks; even linear scans become expensive.

## Sliding Window

- Use on linear data structures (arrays, strings, linked lists).
- Maintain a moving subarray/substring while checking constraints (length, sum, distinctness, frequency).
- Replace nested loops with incremental updates to drop complexity from `O(n^2)` to `O(n)`.
- Combine with hash maps or frequency arrays for character and count tracking.

## Two Pointers

- Operate on sorted or partially ordered arrays/lists/strings.
- Move left/right pointers to find pairs, triplets, or bounded ranges.
- Ideal for deduplication, partitioning, and shrinking/expanding windows.
- Supports in-place filtering (e.g., remove duplicates, move zeros).

## Slow and Fast Pointer

- Use two pointers with different speeds on linear structures.
- Detect cycles (Floyd's tortoise and hare), find middle nodes, or discover cycle entry points.
- Maintain `O(1)` extra space and keep traversal to one pass.

## Linked List Reversal

- Reverse a linked list entirely in one pass with constant space.
- Reverse sublists between indices `m` and `n` without additional data structures.
- Reverse nodes in groups of `k` for chunked reordering.

## Binary Search

- Needs a monotonic condition or sorted input (arrays, answers, time).
- Locate elements, insertion indices, or left/right boundaries.
- Handle duplicates carefully (lower/upper bound variants).
- Apply to rotated arrays, sqrt calculations, and binary search on the answer space.

## Top K Elements

- Retrieve the smallest/largest `k` elements via heaps, partial sorting, or quickselect.
- Maintain running top-k in streaming scenarios using bounded heaps.
- Solve frequency-based problems (top-k frequent elements, k most common words).

## Binary Tree Traversal

- Preorder (root -> left -> right): useful for serialization/deserialization.
- Inorder (left -> root -> right): yields sorted results in BSTs, supports kth-smallest queries.
- Postorder (left -> right -> root): compute aggregated metrics (height, subtree sums).
- Level order (BFS): processes nodes layer by layer; ideal for breadth-first properties.

## Graph and Matrix

- Treat grids as graphs with 4/8-directional adjacency.
- DFS explores depth-first paths; use for connected components, flood fill, backtracking.
- BFS finds shortest paths in unweighted graphs and performs multi-source propagation.
- Topological sort orders tasks with dependencies and detects DAG validity.

## Backtracking

- Enumerate combinations, permutations, subsets, and partitions.
- Solve constraint satisfaction problems (Sudoku, N-Queens, crossword fill).
- Use pruning (bounds, feasibility checks, visited sets) to cut branches early.

## DP

- Presence of overlapping subproblems and optimal substructure signals DP.
- Shines in optimization (min/max cost), counting, and sequence analysis (LIS, LCS, edit distance).
- Either memoize recursive solutions or build bottom-up tables.
- Converts exponential brute-force into polynomial-time solutions.

## Bit Manipulation

- Count set bits, isolate least-significant set bit, or test powers of two.
- Perform arithmetic using bit operators (simulate addition without `+`/`-`).
- Use XOR for duplicate cancellation and subset enumeration via bit masks.
- Combine with DP/state compression to encode sets or visited masks.

## Overlapping Intervals

- Sort intervals by start time; merge overlaps or find disjoint gaps.
- Detect schedule conflicts (meeting rooms) with sweepline scans and min-heaps.
- Compute intersection/union coverage and identify missing ranges.

## Monotonic Stack

- Maintain next greater/smaller elements in linear time.
- Identify span/width in histograms, stock span, daily temperatures.
- Use monotonic queues for sliding-window maxima/minima.

## Prefix Sum

- Precompute cumulative sums to answer range queries quickly.
- Extend to difference arrays, 2D prefix sums, and imos method for range updates.
- Combine with hash maps to count subarrays meeting a target sum.

## Substring vs Subsequence

- Subarrays/substrings are contiguous segments.
- Subsequences retain order but can skip elements.

## Time Complexity

- Plain recursion often costs `O(2^n)`; memoization/tabulation can reduce it drastically.
- Tail recursion optimizes stack usage but may still need conversion in languages without TCO.

## Topics

### Catalan Number

Catalan numbers form a sequence that counts numerous combinatorial structures.

- Closed form: `C_n = (1/(n + 1)) * binom(2n, n) = (2n)! / (n! * (n + 1)!)`.
- DP recurrence: `C_0 = 1`, `C_n = sum_{i=0}^{n-1} C_i * C_{n-1-i}`.
- Applications:
  - Count well-formed parentheses strings (for `n = 3`: `((()))`, `()(())`, `()()()`, `(())()`, `(()())`).
  - Count unique BST structures with `n` keys.
  - Count full binary trees with `n + 1` leaves.
  - Count non-crossing chord pairings on a circle with `2n` points.

### Binary

Useful utility snippets:

- Test kth bit: `(num & (1 << k)) != 0`.
- Set kth bit: `num |= (1 << k)`.
- Unset kth bit: `num &= ~(1 << k)`.
- Toggle kth bit: `num ^= (1 << k)`.
- Power of two check: `(num & (num - 1)) == 0` or `(num & -num) == num`.
- Swap without temp: `a ^= b; b ^= a; a ^= b`.
- Compare floating values with tolerance: `abs(x - y) <= 1e-7`.

### String

- Normalize input (case, whitespace) before comparisons if necessary.
- Two-pointer or sliding-window methods handle most substring problems.
- Use hash maps or arrays for frequency tracking, and tries for prefix problems.

### Non-repeating Characters

Use a 26-bit mask to encode lowercase letters present in a string:

```python
mask = 0
for c in set(word):
    mask |= 1 << (ord(c) - ord("a"))
```

Two strings share common characters if `mask_a & mask_b > 0`.

### Anagram

An anagram rearranges all characters of a word or phrase. Interview variants usually ignore spaces and case.

- Sort both strings and compare (`O(n log n)` time).
- Map characters to primes and multiply products (be cautious of overflow).
- Count letter frequencies with arrays or hash maps for `O(n)` time, `O(1)` space.

### Palindrome

A palindrome reads identically forwards and backwards (e.g., `madam`, `racecar`, `1221`).

- Two pointers meet in the middle to validate in `O(n)` time.
- Clean strings (lowercase, alphanumeric only) when required.
- Reminder: BFS uses a queue, DFS uses a stack — handy when checking palindromic structures in graphs/trees.

### LinkedList

- Quick sort suits arrays; merge sort fits linked lists due to effortless splitting/merging.
- Practice reversing, merging sorted lists, detecting cycles, and swapping pairs — common interview staples.

### Tree

A tree is an undirected, connected, acyclic graph.

- Binary tree level `d` contains at most `2^d` nodes.
- A full binary tree of height `h` has `2^(h + 1) - 1` nodes.
- Number of levels in a tree equals height + 1 (with root at level 1).

### BST

- Inorder traversal yields ascending values.
- Reverse inorder (right → root → left) yields descending values.
- Exploit BST properties for predecessor/successor queries and range searches.

### Graph

- Dijkstra: shortest path from a source in non-negative weighted graphs.
- Bellman-Ford: handles negative edges and detects negative cycles.
- Floyd-Warshall: all-pairs shortest paths, supports negative edges (but not negative cycles).

### Heap

- For 0-indexed heap: `left = 2*i + 1`, `right = 2*i + 2`, `parent = (i - 1) // 2`.
- Maximum nodes in a heap of height `h`: `2^(h + 1) - 1`.
- Supports priority scheduling, median tracking, and top-k queries.

### Some common formulas

- Sum `1..n`: `(n + 1) * n / 2`.
- Geometric sum `2^0 + 2^1 + ... + 2^n = 2^(n + 1) - 1`.
- Permutations `P(n, k) = n! / (n - k)!`.
- Combinations `C(n, k) = n! / (k! * (n - k)!)`.

### 📋 Table of Patterns

| 🧩 Pattern                        | 💡 Real-Life Analogy                              | 🧠 Solves                                                   |
| --------------------------------- | ------------------------------------------------- | ----------------------------------------------------------- |
| **Sliding Window**                | "Peeking through a moving window"                 | Longest Substring, Max Sum Subarray, Anagrams               |
| **Two Pointers**                  | "Two fingers walking toward each other"           | 2Sum, Reverse Vowels, Sorted Squares, Palindrome Check      |
| **Fast & Slow Pointers**          | "Tom & Jerry: one fast, one slow 🐭🐱"            | Linked List Cycle, Happy Number                             |
| **Binary Search**                 | "Guess the number in 7 tries or less"             | Rotated Array, First/Last Position, Koko Eating Bananas     |
| **DFS / BFS**                     | "DFS: go deep. BFS: go wide."                     | Graph Traversals, Flood Fill, Word Ladder, Shortest Path    |
| **Backtracking**                  | "Trying all outfits before choosing one 👗"       | Sudoku, N-Queens, Word Search, Permutations                 |
| **Dynamic Programming (DP)**      | "Why re-solve what you've already solved?"        | Knapsack, House Robber, LIS, Edit Distance                  |
| **Greedy**                        | "Always pick what seems best right now"           | Activity Selection, Jump Game, Gas Station                  |
| **Union-Find (DSU)**              | "Friend circles detection 👯‍♀️"                     | Number of Provinces, Kruskal's MST, Connected Components    |
| **Topological Sort**              | "Finish A before B 📦"                            | Course Schedule, Task Scheduling                            |
| **Prefix Sum / Difference Array** | "Running totals like bank statements 💸"          | Range Sum, Subarray Sum Equals K, Rainwater Trapping        |
| **Monotonic Stack / Queue**       | "Stacking plates or tallest first 📏"             | Next Greater Element, Daily Temperatures, Largest Rectangle |
| **Bit Manipulation**              | "Flip switches to solve puzzles 💡"               | Single Number, Count Bits, Subsets, XOR Problems            |
| **Trie (Prefix Tree)**            | "Autocomplete dictionary 📚"                      | Word Search, StartsWith, Replace Words                      |
| **Heap / Priority Queue**         | "Serve most urgent first ⏳"                      | Kth Largest, Top K Elements, Merge K Lists                  |
| **Graph (Adjacency List/Matrix)** | "Follow paths on a map 🗺️"                        | Shortest Path, Cycles, Connected Components                 |
| **Recursion**                     | "Function calling itself – like Russian dolls 🪆" | Tree Problems, Factorial, Subsets, Merge Sort               |
| **Segment Tree / Fenwick Tree**   | "Smart range queries 📊"                          | Range Sum/Min/Max, Point & Range Updates                    |
| **Matrix Traversal**              | "Walk in all directions 🧭"                       | Spiral Order, Island Count, Diagonal Traversals             |
| **HashMap**                       | "Lookup table memory 📒"                          | 2Sum, Group Anagrams, Frequency Counts                      |

---

## Resources

- [Codeforces article on complexity heuristics](https://codeforces.com/blog/entry/57282)

## Links

- [LeetCode curated resource hub](https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-Leetcode)
- [Google Doc Cheat Sheet](https://docs.google.com/document/d/1wUCqhVHydWiDk6FJdFLSMpgigNrGcs4OFZg0Wa7JGEw/edit?usp=sharing)
- [DevOps Exercises repository](https://github.com/bregman-arie/devops-exercises)
