# 🌳 Binary Tree Fundamentals

## 🔍 Tree Traversal Basics

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder(root):
    """Left → Node → Right (sorted for BST)"""
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)

def preorder(root):
    """Node → Left → Right"""
    if not root:
        return []
    return [root.val] + preorder(root.left) + preorder(root.right)

def postorder(root):
    """Left → Right → Node"""
    if not root:
        return []
    return postorder(root.left) + postorder(root.right) + [root.val]

def levelorder(root):
    """BFS: level by level"""
    if not root:
        return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        res.append([node.val for node in q])
        q = deque(child for node in q for child in [node.left, node.right] if child)
    return res
```

---

## 1️⃣ Tree DFS (Post-order Pattern)

### 1.1 Node Information (size, height, depth)

```python
def tree_dfs_info(root):
    """Returns (subtree_size, height) for each node"""
    info = {}
    
    def dfs(u):
        if not u:
            return 0, -1  # size, height
        left_size, left_h = dfs(u.left)
        right_size, right_h = dfs(u.right)
        size = left_size + right_size + 1
        height = max(left_h, right_h) + 1
        info[u] = (size, height)
        return size, height
    
    dfs(root)
    return info
```

### 1.2 Path Problems (Root to Node/Leaf)

```python
def root_to_leaf_paths(root):
    """All paths from root to leaves"""
    paths = []
    
    def dfs(u, path):
        if not u:
            return
        path.append(u.val)
        if not u.left and not u.right:
            paths.append(path[:])
        else:
            dfs(u.left, path)
            dfs(u.right, path)
        path.pop()
    
    dfs(root, [])
    return paths

def path_sum(root, target):
    """Root to node paths summing to target"""
    paths = []
    
    def dfs(u, path, s):
        if not u:
            return
        path.append(u.val)
        s += u.val
        if s == target:
            paths.append(path[:])
        dfs(u.left, path, s)
        dfs(u.right, path, s)
        path.pop()
    
    dfs(root, [], 0)
    return paths
```

### 1.3 Subtree Queries (Max/Min in subtree)

```python
def max_path_sum_down(root):
    """Max path sum from node downward"""
    
    def dfs(u):
        if not u:
            return 0
        left = dfs(u.left)
        right = dfs(u.right)
        return u.val + max(0, left, right)
    
    return dfs(root)

def max_path_sum_any(root):
    """Max path sum (any two nodes)"""
    ans = [float('-inf')]
    
    def dfs(u):
        if not u:
            return 0
        left = max(0, dfs(u.left))
        right = max(0, dfs(u.right))
        ans[0] = max(ans[0], left + right + u.val)
        return max(left, right) + u.val
    
    dfs(root)
    return ans[0]
```

---

## 2️⃣ Tree Diameter & Center

### 2.1 Tree Diameter (Longest Path)

```python
def tree_diameter(root):
    """Longest path between any two nodes"""
    height, diameter = [0], [0]
    
    def dfs(u):
        if not u:
            return 0
        left_h = dfs(u.left)
        right_h = dfs(u.right)
        diameter[0] = max(diameter[0], left_h + right_h)
        return 1 + max(left_h, right_h)
    
    dfs(root)
    return diameter[0]

def diameter_path(root):
    """Get nodes on diameter path"""
    info = {'diameter': 0, 'path': []}
    
    def dfs(u):
        if not u:
            return 0, []
        left_h, left_p = dfs(u.left)
        right_h, right_p = dfs(u.right)
        new_d = left_h + right_h
        if new_d > info['diameter']:
            info['diameter'] = new_d
            info['path'] = left_p + [u.val] + right_p[::-1]
        h = 1 + max(left_h, right_h)
        return h, left_p + [u.val]
    
    dfs(root)
    return info['path']
```

### 2.2 Tree Center

```python
def tree_center(root):
    """Node(s) minimizing max distance to leaves"""
    height = {}
    
    def dfs(u):
        if not u:
            return -1
        h = 1 + max(dfs(u.left), dfs(u.right))
        height[u] = h
        return h
    
    dfs(root)
    # Center has minimum "eccentricity" (max distance to any leaf)
    # Usually 1 or 2 nodes
    centers = []
    for node, h in height.items():
        child_heights = [height.get(child, -1) for child in [node.left, node.right] if child]
        if child_heights:
            ecc = 1 + max(child_heights)
        else:
            ecc = 0
        if ecc == (height[root] + 1) // 2:
            centers.append(node.val)
    return centers
```

---

## 3️⃣ LCA (Lowest Common Ancestor)

### 3.1 Binary Lifting LCA

```python
def build_lca_binary_lifting(root):
    """Preprocess: O(n log n), Query: O(log n)"""
    LOG = 20
    parent = {}
    depth = {}
    
    def dfs(u, p, d):
        parent[u] = [p] + [None] * (LOG - 1)
        depth[u] = d
        for child in [u.left, u.right]:
            if child:
                dfs(child, u, d + 1)
    
    dfs(root, None, 0)
    
    # Build binary lifting table
    for u in parent:
        for i in range(1, LOG):
            if parent[u][i-1]:
                parent[u][i] = parent[parent[u][i-1]][i-1]
    
    def lca(u, v):
        if depth[u] < depth[v]:
            u, v = v, u
        # Bring u to same level as v
        for i in range(LOG):
            if (depth[u] - depth[v]) & (1 << i):
                u = parent[u][i]
        if u == v:
            return u
        # Binary search upwards
        for i in range(LOG - 1, -1, -1):
            if parent[u][i] != parent[v][i]:
                u = parent[u][i]
                v = parent[v][i]
        return parent[u][0]
    
    return lca
