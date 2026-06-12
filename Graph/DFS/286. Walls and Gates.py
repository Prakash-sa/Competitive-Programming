# https://leetcode.com/problems/walls-and-gates/description/

'''
You are given an m x n grid rooms initialized with these three possible values.
-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example 1:
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:
Input: rooms = [[-1]]
Output: [[-1]]

Constraints:
m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
'''

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        n,m=len(rooms),len(rooms[0])
        q=deque()
        for i in range(n):
            for j in range(m):
                if rooms[i][j]==0:
                    q.append((i,j))
        directions=[[-1,0],[0,1],[0,-1],[1,0]]

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m and rooms[x][y]!=0 and rooms[x][y]!=-1
        while q:
            x,y=q.popleft()
            for dx,dy in directions:
                nx,ny=x+dx,y+dy
                if is_valid(nx,ny) and rooms[nx][ny]>rooms[x][y]+1:
                    rooms[nx][ny]=rooms[x][y]+1
                    q.append((nx,ny))
    



# Complexity analysis

# Time complexity : O(mn).
# If you are having difficulty to derive the time complexity, start simple.
# Let us start with the case with only one gate. The breadth-first search takes at most m×n steps to reach all rooms, therefore the time complexity is O(mn). But what if you are doing breadth-first search from k gates?
# Once we set a room's distance, we are basically marking it as visited, which means each room is visited at most once. Therefore, the time complexity does not depend on the number of gates and is O(mn).

# Space complexity : O(mn).
