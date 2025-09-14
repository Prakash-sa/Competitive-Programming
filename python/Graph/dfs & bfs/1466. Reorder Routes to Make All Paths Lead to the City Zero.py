# https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

'''
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
It's guaranteed that each city can reach city 0 after reorder.
 

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
'''

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        visited=[False]*n
        adj_list=[[] for _ in range(n)]
        for i in range(len(connections)):
            adj_list[connections[i][0]].append(connections[i][1])
            adj_list[connections[i][1]].append(-connections[i][0])

        def dfs(val):
            ans=0
            visited[val]=True
            for i in range(len(adj_list[val])):
                x = adj_list[val][i]
                if not visited[abs(x)]:
                    ans+=dfs(abs(x)) + (1 if x>0 else 0)
            return ans

        return dfs(0)




# Complexity Analysis

# Time complexity: O(n).
# Space complexity: O(n).
