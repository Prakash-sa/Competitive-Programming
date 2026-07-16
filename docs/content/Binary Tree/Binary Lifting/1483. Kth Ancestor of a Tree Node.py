# https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

"""
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
The kth ancestor of a tree node is the kth node in the path from that node to the root node.
Implement the TreeAncestor class:
TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

Example 1:
Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor

Constraints:
1 <= k <= n <= 5 * 104
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 104 queries.
"""


class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        m = 1 + int(log2(n))  # at most 16 for this problem
        self.dp = [[-1] * m for _ in range(n)]  # ith node's 2^j parent
        for j in range(m):
            for i in range(n):
                if j == 0:
                    self.dp[i][0] = parent[i]  # 2^0 parent
                elif self.dp[i][j - 1] != -1:
                    self.dp[i][j] = self.dp[self.dp[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        while k > 0 and node != -1:
            i = int(log2(k))
            node = self.dp[node][i]
            k -= 1 << i
        return node

'''
For node 0, 1, ..., n-1, we define a matrix self.dp[][] whose i, jth element indicates the ith node's 2^j parent. Here, i = 0, 1, ..., n-1 and j = 0, 1, ..., int(log2(n)). An important recursive relationship is that

self.dp[i][j] = self.dp[self.dp[i][j-1]][j-1].

In other words, ith node's 2^j parent is ith node's 2^(j-1) parent's 2^(j-1) parent. In this way, lookup is guarenteed to complete in O(logN) time. Note that it takes O(NlogN) to build self.dp.

Time complexity O(NlogN) to pre-processing the tree and O(logN) for each equery thereafter.
'''