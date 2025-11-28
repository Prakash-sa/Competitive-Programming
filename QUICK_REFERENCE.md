# Quick Reference: Algorithm Selection Guide

## 🎯 How to Pick the Right Algorithm

### Problem Recognition Checklist

#### **1. Sorting & Searching Problems**
- **"Find pair with sum X"** → Two pointers + sort
- **"Median of stream"** → Heaps
- **"Count inversions"** → Merge sort or Fenwick
- **"Kth element"** → Quickselect (average O(n))
- **"Boolean search"** → Binary search on answer
- **Range small"** → Radix sort

**Go to:** `python/Sorting/SORTING_ENHANCED.md`

---

#### **2. Greedy Problems**
- **"Maximize count of..."** → Sort + greedy pick
- **"Minimize sum of..."** → Greedy with heap
- **"Arrange with constraints"** → Greedy rearrangement
- **"Covering with min..."** → Interval greedy
- **"Deadline based"** → EDF (earliest deadline first)
- **"Can we achieve X?"** → Binary search + greedy check

**Test:** Does exchange argument work? Can I swap elements?

**Go to:** `python/Greedy/GREEDY_ENHANCED.md`

---

#### **3. Dynamic Programming**
- **"Count ways to..."** → DP with combinations
- **"Min/max cost to..."** → DP with recurrence
- **"String matching"** → LCS/Edit distance
- **"Sequence with constraints"** → DP on states
- **"Can we select..."** → 0/1 knapsack DP
- **Large recurrence O(n³)"** → CHT optimization
- **Tiling/filling grid"** → Profile DP
- **n ≤ 20, all subsets"** → Bitmask DP
- **n ≤ 40, subset property"** → Meet-in-middle
- **Tree rooted multiple ways"** → Rerooting DP

**Optimization checks:**
- Monotonic k → Knuth-Yao
- Linear transitions → CHT
- Quadrangle inequality → Divide & conquer

**Go to:** `python/Dynamic Programming/DP_ENHANCED.md`

---

#### **4. Graph Problems**
- **"Find shortest path"** → Dijkstra/BFS
- **"All pairs shortest"** → Floyd-Warshall
- **"Negative weights"** → Bellman-Ford
- **"Maximum flow"** → Dinic or push-relabel
- **"Min cost flow"** → Successive shortest paths
- **"Boolean formula"** → 2-SAT solver
- **"Must visit all edges"** → Eulerian path
- **"Remove vertex to disconnect"** → Articulation points
- **"Remove edge to disconnect"** → Bridge finding
- **"Strongly connected"** → SCC/Tarjan
- **"All reachable"** → DFS/BFS

**Go to:** `python/Graph/GRAPH_ENHANCED.md`

---

#### **5. Tree Problems**
- **"Subtree sum queries"** → Euler tour + Fenwick
- **"Path sum queries"** → HLD + Segment tree
- **"LCA distance"** → Binary lifting
- **"Longest path"** → Tree diameter
- **"All roots answer"** → Rerooting DP
- **"Find centroids"** → Centroid decomposition
- **"Max XOR on path"** → XOR basis
- **"Dynamic edges"** → Link-cut tree
- **"Batch node operations"** → Virtual tree
- **"No recursion space"** → Morris traversal

**Go to:** `python/Binary Tree/TREE_ENHANCED.md`

---

## ⚡ Quick Algorithm Complexity Reference

### Sorting & Searching
```
Binary Search:        O(log n)      → Monotonic predicate
Two Pointers:         O(n log n)    → After sorting
Inversion Count:      O(n log n)    → Merge sort
Radix Sort:           O(n)          → When range small
Exponential Search:   O(log n)      → Unbounded arrays
```

### Greedy
```
Interval Scheduling:  O(n log n)    → Sort by end time
Job Scheduling:       O(n log n)    → With DSU
Huffman Coding:       O(n log n)    → Build from leaf
Dijkstra:             O(E log V)    → With heap
MST (Kruskal):        O(E log E)    → Sort edges
```

### DP
```
Knapsack 0/1:         O(nW)         → Weight bounded
LCS:                  O(n × m)      → String matching
DP + CHT:             O(n log n)    → Linear recurrence
DP + Knuth-Yao:       O(n² log n)   → Quadrangle inequality
Bitmask DP:           O(n² × 2ⁿ)    → n ≤ 20
Meet-in-Middle:       O(2^(n/2))    → n ≤ 40
```

### Graphs
```
DFS/BFS:              O(V + E)      → Traversal
Dijkstra:             O(E log V)    → Shortest paths
Floyd-Warshall:       O(V³)         → All pairs
Bellman-Ford:         O(VE)         → Negative weights
Dinic Max Flow:       O(V²E)        → Maximum flow
Tarjan SCC:           O(V + E)      → Components
2-SAT:                O(V + E)      → Satisfiability
```

