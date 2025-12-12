# Binary & N-ary Trees - ENHANCED GUIDE

## Advanced Tree Traversal Techniques

### 1. Morris Traversal (O(1) Space In-Order Traversal)

```python
def morris_inorder(root):
    """
    In-order traversal without recursion or explicit stack.
    Space: O(1), Time: O(n)
    
    Idea: Use right pointers of leaf nodes as temporary links.
    """
    result = []
    current = root
    
    while current:
        if current.left is None:
            # No left child: process current and move right
            result.append(current.val)
            current = current.right
        else:
            # Has left child: find rightmost node in left subtree
            predecessor = current.left
            while predecessor.right and predecessor.right != current:
                predecessor = predecessor.right
            
            if predecessor.right is None:
                # First time visiting: create thread to current
                predecessor.right = current
                current = current.left
            else:
                # Second time visiting: remove thread and process current
                predecessor.right = None
                result.append(current.val)
                current = current.right
    
    return result

# Morris Pre-order: process node before visiting left
def morris_preorder(root):
    result = []
    current = root
    
    while current:
        if current.left is None:
            result.append(current.val)
            current = current.right
        else:
            predecessor = current.left
            while predecessor.right and predecessor.right != current:
                predecessor = predecessor.right
            
            if predecessor.right is None:
                result.append(current.val)  # Process before descending
                predecessor.right = current
                current = current.left
            else:
                predecessor.right = None
                current = current.right
    
    return result
```

### 2. Thread Binary Tree

```python
class ThreadNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.left_thread = False  # Is left a thread?
        self.right_thread = False  # Is right a thread?

def create_threaded_tree(root):
    """Create threaded binary tree for fast traversal"""
    
    def thread_inorder(node, predecessor):
        if node is None:
            return predecessor
        
        # Thread left subtree
        if node.left:
            predecessor = thread_inorder(node.left, predecessor)
        
        # Set predecessor's right thread
        if predecessor:
            predecessor.right = node
            predecessor.right_thread = True
        
        # Set current node's left thread
        node.left_thread = bool(node.left is None)
        
        # Thread right subtree
        successor = node
        if node.right:
            successor = thread_inorder(node.right, node)
        else:
            successor = node
        
        return successor
    
    thread_inorder(root, None)
    return root

def traverse_threaded_tree(root):
    """Traverse threaded tree in O(n) time without recursion"""
    result = []
    current = root
    
    # Find leftmost node
    while current.left:
        current = current.left
    
    while current:
        result.append(current.val)
        
        if current.right_thread:
            # Follow thread
            current = current.right
        else:
            # Go to right child and find leftmost
            current = current.right
            if current:
                while current.left:
                    current = current.left
    
    return result
```

### 3. Cartesian Tree (Segment Tree Building)

```python
class CartesianNode:
    def __init__(self, val, idx):
        self.val = val
        self.idx = idx
        self.left = None
        self.right = None

def build_cartesian_tree(arr):
    """
    Build Cartesian tree: heap property on values, BST on indices.
    Useful for: range minimum queries, LCA preprocessing
    """
    stack = []
    root = None
    
    for i, val in enumerate(arr):
        node = CartesianNode(val, i)
        last = None
        
        # Pop nodes with value > current
        while stack and stack[-1].val > val:
            last = stack.pop()
        
        # Attach last as left child
        if last:
            node.left = last
        
        # Attach current as right child of top
        if stack:
            stack[-1].right = node
        
        stack.append(node)
        root = node if not stack[:-1] else root
    
    # Find root (should be only one element left)
    while stack:
        root = stack.pop()
    
    return root

def cartesian_tree_to_rmq(arr):
    """Use Cartesian tree for RMQ in O(n log n) preprocessing"""
    root = build_cartesian_tree(arr)
    
    # Traverse and extract Euler tour
    euler = []
    depth = []
    
    def dfs(node, d):
        if node is None:
            return
        euler.append(node.idx)
        depth.append(d)
        
        dfs(node.left, d + 1)
        euler.append(node.idx)
        depth.append(d)
        
        dfs(node.right, d + 1)
        euler.append(node.idx)
        depth.append(d)
    
    dfs(root, 0)
    return euler, depth
```

### 4. Binary Indexed Tree on Tree (Fenwick Tree)

