# �� Greedy Algorithm Fundamentals

## 🧠 How to Think Greedy

**Problem signals:**
- Constraints ~2e5 (too fast for DP)
- "Take largest/smallest X", "minimize/maximize" by reordering
- Local optimal choices seem to work globally

**Justification:**
- **Exchange argument:** Swap in an optimal solution without making it worse
- **Monovariant:** Some measure always improves (or never worsens)

---

## 1️⃣ Sort + Take Best Locally

### 1.1 Interval Scheduling (Max Non-Overlapping)

```python
def max_non_overlapping(intervals):
    """Greedy: sort by end time, always take earliest finish"""
    intervals.sort(key=lambda x: x[1])
    cnt, last_end = 0, -10**18
    for l, r in intervals:
        if l >= last_end:
            cnt += 1
            last_end = r
    return cnt
```

### 1.2 Covering Points with Minimum Points

```python
def min_points_to_cover(intervals):
    """Place one point at end of each, skip covered intervals"""
    intervals.sort(key=lambda x: x[1])
    points = []
    last = -10**18
    for l, r in intervals:
        if l > last:
            last = r
            points.append(last)
    return points
```

### 1.3 Interval Covering [L, R] with Min Segments

```python
def cover_range(segments, L, R):
    """Take segment with max end among valid starts"""
    segments.sort()
    i, cur, res = 0, L, []
    while cur < R:
        best_end = cur
        while i < len(segments) and segments[i][0] <= cur:
            best_end = max(best_end, segments[i][1])
            i += 1
        if best_end == cur:
            return None  # impossible
        res.append((cur, best_end))
        cur = best_end
    return res
```

---

## 2️⃣ Two Pointers / Sliding Window Greedy

### 2.1 Longest Subarray with Sum ≤ K

```python
def longest_subarray_sum_leq(a, K):
    l = best = s = 0
    for r in range(len(a)):
        s += a[r]
        while s > K and l <= r:
            s -= a[l]
            l += 1
        best = max(best, r - l + 1)
    return best
```

### 2.2 Two Pointers on Sorted Arrays

```python
def count_pairs_leq(a, b, X):
    """Count pairs (a[i], b[j]) where sum <= X"""
    a.sort()
    b.sort()
    j = len(b) - 1
    cnt = 0
    for i in range(len(a)):
        while j >= 0 and a[i] + b[j] > X:
            j -= 1
        cnt += (j + 1)
    return cnt
```

---

## 3️⃣ Greedy + Priority Queue

### 3.1 Scheduling with Deadlines (Max Tasks)

```python
import heapq

def max_tasks(tasks):
    """Each task: (duration, deadline). Maximize completed."""
    tasks.sort(key=lambda x: x[1])  # sort by deadline
    total = 0
    heap = []
    for t, d in tasks:
        total += t
        heapq.heappush(heap, -t)  # max-heap
        if total > d:
            largest = -heapq.heappop(heap)
            total -= largest
    return len(heap)
```

### 3.2 Always Take Best Available

```python
import heapq

def greedy_heap_process(values):
    """Repeatedly pick min-cost element"""
    heapq.heapify(values)
    ans = 0
    while values:
        x = heapq.heappop(values)
        ans += x
    return ans
```

---

## 4️⃣ Monotonic Stack Greedy

### 4.1 Remove K Digits for Smallest Number

```python
def remove_k_digits(num: str, k: int) -> str:
    """Lexicographically smallest after removing k digits"""
    stack = []
    for c in num:
        while k > 0 and stack and stack[-1] > c:
            stack.pop()
            k -= 1
        stack.append(c)
    while k:
        stack.pop()
        k -= 1
    res = ''.join(stack).lstrip('0')
    return res if res else "0"
```

### 4.2 Next Greater Element

```python
def next_greater_elements(a):
    """For each element, find next greater in circular array"""
    n = len(a)
    res = [-1] * n
    stack = []
    for i in range(2 * n):
        while stack and a[stack[-1]] < a[i % n]:
            idx = stack.pop()
            res[idx] = a[i % n]
        stack.append(i % n)
    return res
```

---

## 5️⃣ Greedy on Graphs

### 5.1 MST — Kruskal (Greedy with DSU)

```python
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        self.p[b] = a
        return True

def kruskal(n, edges):
    """Minimum spanning tree cost"""
    edges.sort()
    dsu = DSU(n)
    mst_cost = 0
    for w, u, v in edges:
        if dsu.union(u, v):
            mst_cost += w
    return mst_cost
```

### 5.2 Dijkstra (Greedy on Distances)

```python
import heapq

def dijkstra(n, adj, src):
    """Shortest paths from src (non-negative weights)"""
    dist = [10**18] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in adj[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist
```

---

## 6️⃣ Greedy + Binary Search on Answer

```python
def can_place_cows(stalls, k, D):
    """Can place k cows with min distance D?"""
    cnt, last = 1, stalls[0]
    for x in stalls[1:]:
        if x - last >= D:
            cnt += 1
            last = x
            if cnt == k:
                return True
    return False

def max_min_distance(stalls, k):
    """Maximize minimum distance between cows"""
    stalls.sort()
    lo, hi = 0, stalls[-1] - stalls[0]
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if can_place_cows(stalls, k, mid):
            lo = mid
        else:
            hi = mid - 1
    return lo
```

---

## 7️⃣ Greedy via Frequencies

### 7.1 Rearrange: No Two Adjacent Equal

```python
import heapq
from collections import Counter

def rearrange_no_adjacent(s):
    """Build string with no adjacent equal chars"""
    cnt = Counter(s)
    heap = [(-f, c) for c, f in cnt.items()]
    heapq.heapify(heap)
    prev = (0, '')
    res = []
    while heap or prev[0] < 0:
        if not heap and prev[0] < 0:
            return None  # impossible
        f, c = heapq.heappop(heap)
        res.append(c)
        if prev[0] < 0:
            heapq.heappush(heap, prev)
        prev = (f + 1, c)
    return ''.join(res)
```

---

## 8️⃣ Constructive Greedy

```python
def build_lex_smallest(n, alphabet, is_ok_prefix):
    """Build lexicographically smallest valid string"""
    res = []
    for pos in range(n):
        for c in alphabet:
            res.append(c)
            if is_ok_prefix(res):
                break
            res.pop()
        else:
            return None
    return ''.join(res)
```

---

## 📊 Greedy Checklist

- [ ] Intervals → Sort by end, take earliest
- [ ] Subarray/substring → Two pointers or sliding window
- [ ] Pick many times → Priority queue + best choice
- [ ] Remove K chars → Monotonic stack
- [ ] MST → Kruskal (greedy + DSU)
- [ ] Shortest paths → Dijkstra (greedy on dist)
- [ ] Min/max with constraints → Binary search + greedy check
- [ ] Rearrange strings → Frequency + heap

