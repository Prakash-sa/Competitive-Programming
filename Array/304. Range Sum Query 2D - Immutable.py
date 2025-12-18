# https://leetcode.com/problems/range-sum-query-2d-immutable/description/

'''
Given a 2D matrix matrix, handle multiple queries of the following type:
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:
NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

Example 1:
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]
Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-104 <= matrix[i][j] <= 104
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.
'''

from collections import List


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows=len(matrix)
        cols=len(matrix[0]) if rows else 0
        self.P=[[0]*(cols+1) for _ in range(rows+1)]

        for r in range(rows):
            row_acc=0
            for c in range(cols):
                row_acc+=matrix[r][c]
                self.P[r+1][c+1]=self.P[r][c+1]+row_acc


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        r1,c1,r2,c2=row1+1,col1+1,row2+1,col2+1
        total=self.P[r2][c2]
        above=self.P[r1-1][c2]
        left=self.P[r2][c1-1]
        overlap=self.P[r1-1][c1-1]

        return total-above-left+overlap



# Complexity Analysis

# Time complexity: O(1) time per query, O(mn) time pre-computation.
# The pre-computation in the constructor takes O(mn) time. Each sumRegion query takes O(1) time.

# Space complexity: O(mn).
# The algorithm uses O(mn) space to store the cumulative region sum.

