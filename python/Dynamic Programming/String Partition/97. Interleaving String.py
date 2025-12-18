# https://leetcode.com/problems/interleaving-string/description/
# https://www.youtube.com/watch?v=ih2OZ9-M3OM

'''
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 
Follow up: Could you solve it using only O(s2.length) additional memory space?
'''

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3)!=len(s1)+len(s2):
            return False
        dp=[[False]*(len(s2)+1) for _ in range(len(s1)+1)]
        for i in range(len(s1)+1):
            for j in range(len(s2)+1):
                if i==0 and j==0:
                    dp[i][j]=True
                elif i==0:
                    dp[i][j]=dp[i][j-1] and s2[j-1]==s3[i+j-1]
                elif j==0:
                    dp[i][j]=dp[i-1][j] and s1[i-1]==s3[i+j-1]
                else:
                    dp[i][j]=(
                        dp[i-1][j] and s1[i-1]==s3[i+j-1]
                    ) or (dp[i][j-1] and s2[j-1]==s3[i+j-1])
        return dp[len(s1)][len(s2)]


# Complexity Analysis
# Time complexity : O(m⋅n). dp array of size m∗n is filled.
# Space complexity : O(m⋅n). 2D dp of size (m+1)∗(n+1) is required. m and n are the lengths of strings s1 and s2 respectively.


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3)!=len(s1)+len(s2):
            return False
        dp=[False]*(len(s2)+1)
        for i in range(len(s1)+1):
            for j in range(len(s2)+1):
                if i==0 and j==0:
                    dp[j]=True
                elif i==0:
                    dp[j]=dp[j-1] and s2[j-1]==s3[i+j-1]
                elif j==0:
                    dp[j]=dp[j] and s1[i-1]==s3[i+j-1]
                else:
                    dp[j]=(
                        dp[j] and s1[i-1]==s3[i+j-1]
                    ) or (dp[j-1] and s2[j-1]==s3[i+j-1])
        return dp[len(s2)]


# Complexity Analysis
# Time complexity : O(m⋅n). dp array of size n is filled m times.
# Space complexity : O(n). n is the length of the string s1.
