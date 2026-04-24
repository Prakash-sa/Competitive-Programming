# Square Root Decomposition

Square root decomposition is a block-based range-query technique. Instead of processing every element inside a query range, split the array into blocks of size about `sqrt(n)` and precompute one answer per block.

It belongs to the broader topic of data structures and range query optimization.

## What it does

- Break an array into blocks of size about `sqrt(n)`.
- Store precomputed information for each block.
- Answer queries by combining:
  - a partial prefix block
  - zero or more full blocks
  - a partial suffix block

This is usually much faster than brute force and much easier to implement than a segment tree.

## Where it fits

- Data Structures
- Range Queries
- Query Processing
- Block Decomposition

Closely related topics:

- Prefix Sum
- Fenwick Tree
- Segment Tree
- Mo's Algorithm

## When to use it

Use sqrt decomposition when:

- You have many range queries on an array.
- Updates exist, but the problem does not justify a full segment tree.
- `O(sqrt(n))` per query is fast enough for the given constraints.
- You want a contest-safe implementation with low bug risk.

Common use cases:

- Range sum
- Range min / max
- Frequency counting per block
- Jump queries
- Range updates with block rebuild ideas

## Complexity

- Build: `O(n)`
- Query: `O(sqrt(n))`
- Point update: `O(1)` for block sums, sometimes `O(sqrt(n))` if block metadata must be rebuilt
- Space: `O(n)`

## Core intuition

Array:

```text
[1, 2, 3, 4, 5, 6, 7, 8, 9]
```

Choose block size `3`:

```text
[1,2,3] [4,5,6] [7,8,9]
```

Store block sums:

```text
[6, 15, 24]
```

Now query sum from index `2` to `7`:

- Take partial left block: `3`
- Take full middle block: `4 + 5 + 6 = 15`
- Take partial right block: `7 + 8`

Total: `26`

The key idea is that full blocks are answered in `O(1)` each.

## Python template

```python
import math


class SqrtDecomposition:
    def __init__(self, nums):
        self.n = len(nums)
        self.block_size = int(math.sqrt(self.n)) + 1
        self.nums = nums[:]
        self.blocks = [0] * ((self.n + self.block_size - 1) // self.block_size)

        for i, val in enumerate(self.nums):
            self.blocks[i // self.block_size] += val

    def update(self, idx, val):
        block_idx = idx // self.block_size
        self.blocks[block_idx] += val - self.nums[idx]
        self.nums[idx] = val

    def query(self, left, right):
        total = 0
        start_block = left // self.block_size
        end_block = right // self.block_size

        if start_block == end_block:
            for i in range(left, right + 1):
                total += self.nums[i]
            return total

        end_of_start = min(self.n, (start_block + 1) * self.block_size)
        for i in range(left, end_of_start):
            total += self.nums[i]

        for block in range(start_block + 1, end_block):
            total += self.blocks[block]

        start_of_end = end_block * self.block_size
        for i in range(start_of_end, right + 1):
            total += self.nums[i]

        return total


nums = [1, 2, 3, 4, 5, 6, 7, 8]
sq = SqrtDecomposition(nums)

print(sq.query(2, 6))  # 25
sq.update(3, 10)       # nums[3] = 10
print(sq.query(2, 6))  # 31
```

## Decision map

### 1. Prefix Sum

Use when:

- There are only queries.
- There are no updates.
- The operation is additive and easy to prefix.

Complexity:

- Build: `O(n)`
- Query: `O(1)`

### 2. Fenwick Tree

Use when:

- You need point updates.
- Queries are prefix sums or reducible to prefix sums.
- You want `O(log n)` with a compact implementation.

Complexity:

- Query: `O(log n)`
- Update: `O(log n)`

### 3. Segment Tree

Use when:

- Queries are more complex: min, max, gcd, custom merge.
- You need many updates and many queries.
- You may need lazy propagation.

Complexity:

- Query: `O(log n)`
- Update: `O(log n)`

### 4. Sqrt Decomposition

Use when:

- You want simpler code.
- Constraints are moderate.
- `O(sqrt(n))` is acceptable.

Complexity:

- Query: `O(sqrt(n))`
- Update: `O(1)` or `O(sqrt(n))`

### 5. Mo's Algorithm

Use when:

- Queries are offline.
- The answer depends on frequencies or distinct counts.
- Reordering queries helps maintain a moving window.

Complexity:

- About `O((n + q) * sqrt(n))`

## Quick contest checklist

Ask:

1. Are there updates?
2. Are the queries online or offline?
3. Is the operation simple sum/frequency, or a custom merge?
4. Is implementation speed more important than asymptotic optimality?

Typical choices:

- No updates: prefix sum
- Sum with point updates: Fenwick tree
- Complex range query: segment tree
- Simple and good enough: sqrt decomposition
- Offline distinct/frequency query: Mo's algorithm

## Interview and contest notes

- Sqrt decomposition is often the easiest correct solution under time pressure.
- It is a strong stepping stone before learning segment trees and Mo's algorithm.
- If `O(sqrt(n))` is too slow, upgrade to Fenwick tree or segment tree.
- If the problem is offline and frequency-based, think about Mo's algorithm immediately.

## Practice ideas

- Range sum query with point update
- Range minimum query with updates
- Distinct elements in range
- Frequency of a value in range
- Jump query / teleport blocks
- Offline range query reordering with Mo's algorithm

## Recommended study order

Prefix Sum -> Fenwick Tree -> Sqrt Decomposition -> Segment Tree -> Mo's Algorithm


## Sqrt decomposition (`SQRT_DECOMPOSITION.md`)
- Splits an array into blocks of size about `sqrt(n)`.
- Precomputes one summary per block (sum/min/max/frequency, depending on the problem).
- Best fit when:
  - You need something simpler than a segment tree.
  - Constraints are moderate (`n, q` around `10^5`).
  - Queries are online and updates are not too heavy.
- Typical complexity:
  - Build: `O(n)`
  - Query: `O(sqrt(n))`
  - Point update: `O(1)` or `O(sqrt(n))`, depending on block metadata
- Closely related: Mo's algorithm uses the same block intuition for offline queries.