```python
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta):
        i += 1
        while i <= self.n:
            self.tree[i] += delta
            i += i & (-i)
    
    def query(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & (-i)
        return res
    
    def range_query(self, l, r):
        if l == 0:
            return self.query(r)
        return self.query(r) - self.query(l - 1)

def tree_with_fenwick(n, edges):
    """Use Fenwick tree for subtree queries on tree"""
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    tin = [0] * n
    tout = [0] * n
    timer = 0
    
    def dfs(u, p):
        nonlocal timer
        tin[u] = timer
        timer += 1
        
        for v in g[u]:
            if v != p:
                dfs(v, u)
        
        tout[u] = timer - 1
    
    dfs(0, -1)
    
    # Now subtree of u is [tin[u], tout[u]]
    ft = FenwickTree(n)
    
    def update_subtree(u, delta):
        # Updates all nodes in subtree of u
        for i in range(tin[u], tout[u] + 1):
            ft.update(i, delta)
    
    def query_subtree(u):
        return ft.range_query(tin[u], tout[u])
    
    return ft, update_subtree, query_subtree
```

### 5. Segment Tree on Trees

```python
class SegmentTree:
    def __init__(self, arr):
        self.n = 1
        while self.n < len(arr):
            self.n *= 2
        self.tree = [0] * (2 * self.n)
        
        for i, val in enumerate(arr):
            self.tree[self.n + i] = val
        
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]
    
    def update(self, i, v):
        i += self.n
        self.tree[i] = v
        i //= 2
        while i:
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]
            i //= 2
    
    def query(self, l, r):
        l += self.n
        r += self.n + 1
        res = 0
        while l < r:
            if l & 1:
                res += self.tree[l]
                l += 1
            if r & 1:
                r -= 1
                res += self.tree[r]
            l >>= 1
            r >>= 1
        return res

def tree_with_segtree(n, edges, values):
    """Segment tree on Euler tour of tree"""
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    tin = [0] * n
    euler = []
    timer = 0
    
    def dfs(u, p):
        nonlocal timer
        tin[u] = timer
        euler.append(values[u])
        timer += 1
        
        for v in g[u]:
            if v != p:
                dfs(v, u)
    
    dfs(0, -1)
    
    st = SegmentTree(euler)
    return st, tin

# Now queries on subtrees are range queries on Euler tour
```

### 6. Centroid Decomposition on Trees

```python
def centroid_decomposition_tree(n, edges):
    """
    Decompose tree into nested centroids for fast queries.
    Each node belongs to O(log n) centroid levels.
    """
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    removed = [False] * n
    sz = [0] * n
    centroid_parent = [-1] * n
    depth = [0] * n
    
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
    
    def decompose(u, parent, d):
        tree_size = calc_size(u, -1)
        centroid = find_centroid(u, -1, tree_size)
        removed[centroid] = True
        centroid_parent[centroid] = parent
        depth[centroid] = d
        
        for v in g[centroid]:
            if not removed[v]:
                decompose(v, centroid, d + 1)
    
    decompose(0, -1, 0)
    return centroid_parent, depth

# Can use for: distance queries, offline tree queries
```

### 7. Virtual Tree (Advanced)

```python
def virtual_tree_build(important, lca_func, depth_array):
    """
    Build minimal tree containing only important nodes and LCAs.
    Reduces problem from O(n) to O(k log k) where k = important nodes.
    """
    important = sorted(set(important), key=lambda x: depth_array[x])
    vt = []
    
    for node in important:
        if not vt:
            vt.append(node)
            continue
        
        # LCA of current and last in virtual tree
        last = vt[-1]
        l = lca_func(node, last)
        
        if l != last:
            # Remove nodes until we find parent of l
            while len(vt) > 1 and depth_array[vt[-1]] > depth_array[l]:
                vt.pop()
            
            if vt and vt[-1] != l and l != node:
                vt.append(l)
        
        if node != vt[-1] if vt else True:
            vt.append(node)
    
    return vt
```

### 8. Treap (Randomized Binary Search Tree)

