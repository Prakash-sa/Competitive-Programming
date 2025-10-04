# https://leetcode.com/problems/number-of-islands/description/

'''
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
'''

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n=len(grid)
        m=len(grid[0])

        direction=[(1,0),(-1,0),(0,1),(0,-1)]

        def is_valid(r,c):
            if 0<=r<n and 0<=c<m and grid[r][c]=='1':
                return True
            return False

        def dfs(r,c):
            if grid[r][c]=='0':
                return
            grid[r][c]='0'
            for d1,d2 in direction:
                d_r=r+d1
                d_c=c+d2
                if is_valid(d_r,d_c):
                    dfs(d_r,d_c)

        cnt=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]=='1':
                    dfs(i,j)
                    cnt+=1
        return cnt

            

# Complexity Analysis

# Time complexity : O(M×N) where M is the number of rows and
# N is the number of columns.
# Space complexity : worst case O(M×N) in case that the grid map
# is filled with lands where DFS goes by M×N deep.
