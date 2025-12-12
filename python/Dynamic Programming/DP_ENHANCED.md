# Dynamic Programming - ENHANCED GUIDE

## Advanced DP Techniques Not in Original

### 1. Convex Hull Trick (CHT) - Fast DP Optimization

**Problem Pattern:**
```
dp[i] = min/max over j: (dp[j] + cost(i,j))
Where cost(i,j) = a[j] * i + b[j]
```

**Naive:** O(n²) - evaluate all previous states
**CHT:** O(n log n) - maintain lower envelope of lines

```python
class ConvexHullTrick:
    """
    Maintain lines of form y = mx + c.
    Query minimum y value for given x.
    """
    def __init__(self):
        self.lines = []  # (m, c)
        self.ptr = 0
    
    def bad(self, l1, l2, l3):
        """Check if l2 is useless (between l1 and l3)"""
        m1, c1 = l1
        m2, c2 = l2
        m3, c3 = l3
        # l2 is bad if intersection(l1,l3) is left of intersection(l1,l2)
        return (c3 - c1) * (m1 - m2) <= (c2 - c1) * (m1 - m3)
    
    def add_line(self, m, c):
        """Add line y = mx + c (m must be decreasing)"""
        while len(self.lines) >= 2 and self.bad(self.lines[-2], self.lines[-1], (m, c)):
            self.lines.pop()
        self.lines.append((m, c))
    
    def query(self, x):
        """Query minimum y for given x"""
        if not self.lines:
            return float('inf')
        
        # Move pointer forward (since x queries are increasing)
        while self.ptr + 1 < len(self.lines):
            m1, c1 = self.lines[self.ptr]
            m2, c2 = self.lines[self.ptr + 1]
            if m1 * x + c1 <= m2 * x + c2:
                break
            self.ptr += 1
        
        m, c = self.lines[self.ptr]
        return m * x + c

# Example: Optimal Binary Search Tree / Weighted Matrix Chain Mult
def optimal_matrix_chain(weights):
    """
    weights[i] = dimension of matrix i.
    Matrix i has size weights[i] x weights[i+1]
    Find minimum scalar multiplications to compute product.
    """
    n = len(weights) - 1
    INF = float('inf')
    dp = [[INF] * n for _ in range(n)]
    
    # Base case: single matrices cost 0
    for i in range(n):
        dp[i][i] = 0
    
    # Fill diagonal by length
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + weights[i] * weights[k+1] * weights[j+1]
                dp[i][j] = min(dp[i][j], cost)
    
    return dp[0][n-1]

# With CHT: O(n²) instead of O(n³)
# Requires monotonicity in k - applicable to many DP problems
```

### 2. Knuth-Yao Speedup

**Condition:** Quadrangle Inequality
```
cost[a][c] + cost[b][d] ≤ cost[a][d] + cost[b][c]  for a ≤ b ≤ c ≤ d
```

**Effect:** Optimal split point k is monotonic
```
opt[i][j-1] ≤ opt[i][j] ≤ opt[i+1][j]
```

```python
def knuth_yao_speedup(n, cost_func):
    """
    DP with quadrangle inequality - O(n² log n) instead of O(n³)
    """
    INF = float('inf')
    dp = [[INF] * n for _ in range(n)]
    opt = [[0] * n for _ in range(n)]  # track optimal split
    
    # Base cases
    for i in range(n):
        dp[i][i] = cost_func(i, i)
        opt[i][i] = i
    
    # Fill by chain length
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            # Only search in [opt[i][j-1], opt[i+1][j]] range
            lo = opt[i][j-1] if j > i else i
            hi = opt[i+1][j] if i+1 < n else j
            
            for k in range(lo, hi + 1):
                val = dp[i][k] + dp[k+1][j] + cost_func(i, j)
                if val < dp[i][j]:
                    dp[i][j] = val
                    opt[i][j] = k
    
    return dp[0][n-1]
```

### 3. DP on Subsets (Traveling Salesman Problem)

```python
def tsp_held_karp(dist):
    """
    Traveling Salesman Problem: visit all cities exactly once, return to start.
    dp[mask][i] = minimum cost to visit cities in mask, ending at city i
    Complexity: O(n² × 2ⁿ)
    """
    n = len(dist)
    INF = float('inf')
    
    # dp[mask][i] = min cost to visit cities in mask, last city is i
    dp = [[INF] * n for _ in range(1 << n)]
    
    # Base: start from city 0
    dp[1][0] = 0
    
    for mask in range(1, 1 << n):
        for u in range(n):
            if not (mask & (1 << u)):
                continue
            if dp[mask][u] == INF:
                continue
            
            # Try extending to unvisited cities
            for v in range(n):
                if mask & (1 << v):
                    continue
                
                new_mask = mask | (1 << v)
                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v])
    
    # Return to start
    full_mask = (1 << n) - 1
    ans = min(dp[full_mask][i] + dist[i][0] for i in range(1, n))
    
    return ans

# For n ≤ 20 only
```

### 4. Profile/Broken Profile DP

