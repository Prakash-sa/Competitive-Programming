# https://leetcode.com/problems/island-perimeter/description/

'''
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:
Input: grid = [[1]]
Output: 4
Example 3:
Input: grid = [[1,0]]
Output: 4

Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
'''
from collections import List

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])

        result=0
        for r in range(n):
            for c in range(m):
                if grid[r][c]==1:
                    result+=4

                    if c>0 and grid[r][c-1]==1:
                        result-=2
                    if r>0 and grid[r-1][c]==1:
                        result-=2
        return result
        
# Complexity Analysis
# Time complexity : O(mn) where m is the number of rows of the grid and n is
# the number of columns of the grid. Since two for loops go through all
# the cells on the grid, for a two-dimensional grid of size m×n, the algorithm
# would have to check mn cells.
# Space complexity : O(1). Only the result variable is updated and there is
# no other space requirement.