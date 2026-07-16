# Technical Overview

This file summarizes the topics and data structures present in this repository for interview revision. The repo is mainly Python solutions for competitive programming and LeetCode-style problems, plus operating-system and concurrency notes.

## Topic Tags

| Letter | Topics |
|---|---|
| 0 | [0-1 BFS](#0-1-bfs) |
| 2 | [2 Pointers](#2-pointers) |
| A | [Array](#array) |
| B | [Backtracking](#backtracking), [Bellman-Ford](#bellman-ford), [Binary Lifting](#binary-lifting), [Binary Search](#binary-search), [Binary Search Tree](#binary-search-tree), [Binary Tree](#binary-tree), [Bit Manipulation](#bit-manipulation) |
| C | [Concurrency](#concurrency), [Count DP](#count-dp) |
| D | [DFS and BFS](#dfs-and-bfs), [Dijkstra](#dijkstra), [Disjoint Set Union](#disjoint-set-union), [Dynamic Programming](#dynamic-programming) |
| F | [Fenwick Tree](#fenwick-tree) |
| G | [Graph](#graph), [Greedy](#greedy) |
| H | [Hash Map and Hash Set](#hash-map-and-hash-set), [Heap](#heap) |
| I | [Intervals](#intervals) |
| K | [Kadane](#kadane), [Knapsack](#knapsack) |
| L | [Linked List](#linked-list) |
| M | [Matrix](#matrix), [Monotonic Stack](#monotonic-stack) |
| O | [Operating Systems](#operating-systems) |
| P | [Prefix Sum](#prefix-sum) |
| Q | [Queue](#queue) |
| R | [Recursion](#recursion) |
| S | [Segment Tree](#segment-tree), [Sliding Window](#sliding-window), [Sorting](#sorting), [SortedList](#sortedlist), [Square Root Decomposition](#square-root-decomposition), [Stack](#stack), [Strings](#strings), [Sweep Line](#sweep-line), [System Design](#system-design) |
| T | [Topological Sort](#topological-sort), [Trie](#trie) |

## Repository Map

| Area | Files | What it covers |
|---|---:|---|
| 2 Pointers | 21 | Pair search, partitioning, palindrome checks, sorted-array movement |
| Array | 6 | Frequency, in-place marking, majority vote, product arrays |
| Binary Search | 24 | Classic search, rotated arrays, answer-space search, bounds |
| Binary Search Tree | 7 | BST validation, insert/delete, kth smallest, recovery, LCA |
| Binary Tree | 31 | Traversals, LCA, serialization, paths, width, binary lifting |
| Bit Manipulation | 9 | XOR, bit counting, reverse bits, binary arithmetic |
| Dynamic Programming | 59 | Linear, grid, string, knapsack, state machine, tree, game theory |
| Fenwick Tree | 2 | Binary indexed tree concepts and MRU queue usage |
| Graph | 72 | DFS/BFS, shortest paths, DSU, MST, topo sort, cycles, bridges |
| Greedy | 18 | Exchange arguments, interval choices, stock/gas/jump/candy patterns |
| Heap | 12 | Top-k, scheduling, median stream, priority queues |
| Intervals | 8 | Merge, insert, meeting rooms, sweep line difference events |
| LinkedList | 17 | Reversal, cycle detection, merge, reorder, random pointer |
| Mathematics | 19 | GCD, modular power, matrix operations, number/string math |
| Matrix | 6 | Spiral, rotate, zeroing, sudoku, island perimeter |
| Operating Systems | 27 | OS concepts, processes, memory, scheduling, concurrency problems |
| Prefix Sum & Partial Sum | 14 | 1D/2D prefix sums, difference arrays, range updates |
| Recursion & Backtracking | 21 | Subsets, permutations, combinations, N-Queens, grid paths |
| Segment Trees | 5 | Range query/update structure and advanced interval aggregation |
| Sliding Window | 18 | Fixed and dynamic window problems over arrays/strings |
| Sorting | 9 | Custom sort, buckets/radix-style ideas, ranking, relative ordering |
| Stack | 12 | Parentheses, decoding, RPN, monotonic stack, min stack |
| Strings | 13 | Palindrome, anagrams, KMP, Z algorithm, Manacher, encoding |
| System Design | 13 | LRU/LFU, Twitter, router, hash map/set, queues/stacks |
| Tries | 3 | Prefix tree, wildcard search, word search II |

## Interview Strategy

Use the constraints first. If `n` is tiny, backtracking or bitmask DP may be acceptable. If `n` is up to a few thousand, quadratic DP can pass. If `n` is large, think `O(n)`, `O(n log n)`, or logarithmic search/data structures.

Read aloud note: "Before coding, I map constraints to complexity. Then I identify whether the problem has ordering, monotonicity, overlapping subproblems, or graph connectivity. That choice decides the data structure."

## 0-1 BFS

Present in `Graph/0-1 BFS`.

Use when edge weights are only `0` or `1`. Instead of Dijkstra with a heap, maintain a deque. Push zero-cost relaxations to the front and one-cost relaxations to the back.

Complexity: `O(V + E)`.

Read aloud note: "Because weights are only zero and one, a deque keeps nodes in shortest-distance order without a priority queue. Zero edges deserve immediate processing, so I push them to the front."

## 2 Pointers

Present in `2 Pointers/arrays` and `2 Pointers/strings`.

Use when two positions move through an array/string to maintain a relationship: sorted pair sum, palindrome validation, partitioning, merging, or maximizing area. Common examples in the repo include Two Sum II, 3Sum, 4Sum, Container With Most Water, Trapping Rain Water, Sort Colors, Merge Sorted Array, Next Permutation, and Valid Word Abbreviation.

Key patterns:

- Opposite ends: sorted pair/triplet search, palindrome, water container.
- Same direction: merge, remove duplicates, partition by pivot.
- Fast/slow: cycle detection or in-place filtering.

Read aloud note: "I use two pointers when each pointer movement can safely discard a region of the search space. The proof is usually based on sorted order, monotonic area, or an invariant about processed elements."

## Array

Present in `Array`.

Covers base array techniques: in-place marking, frequency counting, Boyer-Moore majority voting, product except self, longest consecutive sequence, first missing positive, and 2D range sum.

Common data structures:

- Hash set for membership and sequence starts.
- Hash map or counters for frequencies.
- Prefix products/sums for range-independent calculations.
- In-place index marking when values are in `[1, n]`.

Read aloud note: "For array problems, I first check whether values map naturally to indices. If yes, I can often avoid extra space. If not, I use hashing for membership or sorting to create order."

## Backtracking

Present in `Recursion & Backtracking`.

Covers permutations, combinations, subsets, palindrome partitioning, N-Queens, word search, rat in a maze, generate parentheses, matchsticks to square, tower of Hanoi, and recursive stack sorting.

Backtracking template:

```python
def dfs(state):
    if is_solution(state):
        ans.append(build_answer(state))
        return
    for choice in choices:
        if valid(choice, state):
            apply(choice)
            dfs(state)
            undo(choice)
```

Pruning ideas:

- Sort input to skip duplicates.
- Stop when remaining sum or length cannot satisfy the target.
- Track visited cells/nodes.
- Validate partial state early.

Read aloud note: "Backtracking is controlled brute force. I build one decision at a time, reject impossible partial states early, and undo the choice before trying the next branch."

## Bellman-Ford

Present in `Graph/Bellman Ford`.

Use for shortest paths when negative edge weights exist or when the problem limits the number of edges/stops, such as Cheapest Flights Within K Stops.

Complexity: usually `O(VE)`, or `O(kE)` when limited to `k` relaxations.

Read aloud note: "Bellman-Ford is useful when Dijkstra's greedy assumption is unsafe. Each relaxation allows paths with one more edge, so with K stops I can intentionally run only K-plus-one rounds."

## Binary Lifting

Present in `Binary Tree/Binary Lifting`.

Use for kth ancestor queries, LCA, and jump-style tree queries. Precompute `up[node][j]`, where it stores the `2^j`-th ancestor.

Complexity:

- Preprocess: `O(n log n)`.
- Query: `O(log n)`.

Read aloud note: "Binary lifting turns repeated parent jumps into powers of two. Any distance can be decomposed into bits, so a query becomes logarithmic."

## Binary Search

Present in `Binary Search`.

Covers standard search, lower/upper bound, rotated arrays, matrix search, peak element, sqrt, median of two sorted arrays, randomized weighted pick, and binary search on answer for capacity/allocation problems.

Recognition:

- Sorted input or sorted answer space.
- Monotonic predicate: once true, always true; or once false, always false.
- Need first/last position, minimum feasible value, or maximum feasible value.

Template:

```python
lo, hi = 0, answer_upper_bound
while lo < hi:
    mid = (lo + hi) // 2
    if can(mid):
        hi = mid
    else:
        lo = mid + 1
return lo
```

Read aloud note: "I do not need the answer array to exist. I only need a monotonic yes/no function. Then binary search finds the boundary between impossible and possible."

## Binary Search Tree

Present in `Binary Search Tree`.

Covers validation, insert, delete, recover swapped nodes, kth smallest, and LCA.

Core invariant: for every node, all values in the left subtree are smaller and all values in the right subtree are larger, with duplicate handling defined by the problem.

Useful techniques:

- Inorder traversal gives sorted order.
- Bounds recursion validates a BST.
- Kth smallest uses inorder count.
- Delete has three cases: leaf, one child, two children.

Read aloud note: "The main power of a BST is sorted structure. I lean on inorder traversal for sorted order and on min/max bounds for validation."

## Binary Tree

Present in `Binary Tree`.

Covers preorder/inorder/postorder traversal, level order, zigzag order, right side view, inversion, balance, max depth, diameter, path sum, LCA, duplicate subtrees, max path sum, serialization/deserialization, quad tree construction, and binary lifting.

Traversal meanings:

- Preorder: root first, useful for copying/serialization.
- Inorder: sorted only for BSTs.
- Postorder: children first, useful for subtree aggregation.
- BFS: level structure, shortest unweighted depth, width.

Read aloud note: "For tree problems, I ask what each node needs from children or parent. If the answer depends on subtree summaries, postorder is natural. If it depends on levels, BFS is natural."

## Bit Manipulation

Present in `Bit Manipulation`.

Covers single number with XOR, counting bits, reverse bits, bitwise AND range, missing number, add binary, sum without plus, and reverse integer edge handling.

Important operations:

```python
x & 1              # last bit
x & (x - 1)        # remove lowest set bit
x & -x             # isolate lowest set bit
x ^ x == 0         # duplicate cancellation
1 << k             # kth bit mask
```

Read aloud note: "XOR cancels equal values and preserves the odd one out. For bit counting, repeatedly dropping the lowest set bit is proportional to the number of ones."

## Concurrency

Present in `Operating Systems/Concurrency`.

Covers multithreaded LeetCode-style problems: Print in Order, FooBar, Zero Even Odd, Building H2O, Bounded Blocking Queue, Fizz Buzz Multithreaded, Dining Philosophers, and Web Crawler Multithreaded.

Common primitives:

- Lock: protects a critical section.
- Semaphore: limits access or orders phases.
- Condition variable: waits until a predicate becomes true.
- Queue: transfers work safely between producers and consumers.

Read aloud note: "In concurrency problems, I identify the ordering constraint first. Then I choose the smallest primitive that enforces that order without busy waiting."

## Count DP

Present in `Dynamic Programming/Count Distinct Ways`.

Covers climbing stairs, min cost climbing stairs, decode ways, and variants where the goal is number of ways or minimum cost over a small recurrence.

Read aloud note: "Count DP usually means each state represents the number of ways to reach a position or prefix. I define what `dp[i]` means before writing the recurrence."

## DFS and BFS

Present across `Graph/DFS`, `Graph/BFS`, `Graph/Multi Source BFS`, `Graph/Flood Fill`, and matrix/grid problems.

DFS is best for full exploration, connected components, cycle checks, recursion over trees, and backtracking-style graph traversal.

BFS is best for shortest path in unweighted graphs, level order, multi-source spreading, and minimum number of steps.

Read aloud note: "DFS answers reachability and component structure. BFS answers minimum steps when each move has equal cost."

## Dijkstra

Present in `Graph/Dijkastra Algo`.

Use for shortest path with non-negative weighted edges. Common repo examples include Network Delay Time, Path With Minimum Effort, Shortest Path in Binary Matrix variants, and Swim in Rising Water.

Complexity: `O(E log V)` with a heap.

Read aloud note: "Dijkstra works because once the smallest-distance node is popped, no later non-negative path can improve it. The heap gives the next best frontier."

## Disjoint Set Union

Present in `Graph/Disjoint Set Union`.

Also called Union-Find. Used for connectivity, components, cycle detection in undirected graphs, Kruskal MST, account merging, string swaps, power grid maintenance, and GCD traversal.

Implementation ideas:

- `parent[x]` points to representative.
- Path compression flattens trees.
- Union by size/rank keeps depth small.

Complexity: effectively near `O(1)` amortized per operation.

Read aloud note: "DSU is my go-to when the graph changes only by adding connections and I need to know whether two nodes are in the same component."

## Dynamic Programming

Present in `Dynamic Programming`.

The repo includes many DP families:

- Linear DP: House Robber, LIS, Integer Break.
- Grid DP: Unique Paths, Minimum Path Sum, Maximal Square.
- Knapsack: Coin Change, Last Stone Weight II.
- Subset Sum: Target Sum, Partition Equal Subset Sum.
- String DP: LCS, Edit Distance, Word Break, Interleaving String, Regex Matching.
- State Machine: stock buy/sell with cooldown or transaction limits.
- Digit DP: Rotated Digits and number-bound counting.
- Tree DP: House Robber III, Binary Tree Maximum Path Sum, Sum of Distances in Tree.
- Game Theory DP: Stone Game variants.
- Advanced DP: magical sequences, digit-set bounds, trie-assisted extra characters.

DP checklist:

1. Define state exactly.
2. Define transition from smaller states.
3. Define base cases.
4. Pick top-down memoization or bottom-up tabulation.
5. Optimize space only after correctness is clear.

Read aloud note: "I use DP when brute force repeats the same subproblem. The most important interview sentence is the state definition, because the recurrence follows from that."

## Fenwick Tree

Present in `Fenwick Tree`.

Fenwick Tree, or Binary Indexed Tree, supports prefix sums and point updates in logarithmic time. It is useful for dynamic frequency tables, order statistics with coordinate compression, and inversion/count-smaller style problems.

Operations:

```python
i += i & -i   # move upward while updating
i -= i & -i   # move toward prefix while querying
```

Read aloud note: "Fenwick Tree stores partial prefix sums. The lowest set bit tells me the size of the range represented by each index."

## Graph

Present in `Graph`.

The graph section is broad: DFS, BFS, 0-1 BFS, Dijkstra, Bellman-Ford, DSU, connected components, cycle detection, topological sort, MST, bridges, flood fill, and multi-source BFS.

Graph representation:

- Adjacency list for sparse graphs.
- Matrix/grid as implicit graph.
- Edge list for Bellman-Ford, Kruskal, and sweep-style edge processing.

Read aloud note: "I first classify the graph: directed or undirected, weighted or unweighted, cyclic or DAG, static or dynamic connectivity. That classification usually picks the algorithm."

## Greedy

Present in `Greedy`.

Covers jump game, gas station, candy, partition labels, hand of straights, valid parenthesis string, non-overlapping intervals, stock profit, min taps, maximum subarray, and circular subarray.

Greedy is appropriate when a local choice can be proven globally safe, often by exchange argument or maintaining an invariant.

Read aloud note: "For greedy, I need to justify why choosing locally does not block the optimal answer. I usually explain an exchange argument: any optimal solution can be transformed to include my choice."

## Hash Map and Hash Set

Present in `System Design`, `Array`, `Strings`, `Graph`, and many solution files.

Common uses:

- Frequency counting.
- Deduplication.
- Membership lookup.
- Index mapping.
- Collision-handled custom HashMap/HashSet implementations.
- LRU/LFU cache key-to-node maps.

Read aloud note: "Hashing trades extra memory for expected constant-time lookup. I use it when the problem repeatedly asks whether I have seen a value or how many times it occurred."

## Heap

Present in `Heap`.

Covers kth largest, top-k frequent, median from stream, task scheduler, IPO, meeting rooms, minimum interval query, reorganize string, and longest happy string.

Use a heap when you repeatedly need the current min or max while the data changes.

Read aloud note: "A heap is useful when sorting everything is too much, but I still need repeated access to the best candidate."

## Intervals

Present in `Intervals`.

Covers merge intervals, insert interval, meeting rooms, non-overlapping intervals, and sweep-line variants.

Standard approach:

1. Sort by start or end.
2. Merge, count rooms, or greedily select.
3. For many updates/coverage queries, convert to events.

Read aloud note: "Intervals become simpler after sorting. Then overlap is local: I compare the current interval with the previous merged interval or current active set."

## Kadane

Present in `Dynamic Programming/Kadane` and also in `Greedy`.

Kadane tracks the best subarray ending at the current index and the global best. Variants include maximum product, circular maximum sum, and matrix/path versions.

Read aloud note: "At each index, I decide whether to extend the previous subarray or start fresh. That local decision is valid because a negative prefix only hurts future sums."

## Knapsack

Present in `Dynamic Programming/Knapsack`, `Dynamic Programming/1-0 Knapsack`, `Dynamic Programming/Unbounded Knapsack`, and `Dynamic Programming/Subset Sum`.

Families:

- 0/1 knapsack: choose each item at most once.
- Unbounded knapsack: choose an item multiple times.
- Subset sum: boolean or count reachability over sums.
- Coin change: minimize number of coins or count combinations.

Read aloud note: "The loop order tells the item rule. Backward sum iteration means each item is used once. Forward iteration allows reuse."

## Linked List

Present in `LinkedList`.

Covers reverse list, reverse sublist, reverse in k-group, merge two/k lists, cycle detection, cycle entry, remove nth from end, reorder list, palindrome list, copy random pointer, add two numbers, and twin sum.

Core pointers:

- `prev`, `cur`, `nxt` for reversal.
- slow/fast for cycle and midpoint.
- dummy node for simpler head/tail edge cases.

Read aloud note: "For linked lists, I protect edge cases with a dummy node when the head may change. I write pointer updates in a fixed order so I do not lose the rest of the list."

## Matrix

Present in `Matrix` and `Mathematics`.

Covers rotate image, spiral traversal, set zeroes, valid sudoku, island perimeter, transpose, and grid partition.

Common techniques:

- Treat matrix as grid graph for traversal.
- Use row/column marker arrays or first row/column as markers.
- Rotate by transpose plus reverse.
- Use direction vectors for spiral or BFS/DFS.

Read aloud note: "Matrix problems are usually either coordinate transformation or graph traversal. I decide which one by asking whether cells interact by position or by movement."

## Monotonic Stack

Present in `Stack/Monotonic_stack` and advanced stack files.

Use for next greater/smaller element, daily temperatures, stock span, car fleet, and largest rectangle in histogram.

Invariant: stack remains increasing or decreasing so outdated candidates are removed once they can no longer be the answer.

Read aloud note: "The stack stores unresolved candidates. When a new value resolves them, I pop and calculate the answer immediately."

## Operating Systems

Present in `Operating Systems/topics`.

Covers OS introduction, system calls, processes, threads, CPU scheduling, IPC, synchronization, semaphores, deadlocks, memory management, paging, segmentation, TLB, virtual memory, page replacement, file systems, disk scheduling, I/O systems, Linux/system programming basics, and practice notes.

Interview themes:

- Process vs thread.
- User mode vs kernel mode.
- Context switch cost.
- Deadlock conditions and prevention.
- Scheduling policies and tradeoffs.
- Paging, TLB, page faults, and replacement algorithms.

Read aloud note: "In OS answers, I separate mechanism from policy. Mechanism is what the OS can do, like context switching or paging. Policy is how it chooses, like scheduling or replacement."

## Prefix Sum

Present in `Prefix Sum & Partial Sum` and `Array`.

Covers range sum queries, 2D range sum, subarray sum equals K, subarray sums divisible by K, product except self, product of last K numbers, difference arrays, AP/GP range additions, and palindrome query preprocessing.

Use cases:

- Static range queries.
- Counting subarrays by prefix differences.
- Range updates using difference arrays.
- 2D rectangle sums.

Read aloud note: "Prefix sum converts range sum into subtraction of two saved states. For counting subarrays, I store how many times each previous prefix has appeared."

## Queue

Present in `Queue` and `System Design`.

Queue is used for BFS, sliding-window maximum through deque, circular queue design, and queue/stack conversion problems.

Read aloud note: "A queue preserves arrival order, which is exactly what BFS and FIFO buffers need. A deque extends that by allowing me to maintain monotonic candidates."

## Recursion

Present in `Recursion & Backtracking`, `Binary Tree`, and DFS-heavy graph files.

Recursion appears where the problem naturally decomposes into smaller identical problems: trees, DFS, divide-and-conquer, backtracking, and expression/path construction.

Read aloud note: "I define the function contract first: what does this call return for this subtree or state? Then each recursive call becomes easier to reason about."

## Segment Tree

Present in `Segment Trees`.

Segment trees support range queries and updates where the operation is associative: sum, min, max, gcd, or custom merge objects.

Complexity:

- Build: `O(n)`.
- Query/update: `O(log n)`.

Read aloud note: "Segment trees split the array into intervals. Each node stores the answer for its interval, and queries combine only the nodes that exactly cover the requested range."

## Sliding Window

Present in `Sliding Window/fixed` and `Sliding Window/dynamic`.

Fixed window covers exact length problems such as maximum vowels, average threshold, permutation in string, distinct subarray of size K, and card points.

Dynamic window covers variable length problems such as minimum window substring, longest substring without repeats, subarray product less than K, minimum size subarray sum, good subarrays, and bounded maximum.

Read aloud note: "Sliding window works when adding the right side and removing the left side lets me maintain the condition incrementally. Fixed windows move by one; dynamic windows shrink only when invalid."

## Sorting

Present in `Sorting`.

Covers custom ordering, relative sorting, largest number comparator, rank teams by votes, maximum gap, minimum absolute difference, and majority element variants.

Sorting is often used to create structure before applying greedy, two pointers, intervals, or binary search.

Read aloud note: "Sorting is not just for final order. It creates a monotonic structure so later decisions only need local comparisons."

## SortedList

Present in `SortedList`.

Used for maintaining ordered data dynamically when insert/delete/search by order is needed. In Python interviews, this is often simulated with `bisect` over a list for small constraints, or implemented with Fenwick/segment tree/heap depending on operations.

Read aloud note: "I use an ordered container when the data changes but queries still depend on rank or sorted position."

## Square Root Decomposition

Present in `Squart Root Decomposition`.

Square root decomposition splits an array into blocks. It is useful when full segment tree complexity is not necessary or updates have block-level shortcuts.

Complexity: usually around `O(sqrt n)` per query/update, depending on the operation.

Read aloud note: "Sqrt decomposition is a middle ground: precompute block summaries, handle whole blocks quickly, and scan partial blocks directly."

## Stack

Present in `Stack`.

Covers valid parentheses, RPN evaluation, simplify path, decode string, asteroid collision, baseball game, car fleet, online stock span, min stack, histogram rectangle, and daily temperatures.

Use stack when the most recent unresolved item matters first.

Read aloud note: "A stack models nested or last-in-first-out behavior. Parentheses, paths, decoders, and monotonic candidate problems all fit that shape."

## Strings

Present in `Strings`, `2 Pointers/strings`, `Tries/Strings`, and string DP files.

Covers anagrams, valid palindrome, one edit distance, isomorphic strings, alien dictionary verification, encode/decode strings, KMP, Z algorithm, Manacher, longest common prefix, and merge strings alternately.

String algorithm uses:

- Frequency arrays/maps for anagrams.
- Two pointers for palindrome/edit checks.
- KMP/Z for linear-time pattern matching.
- Manacher for palindromic radii.
- Trie for prefix lookup and wildcard search.

Read aloud note: "For strings, I first decide whether order, frequency, prefix, or pattern matching is the core issue. That tells me whether to use two pointers, hashing, trie, or KMP-style preprocessing."

## Sweep Line

Present in `Intervals/sweep line` and `Prefix Sum & Partial Sum`.

Sweep line converts ranges into start/end events, then scans events in sorted order to track active count or accumulated value. Difference arrays are the discrete version.

Read aloud note: "Instead of updating every point in a range, I mark where the effect starts and where it ends. The sweep reconstructs the active value in order."

## System Design

Present in `System Design`.

This folder focuses on design-style data structure problems:

- LRU Cache: hash map plus usage order.
- LFU Cache: frequency buckets plus recency order.
- Design Twitter: follow graph plus recent tweets merge.
- Time Based Key-Value Store: map to sorted timestamped values plus binary search.
- Hit Counter: timestamp queue or buckets.
- Router: FIFO queue, duplicate set, per-destination timestamp lists.
- HashMap/HashSet: bucket array and collision handling.
- Circular Queue: fixed array with head/tail pointers.
- Stack using Queues and Queue using Stacks: adapter designs and amortized analysis.
- Leaderboard: score map plus ranking structure.

Read aloud note: "For design data structures, I list operations and required complexity first. Then I combine primitives, usually hash maps for lookup and a list/heap/tree/queue for ordering."

## Topological Sort

Present in `Graph/Topological Sort`.

Use for directed acyclic graphs and dependency ordering. Covers Course Schedule, Course Schedule II/IV, Alien Dictionary, Build Matrix With Conditions, Minimum Height Trees, and Kahn's algorithm notes.

Two main methods:

- Kahn BFS with indegrees.
- DFS with cycle detection and postorder.

Read aloud note: "Topological sort is valid only for DAGs. If a cycle exists, there is no linear order satisfying all dependencies."

## Trie

Present in `Tries/Strings` and DP trie usage.

Covers implement trie, add/search words with wildcard, Word Search II, and extra characters in a string.

Trie strengths:

- Prefix queries.
- Dictionary word lookup during DFS.
- Wildcard branching.
- Reducing repeated prefix scans.

Read aloud note: "Trie stores shared prefixes once. It is efficient when many words share prefixes or when I need to test prefixes while exploring a grid or string."

## Fast Interview Talk Tracks

Use these when explaining solutions aloud.

| If the problem says... | Say this first |
|---|---|
| "shortest path" | "I check weights. Unweighted means BFS, 0/1 weights means deque BFS, non-negative weights means Dijkstra, negative weights means Bellman-Ford." |
| "count ways" | "I define a DP state over prefix/index/sum and add transitions from previous valid states." |
| "subarray sum equals K" | "I use prefix sums and count previous prefixes equal to current minus K." |
| "top K" | "I use a heap if I only need K best elements, not a full sort." |
| "range query with updates" | "I need a Fenwick tree or segment tree depending on the operation." |
| "dependencies" | "This is a directed graph; topological sort applies if it is acyclic." |
| "connect components dynamically" | "DSU handles incremental union and connectivity queries efficiently." |
| "longest substring" | "This is usually a dynamic sliding window with a frequency map or last-seen index." |
| "parentheses/nested expression" | "A stack matches the nested last-open, first-closed structure." |
| "prefix dictionary" | "A trie avoids repeatedly scanning the same prefixes." |

## Final Revision Checklist

- Can I state the invariant?
- Can I justify the complexity?
- Can I handle edge cases: empty input, one element, duplicates, negative values, disconnected graph?
- Can I explain why this data structure is better than a simpler one?
- Can I dry run on a small example before coding?

Read aloud note: "My solution is not just code. I want to explain the invariant, why the algorithm is correct, and where the complexity comes from."
