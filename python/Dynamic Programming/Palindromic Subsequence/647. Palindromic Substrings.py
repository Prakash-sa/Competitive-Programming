# https://leetcode.com/problems/palindromic-substrings/description/

'''
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
'''

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0

        def expand(l: int, r: int) -> int:
            cnt = 0
            while l >= 0 and r < n and s[l] == s[r]:
                cnt += 1
                l -= 1
                r += 1
            return cnt

        for i in range(n):
            ans += expand(i, i)       # odd-length palindromes centered at i
            ans += expand(i, i + 1)   # even-length palindromes centered between i and i+1
        return ans
        
        
# Why it works
# There are 2n-1 possible centers.
# Each center expands at most O(n) total across all centers → overall O(n²).
# Complexity: Time O(n²), Space O(1).


# https://leetcode.com/problems/longest-palindromic-substring/description/

'''
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s

        start, end = 0, 1  # [start, end) best window so far

        def expand(l: int, r: int) -> None:
            nonlocal start, end
            while l >= 0 and r < n and s[l a] == s[r]:
                l -= 1
                r += 1
            # when loop breaks, palindrome is (l+1, r-1) => slice [l+1:r]
            if r - (l + 1) > end - start:
                start, end = l + 1, r

        for i in range(n):
            expand(i, i)       # odd-length center at i
            expand(i, i + 1)   # even-length center between i and i+1

        return s[start:end]


# Complexity
# Time: O(n2) in the worst case (e.g., all same chars).
# Space: 𝑂(1)
