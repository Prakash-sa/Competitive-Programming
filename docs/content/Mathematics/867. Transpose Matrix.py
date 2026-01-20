# https://leetcode.com/problems/transpose-matrix/description/

'''
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
'''


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        n,m=len(matrix),len(matrix[0])
        result=[[0]*n for _ in range(m)]
        for i in range(n):
            for j in range(m):
                result[j][i]=matrix[i][j]
        return result


# Complexity Analysis
# Time Complexity: O(R∗C), where R and C are the number of rows and columns in the given matrix A.
# Space Complexity: O(R∗C), the space used by the answer.
