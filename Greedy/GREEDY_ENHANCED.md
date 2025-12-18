# Greedy Algorithms - ENHANCED GUIDE

## 0. Understanding Greedy: When & Why It Works

**Greedy WORKS when:**
1. **Optimal Substructure**: Optimal solution contains optimal solutions to subproblems
2. **Greedy Choice Property**: Local optimal choice leads to global optimum
3. **Proof by Exchange Argument**: If non-greedy solution exists, we can swap to greedy without worsening

**Greedy FAILS when:**
- Changing one element affects optimal choices for others → Use DP
- Future choices depend on past decisions in complex ways → Use DP
- Need to consider multiple paths → Use Dijkstra/BFS

---

## 1. Interval Problems (Comprehensive)

### 1.1 Maximum Non-Overlapping Intervals (Classic)
```python
def max_non_overlapping_intervals(intervals):
    """
    Sort by end time, greedily pick earliest ending intervals.
    Proof: If optimal solution doesn't include earliest-ending interval,
    swap it in without affecting feasibility.
    """
    intervals.sort(key=lambda x: x[1])
    count = 0
    last_end = float('-inf')
    
    for start, end in intervals:
        if start > last_end:  # > for open intervals, >= for closed
            count += 1
            last_end = end
    
    return count

# Variants:
# - Weighted intervals: Use DP (not greedy)
# - Meeting rooms: Use sorting + heap
# - Task scheduling: Similar approach
```

### 1.2 Covering Points with Minimum Line Segments
```python
def min_segments_to_cover_points(points, segment_length):
    """
    Cover all points with minimum segments of given length.
    Greedy: place each segment's right end as far right as possible.
    """
    points.sort()
    segments = 0
    i = 0
    n = len(points)
    
    while i < n:
        # Start segment at points[i], end at points[i] + segment_length
        segments += 1
        current_end = points[i] + segment_length
        
        # Skip all points covered by this segment
        while i < n and points[i] <= current_end:
            i += 1
    
    return segments

# Use when: covering points on a line, each point needs coverage
```

### 1.3 Activity Selection with Weights
```python
def weighted_job_scheduling(jobs):
    """
    jobs: list of (start, end, profit)
    Find maximum profit subset of non-overlapping jobs.
    This REQUIRES DP, not pure greedy!
    """
    jobs.sort(key=lambda x: x[1])
    n = len(jobs)
    dp = [0] * n
    
    def find_latest_job(j):
        """Binary search for latest job that doesn't overlap with job j"""
        left, right = 0, j - 1
        result = -1
        
        while left <= right:
            mid = (left + right) // 2
            if jobs[mid][1] <= jobs[j][0]:
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return result
    
    dp[0] = jobs[0][2]
    
    for i in range(1, n):
        # Include current job
        include = jobs[i][2]
        latest = find_latest_job(i)
        if latest != -1:
            include += dp[latest]
        
        # Exclude current job
        exclude = dp[i - 1]
        
        dp[i] = max(include, exclude)
    
    return dp[n - 1]

# Pure greedy doesn't work here!
```

---

## 2. Scheduling & Deadline Problems

### 2.1 Job Sequencing with Deadlines (Maximize Count)
```python
def job_sequencing_maximize_count(jobs):
    """
    jobs: list of (deadline, profit) or just deadlines
    Maximize number of jobs completed before deadline.
    Greedy: sort by deadline, assign greedily.
    """
    jobs.sort()  # sort by deadline
    max_deadline = max(deadline for deadline, _ in jobs)
    
    available_slots = [False] * (max_deadline + 1)
    completed = 0
    
    for deadline, _ in jobs:
        # Try to place in latest available slot before deadline
        for slot in range(min(deadline, max_deadline), 0, -1):
            if not available_slots[slot]:
                available_slots[slot] = True
                completed += 1
                break
    
    return completed

# With DSU optimization (faster for many jobs):
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)

def job_sequencing_with_dsu(jobs):
    """Same problem but O(n log n) instead of O(n * max_deadline)"""
    jobs.sort(key=lambda x: -x[1])  # sort by profit descending
    max_deadline = max(deadline for deadline, _ in jobs)
    
    dsu = DSU(max_deadline + 1)
    profit = 0
    
    for deadline, p in jobs:
        # Find latest available slot before deadline
        available = dsu.find(min(deadline, max_deadline))
        if available > 0:
            profit += p
            dsu.union(available, available - 1)
    
    return profit
```

