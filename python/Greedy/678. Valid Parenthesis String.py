# https://leetcode.com/problems/valid-parenthesis-string/description/

'''
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "(*)"
Output: true
Example 3:
Input: s = "(*))"
Output: true

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.
'''

class Solution:
    def checkValidString(self, s: str) -> bool:
        cnt=0
        for ch in s:
            if ch=='(' or ch=='*':
                cnt+=1
            else:
                cnt-=1
                if cnt<0:
                    return False
        
        cnt=0
        for ch in s[::-1]:
            if ch==')' or ch=='*':
                cnt+=1
            else:
                cnt-=1
                if cnt<0:
                    return False
        return True
    
# Complexity Analysis
# Let n be the length of the input string.
# Time complexity: O(n)
# The time complexity is O(n), as we iterate through the string once.

# Space complexity: O(1)
# The space complexity is O(1), as we use a constant amount of extra space to store the openCount and closeCount variables.