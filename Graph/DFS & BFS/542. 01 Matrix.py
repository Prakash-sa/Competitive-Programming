# https://leetcode.com/problems/01-matrix/description/

'''
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
'''

from heapq import heappush,heappop

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        if not mat or not mat[0]:
            return []

        directions=[(-1,0),(1,0),(0,1),(0,-1)]
        n,m=len(mat),len(mat[0])

        def is_valid(x,y):
            return 0<=x<n and 0<=y<m

        res=[[-1]*m for _ in range(n)]
        queue=deque()

        for r,c in product(range(n),range(m)):
            if mat[r][c]==0:
                res[r][c]=0
                queue.append((r,c))
        while queue:
            r,c=queue.popleft()

            for dr,dc in directions:
                nr,nc=r+dr,c+dc

                if is_valid(nr,nc) and mat[nr][nc]==1 and res[nr][nc]==-1:
                    res[nr][nc]=res[r][c]+1
                    queue.append((nr,nc))


        return res



# Complexity Analysis
# Given m as the number of rows and n as the number of columns,

# Time complexity: O(m⋅n)
# We iterate over m⋅n cells twice, performing constant work at each iteration.

# Space complexity: O(m⋅n)
# As discussed above, some people may choose to reuse mat as dp.
# A common misconception is that it would be O(1) space. It would only be O(1) auxiliary space,
# but as we are modifying the input and using it in the algorithm, it must be included in the space complexity. Again, it is not considered good practice to modify the input anyways, which is why we are creating dp, which uses O(m⋅n) space.