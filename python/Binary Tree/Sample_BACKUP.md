0. Base template for trees in Python

You’ll paste this into almost every tree problem:

import sys
sys.setrecursionlimit(1_000_000)
input = sys.stdin.readline

n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)


Optionally choose root (often 1):

root = 1

1. Basic DFS / BFS, parent & depth arrays
When to use

Need depth, parent, subtree relationships.

Many later patterns require parent[], depth[].

Boiler DFS
n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

root = 1
parent = [0] * (n + 1)
depth = [0] * (n + 1)

def dfs(u, p):
    parent[u] = p
    for v in g[u]:
        if v == p:
            continue
        depth[v] = depth[u] + 1
        dfs(v, u)

dfs(root, 0)

Boiler BFS (sometimes safer than recursion)
from collections import deque

def bfs(root):
    parent = [0] * (n + 1)
    depth = [-1] * (n + 1)
    dq = deque([root])
    depth[root] = 0
    parent[root] = 0

    while dq:
        u = dq.popleft()
        for v in g[u]:
            if depth[v] != -1:
                continue
            depth[v] = depth[u] + 1
            parent[v] = u
            dq.append(v)

    return parent, depth

parent, depth = bfs(1)

2. Subtree DP (sizes, sums, counts)
When to use

“For each node, compute something over its subtree.”

Common tasks: subtree size, subtree sum, #special nodes in subtree, etc.

Many CF problems reduce to: post-order DFS DP.

Generic pattern

We compute dp[u] using children’s dp[v].

Example 1: Subtree size.

sz = [0] * (n + 1)

def dfs(u, p):
    sz[u] = 1
    for v in g[u]:
        if v == p:
            continue
        dfs(v, u)
        sz[u] += sz[v]

dfs(1, 0)


Example 2: Subtree sum (values on nodes):

val = [0] + list(map(int, input().split()))  # 1..n
subsum = [0] * (n + 1)

def dfs(u, p):
    subsum[u] = val[u]
    for v in g[u]:
        if v == p:
            continue
        dfs(v, u)
        subsum[u] += subsum[v]

dfs(1, 0)


Pattern:

Initialize dp[u] with node’s own contribution.

For v in children: combine child DP into parent DP.

3. Tree Diameter & Center
When to use

Find longest path in tree (diameter).

Often in problems about distances, tree center, radius, etc.

Diameter by 2 BFS/DFS

BFS from any node → farthest node a.

BFS from a → farthest node b.

Distance dist[a][b] = diameter.

from collections import deque

def bfs_far(start):
    dist = [-1] * (n + 1)
    dist[start] = 0
    dq = deque([start])
    best_node = start

    while dq:
        u = dq.popleft()
        for v in g[u]:
            if dist[v] != -1:
                continue
            dist[v] = dist[u] + 1
            dq.append(v)
            if dist[v] > dist[best_node]:
                best_node = v
    return best_node, dist

# usage:
a, _ = bfs_far(1)
b, dista = bfs_far(a)
# dista[b] is diameter length

Tree center

Path from a to b is diameter path.

Center(s) are middle node(s) on that path.
(Useful for minimizing max distance, etc.)

Recover path:

def bfs_par(start):
    dist = [-1] * (n + 1)
    par = [-1] * (n + 1)
    dist[start] = 0
    dq = deque([start])
    while dq:
        u = dq.popleft()
        for v in g[u]:
            if dist[v] != -1:
                continue
            dist[v] = dist[u] + 1
            par[v] = u
            dq.append(v)
    return par, dist

par, _ = bfs_par(a)
path = []
cur = b
while cur != -1:
    path.append(cur)
    cur = par[cur]
