# https://leetcode.com/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27

'''
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.

Example 2:
Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000
 

Constraints:
3 <= points.length <= 50
-50 <= xi, yi <= 50
All the given points are unique.
'''

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        n=len(points)
        ans=0.0
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    area=abs(points[i][0]*(points[j][1]-points[k][1])+points[j][0]*(points[k][1]-points[i][1])+points[k][0]*(points[i][1]-points[j][1]))/2.0
                    ans=max(ans,area)
        return ans

# You can calculate the area of a triangle constructed on 3 points (x1,y1), (x2,y2), and (x3,y3) using Shoelace's Formula (also known as Gauss's area formula and surveyor's formula):
# Area = (1/2) * |x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)|


# Complexity Analysis
# Time Complexity: O(N^3), where N is the length of points. We use three for-loops of length O(N), and our work calculating the area of a single triangle is O(1).
# Space Complexity: O(1)
