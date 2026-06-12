# Prim's Algorithm

## What It Finds

Prim's algorithm finds a Minimum Spanning Tree (MST) of an undirected, weighted, connected graph.

An MST connects all `n` nodes using exactly `n - 1` edges with the minimum possible total edge weight.

If the graph is disconnected, running Prim from one node only gives the MST of that connected component.

## Main Idea

Prim is node/component-focused.

Start from any node. Keep growing the MST by repeatedly choosing the cheapest edge that connects the current MST to a new unvisited node.

Use a min-heap to always pick the smallest available edge.

This is similar to Dijkstra's algorithm, but:

- Dijkstra picks the shortest total distance from the source.
- Prim picks the cheapest edge that expands the MST.

## Algorithm Steps

1. Build an adjacency list from the weighted edges.
2. Pick any start node, usually `0`.
3. Push `(0, start)` into a min-heap.
4. While the heap is not empty:
   - Pop the edge with the smallest weight.
   - If the node is already visited, skip it.
   - Mark the node visited.
   - Add the edge weight to the MST cost.
   - Push all edges from this node to unvisited neighbors.
5. At the end, all nodes must be visited for a valid MST.

## Python Template

`graph[u]` should contain tuples like `(v, weight)`.

```python
from heapq import heappop, heappush


def prim(n, graph):
    visited = [False] * n
    min_heap = [(0, 0)]  # (edge_weight, node)

    mst_cost = 0
    nodes_used = 0

    while min_heap:
        weight, u = heappop(min_heap)

        if visited[u]:
            continue

        visited[u] = True
        mst_cost += weight
        nodes_used += 1

        for v, edge_weight in graph[u]:
            if not visited[v]:
                heappush(min_heap, (edge_weight, v))

    if nodes_used != n:
        return -1

    return mst_cost
```

## Python Template With MST Edges

Use this version when the problem asks for the actual edges in the MST.

```python
from heapq import heappop, heappush


def prim_with_edges(n, graph):
    visited = [False] * n
    min_heap = [(0, 0, -1)]  # (edge_weight, node, parent)

    mst_cost = 0
    mst_edges = []

    while min_heap:
        weight, u, parent = heappop(min_heap)

        if visited[u]:
            continue

        visited[u] = True
        mst_cost += weight

        if parent != -1:
            mst_edges.append((parent, u, weight))

        for v, edge_weight in graph[u]:
            if not visited[v]:
                heappush(min_heap, (edge_weight, v, u))

    if len(mst_edges) != n - 1:
        return -1

    return mst_cost, mst_edges
```

## Complexity

Time Complexity: `O(E log E)` or commonly written as `O(E log V)`

Each edge can be pushed into the heap, and heap operations cost logarithmic time.

Space Complexity: `O(V + E)`

The adjacency list stores all edges, and the heap can contain many candidate edges.

## When To Use

Use Prim when:

- The graph is already in adjacency-list form.
- You want to grow the MST from a starting node.
- The graph is dense, especially with optimized implementations.

## Common Mistakes

- Marking a node visited when pushing it into the heap instead of when popping it.
- Adding every popped edge without checking whether the node is already visited.
- Forgetting that the first heap entry has weight `0` because it only chooses the start node.
- Not checking whether all nodes were visited in a disconnected graph.
