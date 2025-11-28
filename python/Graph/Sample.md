🟥 LEVEL 0 — Graph Building Templates (CF Style)
Adjacency list (unweighted)
vector<vector<int>> g(n);
for (auto &e : edges) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);   // remove if directed
}

Weighted graph
vector<vector<pair<int,int>>> g(n);
int u, v, w;
g[u].push_back({v, w});
g[v].push_back({u, w});

Edge list
struct Edge { int u, v, w; };
vector<Edge> edges;

🟩 LEVEL 1 — DFS/BFS Foundations (Core Patterns)
1️⃣ DFS (Recursion + Stack) — Backbones of CF Graph Problems
Use when:

Connected components

Checking paths

Bridges / articulation points

Tree problems

Ordering / structure extraction

Boilerplate DFS:
vector<int> vis;
void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) 
        if (!vis[v]) dfs(v);
}

2️⃣ BFS — Layer-by-Layer Expansion
Use when:

Shortest path in unweighted graph

Multi-source spread

Distance layering & bipartite check

Boilerplate BFS:
queue<int> q;
vector<int> dist(n, -1);
dist[s] = 0; q.push(s);

while(!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u])
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
}

🟦 LEVEL 2 — Classic CP Graph Patterns
3️⃣ Connected Components (DFS/BFS)

CF tags: graphs, dfs and similar

Applications:

Count components

Flood-fill

Checking connectivity constraints

4️⃣ Bipartite Check (Graph Coloring)
vector<int> color(n, -1);
bool bfs_bip(int s) {
    queue<int> q; q.push(s);
    color[s] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u])
                return false;
        }
    }
    return true;
}

5️⃣ Cycle Detection
Undirected
bool dfs(int u, int p) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        if (vis[v]) return true;
        if (dfs(v, u)) return true;
    }
    return false;
}

Directed (3-color)
vector<int> col(n,0); // 0 unvisited, 1 inStack, 2 done
bool dfs(int u) {
    col[u]=1;
    for(int v:g[u]) {
        if(col[v]==1) return true;
        if(col[v]==0 && dfs(v)) return true;
    }
    col[u]=2;
    return false;
}

🟧 LEVEL 3 — Trees (Extremely Important for Codeforces)

Tree questions are 20–30% of CF rounds.