### 2.2 Minimizing Lateness (Earliest Deadline First)
```python
def minimize_lateness(jobs):
    """
    jobs: list of (duration, deadline)
    Schedule jobs to minimize maximum lateness.
    Greedy: EDF (Earliest Deadline First)
    """
    jobs.sort(key=lambda x: x[1])  # sort by deadline
    
    current_time = 0
    max_lateness = 0
    
    for duration, deadline in jobs:
        current_time += duration
        lateness = max(0, current_time - deadline)
        max_lateness = max(max_lateness, lateness)
    
    return max_lateness

# Proof: If two adjacent jobs are out of deadline order,
# swapping reduces maximum lateness. Therefore, EDF is optimal.
```

---

## 3. Huffman Coding & Merging Patterns

### 3.1 Huffman Coding (Optimal Prefix-Free Code)
```python
import heapq

def huffman_coding(frequencies):
    """
    Create optimal prefix-free binary code.
    Greedy: always merge two smallest frequency nodes.
    """
    if len(frequencies) == 1:
        return {list(frequencies.keys())[0]: '0'}
    
    # Min heap: (freq, unique_id, node)
    heap = [(freq, i, char) for i, (char, freq) in enumerate(frequencies.items())]
    heapq.heapify(heap)
    
    counter = len(frequencies)
    codes = {}
    
    while len(heap) > 1:
        freq1, _, left = heapq.heappop(heap)
        freq2, _, right = heapq.heappop(heap)
        
        merged_freq = freq1 + freq2
        heapq.heappush(heap, (merged_freq, counter, (left, right)))
        counter += 1
    
    def generate_codes(node, prefix=''):
        if isinstance(node, str):
            codes[node] = prefix if prefix else '0'
        else:
            left, right = node
            generate_codes(left, prefix + '0')
            generate_codes(right, prefix + '1')
    
    _, _, root = heap[0]
    generate_codes(root)
    
    return codes

# Use when: Data compression, optimal binary tree construction
```

### 3.2 Minimum Cost to Connect Ropes
```python
def min_cost_connect_ropes(ropes):
    """
    Connect ropes by joining two smallest first.
    Cost to join two ropes = sum of their lengths.
    Minimize total cost.
    """
    import heapq
    
    heap = list(ropes)
    heapq.heapify(heap)
    total_cost = 0
    
    while len(heap) > 1:
        rope1 = heapq.heappop(heap)
        rope2 = heapq.heappop(heap)
        
        cost = rope1 + rope2
        total_cost += cost
        heapq.heappush(heap, cost)
    
    return total_cost

# Greedy proof: Always combine smallest ropes first
# because larger ropes will be "handled" multiple times
```

---

## 4. String & Character Rearrangement

### 4.1 Reorganize String (No Adjacent Duplicates)
```python
def reorganize_string(s):
    """
    Rearrange string so no two adjacent characters are same.
    Greedy: always pick character with highest remaining count.
    """
    from collections import Counter
    import heapq
    
    count = Counter(s)
    max_char = max(count, key=count.get)
    
    if count[max_char] > (len(s) + 1) // 2:
        return ""  # impossible
    
    # Max heap (negative counts)
    heap = [(-cnt, ch) for ch, cnt in count.items()]
    heapq.heapify(heap)
    
    result = []
    prev_cnt, prev_ch = 0, ''
    
    while heap:
        cnt, ch = heapq.heappop(heap)
        cnt = -cnt
        
        result.append(ch)
        
        if prev_cnt > 0:
            heapq.heappush(heap, (-prev_cnt, prev_ch))
        
        cnt -= 1
        prev_cnt, prev_ch = cnt, ch
    
    return ''.join(result) if len(result) == len(s) else ""

# Use when: Valid arrangement exists, maximize using greedy pick
```

### 4.2 Lexicographically Smallest String After Removals
```python
def smallest_string_after_k_removals(s, k):
    """
    Remove k characters to get lexicographically smallest remaining string.
    Greedy: maintain monotonically increasing stack.
    """
    stack = []
    to_remove = k
    
    for ch in s:
        while to_remove > 0 and stack and stack[-1] > ch:
            stack.pop()
            to_remove -= 1
        stack.append(ch)
    
    # If k characters still remain, remove from end
    while to_remove > 0:
        stack.pop()
        to_remove -= 1
    
    return ''.join(stack)

# Use when: Lexicographic optimization with removals
```