```python
import random

class TreapNode:
    def __init__(self, val):
        self.val = val
        self.priority = random.random()
        self.left = None
        self.right = None
        self.size = 1

class Treap:
    def __init__(self):
        self.root = None
    
    def get_size(self, node):
        return node.size if node else 0
    
    def update_size(self, node):
        if node:
            node.size = 1 + self.get_size(node.left) + self.get_size(node.right)
    
    def rotate_right(self, y):
        x = y.left
        y.left = x.right
        x.right = y
        self.update_size(y)
        self.update_size(x)
        return x
    
    def rotate_left(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        self.update_size(x)
        self.update_size(y)
        return y
    
    def insert(self, val):
        self.root = self._insert(self.root, val)
    
    def _insert(self, node, val):
        if node is None:
            return TreapNode(val)
        
        if val < node.val:
            node.left = self._insert(node.left, val)
            if node.left.priority > node.priority:
                node = self.rotate_right(node)
        else:
            node.right = self._insert(node.right, val)
            if node.right.priority > node.priority:
                node = self.rotate_left(node)
        
        self.update_size(node)
        return node
    
    def kth_smallest(self, k):
        return self._kth_smallest(self.root, k)
    
    def _kth_smallest(self, node, k):
        if node is None:
            return None
        
        left_size = self.get_size(node.left)
        if k <= left_size:
            return self._kth_smallest(node.left, k)
        elif k == left_size + 1:
            return node.val
        else:
            return self._kth_smallest(node.right, k - left_size - 1)
```

### 9. Heavy-Light Decomposition (HLD) Advanced

```python
def heavy_light_decomposition(n, edges, root=0):
    """
    Decompose tree into heavy and light paths for O(log² n) path queries.
    With segment tree: O(log² n) per query.
    """
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    
    parent = [-1] * n
    depth = [0] * n
    sz = [0] * n
    heavy_child = [-1] * n
    
    def dfs1(u, p):
        parent[u] = p
        sz[u] = 1
        max_child_size = 0
        
        for v in g[u]:
            if v != p:
                depth[v] = depth[u] + 1
                dfs1(v, u)
                sz[u] += sz[v]
                
                if sz[v] > max_child_size:
                    max_child_size = sz[v]
                    heavy_child[u] = v
    
    dfs1(root, -1)
    
    chain_id = [0] * n
    chain_pos = [0] * n
    chain_head = []
    current_chain = 0
    
    def dfs2(u, head):
        nonlocal current_chain
        chain_id[u] = current_chain
        chain_pos[u] = len(chain_head)
        chain_head.append(u)
        
        if heavy_child[u] != -1:
            dfs2(heavy_child[u], head)
            for v in g[u]:
                if v != parent[u] and v != heavy_child[u]:
                    current_chain += 1
                    dfs2(v, v)
    
    dfs2(root, root)
    
    def get_path(u, v):
        """Get all edges on path from u to v"""
        path = []
        while chain_id[u] != chain_id[v]:
            if depth[chain_head[chain_id[u]]] < depth[chain_head[chain_id[v]]]:
                u, v = v, u
            # Bring u to head of its chain, then move to parent
            path.append((min(chain_pos[chain_head[chain_id[u]]], chain_pos[u]),
                       chain_pos[u]))
            u = parent[chain_head[chain_id[u]]]
        
        path.append((min(chain_pos[u], chain_pos[v]), max(chain_pos[u], chain_pos[v])))
        return path
    
    return chain_id, chain_pos, chain_head, get_path
```

### 10. XOR Basis on Tree

```python
def xor_basis_from_path(tree_path):
    """Extract XOR basis from path values"""
    basis = [0] * 60
    
    for val in tree_path:
        for i in range(59, -1, -1):
            if not (val & (1 << i)):
                continue
            
            if not basis[i]:
                basis[i] = val
                break
            
            val ^= basis[i]
    
    return basis

def max_xor_with_basis(basis, x):
    """Get maximum XOR using basis"""
    for i in range(59, -1, -1):
        if basis[i]:
            x = max(x, x ^ basis[i])
    return x
```

---

## Quick Reference: Tree Techniques by Use Case

| Use Case | Technique | Complexity |
|----------|-----------|-----------|
| Subtree sum queries | Euler tour + Fenwick | O(log n) |
| Path queries | HLD + Segment tree | O(log² n) |
| LCA queries | Binary lifting | O(log n) |
| Diameter | Two BFS/DFS | O(n) |
| Rerooting | DP | O(n) |
| Centroids | Centroid decomp | O(log n) levels |
| Distance queries | Centroid decomp | O(n log n) build |
| Max XOR on path | XOR basis + LCA | O(60) per query |
| Dynamic trees | Link-cut tree | O(log n) |
| Offline batch queries | Virtual tree | O(k log k) |