6️⃣ Tree DFS — Depth, Parent, Subtree Size
vector<int> depth(n), parent(n), sub(n);
void dfs(int u, int p) {
    parent[u] = p;
    sub[u] = 1;
    for(int v:g[u]) if(v!=p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

7️⃣ LCA (Binary Lifting)

Used in:

distance queries

tree path queries

k-th ancestor

const int LOG = 20;
vector<vector<int>> up(n, vector<int>(LOG));
vector<int> depth;

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int k = depth[a] - depth[b];
    for(int i=0;i<LOG;i++) if(k&(1<<i)) a = up[a][i];
    if(a==b) return a;
    for(int i=LOG-1;i>=0;i--)
        if(up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    return up[a][0];
}

8️⃣ Tree Diameter (Longest Path)
pair<int,int> bfs(int s) { ... }
int diameter() {
    auto [a,_] = bfs(0);
    auto [b,dist] = bfs(a);
    return dist;
}

9️⃣ Heavy-Light Decomposition (HLD)

Used for:

Path queries (sum/min/max)

Update/query on tree paths

(Boilerplate is long but essential for 2000–2300 rated problems.)

🟫 LEVEL 4 — Graph DP
🔟 DP on Trees (Tree DP)

Patterns:

DP downwards (subtree)

DP upwards (rerooting / dp on tree)

Rerooting DP (dp[u] based on parent/children)
Used in:

“sum of distances to all nodes”

“best root”

“tree beauty”

Template:

void dfs1(int u, int p) { /* compute dp_down */ }
void dfs2(int u, int p) { /* compute dp_up */ }

🟪 LEVEL 5 — Shortest Path Algorithms (Codeforces-critical)
1️⃣1️⃣ Dijkstra (non-negative weights)
vector<long long> dist(n, 1e18);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

dist[s] = 0; pq.push({0, s});
while(!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if(d != dist[u]) continue;
    for(auto [v, w] : g[u])
        if(dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
}

12️⃣ 0-1 BFS (weights = 0/1 only)
deque<int> dq;
vector<int> dist(n, 1e9);
dist[s] = 0; dq.push_front(s);

while(!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    for(auto [v,w] : g[u]) {
        int nd = dist[u] + w;
        if(nd < dist[v]) {
            dist[v] = nd;
            if(w == 0) dq.push_front(v);
            else dq.push_back(v);
        }
    }
}

13️⃣ Multi-source BFS
queue<int> q;
for (int s : sources) { dist[s]=0; q.push(s); }

14️⃣ Floyd–Warshall (Small n <= 500)

All-pairs shortest path

Detect negative cycles

15️⃣ Bellman-Ford (Detect negative cycle)

Used in CF for:

Currency arbitrage

Graph with negative edges

🟫 LEVEL 6 — Disjoint Set Union (DSU)
16️⃣ DSU / Union-Find

Used for:

Kruskal MST

Offline queries

Dynamic connectivity

DSU rollback (for queries on offline graph modifications)

struct DSU {
    vector<int> p, sz;
    DSU(int n):p(n),sz(n,1){ iota(p.begin(),p.end(),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; return true;
    }
};

🟦 LEVEL 7 — Minimum Spanning Tree (MST)
17️⃣ Kruskal (DSU)
sort(edges.begin(),edges.end(),[](auto&a,auto&b){return a.w<b.w;});
DSU dsu(n);
long long cost=0;

for (auto &e: edges)
    if (dsu.unite(e.u, e.v))
        cost += e.w;

18️⃣ Prim (Heap)

For dense graphs.

🟩 LEVEL 8 — Strong Components & DAG Tricks
19️⃣ Kosaraju / Tarjan SCC

Used for:

Condensing graph into DAG

2-SAT

Component-level DP

Tarjan boilerplate:
vector<int> low, tin, onstack;
stack<int> st;
int timer=0, comp=0;

void dfs(int u) {
    tin[u] = low[u] = timer++;
    st.push(u); onstack[u] = 1;

    for(int v: g[u]) {
        if(tin[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(onstack[v])
            low[u] = min(low[u], tin[v]);
    }

    if(low[u] == tin[u]) {
        // head of SCC
        while(true) {
            int v = st.top(); st.pop();
            onstack[v] = 0;
            if(v == u) break;
        }
        comp++;
    }
}

20️⃣ Topological Sorting (Kahn + DFS)

Used for:

Ordering tasks

DAG DP

Path counts on DAG

21️⃣ DP on DAG

e.g. Longest path in DAG.

🟧 LEVEL 9 — Advanced Graph Algorithms (2200+ Problems)

These are hard but essential for CM:

22️⃣ Lowest Common Ancestor in DAG (Hard)

Trick: Transform DAG → tree-like structure via DP.

23️⃣ Centroid Decomposition

Solve tree queries faster.

24️⃣ DSU on Tree (Small-to-Large / Sack Technique)

Used when:

You need to maintain frequency of colors/values in subtree queries.

“Count distinct values in subtrees” with fast updates.

25️⃣ Euler Tour + Segment Tree

Flatten tree to array to make subtree range operations.

🟥 LEVEL 10 — Flow & Matching (Advanced but Appears in CF)
Required for CM level:
26️⃣ Max Flow (Dinic)

Used for:

bipartite matching

min cut

network problems

scheduling

edge-disjoint paths

Dinic boilerplate is long; this is the optimized CF version.

struct Dinic {
    struct Edge { int v; long long cap; int rev; };
    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;
    Dinic(int n):n(n),g(n),level(n),ptr(n){}

    void addEdge(int u, int v, long long cap){
        g[u].push_back({v,cap,(int)g[v].size()});
        g[v].push_back({u,0,(int)g[u].size()-1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q; q.push(s); level[s] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e: g[u])
                if(level[e.v] < 0 && e.cap > 0)
                    level[e.v] = level[u] + 1, q.push(e.v);
        }
        return level[t] >= 0;
    }

    long long dfs(int u, int t, long long f) {
        if (!f) return 0;
        if (u == t) return f;
        for(int &cid = ptr[u]; cid < (int)g[u].size(); cid++){
            auto &e = g[u][cid];
            if(level[e.v] == level[u] + 1 && e.cap > 0) {
                long long pushed = dfs(e.v, t, min(f, e.cap));
                if(pushed){
                    e.cap -= pushed;
                    g[e.v][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    long long maxflow(int s, int t) {
        long long flow = 0;
        while(bfs(s,t)) {
            fill(ptr.begin(),ptr.end(),0);
            while(long long pushed = dfs(s,t,1e18))
                flow += pushed;
        }
        return flow;
    }
};

27️⃣ Minimum Cost Maximum Flow

Used in harder CF problems.

28️⃣ Maximum Bipartite Matching

(Kuhn’s algorithm)

bool try_kun(int u) {
    for(int v: g[u]) if(!used[v]) {
        used[v] = 1;
        if(match[v] == -1 || try_kun(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

🧠 LEVEL 11 — Misc Advanced Topics
29️⃣ Functional Graphs

Used when each node has exactly one outgoing edge.

30️⃣ Eulerian Path / Cycle

Directed and undirected.

31️⃣ Top-tree / Link-Cut Tree (very advanced)

Seldom required except 2400+ level.

# =========================
# GLOBAL CP PYTHON SETUP
# =========================
import sys
from collections import defaultdict, deque
from math import inf

sys.setrecursionlimit(10**7)
input = sys.stdin.readline

0. Graph Building Helpers
def build_graph_unweighted(n, edges, directed=False):
    """edges: iterable of (u, v), 0-based"""
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        if not directed:
            g[v].append(u)
    return g


def build_graph_weighted(n, edges, directed=False):
    """edges: iterable of (u, v, w)"""
    g = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u].append((v, w))
        if not directed:
            g[v].append((u, w))
    return g

1. DFS / BFS Basics
DFS (recursive)
def dfs(u, g, vis):
    vis[u] = True
    for v in g[u]:
        if not vis[v]:
            dfs(v, g, vis)

BFS
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

2. Connected Components
def count_components(n, edges):
    g = build_graph_unweighted(n, edges)
    vis = [False] * n
    comp_cnt = 0

    def dfs(u):
        vis[u] = True
        for v in g[u]:
            if not vis[v]:
                dfs(v)

    for i in range(n):
        if not vis[i]:
            comp_cnt += 1
            dfs(i)
    return comp_cnt

3. Bipartite Check (Graph Coloring)
def is_bipartite(n, edges):
    g = build_graph_unweighted(n, edges)
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
                    color[v] = color[u] ^ 1
                    q.append(v)
                elif color[v] == color[u]:
                    return False
    return True

4. Cycle Detection
Undirected
def has_cycle_undirected(n, edges):
    g = build_graph_unweighted(n, edges)
    vis = [False] * n

    def dfs(u, parent):
        vis[u] = True
        for v in g[u]:
            if v == parent:
                continue
            if vis[v]:
                return True
            if dfs(v, u):
                return True
        return False

    for i in range(n):
        if not vis[i]:
            if dfs(i, -1):
                return True
    return False

Directed (3-color)
def has_cycle_directed(n, edges):
    g = build_graph_unweighted(n, edges, directed=True)
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

5. Tree Basics: parent, depth, subtree size
def tree_dfs(root, g):
    n = len(g)
    parent = [-1] * n
    depth = [0] * n
    sub = [0] * n

    def dfs(u, p):
        parent[u] = p
        sub[u] = 1
        for v in g[u]:
            if v == p:
                continue
            depth[v] = depth[u] + 1
            dfs(v, u)
            sub[u] += sub[v]

    dfs(root, -1)
    return parent, depth, sub

6. Tree Diameter (two BFS/DFS trick)
def tree_diameter(g):
    def bfs_far(start):
        n = len(g)
        dist = [-1] * n
        dist[start] = 0
        q = deque([start])
        far = start
        while q:
            u = q.popleft()
            if dist[u] > dist[far]:
                far = u
            for v in g[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    q.append(v)
        return far, dist[far]

    a, _ = bfs_far(0)
    b, d = bfs_far(a)
    return d  # length of diameter

7. LCA (Binary Lifting)
def build_lca(g, root=0):
    n = len(g)
    LOG = (n).bit_length()
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
        k = 0
        while diff:
            if diff & 1:
                a = up[k][a]
            diff >>= 1
            k += 1
        if a == b:
            return a
        for k in range(LOG-1, -1, -1):
            if up[k][a] != up[k][b]:
                a = up[k][a]
                b = up[k][b]
        return up[0][a]

    return lca, depth, up

8. Tree DP / Rerooting Skeleton

Rerooting pattern (you plug in your own logic):

def rerooting_dp(g):
    n = len(g)
    dp_down = [0] * n   # example
    dp_all = [0] * n    # final answer per node

    def dfs1(u, p):
        # compute dp_down[u] using children
        for v in g[u]:
            if v == p:
                continue
            dfs1(v, u)
            # combine dp_down[v] into dp_down[u]
            # dp_down[u] += f(dp_down[v])
        # plus own contribution

    def dfs2(u, p):
        # dp_all[u] known; propagate to children
        # compute stuff for children using parent info
        prefix = []
        suffix = []
        # typical pattern: precompute over children, etc.
        for v in g[u]:
            if v == p:
                continue
            # compute dp_all[v] using dp_down[v] + "rest"
            dfs2(v, u)

    dfs1(0, -1)
    dfs2(0, -1)
    return dp_all


You adapt dp_down, dp_all, and combine logic for specific problems ("sum of distances", "number of good paths", etc).

9. Shortest Paths
9.1 Dijkstra (non-negative weights)
import heapq

def dijkstra(n, edges, src):
    g = build_graph_weighted(n, edges, directed=False)
    dist = [inf] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in g[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist

9.2 0-1 BFS (weights 0 or 1)
def zero_one_bfs(n, edges, src):
    """edges: list of (u, v, w) with w in {0,1}, directed or not as needed"""
    g = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u].append((v, w))
        # if undirected: g[v].append((u, w))

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

9.3 Multi-source BFS
def multi_source_bfs(starts, g):
    n = len(g)
    dist = [-1] * n
    q = deque()
    for s in starts:
        dist[s] = 0
        q.append(s)
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

9.4 Floyd–Warshall (small n, all-pairs shortest paths)
def floyd_warshall(n, edges):
    dist = [[inf] * n for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
    for u, v, w in edges:
        dist[u][v] = min(dist[u][v], w)
        dist[v][u] = min(dist[v][u], w)  # if undirected

    for k in range(n):
        dk = dist[k]
        for i in range(n):
            di = dist[i]
            via = di[k]
            if via == inf:
                continue
            for j in range(n):
                nd = via + dk[j]
                if nd < di[j]:
                    di[j] = nd
    return dist

9.5 Bellman–Ford (negative edges + cycle detection)
def bellman_ford(n, edges, src):
    dist = [inf] * n
    dist[src] = 0
    for _ in range(n - 1):
        updated = False
        for u, v, w in edges:
            if dist[u] != inf and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break

    has_neg_cycle = False
    for u, v, w in edges:
        if dist[u] != inf and dist[u] + w < dist[v]:
            has_neg_cycle = True
            break
    return dist, has_neg_cycle

10. Disjoint Set Union (DSU / Union-Find)
class DSU:
    __slots__ = ("parent", "size")
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1]*n

    def find(self, x):
        while x != self.parent[x]:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return False
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.parent[b] = a
        self.size[a] += self.size[b]
        return True

11. MST: Kruskal and Prim
11.1 Kruskal
def mst_kruskal(n, edges):
    """edges: list of (u, v, w)"""
    edges_sorted = sorted(edges, key=lambda e: e[2])
    dsu = DSU(n)
    total = 0
    used = 0
    for u, v, w in edges_sorted:
        if dsu.union(u, v):
            total += w
            used += 1
            if used == n - 1:
                break
    # if used < n-1 => graph disconnected
    return total

11.2 Prim (heap)
def mst_prim(n, edges):
    g = build_graph_weighted(n, edges)
    import heapq
    vis = [False]*n
    pq = [(0, 0)]  # cost, node
    total = 0
    cnt = 0
    while pq and cnt < n:
        w, u = heapq.heappop(pq)
        if vis[u]:
            continue
        vis[u] = True
        total += w
        cnt += 1
        for v, w2 in g[u]:
            if not vis[v]:
                heapq.heappush(pq, (w2, v))
    return total

12. SCC (Strongly Connected Components) — Tarjan
def tarjan_scc(n, edges):
    g = build_graph_unweighted(n, edges, directed=True)
    index = 0
    stack = []
    on_stack = [False] * n
    idx = [-1] * n
    low = [0] * n
    comp_id = [-1] * n
    comp_cnt = 0

    def dfs(u):
        nonlocal index, comp_cnt
        idx[u] = low[u] = index
        index += 1
        stack.append(u)
        on_stack[u] = True
        for v in g[u]:
            if idx[v] == -1:
                dfs(v)
                low[u] = min(low[u], low[v])
            elif on_stack[v]:
                low[u] = min(low[u], idx[v])
        if low[u] == idx[u]:
            # head of SCC
            while True:
                v = stack.pop()
                on_stack[v] = False
                comp_id[v] = comp_cnt
                if v == u:
                    break
            comp_cnt += 1

    for i in range(n):
        if idx[i] == -1:
            dfs(i)

    return comp_id, comp_cnt

13. Topological Sort & DAG DP
13.1 Kahn’s Toposort
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
    if len(order) != n:
        return None  # cycle
    return order

13.2 DP on DAG (e.g., longest path)
def longest_path_dag(n, edges):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
    order = topo_sort(n, edges)
    if order is None:
        return None
    dp = [-inf] * n
    # if we want from source s, set dp[s]=0 etc
    for u in order:
        if dp[u] == -inf:
            continue
        for v in g[u]:
            if dp[v] < dp[u] + 1:   # or some weight
                dp[v] = dp[u] + 1
    return dp

14. Dinic Max Flow (Python Version)

This is the go-to for Codeforces hard flow problems.

class Dinic:
    class Edge:
        __slots__ = ("v", "cap", "rev")
        def __init__(self, v, cap, rev):
            self.v = v
            self.cap = cap
            self.rev = rev

    def __init__(self, n):
        self.n = n
        self.g = [[] for _ in range(n)]
        self.level = [0]*n
        self.it = [0]*n

    def add_edge(self, u, v, cap):
        """Directed edge u -> v"""
        self.g[u].append(self.Edge(v, cap, len(self.g[v])))
        self.g[v].append(self.Edge(u, 0, len(self.g[u]) - 1))

    def bfs(self, s, t):
        self.level = [-1]*self.n
        q = deque([s])
        self.level[s] = 0
        while q:
            u = q.popleft()
            for e in self.g[u]:
                if e.cap > 0 and self.level[e.v] < 0:
                    self.level[e.v] = self.level[u] + 1
                    q.append(e.v)
        return self.level[t] >= 0

    def dfs(self, u, t, f):
        if u == t:
            return f
        for i in range(self.it[u], len(self.g[u])):
            self.it[u] = i
            e = self.g[u][i]
            if e.cap > 0 and self.level[u] < self.level[e.v]:
                ret = self.dfs(e.v, t, min(f, e.cap))
                if ret > 0:
                    e.cap -= ret
                    self.g[e.v][e.rev].cap += ret
                    return ret
        return 0

    def max_flow(self, s, t):
        flow = 0
        INF = 10**18
        while self.bfs(s, t):
            self.it = [0]*self.n
            while True:
                f = self.dfs(s, t, INF)
                if f == 0:
                    break
                flow += f
        return flow

15. Maximum Bipartite Matching (Kuhn)

Assume left part [0..n1-1], right part [0..n2-1]

def max_bipartite_matching(n1, n2, edges):
    """
    edges: list of (u, v) where u in [0,n1), v in [0,n2)
    returns: matchR (size n2, matchR[v]=u or -1), and size of matching
    """
    g = [[] for _ in range(n1)]
    for u, v in edges:
        g[u].append(v)

    matchR = [-1] * n2

    def dfs(u, seen):
        for v in g[u]:
            if seen[v]:
                continue
            seen[v] = True
            if matchR[v] == -1 or dfs(matchR[v], seen):
                matchR[v] = u
                return True
        return False

    result = 0
    for u in range(n1):
        seen = [False] * n2
        if dfs(u, seen):
            result += 1
    return matchR, result

16. Euler Tour of Tree (for subtree queries)

Flatten tree to use segment tree/fenwick on subtrees:

def euler_tour_tree(g, root=0):
    n = len(g)
    tin = [0]*n
    tout = [0]*n
    order = []
    timer = 0

    def dfs(u, p):
        nonlocal timer
        tin[u] = timer
        order.append(u)
        timer += 1
        for v in g[u]:
            if v == p:
                continue
            dfs(v, u)
        tout[u] = timer - 1

    dfs(root, -1)
    return tin, tout, order


Then subtree of u is order[tin[u] : tout[u]+1].

17. 0/1 State BFS (Graph + Extra State)

For problems like “shortest path with at most K special operations”, “keys & doors”:

def bfs_with_state(start_node, start_state, transitions, is_goal):
    """
    transitions(node, state) -> iterable of (next_node, next_state)
    is_goal(node, state) -> bool
    """
    from collections import deque
    q = deque()
    q.append((start_node, start_state, 0))
    seen = set([(start_node, start_state)])

    while q:
        node, state, dist = q.popleft()
        if is_goal(node, state):
            return dist
        for nn, ns in transitions(node, state):
            if (nn, ns) not in seen:
                seen.add((nn, ns))
                q.append((nn, ns, dist+1))
    return -1