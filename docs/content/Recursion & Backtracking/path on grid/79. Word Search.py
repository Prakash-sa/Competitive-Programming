# https://leetcode.com/problems/word-search/description/

'''
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?
'''

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n,m=len(board),len(board[0])

        directions=[(1,0),(-1,0),(0,1),(0,-1)]

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m

        def dfs(row,col,index):
            if board[row][col]!=word[index]:
                return False
            if index==len(word)-1:
                return True
            
            tmp=board[row][col]
            board[row][col]='#'
            ans=False
            for dr,dc in directions:
                nr,nc=row+dr,col+dc
                if is_valid(nr,nc):
                    ans|=dfs(nr,nc,index+1)
            board[row][col]=tmp
            return ans

        for i in range(n):
            for j in range(m):
                if board[i][j]==word[0]:
                    if dfs(i,j,0):
                        return True
        return False


# Time Complexity: O(m * n * 4^L) where m and n are the dimensions of the grid and L is the length of the word. We iterate over each cell once (m * n), and for each cell, we call the dfs function which makes 4 recursive calls with a max depth of L, giving us O(4^L) per cell.

# Space Complexity: O(L) where L is the length of the word. We need to account for the space on the recursive call stack, which can be L calls deep in the worst case.