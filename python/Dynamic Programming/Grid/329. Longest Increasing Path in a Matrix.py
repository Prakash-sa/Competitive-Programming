# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

'''
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:
Input: matrix = [[1]]
Output: 1

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
'''

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n,m=len(matrix),len(matrix[0])
        
        directions=[(-1,0),(1,0),(0,1),(0,-1)]

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m

        @lru_cache(None)
        def dfs(x,y):
            res=1
            for dx,dy in directions:
                nx,ny=x+dx,y+dy

                if is_valid(nx,ny) and matrix[x][y]>matrix[nx][ny]:
                    res=max(res,dfs(nx,ny)+1)
            
            return res

        ans=0
        for i in range(n):
            for j in range(m):
                ans=max(ans,dfs(i,j))
        return ans




# Complexity Analysis
# Time complexity : O(mn). Each vertex/cell will be calculated once and only once, and each edge will be visited once and only once. The total time complexity is then O(V+E). V is the total number of vertices and E is the total number of edges. In our problem, O(V)=O(mn), O(E)=O(4V)=O(mn).
# Space complexity : O(mn). The cache dominates the space complexity.
