# https://leetcode.com/problems/word-break/description/

'''
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 
Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
'''



from typing import List
class Solution:
    def wordBreak(self,s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        if not word_set:
            return False

        # Length pruning to reduce checks
        lens = {len(w) for w in word_set}
        max_len = max(lens)

        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True  # empty prefix is breakable

        for i in range(1, n + 1):
            # Only try segment lengths that exist in the dict and fit
            for L in lens:
                if L <= i and dp[i - L] and s[i - L:i] in word_set:
                    dp[i] = True
                    break  # early exit once true

        return dp[n]

# Complexity Analysis
# Given n as the length of s, m as the length of wordDict, and k as the average length of the words in wordDict,
# Time complexity: O(n⋅m⋅k)
# The logic behind the time complexity is identical to the previous approach. It costs us O(m⋅k) to calculate each state, and we calculate O(n) states in total.

# Space complexity: O(n)
# We use an array dp of length n.