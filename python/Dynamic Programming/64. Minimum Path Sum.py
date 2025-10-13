# https://leetcode.com/problems/minimum-path-sum/description/

'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
'''



class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])

        for i in range(n):
            for j in range(m):
                if i==0 and j==0:
                    continue
                elif i==0:
                    grid[i][j]+=grid[i][j-1]
                elif j==0:
                    grid[i][j]+=grid[i-1][j]
                else:
                    grid[i][j]+=min(grid[i][j-1],grid[i-1][j])
        
        return grid[n-1][m-1]

# Complexity Analysis

# Time complexity : O(mn). We traverse the entire matrix once.

# Space complexity : O(1). No extra space is used.
