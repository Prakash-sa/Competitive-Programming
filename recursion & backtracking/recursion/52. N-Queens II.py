# https://leetcode.com/problems/n-queens-ii/description/

'''
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 9
'''

class Solution:
    def is_valid(self,row,col,n):
        for i in range(row):
            if self.board[i][col]=='Q':
                return False
        
        i,j=row-1,col-1
        while i>=0 and j>=0:
            if self.board[i][j]=='Q':
                return False
            i-=1
            j-=1

        i,j=row-1,col+1
        while i>=0 and j<n:
            if self.board[i][j]=='Q':
                return False
            i-=1
            j+=1
        return True

    def backtrack(self,row,n):
        if row==n:
            self.cnt+=1
            return
        for col in range(n):
            if self.is_valid(row,col,n):
                self.board[row][col]='Q'
                self.backtrack(row+1,n)
                self.board[row][col]='.'

    def totalNQueens(self, n: int) -> int:
        self.board=[['.']*n for _ in range(n)]
        self.cnt=0
        self.backtrack(0,n)
        return self.cnt


# Complexity Analysis

# Time complexity: O(N!), where N is the number of queens (which is the same as the width and height of the board).

# Unlike the brute force approach, we place a queen only on squares that aren't attacked. For the first queen, we have N options. 
# For the next queen, we won't attempt to place it in the same column as the first queen, and there must be at least one square attacked diagonally by the first queen as well. 
# Thus, the maximum number of squares we can consider for the second queen is N−2. For the third queen, we won't attempt to place it in 2 columns already occupied by the first 2 queens, and there must be at least two squares attacked diagonally from the first 2 queens. 
# Thus, the maximum number of squares we can consider for the third queen is N−4. This pattern continues, giving an approximate time complexity of N! at the end.

# Space complexity: O(N), where N is the number of queens (which is the same as the width and height of the board).
