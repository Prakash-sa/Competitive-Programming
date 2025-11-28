I’ll walk through the core DP patterns you really need for Codeforces-level problems, and give Python boilerplate for each:

1D DP

2D / grid / string DP

Tree DP (including rerooting)

Digit DP

“Other” competitive patterns: bitmask DP, SOS DP, DP on DAG, bitset tricks

You can copy–paste these and adapt per problem.

0. DP Mindset (very short)

For every DP:

State: What does dp[... ] represent?

Transition: How to build dp[state] from smaller states?

Base cases

Order: Recursion + memo OR iterative order that respects dependencies.

Answer: Which state(s) correspond to the final answer?

1. 1D DP PATTERNS
1.1 Linear Recurrence / “Classic 1D DP”

Typical problems:
Fibonacci, “min cost to reach index i”, “max sum subsequence with constraints on neighbors”.

Template idea: dp[i] depends on small fixed set of previous indices (i-1, i-2, etc).

def linear_dp(a):
    """
    Example: minimum cost to reach i,
    cost to jump from i-1 or i-2: dp[i] = a[i] + min(dp[i-1], dp[i-2])
    """
    n = len(a)
    INF = 10**18
    dp = [INF] * n

    # base
    dp[0] = a[0]
    if n >= 2:
        dp[1] = a[1] + dp[0]

    # transition
    for i in range(2, n):
        dp[i] = a[i] + min(dp[i-1], dp[i-2])

    return dp[-1]


When you see “position i, choose from a small window of previous indices”, this is your pattern.

1.2 Prefix/Suffix & Kadane (max subarray)

Typical problems:

Maximum subarray sum

Max/min subarray with constraints

Combine prefix-best and suffix-best.

Kadane’s algorithm (max subarray):

def max_subarray_sum(a):
    best = -10**18
    cur = 0
    for x in a:
        cur = max(x, cur + x)  # dp[i] = max(a[i], dp[i-1] + a[i])
        best = max(best, cur)
    return best


Use this when you have continuous subarray & sum/score.

1.3 0/1 Knapsack Pattern (subset DP)

Typical problems:

Choose subset of items (each used at most once) to maximize value under capacity.

Key trick: iterate capacity backwards so you don’t reuse items.

def knapsack_01(weights, values, W):
    n = len(weights)
    dp = [0] * (W + 1)  # dp[w] = max value with capacity w

    for i in range(n):
        w_i, v_i = weights[i], values[i]
        for w in range(W, w_i - 1, -1):  # backwards
            dp[w] = max(dp[w], dp[w - w_i] + v_i)
    return max(dp)


Whenever you see: “n up to 100, W up to 10^5, each item 0/1”, think this.

1.4 Unbounded Knapsack / Coin Change

Typical problems:

Use coins unlimited times to reach a sum or minimize number of coins.

dp[x] = ways / min coins for sum x.

Order: forward over capacity.

def coin_change_ways(coins, target):
    dp = [0] * (target + 1)
    dp[0] = 1
    for c in coins:
        for s in range(c, target + 1):
            dp[s] += dp[s - c]
    return dp[target]


Use when items can be reused arbitrarily.

1.5 LIS DP (O(n²) pattern)

Typical problems:

Longest increasing subsequence

Longest chain, etc.

def lis_n2(a):
    n = len(a)
    dp = [1] * n  # dp[i] = LIS ending at i
    for i in range(n):
        for j in range(i):
            if a[j] < a[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)


You should also know LIS with binary search O(n log n), but the DP idea is this.

1.6 Bitmask DP over Subsets

Typical problems:

Travelling Salesman on small n

“Assign persons to tasks” (n≤20)

DP over subset of used items.

State: dp[mask] (maybe with an additional index like dp[mask][last]).

from functools import lru_cache

def subset_dp(cost):
    """
    Example: assignment:
    cost[i][j] = cost of assigning worker i to job j
    n <= 20 (small)
    dp[mask] = min cost to assign first k workers to jobs in mask
    where k = number of bits in mask
    """
    n = len(cost)

    @lru_cache(None)
    def dp(mask):
        k = mask.bit_count()  # how many workers already assigned
        if k == n:
            return 0
        ans = 10**18
        for job in range(n):
            if not (mask & (1 << job)):
                ans = min(ans, cost[k][job] + dp(mask | (1 << job)))
        return ans

    return dp(0)


Whenever n ≤ 20 and you see “used/un-used” toggling, think bitmask DP.

2. 2D / GRID / STRING DP PATTERNS
2.1 Grid Paths / Min Cost Path

Typical problems:

Count paths from (0,0) to (n-1,m-1)

Min path sum

Obstacles.

