# https://leetcode.com/problems/integer-break/description/
# https://www.youtube.com/watch?v=61kuCyvWWhI

'''
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:
2 <= n <= 58
'''

class Solution:
    def integerBreak(self, n: int) -> int:
        dp=[1]*(n+1)

        for i in range(1,n+1):
            for j in range(1,i+1 if i!=n else i):
                dp[i]=max(dp[i],dp[i-j]*j)
        return dp[-1]
        
# Complexity Analysis

# Time complexity: O(n*2)
# There are O(n) possible states of num that dp can be called with. We only calculate each state once, as we calculate one state per outer for loop iteration. To calculate a state, we iterate from 2 until num, which costs up to O(n). Thus, we have a time complexity of O(n*2).

# Space complexity: O(n)
# The table dp requires O(n) space.
