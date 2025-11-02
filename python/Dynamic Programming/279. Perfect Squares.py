# https://leetcode.com/problems/perfect-squares/description/

'''
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

Constraints:
1 <= n <= 104
'''

import math

class Solution:
    def numSquares(self, n: int) -> int:
        nums=[i*i for i in range(0,int(math.sqrt(n))+1)]
        
        dp=[float('inf')]*(n+1)
        dp[0]=0

        for i in range(n+1):
            for square in nums:
                if i<square:
                    break
                dp[i]=min(dp[i],dp[i-square]+1)
        return dp[-1]

# Complexity
# Time complexity: O(n⋅n). In main step, we have a nested loop, where the outer loop is of n iterations and in the inner loop it takes at maximum n  iterations.
# Space Complexity: O(n). We keep all the intermediate sub-solutions in the array dp[].
