# 🔗 Graph Algorithms Fundamentals

## 🏗️ Quick Setup

```python
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)
input = sys.stdin.readline

# Adjacency list
g = [[] for _ in range(n)]
for u, v in edges:
    g[u].append(v)
    g[v].append(u)  # remove if directed
```

---

## 1️⃣ DFS & BFS Basics

### 1.1 DFS (Recursion)

```python
def dfs(u, g, vis):
    vis[u] = True
    for v in g[u]:
        if not vis[v]:
            dfs(v, g, vis)

# usage
n = len(g)
vis = [False] * n
dfs(0, g, vis)
```

### 1.2 BFS

```python
def bfs(start, g):
    n = len(g)
    dist = [-1] * n
    dist[start] = 0
    q = deque([start])
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist
```

---

## 2️⃣ Classic Problems

### 2.1 Connected Components

```python
def count_components(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    vis = [False] * n
    comp = 0
    def dfs(u):
        vis[u] = True
        for v in g[u]:
            if not vis[v]:
                dfs(v)
    
    for i in range(n):
        if not vis[i]:
            comp += 1
            dfs(i)
    return comp
```

### 2.2 Bipartite Check (Graph Coloring)

```python
def is_bipartite(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    color = [-1] * n
    for s in range(n):
        if color[s] != -1:
            continue
        q = deque([s])
        color[s] = 0
        while q:
            u = q.popleft()
            for v in g[u]:
                if color[v] == -1:
                    color[v] = 1 - color[u]
                    q.append(v)
                elif color[v] == color[u]:
                    return False
    return True
```

### 2.3 Cycle Detection (Directed)

```python
def has_cycle_directed(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
    
    state = [0] * n  # 0=unvisited, 1=visiting, 2=done
    def dfs(u):
        state[u] = 1
        for v in g[u]:
            if state[v] == 0:
                if dfs(v):
                    return True
            elif state[v] == 1:
                return True
        state[u] = 2
        return False
    
    for i in range(n):
        if state[i] == 0 and dfs(i):
            return True
    return False
```

---

## 3️⃣ Trees

### 3.1 Tree DFS (Parent, Depth, Subtree Size)

```python
def tree_dfs(root, g):
    n = len(g)
    parent = [-1] * n
    depth = [0] * n
    sz = [0] * n
    
    def dfs(u, p):
        parent[u] = p
        sz[u] = 1
        for v in g[u]:
            if v == p:
                continue
            depth[v] = depth[u] + 1
            dfs(v, u)
            sz[u] += sz[v]
    
    dfs(root, -1)
    return parent, depth, sz
```

### 3.2 Tree Diameter

```python
def tree_diameter(g):
    def bfs_far(start):
        n = len(g)
        dist = [-1] * n
        dist[start] = 0
        q = deque([start])
        far = start
        while q:
            u = q.popleft()
            for v in g[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    q.append(v)
                    if dist[v] > dist[far]:
                        far = v
        return far, dist
    
    a, _ = bfs_far(0)
    b, dist = bfs_far(a)
    return dist[b]
```

### 3.3 LCA (Binary Lifting)

```python
def build_lca(g, root=0):
    n = len(g)
    LOG = 20
    up = [[-1] * n for _ in range(LOG)]
    depth = [0] * n
    
    def dfs(u, p):
        up[0][u] = p
        for v in g[u]:
            if v == p:
                continue
            depth[v] = depth[u] + 1
            dfs(v, u)
    
    dfs(root, -1)
    for k in range(1, LOG):
        for v in range(n):
            if up[k-1][v] != -1:
                up[k][v] = up[k-1][up[k-1][v]]
    
    def lca(a, b):
        if depth[a] < depth[b]:
            a, b = b, a
        diff = depth[a] - depth[b]
        for i in range(LOG):
            if (diff >> i) & 1:
                a = up[i][a]
        if a == b:
            return a
        for i in range(LOG-1, -1, -1):
            if up[i][a] != up[i][b]:
                a = up[i][a]
                b = up[i][b]
        return up[0][a]
    
    return lca, depth
```

---

## 4️⃣ Shortest Paths

### 4.1 Dijkstra (Non-negative Weights)

```python
import heapq

def dijkstra(n, adj, src):
    dist = [10**18] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in adj[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist
```

### 4.2 0-1 BFS (Weights 0/1 only)

```python
def zero_one_bfs(n, edges, src):
    g = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u].append((v, w))
    
    dist = [10**18] * n
    dist[src] = 0
    dq = deque([src])
    while dq:
        u = dq.popleft()
        for v, w in g[u]:
            nd = dist[u] + w
            if nd < dist[v]:
                dist[v] = nd
                if w == 0:
                    dq.appendleft(v)
                else:
                    dq.append(v)
    return dist
```

### 4.3 Multi-Source BFS

```python
def multi_source_bfs(sources, g):
    n = len(g)
    dist = [-1] * n
    q = deque()
    for s in sources:
        dist[s] = 0
        q.append(s)
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist
```

---

## 5️⃣ MST & DSU

### 5.1 DSU (Disjoint Set Union)

```python
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n
    
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True
```

### 5.2 Kruskal MST

```python
def kruskal(n, edges):
    edges.sort(key=lambda e: e[2])
    dsu = DSU(n)
    total = 0
    cnt = 0
    for u, v, w in edges:
        if dsu.union(u, v):
            total += w
            cnt += 1
            if cnt == n - 1:
                break
    return total if cnt == n - 1 else -1
```

---

## 6️⃣ SCC & Topological Sort

### 6.1 Tarjan SCC

```python
def tarjan_scc(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
    
    idx, low, on_st = [-1]*n, [0]*n, [False]*n
    cnt, stk, timer = 0, [], 0
    comp = [-1] * n
    
    def dfs(u):
        nonlocal timer, cnt
        idx[u] = low[u] = timer
        timer += 1
        stk.append(u)
        on_st[u] = True
        for v in g[u]:
            if idx[v] == -1:
                dfs(v)
                low[u] = min(low[u], low[v])
            elif on_st[v]:
                low[u] = min(low[u], idx[v])
        if low[u] == idx[u]:
            while True:
                v = stk.pop()
                on_st[v] = False
                comp[v] = cnt
                if v == u:
                    break
            cnt += 1
    
    for i in range(n):
        if idx[i] == -1:
            dfs(i)
    return comp, cnt
```

### 6.2 Topological Sort (Kahn)

```python
def topo_sort(n, edges):
    g = [[] for _ in range(n)]
    indeg = [0] * n
    for u, v in edges:
        g[u].append(v)
        indeg[v] += 1
    
    q = deque(i for i in range(n) if indeg[i] == 0)
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in g[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    
    return order if len(order) == n else None
```

---

## 📊 Quick Reference

| Problem | Algorithm | Complexity |
|---------|-----------|-----------|
| Reachability | DFS/BFS | O(V+E) |
| Shortest path (unweighted) | BFS | O(V+E) |
| Shortest path (non-neg) | Dijkstra | O((V+E)logV) |
| MST | Kruskal/Prim | O(E log E) / O(E log V) |
| Connectivity | DSU | O(α(n)) amortized |
| SCCs | Tarjan/Kosaraju | O(V+E) |
| Bipartite | BFS coloring | O(V+E) |

