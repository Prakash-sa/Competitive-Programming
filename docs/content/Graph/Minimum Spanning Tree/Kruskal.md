# Kruskal's Algorithm

## What It Finds

Kruskal's algorithm finds a Minimum Spanning Tree (MST) of an undirected, weighted, connected graph.

An MST connects all `n` nodes using exactly `n - 1` edges with the minimum possible total edge weight.

If the graph is disconnected, Kruskal gives a Minimum Spanning Forest, one MST per connected component.

## Main Idea

Kruskal is edge-focused.

It sorts all edges by weight and keeps taking the cheapest edge that does not create a cycle.

To detect cycles efficiently, use Disjoint Set Union (DSU), also called Union Find.

If two nodes are already in the same DSU component, adding that edge would create a cycle, so skip it.
If they are in different components, add the edge to the MST and union their components.

## Algorithm Steps

1. Sort all edges by increasing weight.
2. Initialize DSU so every node is its own component.
3. For each edge `(weight, u, v)` in sorted order:
   - If `u` and `v` are in different components:
     - Add this edge to the MST.
     - Add `weight` to the answer.
     - Union the components of `u` and `v`.
   - Otherwise, skip the edge because it creates a cycle.
4. Stop early once the MST has `n - 1` edges.

## Python Template

`edges` should contain tuples like `(weight, u, v)`.

```python
def kruskal(n, edges):
    parent = list(range(n))
    rank = [0] * n

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    def union(a, b):
        root_a = find(a)
        root_b = find(b)

        if root_a == root_b:
            return False

        if rank[root_a] < rank[root_b]:
            parent[root_a] = root_b
        elif rank[root_a] > rank[root_b]:
            parent[root_b] = root_a
        else:
            parent[root_b] = root_a
            rank[root_a] += 1

        return True

    edges.sort()

    mst_cost = 0
    mst_edges = []

    for weight, u, v in edges:
        if union(u, v):
            mst_cost += weight
            mst_edges.append((u, v, weight))

            if len(mst_edges) == n - 1:
                break

    if len(mst_edges) != n - 1:
        return -1

    return mst_cost, mst_edges
```

## Complexity

Time Complexity: `O(E log E)`

Sorting edges takes `O(E log E)`.
DSU operations are almost constant time, `O(alpha(V))`, so sorting dominates.

Space Complexity: `O(V)`

DSU stores parent and rank arrays.

## When To Use

Use Kruskal when:

- Edges are already given as a list.
- The graph is sparse.
- DSU fits the problem naturally.

## Common Mistakes

- Forgetting to sort edges by weight.
- Adding an edge even when both nodes already belong to the same component.
- Returning an MST when fewer than `n - 1` edges were added.
- Using Kruskal on a directed graph. MST is for undirected graphs.
