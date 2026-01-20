# https://leetcode.com/problems/rotting-oranges/description/

'''
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
'''

from collections import deque, List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue=deque()

        fresh_oranges=0

        n,m=len(grid),len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j]==2:
                    queue.append((i,j))
                elif grid[i][j]==1:
                    fresh_oranges+=1

        minutes_elapsed=0

        directions=[(-1,0),(1,0),(0,1),(0,-1)]

        while queue and fresh_oranges>0:
            for i in range(len(queue)):
                r,c=queue.popleft()
                for d in directions:
                    nr,nc=r+d[0],c+d[1]
                    if 0<=nr<n and 0<=nc<m and grid[nr][nc]==1:
                        grid[nr][nc]=2
                        fresh_oranges-=1
                        queue.append((nr,nc))
            minutes_elapsed+=1
        return minutes_elapsed if fresh_oranges==0 else -1



class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue=deque()

        fresh_oranges=0

        n,m=len(grid),len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j]==2:
                    queue.append((i,j))
                elif grid[i][j]==1:
                    fresh_oranges+=1
        
        queue.append((-1,-1))

        minutes_elapsed=-1

        directions=[(-1,0),(1,0),(0,1),(0,-1)]

        while queue:
            r,c=queue.popleft()
            if r==-1:
                minutes_elapsed+=1
                if queue:
                    queue.append((-1,-1))
            else:
                for d in directions:
                    nr,nc=r+d[0],c+d[1]
                    if 0<=nr<n and 0<=nc<m:
                        if grid[nr][nc]==1:
                            grid[nr][nc]=2
                            fresh_oranges-=1
                            queue.append((nr,nc))
        return minutes_elapsed if fresh_oranges==0 else -1



# Complexity Analysis:
# Time Complexity: O(NM), where N×M is the size of the grid.
# First, we scan the grid to find the initial values for the queue, which would take O(NM) time.
# Then we run the BFS process on the queue, which in the worst case would enumerate all the cells in the grid once and only once. 
# Therefore, it takes O(NM) time.
# Thus combining the above two steps, the overall time complexity would be O(NM)+O(NM)=O(NM)

# Space Complexity: O(NM), where N is the size of the grid.
# In the worst case, the grid is filled with rotten oranges. As a result, the queue would be initialized with all the cells in the grid.
# By the way, normally for BFS, the main space complexity lies in the process rather than the initialization. 
# For instance, for a BFS traversal in a tree, at any given moment, the queue would hold no more than 2 levels of tree nodes. 
# Therefore, the space complexity of BFS traversal in a tree would depend on the width of the input tree.