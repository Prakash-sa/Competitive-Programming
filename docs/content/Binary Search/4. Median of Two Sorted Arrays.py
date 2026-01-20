# https://leetcode.com/problems/median-of-two-sorted-arrays/description/

'''
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
'''

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1)>len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)
        m,n=len(nums1),len(nums2)
        l,r=0,m

        while l<=r:
            pa=(l+r)//2
            pb=(m+n+1)//2-pa

            maxA=-math.inf if pa==0 else nums1[pa-1]
            minA=math.inf if pa==m else nums1[pa]
            maxB=-math.inf if pb==0 else nums2[pb-1]
            minB=math.inf if pb==n else nums2[pb]

            if maxA<=minB and maxB<=minA:
                if (m+n)%2==0:
                    return (max(maxA,maxB)+min(minA,minB))/2
                else:
                    return max(maxA,maxB)
            elif maxA>minB:
                r=pa-1
            else:
                l=pa+1


# Complexity Analysis
# Let m be the size of array nums1 and n be the size of array nums2.

# Time complexity: O(log(min(m,n)))

# We perform a binary search over the smaller array of size min(m,n).
# Space complexity: O(1)

# The algorithm only requires a constant amount of additional space to store and update a few parameters during the binary search.