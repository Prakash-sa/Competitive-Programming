# https://leetcode.com/problems/coin-change/description/

'''
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:
Input: coins = [2], amount = 3
Output: -1
Example 3:
Input: coins = [1], amount = 0
Output: 0
 

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
'''

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[float('inf')]*(amount+1)
        dp[0]=0

        for coin in coins:
            for j in range(coin,amount+1):
                dp[j]=min(dp[j],dp[j-coin]+1)
        return dp[amount] if dp[amount]!=float('inf') else -1

# Complexity Analysis
# Time complexity : O(S∗n).
# On each step the algorithm finds the next F(i) in n iterations, where 1≤i≤S. Therefore in total the iterations are S∗n.
# Space complexity : O(S).
# We use extra space for the memoization table.
# In the example above you can see that:

# F(3)​=min{F(3−c1),F(3−c2),F(3−c3)}+1
# =min{F(3−1),F(3−2),F(3−3)}+1
# =min{F(2),F(1),F(0)}+1
# =min{1,1,0}+1
# =1
# ​
 
