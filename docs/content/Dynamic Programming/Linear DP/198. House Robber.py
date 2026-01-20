# https://leetcode.com/problems/house-robber/description/

'''
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
'''

class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=1:
            return nums[0]
        dp=[nums[i] for i in range(n)]
        dp[1]=max(dp[1],dp[0])
        for i in range(2,n):
            dp[i]=max(dp[i-1],dp[i]+dp[i-2])
        return dp[n-1]
    

# Complexity Analysis
# Time Complexity: O(N) since we have a loop from N−2⋯0 and we simply use the pre-calculated values of our dynamic programming table for calculating the current value in the table which is a constant time operation.
# Space Complexity: O(N) which is used by the table. So what is the real advantage of this solution over the previous solution? In this case, we don't have a recursion stack. When the number of houses is large, a recursion stack can become a serious limitation, because the recursion stack size will be huge and the compiler will eventually run into stack-overflow problems (no pun intended!).