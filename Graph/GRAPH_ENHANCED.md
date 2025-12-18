# Graph & Tree Algorithms - ENHANCED GUIDE

## Advanced Graph Topics

### 1. 2-SAT Solver (Boolean Satisfiability)

```python
def solve_2sat(n, clauses):
    """
    2-SAT: determine if formula (a ∨ b) ∧ (¬c ∨ d) ∧ ... is satisfiable.
    
    Variables: 0, 1, ..., n-1 (positive = true, negative = false)
    Returns: assignment or None if unsatisfiable
    """
    # Build implication graph
    g = [[] for _ in range(2*n)]
    g_rev = [[] for _ in range(2*n)]
    
    def add_clause(a, b):
        """Clause: a ∨ b  ≡  ¬a → b, ¬b → a"""
        g[a^1].append(b)
        g[b^1].append(a)
        g_rev[b].append(a^1)
        g_rev[a].append(b^1)
    
    for a, b in clauses:
        add_clause(a, b)
    
    # Find SCCs using Kosaraju
    order = []
    visited = [False] * (2*n)
    
    def dfs1(u):
        visited[u] = True
        for v in g[u]:
            if not visited[v]:
                dfs1(v)
        order.append(u)
    
    for i in range(2*n):
        if not visited[i]:
            dfs1(i)
    
    # Assign SCC ids in reverse topological order
    scc_id = [-1] * (2*n)
    scc_count = 0
    
    def dfs2(u, scc):
        scc_id[u] = scc
        for v in g_rev[u]:
            if scc_id[v] == -1:
                dfs2(v, scc)
    
    for u in reversed(order):
        if scc_id[u] == -1:
            dfs2(u, scc_count)
            scc_count += 1
    
    # Check satisfiability: for each variable, it and its negation
    # must not be in same SCC
    for i in range(n):
        if scc_id[2*i] == scc_id[2*i + 1]:
            return None
    
    # Extract solution: if x has lower SCC id than ¬x, set x = true
    assignment = [scc_id[2*i] > scc_id[2*i + 1] for i in range(n)]
    return assignment

# Example usage:
# Variables: 0 (x), 1 (y), 2 (z)
# Problem: (x ∨ y) ∧ (¬x ∨ z) ∧ (¬y ∨ ¬z)
# Clauses: [(0,1), (1,2), (3,4)] where 0=x, 1=¬x, 2=y, 3=¬y, 4=z, 5=¬z
```

### 2. Bridges and Articulation Points (Tarjan)

```python
def find_bridges(n, edges):
    """Find all bridges (edges whose removal disconnects graph)"""
    g = [[] for _ in range(n)]
    edge_id = 0
    edge_map = {}
    
    for u, v in edges:
        if u > v:
            u, v = v, u
        edge_map[(u, v)] = edge_id
        g[u].append((v, edge_id))
        g[v].append((u, edge_id))
        edge_id += 1
    
    visited = [False] * n
    disc = [0] * n
    low = [0] * n
    bridges = []
    timer = 0
    
    def dfs(u, parent_edge):
        nonlocal timer
        visited[u] = True
        disc[u] = low[u] = timer
        timer += 1
        
        for v, eid in g[u]:
            if eid == parent_edge:
                continue
            
            if visited[v]:
                low[u] = min(low[u], disc[v])
            else:
                dfs(v, eid)
                low[u] = min(low[u], low[v])
                
                # Bridge found if low[v] > disc[u]
                if low[v] > disc[u]:
                    bridges.append((u, v) if u < v else (v, u))
    
    for i in range(n):
        if not visited[i]:
            dfs(i, -1)
    
    return bridges

def find_articulation_points(n, edges):
    """Find articulation points (cut vertices)"""
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    visited = [False] * n
    disc = [0] * n
    low = [0] * n
    parent = [-1] * n
    ap = set()
    timer = 0
    
    def dfs(u):
        nonlocal timer
        visited[u] = True
        disc[u] = low[u] = timer
        timer += 1
        children = 0
        
        for v in g[u]:
            if not visited[v]:
                children += 1
                parent[v] = u
                dfs(v)
                low[u] = min(low[u], low[v])
                
                # If u is root and has >= 2 children, u is AP
                if parent[u] == -1 and children > 1:
                    ap.add(u)
                
                # If u is not root and low[v] >= disc[u], u is AP
                if parent[u] != -1 and low[v] >= disc[u]:
                    ap.add(u)
            
            elif v != parent[u]:
                low[u] = min(low[u], disc[v])
    
    for i in range(n):
        if not visited[i]:
            dfs(i)
    
    return ap
```

### 3. Eulerian Path/Cycle