```python
def tile_grid_broken_profile(width, height):
    """
    Tile a grid with 1×2 tiles. Count number of ways.
    Uses "profile" - which cells in current column are filled.
    """
    def solve(col, current_profile, next_profile, row):
        if row == height:
            # Finished current column, move to next
            if col + 1 == width:
                return 1 if next_profile == 0 else 0
            else:
                return dp(col + 1, next_profile, 0, 0)
        
        if (current_profile >> row) & 1:
            # Cell already filled, move to next row
            return solve(col, current_profile, next_profile, row + 1)
        
        # Try horizontal tile (if not in last column)
        result = 0
        if col + 1 < width:
            result += solve(col, current_profile | (1 << row), 
                          next_profile, row + 1)
        
        # Try vertical tile (if next row exists)
        if row + 1 < height and not ((current_profile >> (row + 1)) & 1):
            result += solve(col, current_profile | (1 << row) | (1 << (row + 1)),
                          next_profile, row + 2)
        
        return result
    
    return dp(0, 0, 0, 0)

# Memoization version with caching
def tile_grid_dp(width, height):
    from functools import lru_cache
    
    @lru_cache(maxsize=None)
    def fill(col, profile):
        if col == width:
            return 1 if profile == 0 else 0
        
        return fill_column(col, profile, 0, 0)
    
    @lru_cache(maxsize=None)
    def fill_column(col, current, row, next_profile):
        if row == height:
            return fill(col + 1, next_profile)
        
        if (current >> row) & 1:
            return fill_column(col, current, row + 1, next_profile)
        
        # Horizontal
        result = fill_column(col, current | (1 << row), row + 1, next_profile)
        
        # Vertical
        if row + 1 < height and not ((current >> (row + 1)) & 1):
            result += fill_column(col, current | (1 << row) | (1 << (row + 1)), 
                                row + 2, next_profile)
        
        return result
    
    return fill(0, 0)
```

### 5. DP on Permutations

```python
def permutation_dp(n):
    """
    Count permutations with special properties using bitmask.
    Example: count permutations where no element i is at position i.
    """
    # Derangements: permutations where no element is in original position
    # dp[mask] = ways to arrange elements in mask with no conflicts
    
    dp = [0] * (1 << n)
    dp[0] = 1  # Empty arrangement
    
    for mask in range(1 << n):
        if not dp[mask]:
            continue
        
        # Find first unset bit
        pos = bin(mask).count('1')  # position to fill
        
        for i in range(n):
            if mask & (1 << i):
                continue  # element already used
            
            # Can we place element i at position pos?
            if i != pos:  # No conflict
                new_mask = mask | (1 << i)
                dp[new_mask] += dp[mask]
    
    return dp[(1 << n) - 1]

# For n ≤ 20
```

### 6. Meet-in-the-Middle DP

```python
def subset_sum_meet_middle(arr, target):
    """
    Find if subset of arr sums to target.
    Time: O(n × 2^(n/2)) instead of O(2^n)
    """
    n = len(arr)
    mid = n // 2
    
    # Generate all subset sums for first half
    left_sums = {}
    for mask in range(1 << mid):
        s = 0
        for i in range(mid):
            if mask & (1 << i):
                s += arr[i]
        left_sums[s] = left_sums.get(s, 0) + 1
    
    # Check second half against first
    count = 0
    for mask in range(1 << (n - mid)):
        s = 0
        for i in range(n - mid):
            if mask & (1 << i):
                s += arr[mid + i]
        
        complement = target - s
        if complement in left_sums:
            count += left_sums[complement]
    
    return count

# Useful for large n (up to 40) with small targets
```

### 7. Tree DP with HLD Integration

```python
def tree_dp_with_hld(n, edges, root=0):
    """
    Combine tree DP with Heavy-Light Decomposition for fast path queries.
    """
    from collections import defaultdict
    
    g = defaultdict(list)
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    # Tree decomposition
    sz = [0] * n
    heavy = [-1] * n
    parent = [-1] * n
    depth = [0] * n
    
    def dfs1(u, p):
        parent[u] = p
        sz[u] = 1
        max_child = -1
        
        for v in g[u]:
            if v == p:
                continue
            depth[v] = depth[u] + 1
            dfs1(v, u)
            sz[u] += sz[v]
            
            if sz[v] > (0 if max_child == -1 else sz[max_child]):
                max_child = v
        
        heavy[u] = max_child
    
    dfs1(root, -1)
    
    # DP on chains
    chain_head = [0] * n
    chain_pos = [0] * n
    chain_id = 0
    
    def dfs2(u, h):
        nonlocal chain_id
        chain_head[chain_id] = h
        chain_pos[u] = chain_id
        chain_id += 1
        
        if heavy[u] != -1:
            dfs2(heavy[u], h)
            for v in g[u]:
                if v != parent[u] and v != heavy[u]:
                    dfs2(v, v)
    
    dfs2(root, root)
    
    return chain_head, chain_pos, parent, depth

# Now can query/update paths efficiently using chains
```

---

## Summary Table: DP Optimization Techniques

| Technique | Time | Space | Conditions |
|-----------|------|-------|-----------|
| Naive DP | O(n³) or more | O(n²) | No structure |
| CHT | O(n log n) | O(n) | Linear recurrence |
| Knuth-Yao | O(n² log n) | O(n²) | Quadrangle inequality |
| Divide & Conquer | O(n log n) | O(n) | Monotonicity |
| Bitmask DP | O(n² × 2ⁿ) | O(2ⁿ) | n ≤ 20 |
| Meet-in-Middle | O(2^(n/2) log 2^(n/2)) | O(2^(n/2)) | n ≤ 40 |
| Profile DP | O(2^w × h × w) | O(2^w) | Tiling problems |