def min_path_sum(grid):
    n = len(grid)
    m = len(grid[0])
    INF = 10**18
    dp = [[INF] * m for _ in range(n)]
    dp[0][0] = grid[0][0]
    for i in range(n):
        for j in range(m):
            if i > 0:
                dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j])
            if j > 0:
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j])
    return dp[-1][-1]


Pattern: dp[i][j] from top/left neighbors.

2.2 LCS / Edit Distance (string DP)

Basics for many Codeforces string DPs.

LCS (Longest Common Subsequence):

def lcs(a, b):
    n, m = len(a), len(b)
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]


Edit distance (Levenshtein):

def edit_distance(a, b):
    n, m = len(a), len(b)
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = i
    for j in range(m+1):
        dp[0][j] = j

    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(
                    dp[i-1][j] + 1,   # delete
                    dp[i][j-1] + 1,   # insert
                    dp[i-1][j-1] + 1  # replace
                )
    return dp[n][m]


Think: dp over prefixes of strings.

2.3 Subsequence / “2D Over Indices” DP

Typical:

Count subsequences equal to a target string

“Number of ways to transform string A into B”.

Example: count subsequences of s equal to t:

def count_subseq(s, t):
    n, m = len(s), len(t)
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1  # empty t

    for i in range(1, n+1):
        for j in range(1, m+1):
            dp[i][j] = dp[i-1][j]
            if s[i-1] == t[j-1]:
                dp[i][j] += dp[i-1][j-1]
    return dp[n][m]


Pattern: dp[i][j] uses “skip current char, or take it”.

2.4 Interval DP (dp[l][r])

Very common for higher-rated problems:

Typical:

Optimal merging (like matrix chain multiplication)

Palindromic partitions, removing segments, game on segment.

Form:
dp[l][r] = combine over partition points k (l <= k < r).

Skeleton:

def interval_dp(a):
    n = len(a)
    INF = 10**18
    dp = [[0]*n for _ in range(n)]

    # base: segments of length 1 often 0 or a[i]
    for i in range(n):
        dp[i][i] = 0

    for length in range(2, n+1):
        for l in range(0, n-length+1):
            r = l + length - 1
            best = INF
            # try all splits
            for k in range(l, r):
                best = min(best, dp[l][k] + dp[k+1][r] + cost_of_merging(l, r, a))
            dp[l][r] = best

    return dp[0][n-1]

def cost_of_merging(l, r, a):
    # example placeholder: sum(a[l:r+1]) etc
    return 0


Recognize this when the problem involves segments and combining subsegments.

3. TREE DP PATTERNS
3.1 Subtree DP (post-order)

Typical:

Subtree sizes

Max path in subtree

Independent set on tree (no adjacent selected nodes)

DP "downwards" only.

Generic DFS + DP:

import sys
sys.setrecursionlimit(10**7)

def tree_dp_subtree(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)

    dp = [0] * n

    def dfs(u, p):
        # base for leaf: dp[u] = something
        dp[u] = 1  # example: subtree size
        for v in g[u]:
            if v == p:
                continue
            dfs(v, u)
            # combine child contribution
            dp[u] += dp[v]

    dfs(0, -1)
    return dp


Pattern: root tree, DFS, each node uses its children’s dp.

3.2 Tree DP with States (e.g., Tree Independent Set)

State example:

dp[u][0] = best value if u is not taken

dp[u][1] = best value if u is taken

def tree_independent_set(n, edges, weight):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)

    dp0 = [0]*n  # u not taken
    dp1 = [0]*n  # u taken

    def dfs(u, p):
        dp0[u] = 0
        dp1[u] = weight[u]
        for v in g[u]:
            if v == p:
                continue
            dfs(v, u)
            dp0[u] += max(dp0[v], dp1[v])
            dp1[u] += dp0[v]  # children cannot be taken if u is taken

    dfs(0, -1)
    return max(dp0[0], dp1[0])


Think: two states per node, transitions combine child states.

3.3 Rerooting DP

Used when you need answer for every node as root (e.g., sum of distances from each node).

Two steps:

Compute dp for subtree (downwards).

“Reroot” and propagate from parent to children.

Skeleton:

def rerooting_dp(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)

    size = [1]*n
    dp = [0]*n  # example: sum of distances from node to its subtree

    def dfs1(u, p):
        for v in g[u]:
            if v == p:
                continue
            dfs1(v, u)
            size[u] += size[v]
            dp[u] += dp[v] + size[v]

    def dfs2(u, p):
        for v in g[u]:
            if v == p:
                continue
            # move root from u to v
            dp[v] = dp[u] - size[v] + (n - size[v])
            dfs2(v, u)

    dfs1(0, -1)
    dfs2(0, -1)
    return dp  # dp[u] = sum of distances from u to all nodes in tree


Pattern: compute once from arbitrary root, then use reroot formula.

4. DIGIT DP PATTERN

Used when you need to count numbers in range [0, N] or [L, R] with some digit property:

No consecutive equal digits

Sum of digits = k

Number of digits with certain parity, etc.

States usually:

pos → current index in digits

tight → are we equal to prefix of N (0/1)

leading_zero → still haven’t placed any non-zero digit

plus additional problem-specific state (sum, last digit, etc).

Generic digit DP template:

from functools import lru_cache

def count_numbers(N):
    """
    Example: count numbers in [0, N] whose digit sum is <= 10.
    Adapt condition inside.
    """
    s = str(N)
    n = len(s)

    @lru_cache(None)
    def dp(pos, tight, sum_so_far):
        if pos == n:
            # all digits processed
            return 1 if sum_so_far <= 10 else 0

        limit = int(s[pos]) if tight else 9
        ans = 0
        for d in range(0, limit + 1):
            ntight = tight and (d == limit)
            ans += dp(pos + 1, ntight, sum_so_far + d)
        return ans

    return dp(0, True, 0)

def count_in_range(L, R):
    return count_numbers(R) - count_numbers(L - 1)


To adapt:

Add state for last digit: dp(pos, tight, sum_so_far, last_digit)

Use leading_zero to ignore restrictions before first non-zero.

Example with leading_zero and last_digit:

@lru_cache(None)
def dp(pos, tight, leading_zero, last_d):
    if pos == n:
        return 1  # if number exists
    limit = int(s[pos]) if tight else 9
    ans = 0
    for d in range(0, limit + 1):
        ntight = tight and (d == limit)
        nleading = leading_zero and (d == 0)
        if not nleading and not leading_zero:
            # now we have consecutive digits last_d and d
            if d == last_d:
                continue  # skip if disallowed
        new_last = last_d if nleading else d
        ans += dp(pos+1, ntight, nleading, new_last)
    return ans

5. OTHER IMPORTANT COMPETITIVE DP PATTERNS
5.1 DP on DAG (topological order)

Generalization of 1D DP to arbitrary DAG.

from collections import defaultdict, deque

def dp_on_dag(n, edges):
    g = [[] for _ in range(n)]
    indeg = [0]*n
    for u, v in edges:
        g[u].append(v)
        indeg[v] += 1

    dp = [0]*n
    # base: sources
    q = deque()
    for i in range(n):
        if indeg[i] == 0:
            q.append(i)
            dp[i] = 1  # or some base value

    while q:
        u = q.popleft()
        for v in g[u]:
            # transition
            dp[v] = max(dp[v], dp[u] + 1)  # example: longest path
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)

    return max(dp)


Pattern: toposort + relax edges.

5.2 SOS DP (Sum Over Subsets)

Used when you have a function f[mask] and want to compute g[mask] = sum of f[submask] over all submasks or supermasks.

Skeleton (submask sums):

def sos_dp(f):
    """
    f: array of size 2^n
    return g[mask] = sum of f[submask] for all submask ⊆ mask
    """
    g = f[:]  # copy
    n = (len(f)).bit_length() - 1
    for bit in range(n):
        for mask in range(1 << n):
            if mask & (1 << bit):
                g[mask] += g[mask ^ (1 << bit)]
    return g


Recognize this when problem talks about all subsets containing a mask / subset relations.

5.3 DP + Bitset Trick (for large N, small sum)

Example: subset sum with large N / moderate sum using bitset.

def subset_sum_bitset(a, S):
    bs = 1  # bit 0 set
    for x in a:
        bs |= (bs << x)
        bs &= (1 << (S + 1)) - 1
    # check if sum s is possible: (bs >> s) & 1
    return bs


Pattern: treat dp[s] (possible / not) as bits in an integer.

5.4 DP Optimizations (just awareness)

You don’t need full templates for these yet, but you should know names:

Divide & Conquer Optimization
For DP of form:
dp[i][j] = min_{k <= j} (dp[i-1][k] + C(k,j))
with certain convexity properties. Reduces O(n² k) → O(nk log n).

Knuth Optimization
Interval DP of type dp[l][r] = min_{k in [opt[l][r-1], opt[l+1][r]]} given quadrangle inequalities.

Convex Hull Trick / Li Chao
DP with transitions like dp[i] = min_j (dp[j] + m_j * x_i + b_j).

Knowing when they apply is enough at first; you look up exact implementation mid-contest if allowed or pre-practice them.

6. How to Use This for Codeforces “Candidate Master” Level

Master each pattern with 2–3 problems:

1D DP (simple, knapsack, LIS)

2D DP (grid, LCS, interval)

Tree DP (subtree + rerooting)

Digit DP

Bitmask DP + SOS DP

DP on DAG

For every problem, force yourself to answer:

State: “dp = ?”

Transition: which smaller states combine?

Complexity: is it ok?

Build your own snippet file in Python from these templates so in contests you only adapt transitions.