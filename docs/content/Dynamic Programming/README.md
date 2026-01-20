# Dynamic Programming Toolkit

Dynamic programming thrives when a problem has **overlapping subproblems** and **optimal substructure**. This folder collects patterns across 1D, 2D, tree, bitmask, and combinatorial DP.

## Problem clusters in this folder

- **1D linear DP**
  - `70. Climbing Stairs`, `746. Min Cost Climbing Stairs`, `198/213. House Robber` - forward iteration with rolling variables to keep space O(1).
  - `53. Maximum Subarray`, `918. Maximum Sum Circular Subarray` - Kadane's algorithm with prefix tracking.
  - `279. Perfect Squares`, `343. Integer Break`, `300. Longest Increasing Subsequence` - coin change style transitions (note both O(n^2) and O(n log n) LIS versions exist).

- **Partition / knapsack style**
  - `416. Partition Equal Subset Sum`, `494. Target Sum`, `377. Combination Sum IV`, `1049. Last Stone Weight II`, plus the `knapsack` subfolder.
  - KPI: convert negative indices to positive via offset or dictionary, and favour bitsets when constraints allow.

- **String DP**
  - `1143. Longest Common Subsequence`, `72. Edit Distance`, `647. Palindromic Substrings`, `139. Word Break`.
  - Highlight 2D vs 1D compressed tables; mention top-left -> bottom-right sweep for LCS, and center-expansion alternative for palindromic counts.

- **Grid / path DP**
  - `62/63. Unique Paths`, `64. Minimum Path Sum`, `120. Triangle`, `221. Maximal Square`.
  - Discuss boundary padding with dummy row/column to trim conditionals.

- **Graph / Tree DP**
  - `834. Sum of Distances in Tree` combines post-order and pre-order sweeps (rerooting).
  - `1871. Jump Game VII` uses prefix sums to accelerate reachability transitions.

- **Stocks & optimisation**
  - `122/123. Best Time to Buy and Sell Stock II/III` highlight state machines with limited transactions.

## Loop direction heuristics

| Dependency | Loop direction | Examples |
|------------|----------------|----------|
| `dp[i]` depends on `dp[i-1]` | left -> right | Fibonacci, coin change (unbounded) |
| `dp[i]` depends on `dp[i+1]` | right -> left | Jump Game, stone games |
| `dp[i][j]` depends on bottom/right | reverse loops | Longest common subsequence, edit distance |
| Mixed dependencies | nest carefully per dimension | Matrix chain multiplication, Stone Game VII |

## Checklist before coding

- **State definition** - write down what each index means (`dp[i]` vs `dp[i][j]`); use tuples for multi-parameter memoisation.
- **Base cases** - initialise DP arrays explicitly; forgetting this often yields off-by-one bugs (e.g. `dp[0] = 0`, `dp[0][*]` for empty prefixes).
- **Transition order** - ensure loops respect dependency direction; for 0/1 knapsack iterate weight descending to avoid double counting.
- **Space optimisation** - consider rolling arrays or bitsets when previous row/state is sufficient.
- **Modulus handling** - when results must stay mod `1e9+7`, cast after every addition to avoid Python's big integer overhead.

## Interview extras

- Bring up alternative solutions: e.g. LIS has DP O(n^2) and patience sorting O(n log n); `Word Break` has DP and BFS.
- Mention time/space trade-offs (memoised recursion vs bottom-up).
- For tree DP, outline traversal order (post-order to gather children, pre-order to reroot).
- When constraints are large, note optimisations like sliding-count DP (`Jump Game VII`) or prefix sums to turn O(n^2) into O(n).

```text
❌ Why nonlocal ans breaks memoization
@lru_cache caches the return value of dfs(x, y, s) based on its inputs.
But your dfs doesn’t return anything (None)—it only modifies the global ans.
So when a state (x, y, s) is revisited, lru_cache returns the cached result (which is None) without executing the function body again.
That means you stop counting paths after the first visit to any state!
```