path = path[::-1]
# center(s)
if len(path) % 2 == 1:
    centers = [path[len(path)//2]]
else:
    centers = [path[len(path)//2 - 1], path[len(path)//2]]

4. LCA (Lowest Common Ancestor) + Binary Lifting
When to use

Distances between two nodes.

Path queries (build formulas using LCA).

Many CF tree problems need LCA.

Preprocessing
LOG = 20  # enough for n up to ~10^6; for 2e5, 18 is enough
up = [[0] * (n + 1) for _ in range(LOG)]
depth = [0] * (n + 1)

def dfs(u, p):
    up[0][u] = p
    for k in range(1, LOG):
        up[k][u] = up[k - 1][up[k - 1][u]]
    for v in g[u]:
        if v == p:
            continue
        depth[v] = depth[u] + 1
        dfs(v, u)

root = 1
dfs(root, 0)

Lift function (k-th ancestor)
def kth_ancestor(u, k):
    for i in range(LOG):
        if k & (1 << i):
            u = up[i][u]
            if u == 0:
                break
    return u

LCA query
def lca(a, b):
    if depth[a] < depth[b]:
        a, b = b, a
    # lift a up to same depth as b
    diff = depth[a] - depth[b]
    for i in range(LOG):
        if diff & (1 << i):
            a = up[i][a]

    if a == b:
        return a

    # lift both up until parents are same
    for i in reversed(range(LOG)):
        if up[i][a] != up[i][b]:
            a = up[i][a]
            b = up[i][b]
    return up[0][a]

Distance between nodes
def dist(a, b):
    c = lca(a, b)
    return depth[a] + depth[b] - 2 * depth[c]

5. Euler Tour + Subtree Queries
When to use

“For each query, add/set something in subtree of v.”

“Query sum over subtree.” (or count, min, etc.)

Map subtree to continuous segment [tin[v], tout[v]].

Euler in/out times
tin = [0] * (n + 1)
tout = [0] * (n + 1)
euler = []  # store nodes in entry order
timer = 0

def dfs(u, p):
    global timer
    tin[u] = timer
    euler.append(u)
    timer += 1
    for v in g[u]:
        if v == p:
            continue
        dfs(v, u)
    tout[u] = timer - 1

dfs(1, 0)


Now subtree of u is euler[tin[u] .. tout[u]].

Fenwick / BIT for sums on subtrees
class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)
    def add(self, i, delta):
        i += 1  # shift for 1-based
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i
    def sum(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s
    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l - 1)

# example usage:
val = [0] + list(map(int, input().split()))
fw = Fenwick(n)
for u in range(1, n + 1):
    fw.add(tin[u], val[u])

# query subtree sum of u:
# fw.range_sum(tin[u], tout[u])


Pattern: any static structure on tree subtree → Euler tour + BIT/segment tree.

6. Path Queries (HLD-style, segment tree on paths)

For CF in Python, full HLD can be heavy but still usable for n up to 2e5 if carefully written.

When to use

Query set/sum/max on path u–v.

With updates on nodes/edges.

Typically combine with LCA or HLD.

Heavy-Light Decomposition (outline)

We’ll:

Compute parent, depth, subtree size, heavy child.

Decompose into chains, each chain has a head.

Each node gets a position pos[u] in base array.

Use segment tree/Fenwick on base array.

n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

parent = [0] * (n + 1)
depth = [0] * (n + 1)
sz = [0] * (n + 1)
heavy = [-1] * (n + 1)

def dfs(u, p):
    parent[u] = p
    sz[u] = 1
    max_sub = 0
    for v in g[u]:
        if v == p:
            continue
        depth[v] = depth[u] + 1
        dfs(v, u)
        sz[u] += sz[v]
        if sz[v] > max_sub:
            max_sub = sz[v]
            heavy[u] = v

dfs(1, 0)

head = [0] * (n + 1)
pos = [0] * (n + 1)
cur_pos = 0

def decompose(u, h):
    global cur_pos
    head[u] = h
    pos[u] = cur_pos
    cur_pos += 1
    if heavy[u] != -1:
        decompose(heavy[u], h)
        for v in g[u]:
            if v != parent[u] and v != heavy[u]:
                decompose(v, v)

decompose(1, 1)


Now pos[u] is index in base array.

Segment Tree (sum example, compact)
class SegTree:
    def __init__(self, n):
        self.n = 1
        while self.n < n:
            self.n *= 2
        self.seg = [0] * (2 * self.n)
    def build(self, arr):
        for i, v in enumerate(arr):
            self.seg[self.n + i] = v
        for i in range(self.n - 1, 0, -1):
            self.seg[i] = self.seg[2 * i] + self.seg[2 * i + 1]
    def update(self, i, v):
        i += self.n
        self.seg[i] = v
        i //= 2
        while i:
            self.seg[i] = self.seg[2 * i] + self.seg[2 * i + 1]
            i //= 2
    def query(self, l, r):  # inclusive
        l += self.n
        r += self.n
        res = 0
        while l <= r:
            if l & 1:
                res += self.seg[l]
                l += 1
            if not (r & 1):
                res += self.seg[r]
                r -= 1
            l //= 2
            r //= 2
        return res


Build base array:

val = [0] + list(map(int, input().split()))
base = [0] * n
for u in range(1, n + 1):
    base[pos[u]] = val[u]

st = SegTree(n)
st.build(base)

Path sum query u–v with HLD
def query_path(u, v):
    res = 0
    while head[u] != head[v]:
        if depth[head[u]] < depth[head[v]]:
            u, v = v, u
        # u's head is deeper
        h = head[u]
        res += st.query(pos[h], pos[u])
        u = parent[h]
    # now on same head
    if depth[u] > depth[v]:
        u, v = v, u
    res += st.query(pos[u], pos[v])
    return res

# point update: change val[u] to x:
def update_node(u, x):
    st.update(pos[u], x)


You can adapt SegTree for min/max, bitwise, etc.

7. Rerooting DP (DP on all roots)
When to use

“For every node i, compute some value considering tree rooted at i.”

Example: sum of distances from each node to all others, or number of nodes at even distance, etc.

Template idea

First DFS (post-order) to compute DP when rooted at 1.

Second DFS (pre-order) to “reroot” DP from parent to child.

Example: sum of distances from each node to all others.

We maintain:

sz[u] – subtree size.

dp[u] – sum of distances from u to nodes in its subtree.

ans[u] – final sum of distances from u to all nodes.

First DFS
sz = [0] * (n + 1)
dp = [0] * (n + 1)

def dfs1(u, p):
    sz[u] = 1
    dp[u] = 0
    for v in g[u]:
        if v == p:
            continue
        dfs1(v, u)
        sz[u] += sz[v]
        dp[u] += dp[v] + sz[v]

dfs1(1, 0)


Here dp[u] = sum of distances from u to nodes in its subtree.

Second DFS – reroot
ans = [0] * (n + 1)

def dfs2(u, p):
    ans[u] = dp[u]
    for v in g[u]:
        if v == p:
            continue

        # save original
        pu, pv = dp[u], dp[v]
        su, sv = sz[u], sz[v]

        # move root from u to v:
        # remove v-subtree from u
        dp[u] -= dp[v] + sz[v]
        sz[u] -= sz[v]
        # add u-part to v
        dp[v] += dp[u] + sz[u]
        sz[v] += sz[u]

        dfs2(v, u)

        # restore
        dp[u], dp[v] = pu, pv
        sz[u], sz[v] = su, sv

dfs2(1, 0)


Key pattern:
Pass DP from parent to child by temporarily adjusting DP/size, recurse, then restore.

8. DSU on Tree (small-to-large / Sack)
When to use

For every node’s subtree, answer queries like:

Number of distinct colors in subtree.

Most frequent color in subtree.

Constraints: n up to 2e5, q ~ n.

Idea: DFS; maintain a multiset/map of values. Always merge smaller child’s map into bigger one to keep complexity O(n log n).

Example: Count distinct colors in each subtree.

import sys
sys.setrecursionlimit(1_000_000)
input = sys.stdin.readline

n = int(input())
color = [0] + list(map(int, input().split()))
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

ans = [0] * (n + 1)

def dfs(u, p):
    big = {}  # map color -> count
    big[color[u]] = 1

    for v in g[u]:
        if v == p:
            continue
        child_map = dfs(v, u)
        # merge smaller into bigger
        if len(child_map) > len(big):
            big, child_map = child_map, big
        for col, cnt in child_map.items():
            big[col] = big.get(col, 0) + cnt

    ans[u] = len(big)
    return big

dfs(1, 0)
# ans[u] now has distinct colors in subtree of u


For more complex queries, replace map type and merge logic accordingly.

9. Centroid Decomposition
When to use

Distance-based queries with many operations:

Count pairs of nodes at distance ≤ k.

Sum/min of distance-based cost.

O(n log n) decomposition; each node belongs to O(log n) levels.

Skeleton:

n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

used = [False] * (n + 1)
sz = [0] * (n + 1)

def calc_sz(u, p):
    sz[u] = 1
    for v in g[u]:
        if v == p or used[v]:
            continue
        calc_sz(v, u)
        sz[u] += sz[v]

def find_centroid(u, p, total):
    for v in g[u]:
        if v == p or used[v]:
            continue
        if sz[v] * 2 > total:
            return find_centroid(v, u, total)
    return u

def collect_dist(u, p, d, res):
    res.append(d)
    for v in g[u]:
        if v == p or used[v]:
            continue
        collect_dist(v, u, d + 1, res)

def decompose(u):
    calc_sz(u, -1)
    c = find_centroid(u, -1, sz[u])
    used[c] = True

    # process centroid-level logic here
    # example: count pairs with distance <= K
    #  - maintain global freq of distances
    #  - for each child, collect distances & use freq to count cross pairs

    for v in g[c]:
        if not used[v]:
            decompose(v)

decompose(1)


Then fill in the processing logic based on your specific problem.

10. Common Tree Tricks / Patterns

These don’t need long code, but you should know them conceptually.

10.1 Binary search on answer + DFS

Typical when answer is some minimal X satisfying condition:

E.g., “Is it possible to select ≤ k paths such that each path length ≤ X?”.

Use check(X) that runs DFS on tree and returns True/False.

Wrap in binary search.

def check(x):
    # run dfs with constraint x
    ok = True
    # ...
    return ok

lo, hi = 0, 10**18
while lo < hi:
    mid = (lo + hi) // 2
    if check(mid):
        hi = mid
    else:
        lo = mid + 1
ans = lo

10.2 Color / parity / bitmask DP on tree

Very common:

Each node has some character / color.

DP state is a bitmask (e.g., which letters appear odd times along path).

Example: count paths with palindromic string (at most one bit set in mask).

dp[u] = bitmask from root to u.

For queries, we check dp[u] XOR dp[v] XOR (1 << c) etc.

Use LCA + XOR properties.

10.3 Tree + Two-pointers over Euler tour

For “path queries” with offline queries, you can do Mo’s algorithm on trees:

Use Euler tour with “enter/exit occurrences” → Mo on array.

More advanced, but pattern is: convert path query to segment in Euler order (sometimes with 2 segments + LCA).