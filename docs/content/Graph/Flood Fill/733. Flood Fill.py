# https://leetcode.com/problems/flood-fill/description/

'''
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill:
Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill. 

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]

Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

 

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
'''

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        visited=set()
        direction=[(-1,0),(1,0),(0,1),(0,-1)]
        n=len(image)
        m=len(image[0])
        k=image[sr][sc]

        def is_valid(r,c):
            if 0<=r<n and 0<=c<m and image[r][c]==k:
                return True
            return False

        def dfs(row,col):
            if (row,col) in visited:
                return
            visited.add((row,col))
            image[row][col]=color

            for r,c in direction:
                d_r=row+r
                d_y=col+c
                if is_valid(d_r,d_y):
                    dfs(d_r,d_y)
        dfs(sr,sc)
        return image


# Complexity Analysis
# Time Complexity: O(N), where N is the number of pixels in the image. We might process every pixel.
# Space Complexity: O(N), the size of the implicit call stack when calling dfs.
