# https://leetcode.com/problems/longest-valid-parentheses/description/

'''
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:
Input: s = ""
Output: 0
 

Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
'''

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans=0
        stack=[]
        stack.append(-1)
        for i in range(len(s)):
            if s[i]=='(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    ans=max(ans,i-stack[-1])
        return ans

# Complexity Analysis
# Time complexity: O(n). Single traversal of string to fill dp array is done.
# Space complexity: O(n). dp array of size n is used.