### Trees
```
DFS/BFS:              O(V)          → Basic traversal
LCA Binary Lifting:   O(log V)      → Preprocessing O(V log V)
HLD + SegTree:        O(log² V)     → Path queries
Centroid Decomp:      O(log V)      → Query on centroids
Tree DP:              O(V)          → Single pass
Rerooting:            O(V)          → All nodes as root
Euler Tour:           O(V)          → Build tour
Fenwick on Tree:      O(log V)      → Subtree updates
```

---

## 🔍 Pattern Recognition Table

| Phrase in Problem | Likely Algorithm | Reference |
|-------------------|------------------|-----------|
| "maximize/minimize" | Greedy or DP | Check exchange arg |
| "count ways" | DP | Look for recurrence |
| "shortest path" | Dijkstra/BFS | Check weights |
| "all pairs" | Floyd-W or DFS | Size of V |
| "flow" | Max flow/min cost | Look for capacity |
| "tree" | See tree section | Root choice |
| "subset" | Bitmask if n≤20 | Count subsets |
| "coordinate" | Compress values | If range huge |
| "bit" | XOR basis / bitwise | Max XOR queries |
| "rearrange" | Greedy/sorting | Check constraints |
| "interval/segment" | Interval DP/greedy | Merging/covering |
| "boolean" | 2-SAT | Formula satisfying |
| "bridge/articulation" | Tarjan DFS | Graph structure |
| "meeting/room/schedule" | Greedy events | Sweep line |
| "matrix chain" | DP + CHT | Optimization |

---

## 🚀 Solution Template Selector

```python
# Template 1: Greedy with sorting + binary search
def greedy_binary_search(arr, target):
    arr.sort()
    
    def can_achieve(x):
        # Greedy check for feasibility
        return True or False
    
    lo, hi = 0, 10**18
    while lo < hi:
        mid = (lo + hi) // 2
        if can_achieve(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo
```

```python
# Template 2: DP on intervals
def interval_dp(n, cost_func):
    INF = float('inf')
    dp = [[INF] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = cost_func(i, i)
    
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], 
                              dp[i][k] + dp[k+1][j] + cost_func(i, j))
    
    return dp[0][n-1]
```

```python
# Template 3: Tree with Euler tour + Fenwick
def tree_query_with_fenwick(n, edges, values):
    # Build tree, Euler tour, create Fenwick
    # Update subtree: ft.update(tin[u], delta)
    # Query subtree: ft.query(tin[u], tout[u])
    pass
```

```python
# Template 4: 2-SAT solver
def solve_2sat(n, clauses):
    # Build implication graph
    # Find SCCs
    # Check satisfiability & extract solution
    pass
```

---

## 📊 Problem Difficulty Progression

### Beginner (1200-1400)
- Sorting + two pointers
- Basic greedy (no proof needed)
- Simple DP (fibonacci, knapsack)
- BFS/DFS basics
- Tree traversal

### Intermediate (1400-1700)
- Greedy proofs required
- DP on strings/grid
- Dijkstra/shortest paths
- Tree DP + rerooting
- Bitmask DP (n ≤ 15)

### Advanced (1700-2000)
- Advanced greedy combinations
- DP optimizations (CHT basic)
- Tree with HLD/Centroid
- Max flow basics
- Graph connectivity (bridges/APs)

### Expert (2000-2400)
- CHT/Knuth-Yao optimizations
- 2-SAT applications
- Min cost flow
- Centroid decomposition
- Virtual trees
- Meet-in-middle techniques

### Master (2400+)
- All advanced techniques
- Custom data structures
- Hybrid algorithms
- Novel problem combinations
- Link-Cut trees
- Persistent data structures

---

## 💪 Speed Tips

1. **Pre-code your templates** - Have them ready to paste
2. **Use Fast I/O** - `sys.stdin.readline` is critical
3. **Avoid TLE**:
   - Don't sort unnecessarily (only when needed)
   - Use appropriate DS (dict vs list vs set)
   - Optimize constants (10^6 operations safe)
4. **Debug Fast**:
   - Print intermediate values
   - Check boundary conditions
   - Test on given examples first

---

## 📚 Study Path

1. **Week 1-2**: Master Sorting + Basic Greedy
2. **Week 3-4**: DP foundations + 1D DP patterns
3. **Week 5-6**: 2D DP + Tree DP
4. **Week 7-8**: Graph algorithms
5. **Week 9-10**: Advanced DP optimizations
6. **Week 11-12**: Tree advanced techniques
7. **Week 13-14**: Integration + mixed problems

---

## ✅ Before Submitting Code

- [ ] Read problem statement twice
- [ ] Trace through examples
- [ ] Check edge cases (n=1, empty, all same)
- [ ] Verify I/O format
- [ ] Test on given examples
- [ ] Check time/space complexity
- [ ] Look for integer overflow
- [ ] Use assert for invariants

---

**Remember: Pattern recognition comes from solving 200+ problems!**
**Start with easier patterns, gradually move to advanced techniques.**
