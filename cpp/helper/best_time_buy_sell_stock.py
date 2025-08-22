# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if (len(prices) == 1):
            return 0
        l, r = 0, 1
        max = 0

        while r < len(prices):
            vl = prices[l]
            vr = prices[r]
            curr = vr - vl
            if (curr > max):
                max = curr

            if (vr < vl):
                l = r

            r += 1

        return max

# time complexity O(n)
# space complexity O(1)
