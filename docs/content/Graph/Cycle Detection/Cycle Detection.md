# Cycle Detection Notes

Cycle detection questions usually ask one of these:

- Detect whether a cycle exists.
- Print any cycle path.
- Check if an undirected graph is bipartite.
- Detect a directed cycle using DFS states.
- Detect a cycle in a dependency graph / course schedule / topological ordering problem.

Use adjacency list for competitive programming.

```text
Time to build graph: O(N + M)
Space for graph: O(N + M)
```

Where:

- `N` = number of nodes / vertices
- `M` = number of edges

---

## 1. Undirected Graph Cycle Detection

### Technique

Use DFS/BFS with a `visited` array and track the parent node.

In an undirected graph, every edge appears in both directions:

```text
u -> v
v -> u
```

So while exploring from `u` to `v`, seeing the parent again is normal. A cycle exists only when we visit an already visited node that is not the parent.

### DFS Logic

```python
def dfs(node, parent):
    visited[node] = True

    for nei in adj[node]:
        if not visited[nei]:
            if dfs(nei, node):
                return True
        elif nei != parent:
            return True

    return False
```

### Important

Run DFS from every unvisited node because the graph may be disconnected.

```python
for node in range(1, n + 1):
    if not visited[node]:
        if dfs(node, -1):
            print("Cycle exists")
```

### Complexity

```text
Time Complexity: O(N + M)
Space Complexity: O(N + M)
```

Space breakdown:

- adjacency list: `O(N + M)`
- visited array: `O(N)`
- recursion stack / BFS queue: `O(N)`

### Common Questions

- Round Trip I
- Detect cycle in undirected graph
- Find redundant connection
- Check if a graph is a tree

### Tree Check Note

An undirected graph is a tree if:

```text
M == N - 1
and
graph is connected
```

If connected graph has `N - 1` edges, it has no cycle.

---

## 2. Directed Graph Cycle Detection

### Technique

Use DFS coloring / states.

```text
0 = unvisited
1 = currently in recursion stack / visiting
2 = fully processed / done
```

A directed cycle exists when DFS reaches a node with state `1`.

### DFS Logic

```python
def dfs(node):
    color[node] = 1

    for nei in adj[node]:
        if color[nei] == 0:
            if dfs(nei):
                return True
        elif color[nei] == 1:
            return True

    color[node] = 2
    return False
```

### Why Parent Does Not Work Here

Parent tracking is for undirected graphs. In directed graphs, a node can be reached again through a directed back edge even if it is not related to the immediate parent.

Example:

```text
1 -> 2 -> 3
     ^    |
     |____|
```

When DFS from `2` reaches `3`, and `3` reaches `2`, node `2` is still in the recursion stack, so there is a cycle.

### Complexity

```text
Time Complexity: O(N + M)
Space Complexity: O(N + M)
```

Space breakdown:

- adjacency list: `O(N + M)`
- color/state array: `O(N)`
- recursion stack: `O(N)`

### Common Questions

- Round Trip II
- Course Schedule
- Detect cycle in directed graph
- Check if topological sort is possible
- Dependency resolution problems

### Topological Sort Note

A directed graph has a valid topological ordering only if it is a DAG.

```text
DAG = Directed Acyclic Graph
```

If a directed cycle exists, topological sort is impossible.

---

## 3. Printing A Cycle Path

For path reconstruction, keep a `parent` array.

### Undirected Graph

When you find an already visited neighbor that is not the parent:

```text
node -> nei
```

The cycle is found. Walk backwards using `parent` from `node` until you reach `nei`.

Basic idea:

```python
cycle = [nei]
cur = node
while cur != nei:
    cycle.append(cur)
    cur = parent[cur]
cycle.append(nei)
cycle.reverse()
```

### Directed Graph

When DFS sees `color[nei] == 1`, `nei` is already in the current recursion stack.

Walk backwards from `node` to `nei` using parent.

```python
cycle = [nei]
cur = node
while cur != nei:
    cycle.append(cur)
    cur = parent[cur]
cycle.append(nei)
cycle.reverse()
```

---

## 4. Bipartite Graph

### Meaning

A graph is bipartite if nodes can be divided into two groups such that no edge connects nodes inside the same group.

