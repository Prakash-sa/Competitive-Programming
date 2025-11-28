0. How to Think Greedy (for CF)

Typical signals:

Constraints ~ 2e5 per test and solution seems too fast for DP.

Statement suggests “take largest/smallest X”, “minimize/maximize something” by reordering or picking subsequences.

Ordering matters: usually you can sort / sweep / pick locally optimal.

How to justify:

Exchange argument: Show that if an optimal solution doesn’t use your local choice, you can swap without making it worse.

Monovariant: Some measure always improves (or never worsens) every step.

You don’t need full proofs in contests, but you should know which classic problem your solution resembles.

1. Sort + Take Best Locally
1.1 Interval Scheduling (Max Non-Overlapping Intervals)

“Given intervals, choose maximum number of non-overlapping segments.”

Greedy rule:
Sort by end time, always take the interval that finishes earliest and is compatible with current.

Template:

def max_non_overlapping(intervals):
    # intervals: list of (l, r)
    intervals.sort(key=lambda x: x[1])  # sort by end
    cnt = 0
    last_end = -10**18
    for l, r in intervals:
        if l >= last_end:
            cnt += 1
            last_end = r
    return cnt


Variants:

Maximize tasks you can do.

Maximize number of meetings in one room.

1.2 Covering Points with Minimum Segments / Points

“Given intervals, choose minimum number of points so that each segment contains at least one point.”

Greedy rule:
Sort by end, always place a point at the end of the first segment, then skip all segments covered by that point.

def min_points_to_cover(intervals):
    intervals.sort(key=lambda x: x[1])
    points = []
    last_point = -10**18
    for l, r in intervals:
        if l > last_point:
            last_point = r
            points.append(last_point)
    return points  # list of chosen points

1.3 Interval Covering [L, R] with Min Segments

“Cover [L, R] using given segments, minimize segments used or decide impossible.”

Greedy rule:
Sort by start, then at each step, take the segment with maximal end among all segments whose start ≤ current coverage.

def cover_range(segments, L, R):
    segments.sort()  # sort by (l, r)
    res = []
    i, n = 0, len(segments)
    cur = L
    while cur < R:
        best_end = cur
        best_idx = -1
        while i < n and segments[i][0] <= cur:
            if segments[i][1] > best_end:
                best_end = segments[i][1]
                best_idx = i
            i += 1
        if best_idx == -1:
            return None  # impossible
        res.append(segments[best_idx])
        cur = best_end
    return res


This pattern appears in CF often (covering line / circle, etc.).

2. Two Pointers / Sliding Window Greedy

Arrays / strings, non-negative constraints, choose longest/shortest segment satisfying something.

2.1 Longest Subarray with Sum ≤ K (Non-negative)
def longest_subarray_sum_leq_k(a, K):
    n = len(a)
    l = 0
    s = 0
    best = 0
    for r in range(n):
        s += a[r]
        while s > K and l <= r:
            s -= a[l]
            l += 1
        best = max(best, r - l + 1)
    return best


Patterns:

Longest substring with ≤ K distinct characters.

Smallest window satisfying sum ≥ K.

Move r forward, fix violation by moving l.

2.2 Two Pointers on Sorted Arrays

Use when:

You need pairs (i, j) with a[i] + b[j] satisfying something.

You need to count “how many pairs satisfy …”.

def count_pairs_leq(a, b, X):
    a.sort()
    b.sort()
    j = len(b) - 1
    cnt = 0
    for i in range(len(a)):
        while j >= 0 and a[i] + b[j] > X:
            j -= 1
        cnt += (j + 1)
    return cnt


Often used inside binary search on X.

