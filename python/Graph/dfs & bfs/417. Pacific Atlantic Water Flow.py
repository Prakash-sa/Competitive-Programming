# https://leetcode.com/problems/pacific-atlantic-water-flow/description/

'''
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
 

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105
'''

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        n=len(heights)
        m=len(heights[0])
        pac=set()
        at=set()

        directions=[(1,0),(-1,0),(0,1),(0,-1)]

        def is_valid(r,c):
            return 0<=r<n and 0<=c<m
        
        def dfs(r,c,vis):
            if (r,c) in vis:
                return
            vis.add((r,c))
            for dr,dc in directions:
                nr,nc=r+dr,c+dc
                if is_valid(nr,nc) and heights[nr][nc]>=heights[r][c]:
                    dfs(nr,nc,vis)
        
        for i in range(n):
            dfs(i,0,pac)
        for j in range(m):
            dfs(0,j,pac)

        for i in range(n):
            dfs(i,m-1,at)
        for j in range(m):
            dfs(n-1,j,at)

        return [(r,c) for r,c in at & pac]

        
# Complexity Analysis:

# Time complexity: O(M⋅N), where M is the number of rows and N is the number of columns.
# Similar to approach 1. The dfs function runs exactly once for each cell accessible from an ocean.

# Space complexity: O(M⋅N), where M is the number of rows and N is the number of columns.
# Similar to approach 1. Space that was used by our queues is now occupied by dfs calls on the recursion stack.
