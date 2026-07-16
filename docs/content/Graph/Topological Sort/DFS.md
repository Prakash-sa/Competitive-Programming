# Topological Sort using DFS

## Definition

Topological sorting gives a valid ordering of nodes in a directed graph such that for every edge `u -> v`, node `u` appears before node `v`.

Topological sort only works for a Directed Acyclic Graph (DAG).

DFS topological sort is based on finish time.

## Main Idea

In DFS, a node is added to the answer after all nodes reachable from it are processed.

That means dependencies deeper in the graph finish first.

After DFS finishes, reverse the answer to get the topological order.

To detect cycles, use three states:

- `0`: unvisited
- `1`: currently visiting
- `2`: fully processed

If DFS reaches a node with state `1`, there is a cycle, so topological sort is impossible.

## Algorithm Steps

1. Build the adjacency list.
2. Keep a `state` array for cycle detection.
3. Run DFS from every unvisited node.
4. During DFS:
   - Mark the node as visiting.
   - Visit all neighbors.
   - If a visiting neighbor is found, report a cycle.
   - Mark the node as processed.
   - Add the node to the order.
5. Reverse the order.
6. If a cycle was found, return no valid order.

## Python Template

```python
def topo_sort_dfs(n, edges):
    graph = [[] for _ in range(n)]

    for u, v in edges:
        graph[u].append(v)

    state = [0] * n
    order = []

    def dfs(u):
        state[u] = 1

        for v in graph[u]:
            if state[v] == 0:
                if not dfs(v):
                    return False
            elif state[v] == 1:
                return False

        state[u] = 2
        order.append(u)
        return True

    for node in range(n):
        if state[node] == 0:
            if not dfs(node):
                return []

    order.reverse()
    return order
```

## Python Template Without Cycle Detection

Use this only when the problem guarantees the graph is a DAG.

```python
def topo_sort_dfs_dag(n, edges):
    graph = [[] for _ in range(n)]

    for u, v in edges:
        graph[u].append(v)

    visited = [False] * n
    order = []

    def dfs(u):
        visited[u] = True

        for v in graph[u]:
            if not visited[v]:
                dfs(v)

        order.append(u)

    for node in range(n):
        if not visited[node]:
            dfs(node)

    order.reverse()
    return order
```

## Complexity

Time Complexity: `O(V + E)`

Each node is visited once, and each directed edge is checked once.

Space Complexity: `O(V + E)`

The adjacency list stores edges. The `state`, `order`, and recursion stack use `O(V)` space.

## When To Use

Use DFS topological sort when:

- The problem naturally fits recursion.
- You need to detect a cycle while doing DFS.
- You need finish-time ordering.
- You are solving dependency, course schedule, build order, or graph ordering problems.

## Common Mistakes

- Forgetting to reverse the DFS finish order.
- Adding a node to the answer before processing its neighbors.
- Not using three states when cycle detection is required.
- Treating a directed graph like an undirected graph.
- Building the edge direction backward in prerequisite problems.