3. Greedy + Priority Queue (heap)
3.1 Scheduling with Deadlines (Max #tasks)

Each task: duration t, deadline d. Maximize number of tasks finished before deadline.

Greedy rule:

Sort tasks by deadline.

Iterate, keep total time and a max-heap of durations.

If total > current deadline, remove the task with largest duration.

import heapq

def max_tasks(tasks):
    # tasks: list of (t, d)
    tasks.sort(key=lambda x: x[1])
    total = 0
    heap = []  # max-heap via negative values
    for t, d in tasks:
        total += t
        heapq.heappush(heap, -t)
        if total > d:
            largest = -heapq.heappop(heap)
            total -= largest
    return len(heap)


Variants:

Maximize score with penalties.

Minimize lateness/overdue tasks.

3.2 Always Take Smallest / Largest Available

You repeatedly pick an element with min or max “cost” among available ones.

Examples:

Always take smallest edge (MST Kruskal).

Always take smallest cost item until budget exceeded.

Assign jobs to machines (take machine with earliest finish).

Template:

import heapq

def greedy_heap_process(values):
    heapq.heapify(values)  # min-heap
    ans = 0
    while values:
        x = heapq.heappop(values)
        # do greedy step with x
        ans += x
    return ans


In CF, often you maintain a heap of “currently possible” items where feasibility grows over time (like events over coordinates or time).

4. Monotonic Stack Greedy (Arrays / Strings)
4.1 Remove K Digits for Smallest Number

Given a string num, remove k digits to get lexicographically smallest / numerically smallest result.

Greedy rule:
Scan left to right; keep a stack that’s monotonically increasing (for smallest); whenever new character c is smaller than stack top and k > 0, pop.

def remove_k_digits(num: str, k: int) -> str:
    stack = []
    for c in num:
        while k > 0 and stack and stack[-1] > c:
            stack.pop()
            k -= 1
        stack.append(c)
    # if still k left, remove from end
    while k > 0 and stack:
        stack.pop()
        k -= 1
    # strip leading zeros
    res = ''.join(stack).lstrip('0')
    return res if res else "0"


This pattern generalizes to:

Make lexicographically smallest subsequence of length k.

Remove k characters to make largest/smallest possible.

4.2 Next Greater Element / Maintaining Monotonic Stack

Not always “greedy optimization”, but heavily used.

def next_greater_elements(a):
    n = len(a)
    res = [-1] * n
    stack = []  # indices, stack is decreasing in a[i]
    for i in range(n):
        while stack and a[stack[-1]] < a[i]:
            idx = stack.pop()
            res[idx] = a[i]
        stack.append(i)
    return res


Use this whenever problem needs “next greater/smaller element” or something like “stock span”.

5. Greedy on Graphs
5.1 MST – Kruskal (Classic Greedy)

Find minimum spanning tree of connected, weighted, undirected graph.

Greedy rule:
Sort edges by weight; add the lightest edge that doesn’t form a cycle.

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b: return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True

def kruskal(n, edges):
    # edges: list of (w, u, v)
    edges.sort()
    dsu = DSU(n)
    mst = 0
    used = []
    for w, u, v in edges:
        if dsu.union(u, v):
            mst += w
            used.append((u, v, w))
    # if len(used) < n-1 => not connected
    return mst, used

5.2 Dijkstra as Greedy

Single-source shortest paths with non-negative weights.

Greedy rule:
Always fix the vertex with smallest tentative distance (from a PQ) – once taken, it’s final.

import heapq

def dijkstra(n, adj, src):
    # adj[u] = [(v, w), ...]
    INF = 10**18
    dist = [INF] * n
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


If edges can be negative, plain greedy fails — you move to Bellman-Ford or other methods.

6. Greedy + Binary Search on Answer

Big pattern on CF:

You need to find max/min possible value X.

For a fixed X, you can check feasibility using greedy.

Structure:

def can(X, params):
    # Greedy check: for this candidate X, can we satisfy constraints?
    # Return True / False
    pass

def binary_search_answer(lo, hi, params):
    while lo < hi:
        mid = (lo + hi) // 2
        if can(mid, params):
            hi = mid
        else:
            lo = mid + 1
    return lo

Example: Placing Cows with Min Distance ≥ D

Given sorted stalls a[], can we place k cows with at least distance D?

def can_place(a, k, D):
    cnt = 1
    last = a[0]
    for x in a[1:]:
        if x - last >= D:
            cnt += 1
            last = x
            if cnt == k:
                return True
    return False

def max_min_distance(a, k):
    a.sort()
    lo, hi = 0, a[-1] - a[0] + 1
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if can_place(a, k, mid):
            lo = mid
        else:
            hi = mid
    return lo


This pattern is everywhere:

Minimize max segment sum (split array).

Minimize max height difference after operations.

Maximize minimal sweetness, etc.

7. Greedy via Counting / Frequencies

Many CF problems are about rearranging strings/arrays with frequency constraints.

7.1 Rearranging So No Two Adjacent Equal

Given characters and counts, build string so that no two adjacents equal, or report impossible.

Greedy rule:
Always pick the character with highest remaining count that is different from previous.

import heapq
from collections import Counter

def rearrange_no_adjacent(s):
    cnt = Counter(s)
    # max-heap: (-freq, char)
    heap = [(-f, c) for c, f in cnt.items()]
    heapq.heapify(heap)
    prev = (0, '')
    res = []
    while heap or prev[0] < 0:
        if not heap and prev[0] < 0:
            return None  # impossible
        f, c = heapq.heappop(heap)
        res.append(c)
        # push prev back
        if prev[0] < 0:
            heapq.heappush(heap, prev)
        # decrement freq
        prev = (f + 1, c)  # because f is negative
    return ''.join(res)


Variants:

Building lexicographically smallest valid string under constraints.

Choose most frequent / least frequent first.

8. Classic Coin/Change-Type Greedy

Works only for canonical coin systems (like usual currency, or specific constraints coded in problem).

8.1 Minimum Coins (Canonical Systems)
def min_coins(n, coins):
    coins.sort(reverse=True)
    cnt = 0
    for c in coins:
        take = n // c
        cnt += take
        n -= take * c
    return cnt


On CF, more common: minimum banknotes or some custom coin system where problem setter guarantees greedy works.

9. Constructive Greedy – Build Answer Character by Character

You often see:

“Find lexicographically smallest string/sequence satisfying conditions.”

General pattern:

Iterate over positions.

For each position, try values in order (e.g., 'a'..'z').

For each candidate, check if rest can be completed (sometimes with greedy or feasibility check).

Simple template:

def build_string(n, alphabet, is_ok_prefix):
    res = []
    for pos in range(n):
        for c in alphabet:
            res.append(c)
            if is_ok_prefix(res):
                break
            res.pop()
        else:
            return None  # impossible
    return ''.join(res)


is_ok_prefix should be a fast greedy feasibility check (“Can this prefix be extended to full solution?”). This appears in problems about periodicity, pattern constraints, subsequences etc.

10. Putting It Together for Codeforces

When you read a CF problem, mentally run this checklist:

Does it look like intervals / covering / scheduling?
→ Sort by start/end, interval greedy.

Is it about subarrays / substrings with constraints?
→ Two pointers / sliding window.

Is there “do X many times, picking one element each time”?
→ Priority queue, always pick best candidate.

Array/string transform with “remove K”, “smallest/largest lexicographically”?
→ Monotonic stack greedy.

Graph with non-negative weights and “shortest path”
→ Dijkstra (greedy on distances).

Graph with “connect everything with minimal cost”
→ MST (Kruskal/Prim).

Min/max some value with constraints – monotone feasibility
→ Binary search + greedy can(mid).

Reordering elements under frequency constraints
→ Heap over counts, always pick best allowed.

Coin-like or numeric decomposition, problem says greedy is fine
→ Largest-first greed.
