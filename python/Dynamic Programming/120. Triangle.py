# https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25

'''
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
 

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
'''

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        dp=[0]*n
        dp[0]=triangle[0][0]
        
        for i in range(1,n):
            for j in range(i,-1,-1):
                if j==0:
                    dp[j]=dp[j]+triangle[i][j]
                elif j==i:
                    dp[j]=dp[j-1]+triangle[i][j]
                else:
                    dp[j]=min(dp[j],dp[j-1])+triangle[i][j]
    
        return min(dp)
                

# Complexity Analysis:
# Let n be the number of rows in the triangle.
# Time Complexity: O(n*2).
# Space Complexity: O(n*2).