```python
def find_eulerian_path(n, edges):
    """Find Eulerian path (visits every edge exactly once)"""
    from collections import defaultdict, deque
    
    g = defaultdict(list)
    degree = defaultdict(int)
    
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
        degree[u] += 1
        degree[v] += 1
    
    # Check Eulerian conditions
    odd_nodes = sum(1 for d in degree.values() if d % 2 == 1)
    
    if odd_nodes not in (0, 2):
        return None  # No Eulerian path
    
    # Start from odd degree node if exists, else any node
    start = next((u for u in degree if degree[u] % 2 == 1), 0)
    
    # Hierholzer's algorithm
    stack = [start]
    path = []
    current_g = defaultdict(list)
    for u in g:
        current_g[u] = g[u][:]
    
    while stack:
        u = stack[-1]
        if current_g[u]:
            v = current_g[u].pop()
            # Remove reverse edge
            current_g[v].remove(u)
            stack.append(v)
        else:
            path.append(stack.pop())
    
    path.reverse()
    
    # Verify path uses all edges
    if len(path) == len(edges) + 1:
        return path
    return None
```

### 4. Network Flow: Push-Relabel Algorithm (Alternative to Dinic)

```python
class PushRelabel:
    """Push-relabel algorithm for maximum flow"""
    
    def __init__(self, n):
        self.n = n
        self.g = [[0] * n for _ in range(n)]
    
    def add_edge(self, u, v, cap):
        self.g[u][v] += cap
    
    def max_flow(self, s, t):
        n = self.n
        h = [0] * n
        e = [0] * n  # excess flow
        h[s] = n
        
        # Initialize: push all flow from s
        for v in range(n):
            if v != s:
                e[v] = self.g[s][v]
                self.g[s][v] = 0
                self.g[v][s] = self.g[v][s] + self.g[s][v]
        
        def push(u, v):
            delta = min(e[u], self.g[u][v])
            self.g[u][v] -= delta
            self.g[v][u] += delta
            e[u] -= delta
            e[v] += delta
        
        def relabel(u):
            min_h = float('inf')
            for v in range(n):
                if self.g[u][v] > 0:
                    min_h = min(min_h, h[v])
            h[u] = min_h + 1
        
        active = set(v for v in range(n) if v != s and v != t and e[v] > 0)
        
        while active:
            u = active.pop()
            
            while e[u] > 0:
                # Try to push to neighbor with smaller height
                found = False
                for v in range(n):
                    if self.g[u][v] > 0 and h[u] == h[v] + 1:
                        push(u, v)
                        if v != s and v != t and e[v] > 0:
                            active.add(v)
                        found = True
                        break
                
                if not found:
                    relabel(u)
        
        return e[t]
```

### 5. Minimum Cost Maximum Flow

```python
def min_cost_max_flow(n, edges, source, sink):
    """
    edges: (u, v, capacity, cost)
    Find max flow from source to sink with minimum total cost.
    Uses Bellman-Ford for negative costs.
    """
    INF = float('inf')
    
    # Build graph
    from collections import defaultdict
    g = defaultdict(lambda: defaultdict(lambda: [0, 0]))
    
    for u, v, cap, cost in edges:
        g[u][v][0] += cap
        g[u][v][1] = cost
        g[v][u][1] = -cost
    
    total_cost = 0
    total_flow = 0
    
    while True:
        # Find augmenting path using Bellman-Ford
        dist = defaultdict(lambda: INF)
        dist[source] = 0
        parent = {}
        
        for _ in range(n):
            for u in g:
                if dist[u] == INF:
                    continue
                for v in g[u]:
                    cap, cost = g[u][v]
                    if cap > 0 and dist[u] + cost < dist[v]:
                        dist[v] = dist[u] + cost
                        parent[v] = u
        
        if sink not in parent:
            break  # No more augmenting paths
        
        # Find bottleneck capacity
        flow = INF
        v = sink
        while v != source:
            u = parent[v]
            flow = min(flow, g[u][v][0])
            v = u
        
        # Augment flow
        v = sink
        while v != source:
            u = parent[v]
            g[u][v][0] -= flow
            g[v][u][0] += flow
            cost = g[u][v][1]
            total_cost += flow * cost
            v = u
        
        total_flow += flow
    
    return total_flow, total_cost
```

### 6. Vertex Connectivity & Edge Connectivity

```python
def vertex_connectivity(n, edges):
    """Minimum number of vertices to remove to disconnect graph"""
    from collections import deque
    
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    def can_reach(blocked_set):
        """BFS avoiding blocked vertices"""
        visited = [False] * n
        for v in blocked_set:
            visited[v] = True
        
        q = deque([0])
        visited[0] = False  # Start always allowed
        count = 1
        
        while q:
            u = q.popleft()
            for v in g[u]:
                if not visited[v]:
                    visited[v] = True
                    count += 1
                    q.append(v)
        
        return count == n
    
    # Binary search on connectivity
    for k in range(1, n):
        found = False
        for mask in range(1 << n):
            if bin(mask).count('1') == k:
                blocked = [i for i in range(n) if (mask >> i) & 1]
                if not can_reach(blocked):
                    return k
        if found:
            break
    
    return n - 1
```