```

### 3.2 DFS-based LCA (Simple)

```python
def lca_simple(root, p, q):
    """O(n) per query"""
    def dfs(u):
        if not u or u == p or u == q:
            return u
        left = dfs(u.left)
        right = dfs(u.right)
        if left and right:
            return u
        return left or right
    
    return dfs(root)
```

---

## 4️⃣ Euler Tour & Path Queries

### 4.1 Euler Tour + Segment Tree

```python
def euler_tour(root):
    """Flatten tree to array, track in/out times"""
    tin = {}
    tout = {}
    timer = [0]
    arr = []
    
    def dfs(u):
        tin[u] = timer[0]
        arr.append(u.val)
        timer[0] += 1
        if u.left:
            dfs(u.left)
        if u.right:
            dfs(u.right)
        tout[u] = timer[0] - 1
    
    dfs(root)
    # Now use segment tree on arr for subtree queries
    return arr, tin, tout
```

### 4.2 Path Queries (Root to Node)

```python
def path_to_node(root, target, path=[]):
    """Path from root to target node"""
    if not root:
        return None
    if root.val == target:
        return path + [root.val]
    left = path_to_node(root.left, target, path + [root.val])
    if left:
        return left
    return path_to_node(root.right, target, path + [root.val])
```

---

## 5️⃣ Tree Decompositions

### 5.1 Heavy-Light Decomposition (Sketch)

```python
def hld_decompose(root):
    """Heavy-light decomposition for path queries in O(log² n)"""
    size = {}
    parent = {}
    chain_head = {}
    pos_in_chain = {}
    chains = []
    chain_id = [0]
    
    def dfs1(u, p):
        size[u] = 1
        parent[u] = p
        heavy_child = None
        for child in [u.left, u.right]:
            if child:
                dfs1(child, u)
                size[u] += size[child]
                if not heavy_child or size[child] > size[heavy_child]:
                    heavy_child = child
        return heavy_child
    
    def dfs2(u, head):
        chain_head[u] = head
        pos_in_chain[u] = len(chains[-1])
        chains[-1].append(u)
        for child in [u.left, u.right]:
            if child:
                if child == dfs1(u, None):
                    dfs2(child, head)
                else:
                    chains.append([])
                    chain_id[0] += 1
                    dfs2(child, child)
    
    dfs1(root, None)
    chains.append([])
    dfs2(root, root)
    return chain_head, pos_in_chain, chains
```

### 5.2 Centroid Decomposition (Sketch)

```python
def centroid_decomposition(root):
    """Find tree centroid: node minimizing max subtree size"""
    size = {}
    
    def calc_size(u, p):
        size[u] = 1
        for child in [u.left, u.right]:
            if child:
                size[u] += calc_size(child, u)
        return size[u]
    
    def find_centroid(u, p, tree_size):
        for child in [u.left, u.right]:
            if child and size[child] > tree_size // 2:
                return find_centroid(child, u, tree_size)
        return u
    
    tree_size = calc_size(root, None)
    centroid = find_centroid(root, None, tree_size)
    return centroid
```

---

## 6️⃣ Rerooting

### 6.1 Rerooting DP Pattern

```python
def rerooting_dp(root):
    """Example: depth sum from each node as root"""
    dp_down = {}  # dp[u] = cost with u as root going down
    dp_up = {}    # dp[u] = cost from parent going up
    
    def dfs1(u, p):
        dp_down[u] = 0
        for child in [u.left, u.right]:
            if child:
                dfs1(child, u)
                dp_down[u] += dp_down[child] + 1  # +1 for edge
    
    def dfs2(u, p):
        for child in [u.left, u.right]:
            if child:
                # Reroot: move root from u to child
                dp_up[child] = dp_up.get(u, 0) + (dp_down[u] - dp_down[child] - 1) + 1
                dfs2(child, u)
    
    dfs1(root, None)
    dp_up[root] = 0
    dfs2(root, None)
    
    # Now dp_up[u] + dp_down[u] = total cost if u is root
    return dp_down, dp_up
```

---

## 📊 Quick Reference

| Concept | Implementation | Complexity |
|---------|---|---|
| Traversal | DFS/BFS | O(n) |
| Subtree size | Post-order DFS | O(n) |
| Tree diameter | 2× DFS | O(n) |
| LCA (binary lifting) | Preprocess + query | O(n log n) + O(log n) |
| LCA (simple) | DFS per query | O(n) |
| Euler tour | DFS with timer | O(n) |
| HLD | Decompose tree | O(n log n) preprocess |
| Centroid | Find center recursively | O(n log n) |
| Rerooting | 2 DFS passes | O(n) |
| Max path sum | Single DFS | O(n) |
| Path to node | DFS search | O(n) |

