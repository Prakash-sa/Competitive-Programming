# https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

'''
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
Return the number of connected components in the graph.

Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

Constraints:
1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
'''

## DFS

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_list=defaultdict(list)
        vis=set()
        cnt=0

        for i in range(len(edges)):
            adj_list[edges[i][0]].append(edges[i][1])
            adj_list[edges[i][1]].append(edges[i][0])
        
        def dfs(root):
            if root in vis:
                return
            vis.add(root)
            for k in adj_list[root]:
                dfs(k)
        
        for i in range(n):
            if i not in vis:
                dfs(i)
                cnt+=1
        return cnt
        

# Iterative DFS

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        from collections import defaultdict
        adj_list = defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        
        visited = [False] * n
        components = 0
        
        for i in range(n):
            if not visited[i]:
                components += 1
                stack = [i]
                while stack:
                    node = stack.pop()
                    if not visited[node]:
                        visited[node] = True
                        stack.extend(adj_list[node])
        
        return components
    
'''
Advantages:

No recursion limit issues
Slightly faster due to avoiding function call overhead
Better cache locality with list vs set for visited
'''

# DSU

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent=list(range(n))
        rank=[0]*n
        components=n

        def find(x):
            if parent[x]!=x:
                parent[x]=find(parent[x])
            return parent[x]
        
        def union(x,y):
            nonlocal components
            px,py=find(x),find(y)
            if px==py:
                return
            
            if rank[px]<rank[py]:
                px,py=py,px
            parent[py]=px
            if rank[px]==rank[py]:
                rank[px]+=1
            components-=1
            
        for u,v in edges:
            union(u,v)
        return components

'''
Advantages:

Same time complexity: O(E × α(V)) where α is inverse Ackermann (practically constant)
Better space: O(V) vs O(V + E) for adjacency list
More efficient for sparse graphs with many queries
No recursion stack: avoids potential stack overflow for deep graphs
'''