---

## Advanced Tree Techniques

### 7. Virtual Tree Construction

```python
def build_virtual_tree(important_nodes, lca_func, depth_func):
    """
    Build a smaller tree containing only important nodes and LCAs.
    Reduces problem space significantly.
    """
    important_nodes = sorted(important_nodes, key=depth_func)
    vt = []
    
    for node in important_nodes:
        if not vt:
            vt.append(node)
        else:
            # Find LCA with last node in virtual tree
            last = vt[-1]
            l = lca_func(node, last)
            
            if l != last:
                # Pop nodes until we find parent of l
                while vt and depth_func(vt[-1]) > depth_func(l):
                    vt.pop()
                
                if vt and vt[-1] != l:
                    vt.append(l)
            
            vt.append(node)
    
    return vt
```

### 8. XOR Basis on Tree Paths

```python
def xor_basis_tree(n, edges, values):
    """
    For tree paths, maintain XOR basis to answer:
    - Maximum XOR on path u to v
    - Count of different maximum XORs
    """
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    class XORBasis:
        def __init__(self):
            self.basis = [0] * 60
        
        def add(self, x):
            for i in range(59, -1, -1):
                if not (x & (1 << i)):
                    continue
                
                if not self.basis[i]:
                    self.basis[i] = x
                    return
                
                x ^= self.basis[i]
        
        def query_max(self, x):
            for i in range(59, -1, -1):
                if self.basis[i]:
                    x = max(x, x ^ self.basis[i])
            return x
    
    # Find all XOR values on path from node to root
    parent = [-1] * n
    path_xor = [0] * n
    visited = [False] * n
    
    def dfs(u, p, xor_val):
        visited[u] = True
        parent[u] = p
        path_xor[u] = xor_val ^ values[u]
        
        for v in g[u]:
            if not visited[v]:
                dfs(v, u, path_xor[u])
    
    dfs(0, -1, 0)
    
    # For path queries: u to v passes through LCA(u,v)
    # XOR(u to v) = XOR(u to root) ^ XOR(v to root)
    return path_xor, parent
```

### 9. Centroid Decomposition (Detailed)

```python
def centroid_decomposition(n, edges):
    """
    Decompose tree into centroids for O(n log n) distance queries.
    Each node is in O(log n) centroid levels.
    """
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    removed = [False] * n
    sz = [0] * n
    parent_centroid = [-1] * n
    depth_in_decomp = [0] * n
    
    def calc_size(u, p):
        sz[u] = 1
        for v in g[u]:
            if v != p and not removed[v]:
                sz[u] += calc_size(v, u)
        return sz[u]
    
    def find_centroid(u, p, tree_size):
        for v in g[u]:
            if v != p and not removed[v] and sz[v] * 2 > tree_size:
                return find_centroid(v, u, tree_size)
        return u
    
    def decompose(u, depth):
        tree_size = calc_size(u, -1)
        centroid = find_centroid(u, -1, tree_size)
        removed[centroid] = True
        depth_in_decomp[centroid] = depth
        
        for v in g[centroid]:
            if not removed[v]:
                parent_centroid[v] = centroid
                decompose(v, depth + 1)
    
    decompose(0, 0)
    
    return parent_centroid, depth_in_decomp
```

### 10. Link-Cut Trees (Brief Overview)

```
Provides O(log n) operations for:
- Link/cut tree edges dynamically
- Query maximum edge weight on path
- Query path properties

Too complex for most CF problems, but useful for:
- Dynamic tree diameter
- Dynamic connectivity with queries
- Online tree problems

Recommend using Centroid Decomposition instead for most cases.
```

---

## Summary: When to Use Each Technique

| Problem | Technique | Complexity |
|---------|-----------|-----------|
| Bridges/APs | Tarjan DFS | O(V + E) |
| 2-SAT | SCC + Implication | O(V + E) |
| Eulerian path | Hierholzer | O(V + E) |
| Max flow | Dinic | O(V² × E) |
| Min cost flow | Successive shortest paths | O(V² × E × log V) |
| Vertex connectivity | Binary search + BFS | O(n² × V + E) |
| Tree queries with LCA | HLD + Segment Tree | O(log² n) per query |
| Virtual trees | LCA + Sorting | O(k log k) to build |
| Centroid queries | Centroid Decomp | O(n log n) build, O(log n) query |
| XOR queries on paths | XOR basis | O(60) per query |
