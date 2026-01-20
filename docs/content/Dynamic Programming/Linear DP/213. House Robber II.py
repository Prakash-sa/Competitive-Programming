# https://leetcode.com/problems/house-robber-ii/description/

'''
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:
Input: nums = [1,2,3]
Output: 3
 

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000
'''

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==0 or nums is None:
            return 0
        
        if len(nums)==1:
            return nums[0]

        def house_robber(new_nums):
            n=len(new_nums)
            if n==1:
                return new_nums[0]
            dp=[0]*n
            dp[0]=new_nums[0]
            dp[1]=max(new_nums[1],new_nums[0])

            for i in range(2,n):
                dp[i]=max(dp[i-1],new_nums[i]+dp[i-2])

            return dp[n-1]
        
        return max(house_robber(nums[:-1]),house_robber(nums[1:]))


# Complexity Analysis

# Time complexity : O(N) where N is the size of nums. We are accumulating results as we are scanning nums.

# Space complexity : O(1) since we are not consuming additional space other than variables for two previous results and a temporary variable to hold one of the previous results.