# https://leetcode.com/problems/maximal-square/description/

'''
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:
Input: matrix = [["0"]]
Output: 0
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
'''


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n,m=len(matrix),len(matrix[0])
        dp=[[0]*m for _ in range(n)]
        ans=0
        for i in range(n):
            for j in range(m):
                if matrix[i][j]=='1':
                    dp[i][j]=1
                    if i>0 and j>0:
                        dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])
                    ans=max(ans,dp[i][j])

        return ans*ans
        

# Complexity Analysis
# Time complexity : O(mn). Single pass.
# Space complexity : O(n). Another array which stores elements in a row is used for dp.
