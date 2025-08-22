Quick-start template
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

C++ → Python “equivalents”

- vector<int> → list[int]

- array (fixed) → list (or array module rarely)

- unordered_map → dict

- unordered_set/set → set

- priority_queue<int> → heapq (min-heap; push (-x, ...) for max-heap)

- deque → collections.deque

- lower_bound/upper_bound → bisect_left/bisect_right

- sort(v.begin(), v.end(), cmp) → arr.sort(key=...) (use key, not custom comparator)

- pair/tuple/struct → tuple/dataclass (usually tuple)

- i/o (cin/cout) → sys.stdin.readline / sys.stdout.write

# Fast I/O patterns
## many ints on a line
- a,b,c = map(int, input().split())

## big array
- n = int(input())
- arr = list(map(int, input().split()))

## write
- sys.stdout.write(str(ans) + "\n")

# Common snippets
BFS / DFS (avoid deep recursion)
```python
# BFS on unweighted graph
- g = [[] for _ in range(n)]
# fill g
dist = [-1]*n
q = deque([src]); dist[src]=0
while q:
    u = q.popleft()
    for v in g[u]:
        if dist[v] == -1:
            dist[v] = dist[u]+1
            q.append(v)

# Iterative DFS
seen = [False]*n
st = [src]
while st:
    u = st.pop()
    if seen[u]: continue
    seen[u] = True
    for v in g[u]:
        if not seen[v]:
            st.append(v)

# Dijkstra

INF = 10**18
dist = [INF]*n
dist[s] = 0
pq = [(0, s)]
while pq:
    d,u = heappop(pq)
    if d != dist[u]: continue
    for v,w in g[u]:
        nd = d + w
        if nd < dist[v]:
            dist[v] = nd
            heappush(pq, (nd, v))

# Union–Find (DSU)
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1]*n
    def find(self, x):
        while x != self.p[x]:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x
    def unite(self, a,b):
        a,b = self.find(a), self.find(b)
        if a==b: return False
        if self.sz[a] < self.sz[b]:
            a,b = b,a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True

#Binary search on answer
def ok(x):
    # predicate
    return True

lo, hi = 0, 10**18
while lo < hi:
    mid = (lo + hi)//2
    if ok(mid): hi = mid
    else: lo = mid+1
# lo is minimal feasible

#Combinatorics / mod
MOD = 10**9+7
# fast pow: pow(a,b,MOD)
# modular inverse (Python 3.8+): pow(a, -1, MOD)
from math import comb  # nCk exact ints (handles big)

# Prefix sums & 2D
pref = [0]
for x in arr: pref.append(pref[-1]+x)
# range sum [l,r): pref[r]-pref[l]

#Sliding window
best = cur = 0
l = 0
for r,x in enumerate(arr):
    cur += x
    while condition_to_shrink:
        cur -= arr[l]; l += 1
    best = max(best, cur)

```

# Performance tips (Python vs C++)

- Use PyPy 3 if allowed—usually faster on loop-heavy tasks.

- Prefer iterative over deep recursive DFS (recursion limit/overhead). If needed: sys.setrecursionlimit(1_000_000).

- Use local variables inside hot loops (bind functions/attrs to names).

- Heavy counts/multisets: Counter, defaultdict(int).

- Avoid per-element string concatenation; collect in list then "".join.

# Typical safe upper bounds:

- O(n log n) up to ~2e5 is fine; pure O(n^2) on 1e5 is not.

- Don’t import big libs (numpy) — most judges disallow or it’s slow to start.

# Idioms you’ll use a lot
# sort by two keys, then descending second
- arr.sort(key=lambda x: (x[0], -x[1]))

```python
# k-th smallest/largest
import heapq
heapq.heapify(arr)         # min-k pop k times
# or for top-k largest:
largest_k = heapq.nlargest(k, arr)  # uses key=... if needed

# frequency map
freq = Counter(arr)

# dedup while keeping order
seen=set(); out=[]
for x in arr:
    if x not in seen:
        seen.add(x); out.append(x)
```

# Gotchas moving from C++

- No built-in max-heap: use heapq with negated values or tuples.

- Comparators: use key=; Python doesn’t accept custom less-than for sort on the fly.

- Integers are unbounded (no overflow), but modulo logic still needed if problem requires it.

- Strings are immutable; slicing is O(k).

Be careful with recursion depth/timeouts.