# https://leetcode.com/problems/minimum-height-trees/description/

'''
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Example 1:
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]

Constraints:
1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
'''

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n<=2:
            return [i for i in range(n)]

        neighbours=[set() for i in range(n)]
        for start,end in edges:
            neighbours[start].add(end)
            neighbours[end].add(start)

        leaves=[]
        for i in range(n):
            if len(neighbours[i])==1:
                leaves.append(i)

        remaining_node=n
        while remaining_node>2:
            remaining_node-=len(leaves)
            new_leaves=[]
            for i in range(len(leaves)):
                leaf=leaves.pop()
                neighbour=neighbours[leaf].pop()
                neighbours[neighbour].remove(leaf)
                if len(neighbours[neighbour])==1:
                    new_leaves.append(neighbour)
            leaves=new_leaves
        return leaves




# Complexity Analysis

# Let ∣V∣ be the number of nodes in the graph, then the number of edges would be ∣V∣−1 as specified in the problem.

# Time Complexity: O(∣V∣)
# First, it takes ∣V∣−1 iterations for us to construct a graph, given the edges.
# With the constructed graph, we retrieve the initial leaf nodes, which takes ∣V∣ steps.
# During the BFS trimming process, we will trim out almost all the nodes (∣V∣) and edges (∣V∣−1) from the edges.
# Therefore, it would take us around ∣V∣+∣V∣−1 operations to reach the centroids.
# To sum up, the overall time complexity of the algorithm is O(∣V∣).

# Space Complexity: O(∣V∣)
# We construct the graph with adjacency list, which has ∣V∣ nodes and ∣V∣−1 edges.
# Therefore, we would need ∣V∣+∣V∣−1 space for the representation of the graph.
# In addition, we use a queue to keep track of the leaf nodes.
# In the worst case, the nodes form a star shape, with one centroid and the rest of the nodes as leaf nodes.
# In this case, we would need ∣V∣−1 space for the queue.
# To sum up, the overall space complexity of the algorithm is also O(∣V∣).

