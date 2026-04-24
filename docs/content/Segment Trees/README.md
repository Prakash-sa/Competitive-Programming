# Fenwick & Segment Tree Guide

This directory stores advanced range query data structures in Python.

- Full binary tree stored as an array; supports point updates and range queries in `O(log n)`.
- Example solution: `countSmaller` (LeetCode 315) builds a tree over the value range `[-10^4, 10^4]` after shifting by an offset.
- Key helpers:
  - `update(index, value)` - bubble changes up the tree.
  - `query(left, right)` - gather contributions while walking up to the root.
- Complexity: `O(n log M)` time (`M` = coordinate range), `O(M)` space for the tree array.
- Talking point: when constraints explode, consider coordinate compression to shrink `M`.
- [Video](https://www.youtube.com/watch?v=rwXVCELcrqU&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=4)
- [Codeforces blog](https://codeforces.com/blog/entry/99074)


## When to use which
- Fenwick tree: easier to code, handles prefix queries and range updates with small tweaks.
- Segment tree: more flexible (min/max, gcd, lazy propagation, two-dimensional variants).
- Sqrt decomposition: simpler than a segment tree, strong fallback for online range queries when `O(sqrt(n))` is fast enough.
- Mo's algorithm: use for offline range queries, especially distinct-count and frequency-style problems.

## Contest decision guide
- Static range sum, no updates: prefix sum.
- Prefix/range sum with point updates: Fenwick tree.
- Complex online range queries or heavy updates: segment tree.
- Medium constraints and faster implementation pressure: sqrt decomposition.
- Offline frequency/distinct queries: Mo's algorithm.