This is the same as 2-coloring the graph.

```text
color[node] = 0 or 1
```

For every edge `u - v`:

```text
color[u] != color[v]
```

### DFS Technique

```python
def dfs(node, c):
    color[node] = c

    for nei in adj[node]:
        if color[nei] == -1:
            if not dfs(nei, 1 - c):
                return False
        elif color[nei] == color[node]:
            return False

    return True
```

Run from every uncolored node:

```python
color = [-1] * (n + 1)

for node in range(1, n + 1):
    if color[node] == -1:
        if not dfs(node, 0):
            print("NO")
```

### BFS Technique

```python
from collections import deque

def bfs(start):
    q = deque([start])
    color[start] = 0

    while q:
        node = q.popleft()

        for nei in adj[node]:
            if color[nei] == -1:
                color[nei] = 1 - color[node]
                q.append(nei)
            elif color[nei] == color[node]:
                return False

    return True
```

### Complexity

```text
Time Complexity: O(N + M)
Space Complexity: O(N + M)
```

Space breakdown:

- adjacency list: `O(N + M)`
- color array: `O(N)`
- recursion stack / queue: `O(N)`

### Important Bipartite Facts

- Every tree is bipartite.
- A graph is bipartite if and only if it has no odd length cycle.
- Even length cycles are bipartite.
- Odd length cycles are not bipartite.
- Disconnected graphs must be checked component by component.

### Common Questions

- Creating Teams
- Is Graph Bipartite?
- Possible Bipartition
- Split people into two groups
- Check whether graph has an odd cycle

---

## 5. Union Find For Undirected Cycle Detection

For undirected graphs, DSU / Union Find can detect cycles while adding edges.

### Technique

For every edge `u - v`:

- if `find(u) == find(v)`, then adding this edge creates a cycle
- otherwise union them

```python
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    ra = find(a)
    rb = find(b)

    if ra == rb:
        return False

    parent[rb] = ra
    return True
```

### Complexity

```text
Time Complexity: O((N + M) * alpha(N))
Space Complexity: O(N)
```

`alpha(N)` is inverse Ackermann, almost constant.

### When To Use

Use DSU when:

- edges are being added one by one
- the graph is undirected
- you only need to know if a cycle appears

Do not use basic DSU for directed cycle detection.

---

## 6. Quick Pattern Table

| Problem Type | Graph Type | Best Technique | Key Idea | TC | SC |
|---|---|---|---|---|---|
| Detect cycle | Undirected | DFS/BFS + parent | visited neighbor not parent | `O(N + M)` | `O(N + M)` |
| Detect cycle | Directed | DFS color states | edge to state `1` node | `O(N + M)` | `O(N + M)` |
| Print cycle | Undirected/Directed | DFS + parent | reconstruct path after back edge | `O(N + M)` | `O(N + M)` |
| Check bipartite | Undirected | DFS/BFS coloring | adjacent nodes need opposite colors | `O(N + M)` | `O(N + M)` |
| Detect cycle while adding edges | Undirected | DSU | same component means cycle | `O((N + M) * alpha(N))` | `O(N)` |
| Topological sort possible | Directed | DFS/Kahn | possible only if no cycle | `O(N + M)` | `O(N + M)` |

---

## 7. Common Mistakes

- Forgetting to run DFS/BFS for every component.
- Using parent logic for directed graphs.
- Marking a directed DFS node as done too early.
- Not increasing recursion limit in Python for large graphs.
- Confusing bipartite checking with cycle detection.
- Thinking every cycle breaks bipartite property. Only odd cycles break it.
- Forgetting that undirected edges are added both ways.
- Forgetting that directed edges are added only one way.

Python recursion setup:

```python
import sys
sys.setrecursionlimit(10**7)
```

For very deep graphs, iterative DFS or BFS is safer than recursive DFS.

---

## 8. Template Choices

Use this decision flow:

```text
Undirected cycle?
    DFS/BFS + parent

Directed cycle?
    DFS color states

Need bipartite?
    DFS/BFS 2-coloring

Need topological order?
    Kahn BFS or DFS topo
    if cycle exists -> impossible

Edges added dynamically in undirected graph?
    DSU
```
