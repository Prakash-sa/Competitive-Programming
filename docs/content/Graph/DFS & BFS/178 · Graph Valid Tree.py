# https://www.lintcode.com/problem/178/

'''
Description
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example
Example 1:
Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true.

Example 2:
Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output: false.


In order for a graph to be a valid tree, it must satisfy the following conditions:
- The graph must contain no cycles.
- There should be a single connected component - if we start from any node, we should be able to reach all other nodes.
'''

class Solution:
    """
    @param n: An integer
    @param edges: a list of undirected edges
    @return: true if it's a valid tree, or false
    """
    def valid_tree(self, n, edges):
        adj_list=[[] for _ in range(n)]
        for u,v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        visited=[False]*n

        if self.hasCycle(adj_list,0,visited,-1):
            return False
        return all(visited)


    def hasCycle(self,adj_list,node,visited,parent):
        visited[node]=True
        for neighbor in adj_list[node]:
            if visited[neighbor] and parent!=neighbor:
                return True
            elif not visited[neighbor] and self.hasCycle(adj_list,neighbor,visited,node):
                return True
        return False


'''
For the graph to be a valid tree, it must have exactly n - 1 edges. 
Any less, and it can't possibly be fully connected. Any more, and it has to contain cycles. 
Additionally, if the graph is fully connected and contains exactly n - 1 edges, it can't possibly contain a cycle, 
and therefore must be a tree!

Going by this definition, our algorithm needs to do the following:

Check whether or not there are n - 1 edges. If there's not, then return false.
Check whether or not the graph is fully connected. Return true if it is, false if otherwise.

'''

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!=n-1:
            return False
        adj_list=[[] for _ in range(n)]
        for u,v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        seen=set()

        def dfs(node):
            if node in seen:
                return
            seen.add(node)
            for nei in adj_list[node]:
                dfs(nei)
        dfs(0)
        return len(seen)==n

# TC: O(n)
# SC: O(n)

