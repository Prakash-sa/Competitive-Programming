# https://leetcode.com/problems/swim-in-rising-water/description/

'''
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
'''

from heapq import heappush,heappop

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        directions=[(0,1),(0,-1),(1,0),(-1,0)]
        h=[]
        heappush(h,(grid[0][0],0,0))
        vis=set()
        vis.add((0,0))

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m

        while len(h)>0:
            w,x,y=heappop(h)
            if x==n-1 and y==m-1:
                return w
            for dx,dy in directions:
                nr,nc=x+dx,y+dy
                if is_valid(nr,nc) and (nr,nc) not in vis:
                    vis.add((nr,nc))
                    new_h=max(grid[nr][nc],w)
                    heappush(h,(new_h,nr,nc))

        return -1
    
# Complexity Analysis

# Time Complexity: O(N*2 logN). Our depth-first search during a call to possible is O(N*2), and we make up to O(logN) of them.
# Space Complexity: O(N*2), the maximum size of the stack.
