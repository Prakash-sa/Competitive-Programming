# https://leetcode.com/problems/edit-distance/description/

'''
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
 
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
'''

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n,m=len(word1),len(word2)
        if n==0 or m==0:
            return max(n,m)
        
        dp=[[0]*(m+1) for _ in range(n+1)]

        for i in range(n+1):
            dp[i][0]=i
        
        for j in range(m+1):
            dp[0][j]=j

        for i in range(1,n+1):
            for j in range(1,m+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1

        return dp[n][m]


# Complexity Analysis
# Let M be the length of string word1 and N be the length of string word2.
# Time Complexity: O(M⋅N)
# In the nested for loop, the outer loop iterates M times, and the inner loop iterates N times.
# Thus, the time complexity is O(M⋅N).

# Space Complexity: O(M⋅N)
# The space is for the additional 2-dimensional array dp of size (M⋅N).
