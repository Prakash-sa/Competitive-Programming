# https://leetcode.com/problems/valid-palindrome-ii/description/

'''
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true
Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:
Input: s = "abc"
Output: false

Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
'''

class Solution:
    def validPalindrome(self, s: str) -> bool:
        n=len(s)
        l,r=0,n-1

        def check(x,y):
            while x<=y:
                if s[x]!=s[y]:
                    return False
                x+=1
                y-=1
            return True

        while l<=r:
            if s[l]!=s[r]:
                return check(l,r-1) or check(l+1,r)
            l+=1
            r-=1
        
        return True
        
# Complexity Analysis
# Given N as the length of s,
# Time complexity: O(N).
# The main while loop we use can iterate up to N / 2 times, since each iteration represents a pair of characters. On any given iteration, we may find a mismatch and call checkPalindrome twice. checkPalindrome can also iterate up to N / 2 times, in the worst case where the first and last character of s do not match.
# Because we are only allowed up to one deletion, the algorithm only considers one mismatch. This means that checkPalindrome will never be called more than twice.
# As such, we have a time complexity of O(N).

# Space complexity: O(1).
# The only extra space used is by the two pointers i and j, which can be considered constant relative to the input size.