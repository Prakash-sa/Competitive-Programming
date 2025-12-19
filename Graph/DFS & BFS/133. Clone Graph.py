

'''
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
'''

from typing import Optional
from collections import deque

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


## dfs

class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        adj_list={}

        def dfs(node):
            if not node:
                return node
            if node in adj_list:
                return adj_list[node]
            clone_node=Node(node.val,[])
            adj_list[node]=clone_node
            for nei in node.neighbors:
                clone_node.neighbors.append(dfs(nei))
            return clone_node
            
        return dfs(node)


## bfs
class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node

        graph={}
        queue=deque([node])
        graph[node]=Node(node.val,[])
        while queue:
            q=queue.popleft()
            for neighbor in q.neighbors:
                if neighbor not in graph:
                    graph[neighbor]=Node(neighbor.val,[])
                    queue.append(neighbor)
                graph[q].neighbors.append(graph[neighbor])
        return graph[node]

# Complexity Analysis
# Time Complexity: O(N+M) 
# where N is a number of nodes (vertices) and M is a number of edges.
# Space Complexity: O(N) 
# This space is occupied by the visited hash map and in addition to that, space would also be occupied by the recursion stack since we are adopting a recursive approach here. 
# The space occupied by the recursion stack would be equal to O(H) where H is the height of the graph. Overall, the space complexity would be O(N).
