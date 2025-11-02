# Python Competitive Programming Playbook

Python-first notes to move quickly in contests and interviews. The code in this repository is organised by technique (stack, queue, DP, graph, etc.); the cheat sheet below maps the most useful patterns to those folders.

## Quick-start template

```python
#!/usr/bin/env python3
import sys
from math import gcd, sqrt, ceil, floor
from collections import defaultdict, Counter, deque
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right

input = sys.stdin.readline  # fast I/O

def ints():
    return map(int, input().split())

def solve():
    # your logic here
    pass

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
```

### C++ -> Python muscle memory
- `vector<int>` -> `list[int]`
- `unordered_map` -> `dict`
- `priority_queue<int>` -> `heapq` (min-heap; negate for max-heap)
- `deque` -> `collections.deque`
- `lower_bound`/`upper_bound` -> `bisect_left`/`bisect_right`
- `cin / cout` -> `sys.stdin.readline` / `sys.stdout.write`

## Python KPIs & Cheatsheet

- **Stacks**
  - Lightweight: `list.append`, `list.pop()` -> both O(1).
  - Queue-to-stack trick: rotate `deque` after each push to keep the newest element at the front.
  - Max stack: maintain `(value, running_max)` pairs for O(1) max queries.

- **Queues / Deques**
  - Use `collections.deque` for O(1) `append`, `appendleft`, `popleft`.
  - Queue via two stacks gives amortized O(1) even without `deque`.
  - Sliding window tip: store indices to drop expired elements quickly.

- **Priority Queues (Heaps)**
  - `heapq` is min-heap; negate keys for max-heap behaviour.
  - Keep `(priority, payload)` tuples - Python compares tuples lexicographically.
  - For time-decay caches, push `( -timestamp, tweet_id, user_id )` so the latest rises first.

- **Hash Maps / Hash Sets**
  - Python `dict`/`set` already O(1) average; when building custom versions, pick a prime bucket count and use chaining.
  - For duplicate detection with range eviction (like the router), pair a `set` for existence with an ordered container for eviction.

- **Ordered Structures**
  - `OrderedDict` keeps insertion order; `move_to_end(key, last=True/False)` is O(1).
  - Great drop-in replacement for manual doubly linked lists in LRU/LFU caches.

- **Binary Search Helpers**
  - `bisect_left`/`bisect_right` from `bisect` module - ideal for time-travel data (TimeMap, Router timestamp queues).
  - Trick: use `bisect_right - bisect_left` to count elements inside `[lo, hi]` in O(log n).

## Interview Talking Points

- Emphasise **amortised analysis** for queue-with-stacks and heap-based feeds.
- When discussing caches, compare options: `OrderedDict`, custom DLL + dict, and `heapq` for LFU variants.
- Always state **space trade-offs** (e.g. timestamps replicated across maps for faster lookup).
- For concurrency-ish designs (router), call out how FIFO eviction interacts with dedupe state.
- Prepare quick examples to show the data structure invariant after each operation - helps convey mastery.

## Data Structure KPIs & Tricks

| Structure | Implementation & Ops | Interview nuggets |
|-----------|----------------------|-------------------|
| Stack | `list.append` / `list.pop()` -> O(1) | For monotonic stacks, store `(value, index)`; mention sentinel to avoid empty checks. |
| Queue | `deque.append` / `popleft` -> O(1) | Two-stack queue gives amortised O(1) without `deque`; highlight lazy transfer. |
| Deque | `deque` with `appendleft` / `popleft` -> O(1) | Sliding window maximum: maintain a decreasing deque of indices. |
| Heap | `heapq` min-heap; use tuples `(priority, item)` | For max-heap, push `(-value, value)`; pair with `heapq.heapreplace` for rolling top-k. |
| Ordered cache | `OrderedDict` with `move_to_end` O(1) | Explains the LRU solution (see `System Design/LRU Cache`). |
| Hash map / set | Built-in `dict` / `set` average O(1) | Custom bucketed map in `System Design/706` uses prime bucket count to spread keys. |
| Prefix sums | `itertools.accumulate` or manual | For 2D prefix, keep an extra row/col of zeros to avoid bounds checks. |
| Binary search | `bisect_left/right` in sorted containers | Count in range via `bisect_right - bisect_left`, used in TimeMap & Router implementations. |

