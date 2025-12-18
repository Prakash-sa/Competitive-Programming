# https://leetcode.com/problems/valid-triangle-number/description/

'''
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle. 

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
'''

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        cnt=0
        for k in range(2,n):
            i,j=0,k-1
            while i<j:
                if nums[i]+nums[j]>nums[k]:
                    cnt+=(j-i)
                    j-=1
                else:
                    i+=1
        return cnt


# Complexity Analysis
# Time complexity : O(nlogn+n^2)=O(n^2).
# Space complexity : O(logn). Sorting takes O(logn) space.