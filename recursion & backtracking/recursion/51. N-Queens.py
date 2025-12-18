# https://leetcode.com/problems/n-queens/description/

'''
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively. 

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

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
            self.res.append(["".join(r) for r in self.board])
            return
        for col in range(n):
            if self.is_valid(row,col,n):
                self.board[row][col]='Q'
                self.backtrack(row+1,n)
                self.board[row][col]='.'

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.board=[['.']*n for _ in range(n)]
        self.res=[]
        self.backtrack(0,n)
        return self.res
    

# Given N as the number of queens (which is the same as the width and height of the board),
# Time complexity: O(N!)
# Space complexity: O(N^2)

