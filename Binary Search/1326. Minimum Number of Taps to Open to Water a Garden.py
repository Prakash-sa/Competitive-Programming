# https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

'''
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).
There are n + 1 taps located at points [0, 1, ..., n] in the garden.
Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.
Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
Example 2:
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.
 

Constraints:
1 <= n <= 104
ranges.length == n + 1
0 <= ranges[i] <= 100
'''

class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        reach=[0]*(n+1)
        for i in range(len(ranges)):
            start=max(0,i-ranges[i])
            end=min(n,i+ranges[i])
            reach[start]=max(reach[start],end)

        cur=0
        next_s=0
        tap=0
        for i in range(n+1):
            if i>next_s:
                return -1

            if i>cur:
                tap+=1
                cur=next_s
            next_s=max(next_s,reach[i])

        return tap


# Complexity Analysis
# Time Complexity: O(n).
# We iterate through the garden once to calculate the maximum reach for each position, and then iterate through the garden again to choose the taps and determine the minimum number of taps required. The iteration involves visiting each position in the garden once, resulting in a linear time complexity.

# Space Complexity: O(n).
# We use additional space to store the max_reach array of size n+1. Therefore, the space complexity is linear with respect to the size of the garden.