---

## 5. Greedy on Graphs

### 5.1 Kruskal's MST (Greedy Edge Selection)
```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] < self.rank[pb]:
            pa, pb = pb, pa
        self.parent[pb] = pa
        if self.rank[pa] == self.rank[pb]:
            self.rank[pa] += 1
        return True

def kruskal_mst(n, edges):
    """
    Find MST using greedy edge selection.
    Greedy: always pick cheapest edge that doesn't form cycle.
    """
    edges.sort(key=lambda x: x[2])
    dsu = DSU(n)
    mst_cost = 0
    edges_used = 0
    
    for u, v, w in edges:
        if dsu.union(u, v):
            mst_cost += w
            edges_used += 1
            if edges_used == n - 1:
                break
    
    return mst_cost if edges_used == n - 1 else -1

# Proof: Cut property - minimum weight edge crossing any cut
# can be in some MST, so greedily selecting always works.
```

### 5.2 Dijkstra's Algorithm (Greedy on Distances)
```python
import heapq

def dijkstra_greedy(n, adj, src):
    """
    Shortest paths from src to all nodes.
    Greedy: always process nearest unprocessed node.
    """
    dist = [float('inf')] * n
    dist[src] = 0
    visited = [False] * n
    pq = [(0, src)]
    
    while pq:
        d, u = heapq.heappop(pq)
        
        if visited[u]:
            continue
        visited[u] = True
        
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    
    return dist

# Why greedy works: Non-negative weights guarantee that
# the closest unprocessed node's distance is final.
```

---

## 6. Binary Search + Greedy Combination

### 6.1 Aggressive Cows (Binary Search Answer + Greedy Check)
```python
def aggressive_cows(stalls, k):
    """
    Place k cows in stalls to maximize minimum distance between any two.
    Binary search on the answer (minimum distance).
    """
    stalls.sort()
    
    def can_place_with_min_distance(min_dist):
        """Greedy check: can we place k cows with >= min_dist between them?"""
        count = 1
        last_pos = stalls[0]
        
        for i in range(1, len(stalls)):
            if stalls[i] - last_pos >= min_dist:
                count += 1
                last_pos = stalls[i]
                if count == k:
                    return True
        
        return False
    
    lo, hi = 0, stalls[-1] - stalls[0]
    
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if can_place_with_min_distance(mid):
            lo = mid
        else:
            hi = mid - 1
    
    return lo

# Pattern: Binary search on answer + greedy feasibility check
```

---

## 7. Common Greedy Failures & Why

| Problem | Wrong Greedy | Why Fails | Correct Approach |
|---------|--------------|----------|------------------|
| Weighted job scheduling | Pick highest profit first | Might skip earlier jobs needed for later bigger ones | DP with binary search |
| 0-1 Knapsack | Pick highest value/weight ratio | Might leave gaps; need exact capacity | DP |
| Coin change (custom coins) | Largest coin first | Not always optimal for arbitrary coin systems | DP |
| Shortest path (negative edges) | Greedy nearest | Negative cycles invalidate greedy assumption | Bellman-Ford |
| Graph coloring | Color greedily | Uses O(n) colors when optimal might be O(log n) | 2-coloring / Approximation |
| Activity with weights | Sort by efficiency | Can miss globally optimal selections | DP |

---

## 8. Proof Techniques for Greedy Correctness

### 8.1 Exchange Argument Template
```
Theorem: Greedy algorithm G produces optimal solution.

Proof by contradiction:
1. Suppose optimal solution OPT ≠ G
2. Find first position where they differ: G[i] ≠ OPT[i]
3. Show that swapping OPT[i] ← G[i] gives solution ≥ OPT
4. Continue until OPT = G
5. Contradiction: OPT was optimal but we improved it
```

### 8.2 Monovariant / Potential Function
```
Show that greedy choice maintains an invariant:
- Define measure φ that improves (or doesn't worsen) at each step
- Prove that φ(greedy) ≥ φ(any other choice)
- Therefore, greedy is optimal
```

---

## 9. Putting It All Together

**Decision tree for when to use greedy:**
1. Does statement mention "minimize/maximize" + "pick locally best"? → Maybe greedy
2. Can I justify with exchange argument? → Likely greedy
3. Can I verify on small examples? → Test it
4. Is there overlapping subproblems? → Use DP instead
5. Does local choice affect future decisions? → Use DP instead
