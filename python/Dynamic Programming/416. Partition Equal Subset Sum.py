# https://leetcode.com/problems/partition-equal-subset-sum/description/

'''
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
'''

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n=len(nums)
        total=sum(nums)
        if total%2!=0:
            return False

        subset_sum=total//2

        dp=[False]*(subset_sum+1)
        dp[0]=True

        for curr in nums:
            for j in range(subset_sum,curr-1,-1):
                dp[j]=dp[j] or dp[j-curr]
        
        return dp[subset_sum]
        
# Complexity Analysis
# Time Complexity : O(m⋅n), where m is the subSetSum, and n is the number of array elements. The time complexity is the same as Approach 3.
# Space Complexity: O(m), As we use an array of size m to store the result of subproblems.