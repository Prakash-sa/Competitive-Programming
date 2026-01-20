# Fenwick & Segment Tree Guide

This directory stores advanced range query data structures in Python.

## Fenwick tree (`feenwick.py`)
- Supports point updates and prefix sums in `O(log n)` using least-significant-bit jumps.
- Ideal for:
  - Frequency counting with many prefix queries (e.g. inversion counts).
  - Maintaining cumulative sums where range queries = `prefix(r) - prefix(l-1)`.
- Interview reminder: mention 1-based indexing internally and show how `i += i & -i` climbs the tree.
- [Video](https://www.youtube.com/watch?v=9uaXG62Y8Uw&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN)
- [Binary Lifting](https://www.youtube.com/watch?v=nuUspQ7ORXE&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=2)

## Segment tree (`implementation.py`)
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
