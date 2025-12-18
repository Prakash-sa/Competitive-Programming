# Fenwick / BIT (point add, prefix/range sum)
```python
class BIT:
    def __init__(self, n):
        self.n = n
        self.ft = [0]*(n+1)
    def add(self, i, delta):  # 0-indexed
        i += 1
        while i <= self.n:
            self.ft[i] += delta
            i += i & -i
    def sum_pref(self, i):  # sum [0..i), i is 0..n
        s = 0
        while i > 0:
            s += self.ft[i]
            i -= i & -i
        return s
    def sum_range(self, l, r):  # sum [l, r)
        return self.sum_pref(r) - self.sum_pref(l)
```

# Iterative Segment Tree (range sum, point update)
```python
class SegTree:
    def __init__(self, a):
        n = 1
        while n < len(a): n <<= 1
        self.n = n
        self.t = [0]*(2*n)
        self.t[n:n+len(a)] = a
        for i in range(n-1, 0, -1):
            self.t[i] = self.t[2*i] + self.t[2*i+1]
    def set(self, i, v):  # a[i] = v
        i += self.n
        self.t[i] = v
        i //= 2
        while i:
            self.t[i] = self.t[2*i] + self.t[2*i+1]
            i //= 2
    def query(self, l, r):  # sum [l, r)
        res = 0
        l += self.n; r += self.n
        while l < r:
            if l & 1: res += self.t[l]; l += 1
            if r & 1: r -= 1; res += self.t[r]
            l //= 2; r //= 2
        return res
```

# 0–1 BFS
```python
from collections import deque
INF = 10**18
def zero_one_bfs(n, adj, src):
    # adj[u]: list of (v, w) where w ∈ {0,1}
    dist = [INF]*n
    dist[src] = 0
    dq = deque([src])
    while dq:
        u = dq.popleft()
        du = dist[u]
        for v,w in adj[u]:
            nd = du + w
            if nd < dist[v]:
                dist[v] = nd
                (dq.appendleft if w == 0 else dq.append)(v)
    return dist
```

# Kahn’s Toposort
```python
from collections import deque
def topo_order(n, edges):
    g = [[] for _ in range(n)]
    indeg = [0]*n
    for u,v in edges:
        g[u].append(v); indeg[v]+=1
    q = deque([i for i in range(n) if indeg[i]==0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in g[u]:
            indeg[v]-=1
            if indeg[v]==0: q.append(v)
    return order  # len(order)<n => cycle
```

# KMP (prefix-function) + find all occurrences
```python
def kmp_pi(s):
    n = len(s); pi = [0]*n
    j = 0
    for i in range(1, n):
        while j and s[i] != s[j]: j = pi[j-1]
        if s[i] == s[j]: j += 1
        pi[i] = j
    return pi

def kmp_find(text, pat):
    pi = kmp_pi(pat)
    j = 0; occ = []
    for i,ch in enumerate(text):
        while j and ch != pat[j]: j = pi[j-1]
        if ch == pat[j]: j += 1
        if j == len(pat):
            occ.append(i - j + 1)
            j = pi[j-1]
    return occ
```

# Z-Algorithm (string matching/periods)
```python
def zfunc(s):
    n = len(s)
    z = [0]*n
    l = r = 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z
```

# Coordinate Compression
```python
def compress(arr):
    uniq = {v:i for i,v in enumerate(sorted(set(arr)))}
    return [uniq[v] for v in arr], uniq
```

# Sieve + primes (with smallest prime factor)
```python
def sieve_spf(n):
    spf = list(range(n+1))
    for i in range(2, int(n**0.5)+1):
        if spf[i] == i:
            step = i
            start = i*i
            for j in range(start, n+1, step):
                if spf[j] == j: spf[j] = i
    return spf

def factorize(x, spf):
    fac = []
    while x > 1:
        p = spf[x]; cnt = 0
        while x % p == 0:
            x //= p; cnt += 1
        fac.append((p,cnt))
    return fac
```

# nCr mod p (precompute factorials)
```python
MOD = 10**9+7
class Comb:
    def __init__(self, N, mod=MOD):
        self.mod = mod
        self.fact = [1]*(N+1)
        for i in range(1, N+1):
            self.fact[i] = self.fact[i-1]*i % mod
        self.ifact = [1]*(N+1)
        self.ifact[N] = pow(self.fact[N], -1, mod)
        for i in range(N, 0, -1):
            self.ifact[i-1] = self.ifact[i]*i % mod
    def nCk(self, n, k):
        if k < 0 or k > n: return 0
        return self.fact[n]*self.ifact[k]%self.mod*self.ifact[n-k]%self.mod
```

# 2D Prefix Sum
```python
def prefix2d(a):
    n, m = len(a), len(a[0])
    ps = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n):
        row = ps[i]
        nxt = ps[i+1]
        for j in range(m):
            nxt[j+1] = row[j+1] + nxt[j] - row[j] + a[i][j]
    return ps
# sum of rect [r1..r2), [c1..c2)
def rect_sum(ps, r1, c1, r2, c2):
    return ps[r2][c2]-ps[r1][c2]-ps[r2][c1]+ps[r1][c1]
```

# Shortest Path on Grid (4-dir) with walls
```python
from collections import deque
def grid_bfs(mat, sr, sc):
    n, m = len(mat), len(mat[0])
    dist = [[-1]*m for _ in range(n)]
    q = deque([(sr, sc)])
    dist[sr][sc] = 0
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        r,c = q.popleft()
        for dr,dc in dirs:
            nr, nc = r+dr, c+dc
            if 0 <= nr < n and 0 <= nc < m and mat[nr][nc] != '#' and dist[nr][nc] == -1:
                dist[nr][nc] = dist[r][c] + 1
                q.append((nr, nc))
    return dist
```

# Small Lazy SegTree (range add, range min)
```python
class LazySegMin:
    def __init__(self, a):
        n = 1
        while n < len(a): n <<= 1
        self.n = n
        self.t = [10**18]*(2*n)
        self.lz = [0]*(2*n)
        self.t[n:n+len(a)] = a
        for i in range(n-1, 0, -1):
            self.t[i] = min(self.t[2*i], self.t[2*i+1])
    def _apply(self, i, v):
        self.t[i] += v
        if i < self.n: self.lz[i] += v
    def _push(self, i):
        if self.lz[i]:
            self._apply(2*i, self.lz[i]); self._apply(2*i+1, self.lz[i])
            self.lz[i] = 0
    def range_add(self, l, r, v):
        def rec(i, tl, tr):
            if r <= tl or tr <= l: return
            if l <= tl and tr <= r:
                self._apply(i, v); return
            self._push(i)
            tm = (tl+tr)//2
            rec(2*i, tl, tm); rec(2*i+1, tm, tr)
            self.t[i] = min(self.t[2*i], self.t[2*i+1])
        rec(1, 0, self.n)
    def range_min(self, l, r):
        def rec(i, tl, tr):
            if r <= tl or tr <= l: return 10**18
            if l <= tl and tr <= r: return self.t[i]
            self._push(i)
            tm = (tl+tr)//2
            return min(rec(2*i, tl, tm), rec(2*i+1, tm, tr))
        return rec(1, 0, self.n)
```