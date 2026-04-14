# https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

'''
You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
Notice that the modulo is performed after getting the maximum product.


Example 1:
Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example 2:
Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).

Example 3:
Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 15
-4 <= grid[i][j] <= 4
'''

class Solution:
    MOD=10**9+7
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        maxgt=[[0]*n for _ in range(m)]
        minlt=[[0]*n for _ in range(m)]

        maxgt[0][0]=minlt[0][0]=grid[0][0]

        for i in range(1,n):
            maxgt[0][i]=minlt[0][i]=maxgt[0][i-1]*grid[0][i]
        for i in range(1,m):
            maxgt[i][0]=minlt[i][0]=maxgt[i-1][0]*grid[i][0]
        
        for i in range(1,m):
            for j in range(1,n):
                if grid[i][j]>=0:
                    maxgt[i][j]=max(maxgt[i][j-1],maxgt[i-1][j])*grid[i][j]
                    minlt[i][j]=min(minlt[i][j-1],minlt[i-1][j])*grid[i][j]
                else:
                    maxgt[i][j]=min(minlt[i][j-1],minlt[i-1][j])*grid[i][j]
                    minlt[i][j]=max(maxgt[i][j-1],maxgt[i-1][j])*grid[i][j]

        return maxgt[m-1][n-1]%self.MOD if maxgt[m-1][n-1]>=0 else -1


'''
Complexity Analysis
Let m and n be the number of rows and columns of the matrix.

Time complexity: O(mn).
We traverse each cell once, and each transition takes constant time.

Space complexity: O(mn).
We maintain two matrices of size m×n.
'''