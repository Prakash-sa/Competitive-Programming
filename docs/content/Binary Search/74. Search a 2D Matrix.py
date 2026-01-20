# https://leetcode.com/problems/search-a-2d-matrix/description/

'''
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
'''

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])

        l,r=0,m*n-1

        while l<=r:
            idx=(l+r)//2
            element=matrix[idx//n][idx%n]
            if target==element:
                return True
            elif target<element:
                r=idx-1
            else:
                l=idx+1
        return False


# Complexity Analysis
# Time complexity : O(log(mn)) since it's a standard binary search.
# Space complexity : O(1).
