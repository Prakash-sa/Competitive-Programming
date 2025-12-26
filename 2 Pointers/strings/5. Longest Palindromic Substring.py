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
        n=len(s)
        if n<2:
            return s
        
        start,end=0,1

        def expand(l,r):
            nonlocal start,end
            while l>=0 and r<n and s[l]==s[r]:
                l-=1
                r+=1
            if r-l-1>end-start:
                end=r
                start=l+1

        for i in range(n):
            expand(i,i)
            expand(i,i+1)
        
        return s[start:end]


# Complexity Analysis

# Given n as the length of s,
# Time complexity: O(n*2)
# There are 2n−1=O(n) centers. For each center, we call expand, which costs up to O(n).
# Although the time complexity is the same as in the DP approach, the average/practical runtime of the algorithm is much faster. This is because most centers will not produce long palindromes, so most of the O(n) calls to expand will cost far less than n iterations.
# The worst case scenario is when every character in the string is the same.

# Space complexity: O(1)
# We don't use any extra space other than a few integers. This is a big improvement on the DP approach.



class Solution:
    def longestPalindrome(self, s: str) -> str:
        def check(i,j):
            left=i
            right=j-1

            while left<right:
                if s[left]!=s[right]:
                    return False
                left+=1
                right-=1
            
            return True

        for length in range(len(s),0,-1):
            for start in range(len(s)-length+1):
                if check(start,start+length):
                    return s[start:start+length]
        return ""


# Complexity Analysis

# Given n as the length of s,
# Time complexity: O(n*3)
# The two nested for loops iterate O(n2 ) times. We check one substring of length n, two substrings of length n - 1, three substrings of length n - 2, and so on.

# There are n substrings of length 1, but we don't check them all since any substring of length 1 is a palindrome, and we will return immediately.
# Therefore, the number of substrings that we check in the worst case is 1 + 2 + 3 + ... + n - 1. This is the partial sum of this series for n - 1, which is equal to  2n⋅(n−1)​=O(n2).

# In each iteration of the while loop, we perform a palindrome check. The cost of this check is linear with n as well, giving us a time complexity of O(n 3 ).
# Note that this time complexity is in the worst case and has a significant constant divisor that is dropped by big O. Due to the optimizations of checking the longer length substrings first and exiting the palindrome check early if we determine that a substring cannot be a palindrome, the practical runtime of this algorithm is not too bad.

# Space complexity: O(1)
# We don't count the answer as part of the space complexity. Thus, all we use are a few integer variables.
