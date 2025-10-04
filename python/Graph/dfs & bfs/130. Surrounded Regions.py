# https://leetcode.com/problems/surrounded-regions/

'''
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them. 

Example 1:
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
 

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
'''

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return

        visited=set()
        n=len(board)
        m=len(board[0])
        directions=[(1,0),(-1,0),(0,1),(0,-1)]

        def is_valid(r,c):
            return 0<=r<n and 0<=c<m and board[r][c]=='O'
        
        def dfs(r,c):
            if (r,c) in visited:
                return
            visited.add((r,c))
            for dr,dc in directions:
                nr=r+dr
                nc=c+dc
                if is_valid(nr,nc):
                    dfs(nr,nc)

        for i in range(n):
            for j in [0,m-1]:
                if board[i][j]=='O':
                    dfs(i,j)

        for j in range(m):
            for i in [0,n-1]:
                if board[i][j]=='O':
                    dfs(i,j)
        

        for i in range(n):
            for j in range(m):
                if board[i][j]=='O' and (i,j) not in visited:
                    board[i][j]='X'

# Complexity Analysis
# Time Complexity: O(N) where N is the number of cells in the board. In the worst case where it contains only the O cells on the board, 
# we would traverse each cell twice: once during the DFS traversal and the other time during the cell reversion in the last step.
# Space Complexity: O(N) where N is the number of cells in the board. There are mainly two places that we consume some additional memory.
