# https://leetcode.com/problems/path-with-minimum-effort/description/

'''
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort. 

Constraints:
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
'''


## Dijkastra
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        h=[[0,0,0]]
        n,m=len(heights),len(heights[0])
        vis=set()

        directions=[[1,0],[-1,0],[0,1],[0,-1]]

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m

        while h:
            diff,r,c=heappop(h)
            if r==n-1 and c==m-1:
                return diff
            if (r,c) in vis:
                continue
            vis.add((r,c))

            for dr,dc in directions:
                nr,nc=dr+r,dc+c
                if is_valid(nr,nc):
                    hdiff=max(diff,abs(heights[r][c]-heights[nr][nc]))
                    heappush(h,[hdiff,nr,nc])
        return -1

# Complexity Analysis

# Time Complexity : O(m⋅nlog(m⋅n)), where m is the number of rows and n is the number of columns in matrix heights.
# It will take O(m⋅n) time to visit every cell in the matrix. The priority queue will contain at most m⋅n cells, so it will take O(log(m⋅n)) time to re-sort the queue after every adjacent cell is added to the queue.
# This given as total time complexiy as O(m⋅nlog(m⋅n)).

# Space Complexity: O(m⋅n), where m is the number of rows and n is the number of columns in matrix heights.
# The maximum queue size is equal to the total number of cells in the matrix height which is given by m⋅n. Also, we use a difference matrix of size m⋅n. This gives as time complexity as O(m⋅n+m⋅n) = O(m⋅n)



# Binary Search with DFS
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < m
        
        def canReachWithEffort(max_effort):
            """DFS to check if we can reach bottom-right with given max_effort"""
            if n == 1 and m == 1:
                return True
                
            visited = set()
            stack = [(0, 0)]
            visited.add((0, 0))
            
            while stack:
                r, c = stack.pop()
                
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if is_valid(nr, nc) and (nr, nc) not in visited:
                        # Check if the effort to move to this cell is within limit
                        effort = abs(heights[r][c] - heights[nr][nc])
                        if effort <= max_effort:
                            if nr == n - 1 and nc == m - 1:
                                return True
                            visited.add((nr, nc))
                            stack.append((nr, nc))
            
            return False
        
        # Binary search on the answer
        left, right = 0, 10**6  # max possible effort based on constraints
        result = right
        
        while left <= right:
            mid = (left + right) // 2
            if canReachWithEffort(mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return result


# Complexity Analysis
# Time Complexity : O(m⋅n). As in Approach 4. The only difference is that we are using Depth First Search instead of Breadth First Search and have similar time complexity.
# Space Complexity: O(m⋅n), As in Approach 4. In Depth First Search, we use the internal call stack (instead of the queue in Breadth First Search).

