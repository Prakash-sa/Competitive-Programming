# https://leetcode.com/problems/regular-expression-matching/description/
# https://www.youtube.com/watch?v=HAA8mgxlov8

'''
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
'''

from functools import lru_cache

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        @lru_cache(None)
        def dp(i, j):
            if j==len(p) and i==len(s):
                return True

            first_match=i<len(s) and (p[j] == s[i] or p[j]=='.')

            if j+1<len(p) and p[j+1]=='*':
                return dp(i,j+2) or (first_match and dp(i+1,j))
            
            if first_match:
                return dp(i+1,j+1)
            return False

        return dp(0,0)
