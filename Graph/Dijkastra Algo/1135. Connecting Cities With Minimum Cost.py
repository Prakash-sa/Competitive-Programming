# https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/

'''
There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.
Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,
The cost is the sum of the connections' costs used.

Example 1:
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

Example 2:
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
 

Constraints:

1 <= n <= 104
1 <= connections.length <= 104
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 105
'''

from heapq import heappush,heappop
from collections import defaultdict,List


class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        '''
        Prim's Algorithm:
        1) Initialize a tree with a single vertex, chosen
        arbitrarily from the graph.
        2) Grow the tree by one edge: of the edges that
        connect the tree to vertices not yet in the tree,
        find the minimum-weight edge, and transfer it to the tree.
        3) Repeat step 2 (until all vertices are in the tree).
        '''

        neighbor=defaultdict(list)

        for i,j,c in connections:
            neighbor[i].append((j,c))
            neighbor[j].append((i,c))

        min_heap=[(0,1)]
        visited=set()
        res=0
        while min_heap:
            c,i=heappop(min_heap)
            if i in visited:
                continue
            visited.add(i)
            res+=c
            if len(visited)==n:
                return res
            for j,c in neighbor[i]:
                if j not in visited:
                    heappush(min_heap,(c,j))
        return -1
    
# Time Complexity: O(Eloge)
# Space Complexity: O(E+V)



class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        '''
        Kruskal's Algorithm:
        1) Create a forest F (a set of trees), where each vertex in 
        the graph is a separate tree.
        2) Create a set S containing all the edges in the graph.
        3) While S is nonempty and F is not yet spanning (fully connected):
            3A) Remove an edge with minimum weight from S
            3B) If the removed edge connects two different trees then 
            add it to the forest F, combining two trees into a single tree.
        '''

        def find(city):
            if parent[city] != city:
                parent[city] = find(parent[city])
            return parent[city]
        
        def union(c1, c2):
            root1, root2 = find(c1), find(c2)
            if root1 == root2:
                return False
            parent[root2] = root1
            return True
        
        parent = {city: city for city in range(1, n+1)}
        connections.sort(key=lambda x: x[2])
        total = 0
        for city1, city2, cost in connections: 
            if union(city1, city2):
                total += cost

        root = find(n)
        for city in range(1,n+1):
            k=find(city)
            if k!=root:
                return -1

        return total

# Time Complexity: O(Eloge)
# Space Complexity: O(N)