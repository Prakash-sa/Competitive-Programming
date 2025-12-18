# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
# https://www.youtube.com/watch?v=I7j0F7AHpb8

'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:
Input: prices = [1]
Output: 0

Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
'''



class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        
        @lru_cache(maxsize=None)
        def dfs(i,buying):
            if i>=n:
                return 0
            total=0
            cooldown=dfs(i+1,buying)
            if buying:
                buy=dfs(i+1,not buying)-prices[i]
                total=max(total,buy,cooldown)
            else:
                sold=dfs(i+2,not buying)+prices[i]
                total=max(total,sold,cooldown)
            return total

        return dfs(0,True)

# TC: O(n)
# SC: O(n)
