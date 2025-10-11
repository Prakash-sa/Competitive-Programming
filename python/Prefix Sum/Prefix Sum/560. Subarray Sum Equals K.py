# https://leetcode.com/problems/subarray-sum-equals-k/description/

'''
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
'''

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        freq=defaultdict(int)
        sum1=ans=0
        freq[sum1]+=1
        for i in range(len(nums)):
            sum1+=nums[i]
            ans+=freq[sum1-k]
            freq[sum1]+=1
        return ans
        

# Complexity Analysis
# Time complexity : O(n). The entire nums array is traversed only once.
# Space complexity : O(n). Hashmap map can contain up to n distinct entries in the worst case
