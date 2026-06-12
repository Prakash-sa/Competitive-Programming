# Topological Sort using BFS

## Kahn's Algorithm

Topological sorting gives a valid ordering of nodes in a directed graph such that for every edge `u -> v`, node `u` appears before node `v`.

Topological sort only works for a Directed Acyclic Graph (DAG).

Kahn's algorithm uses BFS with indegree.

Indegree of a node means the number of incoming edges to that node.

## Main Idea

Nodes with indegree `0` have no dependency before them, so they can be placed first in the ordering.

After placing a node in the answer, remove its outgoing edges by decreasing the indegree of its neighbors.

Whenever a neighbor's indegree becomes `0`, push it into the queue.

If all nodes are processed, the graph is a DAG.
If fewer than `n` nodes are processed, the graph has a cycle.

## Algorithm Steps

1. Build the adjacency list.
2. Compute indegree of every node.
3. Push all nodes with indegree `0` into a queue.
4. While the queue is not empty:
   - Pop a node.
   - Add it to the topological order.
   - Decrease indegree of all its neighbors.
   - If a neighbor's indegree becomes `0`, push it into the queue.
5. If the final order has length `n`, return it.
6. Otherwise, no valid topological order exists because the graph has a cycle.

## Python Template

```python
from collections import deque


def topo_sort_bfs(n, edges):
    graph = [[] for _ in range(n)]
    indegree = [0] * n

    for u, v in edges:
        graph[u].append(v)
        indegree[v] += 1

    q = deque()
    for node in range(n):
        if indegree[node] == 0:
            q.append(node)

    order = []

    while q:
        u = q.popleft()
        order.append(u)

        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                q.append(v)

    if len(order) != n:
        return []

    return order
```

## Lexicographically Smallest Order

Use a min-heap instead of a queue when the problem asks for the smallest possible topological order.

```python
from heapq import heappop, heappush


def topo_sort_bfs_lexicographic(n, edges):
    graph = [[] for _ in range(n)]
    indegree = [0] * n

    for u, v in edges:
        graph[u].append(v)
        indegree[v] += 1

    heap = []
    for node in range(n):
        if indegree[node] == 0:
            heappush(heap, node)

    order = []

    while heap:
        u = heappop(heap)
        order.append(u)

        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                heappush(heap, v)

    if len(order) != n:
        return []

    return order
```

## Complexity

Time Complexity: `O(V + E)`

Each node is pushed and popped once, and each edge is processed once.

For the lexicographically smallest version, time complexity becomes `O((V + E) log V)` because of heap operations.

Space Complexity: `O(V + E)`

The adjacency list stores edges, and the indegree array stores one value per node.

## When To Use

Use BFS topological sort when:

- You need to process tasks by dependency order.
- You need cycle detection in a directed graph.
- You need the lexicographically smallest valid topological order.
- The problem talks about prerequisites, ordering, scheduling, or dependencies.

## Common Mistakes

- Using topological sort on an undirected graph.
- Forgetting to check `len(order) == n` for cycle detection.
- Decreasing indegree for the wrong direction of edge.
- Building edges backward. For prerequisite problems, decide carefully whether `a -> b` means `a before b` or `b before a`.
