# 💾 Dynamic Programming Fundamentals

## 🧠 DP Mindset

Every DP requires:
1. **State:** What does `dp[...]` represent?
2. **Transition:** How to build from smaller states?
3. **Base cases:** Initial values
4. **Order:** Dependency direction (recursion+memo or bottom-up)
5. **Answer:** Which state(s) give the final result?

---

## 1️⃣ 1D DP

### 1.1 Linear Recurrence (Classic)

```python
def linear_dp(a):
    """Min cost to reach index i, can jump from i-1 or i-2"""
    n = len(a)
    dp = [10**18] * n
    dp[0] = a[0]
    if n >= 2:
        dp[1] = a[1] + dp[0]
    for i in range(2, n):
        dp[i] = a[i] + min(dp[i-1], dp[i-2])
    return dp[-1]
```

### 1.2 Maximum Subarray (Kadane)

```python
def max_subarray_sum(a):
    """Max sum of contiguous subarray"""
    best = cur = a[0]
    for x in a[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best
```

### 1.3 0/1 Knapsack

```python
def knapsack_01(weights, values, W):
    """Max value with capacity W, each item used at most once"""
    dp = [0] * (W + 1)
    for i in range(len(weights)):
        w, v = weights[i], values[i]
        for capacity in range(W, w - 1, -1):  # iterate backwards!
            dp[capacity] = max(dp[capacity], dp[capacity - w] + v)
    return max(dp)
```

### 1.4 Unbounded Knapsack / Coin Change

```python
def coin_change_ways(coins, target):
    """Ways to make target using coins (unlimited supply)"""
    dp = [0] * (target + 1)
    dp[0] = 1
    for coin in coins:
        for s in range(coin, target + 1):
            dp[s] += dp[s - coin]
    return dp[target]
```

### 1.5 LIS (Longest Increasing Subsequence)

```python
def lis_n2(a):
    """O(n²) LIS"""
    n = len(a)
    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if a[j] < a[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp) if dp else 0
```

### 1.6 Bitmask DP

```python
from functools import lru_cache

def tsp_bitmask(cost):
    """TSP: visited as bitmask, dp[mask][last]"""
    n = len(cost)
    
    @lru_cache(None)
    def dp(mask, last):
        if mask == (1 << n) - 1:
            return 0
        ans = 10**18
        for next_city in range(n):
            if not (mask & (1 << next_city)):
                ans = min(ans, cost[last][next_city] + dp(mask | (1 << next_city), next_city))
        return ans
    
    return dp(1, 0)  # start at city 0
```

---

## 2️⃣ 2D DP

### 2.1 Grid Paths (Min Cost)

```python
def min_path_sum(grid):
    """Min cost path from (0,0) to (n-1,m-1)"""
    n, m = len(grid), len(grid[0])
    dp = [[10**18] * m for _ in range(n)]
    dp[0][0] = grid[0][0]
    for i in range(n):
        for j in range(m):
            if i > 0:
                dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j])
            if j > 0:
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j])
    return dp[-1][-1]
```

### 2.2 LCS (Longest Common Subsequence)

```python
def lcs(a, b):
    """Longest common subsequence"""
    n, m = len(a), len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]
```

### 2.3 Edit Distance

```python
def edit_distance(a, b):
    """Levenshtein distance"""
    n, m = len(a), len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = i
    for j in range(m + 1):
        dp[0][j] = j
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    return dp[n][m]
```

### 2.4 Interval DP

```python
def interval_dp_template(a):
    """DP on segments: dp[l][r] = best of partition"""
    n = len(a)
    dp = [[0] * n for _ in range(n)]
    for length in range(2, n + 1):
        for l in range(n - length + 1):
            r = l + length - 1
            dp[l][r] = 10**18
            for k in range(l, r):
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + cost(l, r))
    return dp[0][n-1]

def cost(l, r):
    return 0  # define based on problem
```

---

## 3️⃣ Tree DP

### 3.1 Subtree DP (Post-order)

```python
def tree_dp_subtree(n, adj):
    """Example: max independent set in tree"""
    dp0 = [0] * n  # not taken
    dp1 = [0] * n  # taken
    
    def dfs(u, p):
        dp0[u] = 0
        dp1[u] = 1  # value when taking this node
        for v in adj[u]:
            if v == p:
                continue
            dfs(v, u)
            dp0[u] += max(dp0[v], dp1[v])
            dp1[u] += dp0[v]
    
    dfs(0, -1)
    return max(dp0[0], dp1[0])
```

### 3.2 Rerooting DP

```python
def rerooting_dp(n, adj):
    """Example: sum of distances from each node"""
    sz = [1] * n
    dp = [0] * n
    
    def dfs1(u, p):
        for v in adj[u]:
            if v == p:
                continue
            dfs1(v, u)
            sz[u] += sz[v]
            dp[u] += dp[v] + sz[v]
    
    def dfs2(u, p):
        for v in adj[u]:
            if v == p:
                continue
            # reroot from u to v
            dp[v] = dp[u] - sz[v] + (n - sz[v])
            dfs2(v, u)
    
    dfs1(0, -1)
    dfs2(0, -1)
    return dp
```

---

## 4️⃣ Digit DP

```python
from functools import lru_cache

def count_numbers_with_property(N):
    """Count numbers in [0, N] with digit sum <= 10"""
    s = str(N)
    n = len(s)
    
    @lru_cache(None)
    def dp(pos, tight, digit_sum):
        if pos == n:
            return 1 if digit_sum <= 10 else 0
        
        limit = int(s[pos]) if tight else 9
        ans = 0
        for d in range(0, limit + 1):
            new_tight = tight and (d == limit)
            ans += dp(pos + 1, new_tight, digit_sum + d)
        return ans
    
    return dp(0, True, 0)
```

---

## 5️⃣ Advanced Patterns

### 5.1 DP on DAG

```python
def dp_on_dag(n, adj):
    """Longest path on DAG"""
    dp = [0] * n
    memo = [False] * n
    
    def dfs(u):
        if memo[u]:
            return dp[u]
        memo[u] = True
        for v in adj[u]:
            dp[u] = max(dp[u], 1 + dfs(v))
        return dp[u]
    
    for i in range(n):
        dfs(i)
    return max(dp)
```

### 5.2 SOS DP (Sum Over Subsets)

```python
def sos_dp(f):
    """g[mask] = sum of f[submask] for all submask ⊆ mask"""
    g = f[:]
    n = (len(f) - 1).bit_length()
    for bit in range(n):
        for mask in range(1 << n):
            if mask & (1 << bit):
                g[mask] += g[mask ^ (1 << bit)]
    return g
```

---

## 📊 Quick Reference

| Problem | State | Complexity |
|---------|-------|-----------|
| Min cost path | dp[i] or dp[i][j] | O(n) or O(n²) |
| Knapsack 0/1 | dp[w] | O(nW) |
| Knapsack unbounded | dp[x] | O(n·target) |
| LIS | dp[i] | O(n²) or O(n log n) |
| LCS | dp[i][j] | O(nm) |
| Edit distance | dp[i][j] | O(nm) |
| Interval | dp[l][r] | O(n³) |
| Tree DP | dp[u][state] | O(n) |
| Rerooting | dp[u] for all roots | O(n) |
| Bitmask | dp[mask][other] | O(2^n·n) |
| Digit DP | dp[pos][tight][state] | O(digits·2·states) |

