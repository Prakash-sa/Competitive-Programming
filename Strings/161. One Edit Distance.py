# https://leetcode.com/problems/one-edit-distance/description/

'''
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.
A string s is said to be one distance apart from a string t if you can:
Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.

Constraints:
0 <= s.length, t.length <= 104
s and t consist of lowercase letters, uppercase letters, and digits.
'''

class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        ns,nt=len(s),len(t)

        if ns>nt:
            return self.isOneEditDistance(t,s)
        
        if ns-nt>1:
            return False
        
        for i in range(ns):
            if s[i]!=t[i]:
                if s[i+1:]==t[i+1:]:
                    return True
                elif s[i:]==t[i+1:]:
                    return True
                else:
                    return False

        return ns+1==nt

# Complexity Analysis

# Time complexity: O(N) in the worst case when string lengths are close enough abs(ns - nt) <= 1, where N is a number of characters in the longest string. O(1) in the best case when abs(ns - nt) > 1.
# Space complexity: O(N) because strings are immutable in Python and Java and create substring costs O(N) space.