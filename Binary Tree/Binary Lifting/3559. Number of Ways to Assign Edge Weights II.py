# https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/description/


"""
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
Return an array answer, where answer[i] is the number of valid assignments for queries[i].
Since the answer may be large, apply modulo 109 + 7 to each answer[i].
Note: For each query, disregard all edges not in the path between node ui and vi.

Example 1:
Input: edges = [[1,2]], queries = [[1,1],[1,2]]
Output: [0,1]
Explanation:
Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

Example 2:
Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]
Output: [2,1,4]
Explanation:
Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.


Constraints:
2 <= n <= 105
edges.length == n - 1
edges[i] == [ui, vi]
1 <= queries.length <= 105
queries[i] == [ui, vi]
1 <= ui, vi <= n
edges represents a valid tree.
"""


class Solution:
    MOD = 10**9 + 7

    def modPow(self, a, b):
        ans = 1
        while b > 0:
            if b & 1:
                ans = (ans * a) % self.MOD
            a = (a * a) % self.MOD
            b >>= 1
        return ans

    def dfs(self, node, parent):
        self.up[node][0] = parent

        for j in range(1, self.LOG):
            self.up[node][j] = self.up[self.up[node][j - 1]][j - 1]

        for neighbour in self.adj[node]:
            if neighbour == parent:
                continue

            self.depth[neighbour] = self.depth[node] + 1
            self.dfs(neighbour, node)

    def lca(self, u, v):
        if self.depth[u] < self.depth[v]:
            u, v = v, u

        diff = self.depth[u] - self.depth[v]

        for j in range(self.LOG - 1, -1, -1):
            if diff & (1 << j):
                u = self.up[u][j]

        if u == v:
            return u

        for j in range(self.LOG - 1, -1, -1):
            if self.up[u][j] != self.up[v][j]:
                u = self.up[u][j]
                v = self.up[v][j]
        return self.up[u][0]

    def assignEdgeWeights(
        self, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        n = len(edges) + 1

        self.LOG = 1
        while (1 << self.LOG) <= n:
            self.LOG += 1

        self.adj = [[] for _ in range(n + 1)]

        for u, v in edges:
            self.adj[u].append(v)
            self.adj[v].append(u)

        self.depth = [0] * (n + 1)
        self.up = [[0] * self.LOG for _ in range(n + 1)]

        self.dfs(1, 0)
        ans = []

        for u, v in queries:
            L = self.lca(u, v)
            dist = self.depth[u] + self.depth[v] - 2 * self.depth[L]

            if dist == 0:
                ans.append(0)
            else:
                ans.append(self.modPow(2, dist - 1))
        return ans

"""
Complexity Analysis
Let n be the number of nodes in the tree, and let m be the number of queries.

Time complexity: O(nlogn+mlogn).
Building the binary lifting table requires O(nlogn) time. Each LCA query takes O(logn) time, resulting in a total query cost of O(mlogn).

Space complexity: O(nlogn).
The binary lifting table stores O(logn) ancestors for each node, requiring O(nlogn) space.
"""
