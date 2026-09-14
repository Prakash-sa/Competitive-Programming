# Competitive Programming Templates (Python)

Copy only the pieces a problem needs. Unless a section says otherwise:

- Arrays and ranges are 0-indexed.
- Range endpoints use the half-open convention `[left, right)`.
- Graph vertices are numbered `0..n-1`.
- `INF = 10**18` is assumed to be larger than any valid answer.

## Contents

1. [Contest starter](#contest-starter)
2. [Arrays and searching](#arrays-and-searching)
3. [Intervals, stacks, and heaps](#intervals-stacks-and-heaps)
4. [Backtracking and dynamic programming](#backtracking-and-dynamic-programming)
5. [Linked lists](#linked-lists)
6. [Graphs](#graphs)
7. [Trees](#trees)
8. [Range-query data structures](#range-query-data-structures)
9. [Strings and tries](#strings-and-tries)
10. [Number theory](#number-theory)

## Contest starter

```python
#!/usr/bin/env python3
import sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from functools import lru_cache
from heapq import heapify, heappop, heappush
from math import gcd, isqrt

input = sys.stdin.readline
INF = 10**18
MOD = 10**9 + 7


def ints():
    return map(int, input().split())


def solve():
    pass


if __name__ == "__main__":
    # For multiple test cases, use: for _ in range(int(input())): solve()
    solve()
```

For output-heavy problems, collect answers and print once:

```python
answers = []
answers.append(str(answer))
sys.stdout.write("\n".join(answers))
```

## Arrays and searching

### Prefix sum

Build in `O(n)` and answer a range-sum query in `O(1)`.

```python
def prefix_sum(nums):
    prefix = [0]
    for value in nums:
        prefix.append(prefix[-1] + value)
    return prefix


def range_sum(prefix, left, right):
    return prefix[right] - prefix[left]
```

### Prefix sum with a hash map

Count subarrays whose sum equals `target` in `O(n)` expected time.

```python
def count_subarrays_with_sum(nums, target):
    frequency = {0: 1}
    prefix = answer = 0

    for value in nums:
        prefix += value
        answer += frequency.get(prefix - target, 0)
        frequency[prefix] = frequency.get(prefix, 0) + 1

    return answer
```

### Difference array

Apply each range addition in `O(1)`, then materialize the result in `O(n)`.

```python
def apply_range_additions(nums, updates):
    # updates contains (left, right, delta), with right exclusive.
    diff = [0] * (len(nums) + 1)
    for left, right, delta in updates:
        diff[left] += delta
        diff[right] -= delta

    running = 0
    result = nums[:]
    for i in range(len(nums)):
        running += diff[i]
        result[i] += running
    return result
```

### 2D prefix sum

Build in `O(rows * cols)` and query a rectangle in `O(1)`.

```python
def prefix_sum_2d(matrix):
    if not matrix or not matrix[0]:
        return [[0]]
    rows, cols = len(matrix), len(matrix[0])
    prefix = [[0] * (cols + 1) for _ in range(rows + 1)]

    for row in range(rows):
        for col in range(cols):
            prefix[row + 1][col + 1] = (
                matrix[row][col]
                + prefix[row][col + 1]
                + prefix[row + 1][col]
                - prefix[row][col]
            )
    return prefix


def rectangle_sum(prefix, row1, col1, row2, col2):
    return (
        prefix[row2][col2]
        - prefix[row1][col2]
        - prefix[row2][col1]
        + prefix[row1][col1]
    )
```

### Fixed-size sliding window

```python
def maximum_window_sum(nums, k):
    if k <= 0 or k > len(nums):
        return None

    window = sum(nums[:k])
    answer = window
    for right in range(k, len(nums)):
        window += nums[right] - nums[right - k]
        answer = max(answer, window)
    return answer
```

### Variable-size sliding window

This form assumes non-negative values, so removing items cannot increase the sum.

```python
def shortest_subarray_at_least_target(nums, target):
    left = window_sum = 0
    answer = len(nums) + 1

    for right, value in enumerate(nums):
        window_sum += value
        while window_sum >= target:
            answer = min(answer, right - left + 1)
            window_sum -= nums[left]
            left += 1

    return answer if answer <= len(nums) else -1
```

### Two pointers on a sorted array

```python
def two_sum_sorted(nums, target):
    left, right = 0, len(nums) - 1
    while left < right:
        total = nums[left] + nums[right]
        if total == target:
            return left, right
        if total < target:
            left += 1
        else:
            right -= 1
    return None
```

### Binary search boundaries

`first_true` finds the smallest value satisfying a monotonic predicate. `last_true`
finds the largest one. Both search inclusive integer bounds.

```python
def first_true(low, high, predicate):
    answer = high + 1
    while low <= high:
        mid = (low + high) // 2
        if predicate(mid):
            answer = mid
            high = mid - 1
        else:
            low = mid + 1
    return answer


def last_true(low, high, predicate):
    answer = low - 1
    while low <= high:
        mid = (low + high) // 2
        if predicate(mid):
            answer = mid
            low = mid + 1
        else:
            high = mid - 1
    return answer
```

For a sorted list, prefer `bisect_left(nums, value)` and
`bisect_right(nums, value)`.

### Coordinate compression

```python
def coordinate_compress(values):
    ordered = sorted(set(values))
    rank = {value: i for i, value in enumerate(ordered)}
    return [rank[value] for value in values], ordered
```

### Kadane's algorithm

Maximum non-empty subarray sum in `O(n)` time and `O(1)` space.

```python
def maximum_subarray_sum(nums):
    current = answer = nums[0]
    for value in nums[1:]:
        current = max(value, current + value)
        answer = max(answer, current)
    return answer
```

## Intervals, stacks, and heaps

### Merge intervals

```python
def merge_intervals(intervals):
    merged = []
    for start, end in sorted(intervals):
        if not merged or merged[-1][1] < start:
            merged.append([start, end])
        else:
            merged[-1][1] = max(merged[-1][1], end)
    return merged
```

### Sweep line with events

The example returns the maximum number of overlapping half-open intervals.
Sorting end events before start events at the same coordinate prevents touching
intervals from being counted as overlapping.

```python
def maximum_overlap(intervals):
    events = []
    for start, end in intervals:
        events.append((start, 1))
        events.append((end, -1))

    active = answer = 0
    for _, delta in sorted(events, key=lambda event: (event[0], event[1])):
        active += delta
        answer = max(answer, active)
    return answer
```

### Monotonic stack

Return the index of the next strictly greater value to the right for every item.

```python
def next_greater_indices(nums):
    answer = [-1] * len(nums)
    stack = []

    for i, value in enumerate(nums):
        while stack and nums[stack[-1]] < value:
            answer[stack.pop()] = i
        stack.append(i)
    return answer
```

### Monotonic deque

Return the maximum in every window in `O(n)`.

```python
from collections import deque


def sliding_window_maximum(nums, k):
    if k <= 0 or k > len(nums):
        return []

    queue = deque()
    answer = []

    for right, value in enumerate(nums):
        while queue and queue[0] <= right - k:
            queue.popleft()
        while queue and nums[queue[-1]] <= value:
            queue.pop()
        queue.append(right)

        if right >= k - 1:
            answer.append(nums[queue[0]])
    return answer
```

### Top K with a heap

Keep the `k` largest values in `O(n log k)` time.

```python
from heapq import heapreplace, heappush


def k_largest(nums, k):
    if k <= 0:
        return []

    heap = []
    for value in nums:
        if len(heap) < k:
            heappush(heap, value)
        elif value > heap[0]:
            heapreplace(heap, value)
    return sorted(heap, reverse=True)
```

### Merge K sorted sequences

```python
from heapq import heappop, heappush


def merge_k_sorted(sequences):
    heap = []
    for sequence_id, sequence in enumerate(sequences):
        if sequence:
            heappush(heap, (sequence[0], sequence_id, 0))

    merged = []
    while heap:
        value, sequence_id, index = heappop(heap)
        merged.append(value)
        next_index = index + 1
        if next_index < len(sequences[sequence_id]):
            next_value = sequences[sequence_id][next_index]
            heappush(heap, (next_value, sequence_id, next_index))
    return merged
```

## Backtracking and dynamic programming

### Backtracking

This subset template shows the choose/explore/unchoose pattern.

```python
def subsets(nums):
    answer = []
    path = []

    def backtrack(index):
        if index == len(nums):
            answer.append(path[:])
            return

        backtrack(index + 1)

        path.append(nums[index])
        backtrack(index + 1)
        path.pop()

    backtrack(0)
    return answer
```

### Memoized DP

Define the state, return at the base case, and cache every state transition.

```python
from functools import lru_cache


def minimum_cost(cost):
    @lru_cache(maxsize=None)
    def dp(index):
        if index >= len(cost):
            return 0
        return cost[index] + min(dp(index + 1), dp(index + 2))

    return min(dp(0), dp(1))
```

### 0/1 knapsack

Descending capacity is essential: it prevents using the same item more than once.

```python
def knapsack_01(weights, values, capacity):
    dp = [0] * (capacity + 1)
    for weight, value in zip(weights, values):
        for current_capacity in range(capacity, weight - 1, -1):
            dp[current_capacity] = max(
                dp[current_capacity],
                dp[current_capacity - weight] + value,
            )
    return dp[capacity]
```

For unbounded knapsack, iterate capacity upward instead.

### Longest increasing subsequence

Find the LIS length in `O(n log n)`.

```python
from bisect import bisect_left


def lis_length(nums):
    tails = []
    for value in nums:
        index = bisect_left(tails, value)
        if index == len(tails):
            tails.append(value)
        else:
            tails[index] = value
    return len(tails)
```

### Longest common subsequence

`O(n * m)` time and `O(m)` space.

```python
def lcs_length(first, second):
    if len(first) < len(second):
        first, second = second, first

    previous = [0] * (len(second) + 1)
    for left_char in first:
        current = [0]
        for col, right_char in enumerate(second, start=1):
            if left_char == right_char:
                current.append(previous[col - 1] + 1)
            else:
                current.append(max(previous[col], current[-1]))
        previous = current
    return previous[-1]
```

### Interval DP

Change `transition_cost` to match the problem. This template tries every final split.

```python
def interval_dp(values, transition_cost):
    n = len(values)
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n + 1):
        for left in range(n - length + 1):
            right = left + length - 1
            dp[left][right] = min(
                dp[left][split]
                + dp[split + 1][right]
                + transition_cost(left, split, right)
                for split in range(left, right)
            )
    return dp[0][n - 1] if n else 0
```

### Bitmask enumeration

```python
def all_subsets(nums):
    for mask in range(1 << len(nums)):
        subset = [nums[i] for i in range(len(nums)) if mask & (1 << i)]
        yield subset


def submasks(mask):
    submask = mask
    while submask:
        yield submask
        submask = (submask - 1) & mask
    yield 0
```

## Linked lists

### Reverse a linked list

```python
class ListNode:
    def __init__(self, value=0, next_node=None):
        self.value = value
        self.next = next_node


def reverse_linked_list(head):
    previous = None
    current = head
    while current:
        next_node = current.next
        current.next = previous
        previous = current
        current = next_node
    return previous
```

### Fast and slow pointers

Floyd's algorithm detects a cycle in `O(n)` time and `O(1)` space. After a
collision, restarting one pointer at the head finds the cycle entry.

```python
def cycle_entry(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            break
    else:
        return None

    slow = head
    while slow is not fast:
        slow = slow.next
        fast = fast.next
    return slow
```

### Merge two sorted linked lists

```python
def merge_sorted_lists(first, second):
    sentinel = ListNode()
    tail = sentinel

    while first and second:
        if first.value <= second.value:
            tail.next = first
            first = first.next
        else:
            tail.next = second
            second = second.next
        tail = tail.next

    tail.next = first or second
    return sentinel.next
```

## Graphs

### Build adjacency lists

```python
def build_graph(n, edges, directed=False):
    graph = [[] for _ in range(n)]
    for start, end in edges:
        graph[start].append(end)
        if not directed:
            graph[end].append(start)
    return graph
```

### Breadth-first search

Shortest distances from `source` in an unweighted graph: `O(V + E)`.

```python
from collections import deque


def bfs(graph, source):
    distance = [-1] * len(graph)
    parent = [-1] * len(graph)
    distance[source] = 0
    queue = deque([source])

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if distance[neighbor] == -1:
                distance[neighbor] = distance[node] + 1
                parent[neighbor] = node
                queue.append(neighbor)
    return distance, parent
```

### Iterative depth-first search

```python
def dfs(graph, source):
    seen = [False] * len(graph)
    order = []
    stack = [source]

    while stack:
        node = stack.pop()
        if seen[node]:
            continue
        seen[node] = True
        order.append(node)
        stack.extend(reversed(graph[node]))
    return order
```

### Grid BFS

```python
from collections import deque


DIRECTIONS_4 = ((1, 0), (-1, 0), (0, 1), (0, -1))


def grid_bfs(grid, start_row, start_col):
    rows, cols = len(grid), len(grid[0])
    distance = [[-1] * cols for _ in range(rows)]
    distance[start_row][start_col] = 0
    queue = deque([(start_row, start_col)])

    while queue:
        row, col = queue.popleft()
        for row_delta, col_delta in DIRECTIONS_4:
            next_row = row + row_delta
            next_col = col + col_delta
            if not (0 <= next_row < rows and 0 <= next_col < cols):
                continue
            if grid[next_row][next_col] == "#":
                continue
            if distance[next_row][next_col] != -1:
                continue
            distance[next_row][next_col] = distance[row][col] + 1
            queue.append((next_row, next_col))
    return distance
```

For multi-source BFS, initialize the queue with every source and set each source's
distance to zero before starting the same loop.

### Dijkstra's algorithm

For non-negative edge weights: `O((V + E) log V)` with a binary heap.

```python
from heapq import heappop, heappush


def dijkstra(graph, source):
    # graph[node] contains (neighbor, weight).
    distance = [10**18] * len(graph)
    parent = [-1] * len(graph)
    distance[source] = 0
    heap = [(0, source)]

    while heap:
        current_distance, node = heappop(heap)
        if current_distance != distance[node]:
            continue

        for neighbor, weight in graph[node]:
            candidate = current_distance + weight
            if candidate < distance[neighbor]:
                distance[neighbor] = candidate
                parent[neighbor] = node
                heappush(heap, (candidate, neighbor))
    return distance, parent
```

### 0-1 BFS

For edges whose weights are only `0` or `1`: `O(V + E)`.

```python
from collections import deque


def zero_one_bfs(graph, source):
    distance = [10**18] * len(graph)
    distance[source] = 0
    queue = deque([source])

    while queue:
        node = queue.popleft()
        for neighbor, weight in graph[node]:
            candidate = distance[node] + weight
            if candidate < distance[neighbor]:
                distance[neighbor] = candidate
                if weight == 0:
                    queue.appendleft(neighbor)
                else:
                    queue.append(neighbor)
    return distance
```

### Bellman-Ford

Handles negative edges and reports a reachable negative cycle: `O(VE)`.

```python
def bellman_ford(n, edges, source):
    distance = [10**18] * n
    distance[source] = 0

    for _ in range(n - 1):
        changed = False
        for start, end, weight in edges:
            if distance[start] == 10**18:
                continue
            candidate = distance[start] + weight
            if candidate < distance[end]:
                distance[end] = candidate
                changed = True
        if not changed:
            break

    has_negative_cycle = any(
        distance[start] != 10**18 and distance[start] + weight < distance[end]
        for start, end, weight in edges
    )
    return distance, has_negative_cycle
```

### Topological sort (Kahn's algorithm)

```python
from collections import deque


def topological_sort(n, edges):
    graph = [[] for _ in range(n)]
    indegree = [0] * n
    for start, end in edges:
        graph[start].append(end)
        indegree[end] += 1

    queue = deque(node for node in range(n) if indegree[node] == 0)
    order = []
    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    return order if len(order) == n else None
```

### Disjoint set union (Union-Find)

Amortized `O(alpha(n))` per operation with path compression and union by size.

```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.components = n

    def find(self, node):
        while node != self.parent[node]:
            self.parent[node] = self.parent[self.parent[node]]
            node = self.parent[node]
        return node

    def union(self, first, second):
        first = self.find(first)
        second = self.find(second)
        if first == second:
            return False
        if self.size[first] < self.size[second]:
            first, second = second, first
        self.parent[second] = first
        self.size[first] += self.size[second]
        self.components -= 1
        return True
```

### Kruskal's minimum spanning tree

```python
def kruskal(n, edges):
    # edges contains (weight, start, end).
    dsu = DSU(n)
    total_weight = 0
    chosen_edges = []

    for weight, start, end in sorted(edges):
        if dsu.union(start, end):
            total_weight += weight
            chosen_edges.append((start, end, weight))

    if len(chosen_edges) != n - 1:
        return None
    return total_weight, chosen_edges
```

### Strongly connected components (Kosaraju)

```python
def strongly_connected_components(graph):
    n = len(graph)
    reverse_graph = [[] for _ in range(n)]
    for node in range(n):
        for neighbor in graph[node]:
            reverse_graph[neighbor].append(node)

    seen = [False] * n
    finish_order = []

    def first_dfs(node):
        seen[node] = True
        for neighbor in graph[node]:
            if not seen[neighbor]:
                first_dfs(neighbor)
        finish_order.append(node)

    for node in range(n):
        if not seen[node]:
            first_dfs(node)

    component = [-1] * n

    def second_dfs(node, component_id):
        component[node] = component_id
        for neighbor in reverse_graph[node]:
            if component[neighbor] == -1:
                second_dfs(neighbor, component_id)

    component_id = 0
    for node in reversed(finish_order):
        if component[node] == -1:
            second_dfs(node, component_id)
            component_id += 1
    return component, component_id
```

The recursive SCC template is concise, but increase the recursion limit or use an
iterative traversal when graph depth can be large.

## Trees

### Iterative tree traversal and subtree sizes

The reversed traversal order gives a postorder without recursion.

```python
def tree_parent_and_subtree_sizes(tree, root=0):
    parent = [-1] * len(tree)
    order = [root]

    for node in order:
        for neighbor in tree[node]:
            if neighbor == parent[node]:
                continue
            parent[neighbor] = node
            order.append(neighbor)

    subtree_size = [1] * len(tree)
    for node in reversed(order[1:]):
        subtree_size[parent[node]] += subtree_size[node]
    return parent, order, subtree_size
```

### Tree diameter

Works for an unweighted tree in `O(n)`.

```python
from collections import deque


def tree_diameter(tree):
    if not tree:
        return None

    def farthest(source):
        distance = [-1] * len(tree)
        distance[source] = 0
        queue = deque([source])
        last = source
        while queue:
            node = queue.popleft()
            last = node
            for neighbor in tree[node]:
                if distance[neighbor] == -1:
                    distance[neighbor] = distance[node] + 1
                    queue.append(neighbor)
        return last, distance[last]

    endpoint, _ = farthest(0)
    other_endpoint, length = farthest(endpoint)
    return endpoint, other_endpoint, length
```

### Lowest common ancestor (binary lifting)

Preprocessing takes `O(n log n)`; each LCA query takes `O(log n)`.

```python
class LCA:
    def __init__(self, tree, root=0):
        n = len(tree)
        self.levels = max(1, n.bit_length())
        self.depth = [0] * n
        self.up = [[root] * n for _ in range(self.levels)]

        parent = [root] * n
        order = [root]
        for node in order:
            for neighbor in tree[node]:
                if neighbor == parent[node]:
                    continue
                parent[neighbor] = node
                self.depth[neighbor] = self.depth[node] + 1
                order.append(neighbor)

        self.up[0] = parent
        for level in range(1, self.levels):
            previous = self.up[level - 1]
            self.up[level] = [previous[previous[node]] for node in range(n)]

    def lift(self, node, distance):
        bit = 0
        while distance:
            if distance & 1:
                node = self.up[bit][node]
            distance >>= 1
            bit += 1
        return node

    def query(self, first, second):
        if self.depth[first] < self.depth[second]:
            first, second = second, first
        first = self.lift(first, self.depth[first] - self.depth[second])
        if first == second:
            return first

        for level in range(self.levels - 1, -1, -1):
            if self.up[level][first] != self.up[level][second]:
                first = self.up[level][first]
                second = self.up[level][second]
        return self.up[0][first]

    def distance(self, first, second):
        ancestor = self.query(first, second)
        return (
            self.depth[first]
            + self.depth[second]
            - 2 * self.depth[ancestor]
        )
```

### Euler tour for subtree queries

Every subtree becomes the contiguous range `[entry[node], exit[node])`.

```python
def euler_tour(tree, root=0):
    n = len(tree)
    entry = [0] * n
    exit_time = [0] * n
    order = []
    stack = [(root, -1, False)]

    while stack:
        node, parent, exiting = stack.pop()
        if exiting:
            exit_time[node] = len(order)
            continue

        entry[node] = len(order)
        order.append(node)
        stack.append((node, parent, True))
        for neighbor in reversed(tree[node]):
            if neighbor != parent:
                stack.append((neighbor, node, False))
    return entry, exit_time, order
```

## Range-query data structures

### Fenwick tree / Binary Indexed Tree

Point addition and prefix/range sums in `O(log n)`.

```python
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    def add(self, index, delta):
        index += 1
        while index <= self.n:
            self.tree[index] += delta
            index += index & -index

    def prefix_sum(self, right):
        result = 0
        while right > 0:
            result += self.tree[right]
            right -= right & -right
        return result

    def range_sum(self, left, right):
        return self.prefix_sum(right) - self.prefix_sum(left)
```

### Iterative segment tree

Point assignment and range sum in `O(log n)`.

```python
class SegmentTree:
    def __init__(self, values):
        size = 1
        while size < len(values):
            size *= 2
        self.size = size
        self.tree = [0] * (2 * size)
        self.tree[size:size + len(values)] = values

        for node in range(size - 1, 0, -1):
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def set(self, index, value):
        node = index + self.size
        self.tree[node] = value
        node //= 2
        while node:
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]
            node //= 2

    def query(self, left, right):
        result = 0
        left += self.size
        right += self.size
        while left < right:
            if left & 1:
                result += self.tree[left]
                left += 1
            if right & 1:
                right -= 1
                result += self.tree[right]
            left //= 2
            right //= 2
        return result
```

To store minimum, maximum, GCD, or another associative operation, replace `0`
with that operation's identity and replace additions with the merge operation.

### Lazy segment tree

Range addition and range minimum in `O(log n)`.

```python
class LazyMinSegmentTree:
    def __init__(self, values):
        size = 1
        while size < len(values):
            size *= 2
        self.size = size
        self.tree = [10**18] * (2 * size)
        self.lazy = [0] * (2 * size)
        self.tree[size:size + len(values)] = values

        for node in range(size - 1, 0, -1):
            self.tree[node] = min(self.tree[2 * node], self.tree[2 * node + 1])

    def _apply(self, node, delta):
        self.tree[node] += delta
        if node < self.size:
            self.lazy[node] += delta

    def _push(self, node):
        if self.lazy[node]:
            self._apply(2 * node, self.lazy[node])
            self._apply(2 * node + 1, self.lazy[node])
            self.lazy[node] = 0

    def add(self, left, right, delta):
        def update(node, node_left, node_right):
            if right <= node_left or node_right <= left:
                return
            if left <= node_left and node_right <= right:
                self._apply(node, delta)
                return

            self._push(node)
            middle = (node_left + node_right) // 2
            update(2 * node, node_left, middle)
            update(2 * node + 1, middle, node_right)
            self.tree[node] = min(self.tree[2 * node], self.tree[2 * node + 1])

        update(1, 0, self.size)

    def query(self, left, right):
        def get_minimum(node, node_left, node_right):
            if right <= node_left or node_right <= left:
                return 10**18
            if left <= node_left and node_right <= right:
                return self.tree[node]

            self._push(node)
            middle = (node_left + node_right) // 2
            return min(
                get_minimum(2 * node, node_left, middle),
                get_minimum(2 * node + 1, middle, node_right),
            )

        return get_minimum(1, 0, self.size)
```

## Strings and tries

### KMP prefix function and matching

Find all occurrences in `O(len(text) + len(pattern))`.

```python
def prefix_function(string):
    prefix = [0] * len(string)
    for i in range(1, len(string)):
        matched = prefix[i - 1]
        while matched and string[i] != string[matched]:
            matched = prefix[matched - 1]
        if string[i] == string[matched]:
            matched += 1
        prefix[i] = matched
    return prefix


def kmp_find_all(text, pattern):
    if not pattern:
        return list(range(len(text) + 1))

    prefix = prefix_function(pattern)
    occurrences = []
    matched = 0
    for i, char in enumerate(text):
        while matched and char != pattern[matched]:
            matched = prefix[matched - 1]
        if char == pattern[matched]:
            matched += 1
        if matched == len(pattern):
            occurrences.append(i - len(pattern) + 1)
            matched = prefix[matched - 1]
    return occurrences
```

### Z algorithm

```python
def z_function(string):
    z = [0] * len(string)
    left = right = 0

    for i in range(1, len(string)):
        if i < right:
            z[i] = min(right - i, z[i - left])
        while i + z[i] < len(string) and string[z[i]] == string[i + z[i]]:
            z[i] += 1
        if i + z[i] > right:
            left, right = i, i + z[i]
    return z
```

### Rolling hash

The returned function hashes `[left, right)` in `O(1)`. For adversarial inputs,
use two moduli or verify equal substrings after a hash match.

```python
def rolling_hash(string, base=911382323, modulus=972663749):
    prefix = [0] * (len(string) + 1)
    powers = [1] * (len(string) + 1)

    for i, char in enumerate(string):
        prefix[i + 1] = (prefix[i] * base + ord(char)) % modulus
        powers[i + 1] = powers[i] * base % modulus

    def substring_hash(left, right):
        return (prefix[right] - prefix[left] * powers[right - left]) % modulus

    return substring_hash
```

### Trie

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            node = node.children.setdefault(char, TrieNode())
        node.is_word = True

    def search(self, word):
        node = self._find(word)
        return node is not None and node.is_word

    def starts_with(self, prefix):
        return self._find(prefix) is not None

    def _find(self, text):
        node = self.root
        for char in text:
            if char not in node.children:
                return None
            node = node.children[char]
        return node
```

## Number theory

### GCD, LCM, and extended Euclid

```python
from math import gcd


def lcm(first, second):
    if first == 0 or second == 0:
        return 0
    return first // gcd(first, second) * second


def extended_gcd(first, second):
    if second == 0:
        return first, 1, 0
    divisor, x1, y1 = extended_gcd(second, first % second)
    return divisor, y1, x1 - (first // second) * y1
```

When `modulus` is prime and `value` is not divisible by it, the modular inverse is
`pow(value, modulus - 2, modulus)`. On modern Python, `pow(value, -1, modulus)`
also computes an inverse when one exists.

### Sieve and smallest prime factor

Build in `O(n log log n)` and factorize a number in `O(log n)` divisions.

```python
def smallest_prime_factors(limit):
    spf = list(range(limit + 1))
    if limit >= 1:
        spf[1] = 1

    for prime in range(2, int(limit**0.5) + 1):
        if spf[prime] == prime:
            for multiple in range(prime * prime, limit + 1, prime):
                if spf[multiple] == multiple:
                    spf[multiple] = prime
    return spf


def factorize(value, spf):
    factors = []
    while value > 1:
        prime = spf[value]
        exponent = 0
        while value % prime == 0:
            value //= prime
            exponent += 1
        factors.append((prime, exponent))
    return factors
```

### Combinations modulo a prime

Precompute in `O(limit)` and answer each `nCk` query in `O(1)`.

```python
class Combinations:
    def __init__(self, limit, modulus=10**9 + 7):
        self.modulus = modulus
        self.factorial = [1] * (limit + 1)
        for value in range(1, limit + 1):
            self.factorial[value] = self.factorial[value - 1] * value % modulus

        self.inverse_factorial = [1] * (limit + 1)
        self.inverse_factorial[limit] = pow(
            self.factorial[limit],
            modulus - 2,
            modulus,
        )
        for value in range(limit, 0, -1):
            self.inverse_factorial[value - 1] = (
                self.inverse_factorial[value] * value % modulus
            )

    def choose(self, n, k):
        if k < 0 or k > n:
            return 0
        return (
            self.factorial[n]
            * self.inverse_factorial[k]
            % self.modulus
            * self.inverse_factorial[n - k]
            % self.modulus
        )
```

### Fast exponentiation

```python
def binary_power(base, exponent, modulus=None):
    result = 1
    while exponent:
        if exponent & 1:
            result *= base
            if modulus is not None:
                result %= modulus
        base *= base
        if modulus is not None:
            base %= modulus
        exponent >>= 1
    return result
```

## Pattern selection checklist

| Signal in the problem | First pattern to consider |
| --- | --- |
| Contiguous subarray/substring | Sliding window or prefix sum |
| Sorted input, pair, or partition | Two pointers or binary search |
| Monotonic feasibility | Binary search on the answer |
| Next greater/smaller value | Monotonic stack |
| Repeated range query/update | Prefix sum, Fenwick, or segment tree |
| Top/bottom `k`, streaming minimum/maximum | Heap |
| Unweighted shortest path | BFS |
| Edge weights only `0` and `1` | 0-1 BFS |
| Non-negative weighted shortest path | Dijkstra |
| Dependencies or prerequisites | Topological sort |
| Connectivity under edge additions | DSU |
| Cycle, midpoint, or kth-from-end in a linked list | Fast and slow pointers |
| Enumerate choices with constraints | Backtracking |
| Overlapping subproblems | Memoization or tabulation |
| `n <= 20` and subsets matter | Bitmask DP |
| Repeated prefix/string matching | Trie, KMP, Z, or rolling hash |

Always verify the constraints, prove the invariant or recurrence, and state both
time and auxiliary-space complexity before coding.
