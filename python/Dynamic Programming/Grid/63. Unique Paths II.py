# https://leetcode.com/problems/unique-paths-ii/description/

'''
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
'''


class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        mod=2*10**9
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    grid[i][j]=-1
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]==-1:
                    continue
                elif i==0 and j==0:
                    grid[i][j]=1
                elif i==0:
                    grid[i][j]=(grid[i][j]+(grid[i][j-1] if grid[i][j-1]!=-1 else 0))%mod
                elif j==0:
                    grid[i][j]=(grid[i][j]+(grid[i-1][j] if grid[i-1][j]!=-1 else 0))%mod
                else:
                    grid[i][j]=(grid[i][j]+(grid[i-1][j] if grid[i-1][j]!=-1 else 0) + (grid[i][j-1] if grid[i][j-1]!=-1 else 0))%mod
        return grid[n-1][m-1] if grid[n-1][m-1]!=-1 else 0


# Complexity Analysis

# Time Complexity: O(M×N). The rectangular grid given to us is of size M×N and we process each cell just once.
# Space Complexity: O(1). We are utilizing the obstacleGrid as the DP array. Hence, no extra space.