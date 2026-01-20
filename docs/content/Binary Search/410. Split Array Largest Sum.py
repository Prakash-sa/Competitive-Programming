# https://leetcode.com/problems/split-array-largest-sum/description/

'''
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array. 

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
'''


class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def min_subarray(max_sum):
            cur_sum=0
            splits=0
            for num in nums:
                if cur_sum+num<=max_sum:
                    cur_sum+=num
                else:
                    cur_sum=num
                    splits+=1
            return splits+1
        
        l,r=max(nums),sum(nums)
        min_largest=0
        while l<=r:
            max_sum=(l+r)//2
            if min_subarray(max_sum)<=k:
                r=max_sum-1
                min_largest=max_sum
            else:
                l=max_sum+1
        return min_largest

# Complexity Analysis
# Here N is the length of the array and S is the sum of integers in the array.

# Time complexity: O(N⋅log(S))
# The total number of iterations in the binary search is log(S), and for each such iteration, we call minimumSubarraysRequired which takes O(N) time. Hence, the time complexity is equal to O(N⋅log(S)).

# Space complexity: O(1)
# We do not use any data structures that require more than constant extra space.
