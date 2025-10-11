# https://leetcode.com/problems/spiral-matrix/description/
# https://www.hellointerview.com/learn/code/matrices/spiral-matrix

'''
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
'''

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result=[]

        while matrix:
            result+=matrix.pop(0)

            if matrix and matrix[0]:
                for row in matrix:
                    result.append(row.pop())
            if matrix:
                result+=matrix.pop()[::-1]
            
            if matrix and matrix[0]:
                for row in matrix:
                    result.append(row.pop(0))
        
        return result


# Complexity Analysis
# Time Complexity: O(m * n) where m is the number of rows and n is the number of columns. We visit each element in the matrix once.
# Space Complexity: O(m * n) for the result array that stores all matrix elements.
