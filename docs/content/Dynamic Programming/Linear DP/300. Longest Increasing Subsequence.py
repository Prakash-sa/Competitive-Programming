# https://leetcode.com/problems/longest-increasing-subsequence/description/

'''
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
'''

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[1]*(n)
        ans=1

        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if nums[i]>nums[j]:
                    dp[i]=max(dp[i],dp[j]+1)
                ans=max(ans,dp[i])
        return ans


# Complexity Analysis
# Given N as the length of nums,
# Time complexity: O(N^2)

# Space complexity: O(N)
# The only extra space we use relative to input size is the dp array, which is the same length as nums.

from bisect import bisect_left
from collections import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub=[]
        for num in nums:
            i=bisect_left(sub,num)
            if i==len(sub):
                sub.append(num)
            else:
                sub[i]=num
        return len(sub)


# Complexity Analysis
# Given N as the length of nums,
# Time complexity: O(N⋅log(N))
# Binary search uses log(N) time as opposed to the O(N) time of a linear scan, which improves our time complexity from O(N^2) to O(N⋅log(N)).

# Space complexity: O(N)
# When the input is strictly increasing, the sub array will be the same size as the input.