## Folder highlights
- **System Design** - cache, hash map/set, queue/stack conversions, router, Twitter, and time-travel KV store patterns.
- **Concurrency** - thread coordination via `Lock`, `Barrier`, `Condition`, `Event`, `Semaphore`; know when to use each primitive.
- **Dynamic Programming** - 1D/2D tabulation, knapsack, LIS (`O(n^2)` and `O(n log n)`), path DP, digit DP, tree DP.
- **Graph** - BFS/DFS templates, multi-source BFS, Dijkstra, Bellman-Ford, Floyd-Warshall, DSU, MST (Prim/Kruskal), topo sort.
- **LinkedList** - cycle detection, k-group reversal, reorder, palindrome check, merge, Floyd's tortoise-hare.
- **Recursion & Backtracking** - permutations, combinations, subsets, grid paths; emphasise cloning state (`curr[:]`) before storing.
- **Advanced Algorithms / Segment Trees** - Fenwick tree and full segment tree for range updates/queries with lazy propagation shells.

## Fast I/O patterns
- Many ints on a line: `a, b, c = map(int, input().split())`
- Big array: `arr = list(map(int, input().split()))`
- Output: `sys.stdout.write(f"{ans}\n")`

## Core snippets

```python
# BFS on unweighted graph
dist = [-1] * n
q = deque([src]); dist[src] = 0
while q:
    u = q.popleft()
    for v in g[u]:
        if dist[v] == -1:
            dist[v] = dist[u] + 1
            q.append(v)

# Iterative DFS
seen = [False] * n
stack = [src]
while stack:
    u = stack.pop()
    if seen[u]:
        continue
    seen[u] = True
    for v in g[u]:
        if not seen[v]:
            stack.append(v)

# Dijkstra (weighted graph)
INF = 10**18
dist = [INF] * n
dist[s] = 0
pq = [(0, s)]
while pq:
    d, u = heappop(pq)
    if d != dist[u]:
        continue
    for v, w in g[u]:
        nd = d + w
        if nd < dist[v]:
            dist[v] = nd
            heappush(pq, (nd, v))

# Union-Find (DSU)
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n
    def find(self, x):
        while x != self.p[x]:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x
    def unite(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True

# Binary search on answer
def ok(x):
    # predicate
    return True

lo, hi = 0, 10**18
while lo < hi:
    mid = (lo + hi) // 2
    if ok(mid):
        hi = mid
    else:
        lo = mid + 1
# lo is minimal feasible

# Prefix sums
pref = [0]
for x in arr:
    pref.append(pref[-1] + x)
# range sum [l, r): pref[r] - pref[l]

# Sliding window maximum
best = float("-inf")
window = deque()
for r, x in enumerate(nums):
    while window and window[-1][0] <= x:
        window.pop()
    window.append((x, r))
    while window and window[0][1] <= r - k:
        window.popleft()
    if r >= k - 1:
        best = max(best, window[0][0])
```

## Performance tips
- Prefer PyPy for loop-heavy tasks; CPython shines with heavy builtins (`heapq`, `bisect`, `collections`).
- Bind frequently used functions to locals (`push = heappush`) before loops.
- Avoid deep recursion; if unavoidable, call `sys.setrecursionlimit(1_000_000)` and still favour iterative stacks.
- Build strings via `list.append` + `"".join`.
- `Counter`/`defaultdict(int)` are invaluable for frequency DP and sliding windows.

## Typical safe bounds
- `O(n log n)` holds comfortably up to ~2e5.
- Pure `O(n^2)` is usually fine up to ~5e3, sometimes 1e4 with pruning.
- Segment tree / Fenwick tree handles 2e5 range updates/queries easily.

## Idioms you'll use a lot
- Sort by two keys: `arr.sort(key=lambda x: (x[0], -x[1]))`
- Top-k largest: `heapq.nlargest(k, arr, key=...)`
- Dedup while preserving order:

```python
seen = set(); out = []
for x in arr:
    if x not in seen:
        seen.add(x)
        out.append(x)
```

## Gotchas moving from C++
- No built-in max-heap (negate keys).
- Custom comparators for `sort` become `key=` functions - precompute the sorting key for performance.
- Integers never overflow; when the problem demands modulo, do it explicitly.
- Strings are immutable; slicing creates copies.
- For backtracking, stash copies: `ans.append(path[:])`. Without slicing, every reference points to the same list:
Using self.output.append(curr[:]) stores a snapshot of the current subset that won’t change when you later mutate curr.

```python
curr = [1]
out = []
out.append(curr)      # same object reference
curr.append(2)
print(out)  # [[1, 2]]  <-- changed because curr changed

out = []
curr = [1]
out.append(curr[:])   # copy
curr.append(2)
print(out)  # [[1]]    <-- snapshot preserved
```

Notes:

- curr[:], list(curr), and curr.copy() are equivalent here.

- It’s a shallow copy: fine for lists of ints; for nested/mutable elements you’d need copy.deepcopy.

- `str.isnumeric()` helps when parsing tokens character by character.
- Watch recursion depth and timeouts; convert to iterative if the DFS depth could hit ~1e5.
