# https://leetcode.com/problems/distinct-subsequences/description/
# https://www.youtube.com/watch?v=A5IBp1ldlik

'''
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.
'''


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m=len(t)
        n=len(s)
        if n<m:
            return 0
        dp=[0]*(m+1)
        dp[0]=1

        for ch in s:
            for j in range(m,0,-1):
                if ch==t[j-1]:
                    dp[j]+=dp[j-1]
        return dp[m]
        
# dp(i-1)(j-1) and dp(i-1)(j)
# dp(i-1)(j-1)
