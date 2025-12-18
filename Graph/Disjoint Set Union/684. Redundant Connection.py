# https://leetcode.com/problems/redundant-connection/description/

'''
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
'''

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n=len(edges)+1
        parent=[i for i in range(n)]
        rank=[1]*n

        def find(x):
            if x!=parent[x]:
                parent[x]=find(parent[x])
            return parent[x]
        
        def union(x,y):
            px,py=find(x),find(y)
            if px==py:
                return False
            if rank[px]>rank[py]:
                parent[py]=px
                rank[px]+=rank[py]
            else:
                parent[px]=py
                rank[py]+=rank[px]
            return True
        
        for e1,e2 in edges:
            if not union(e1,e2):
                return [e1,e2]
        return []


# Complexity Analysis
# Here, N is the number of nodes and edges in the given graph.

# Time complexity: O(N⋅α(N))
# We iterate over all edges, and for each edge, we invoke the doUnion function, which has a time complexity of O(α(N)), given that both union by size and path compression are employed. Consequently, the overall time complexity of the algorithm is O(N⋅α(N)). It is important to note that α(N) represents the inverse Ackermann function, which grows so slowly that it is often considered asymptotically constant, or O(1).

# Space complexity: O(N)
# The list representative, used to store the representatives, and the list size, used to store the size of each component, will each contain N entries. Therefore, the total space complexity is O(N).
