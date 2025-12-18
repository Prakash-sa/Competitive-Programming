# https://leetcode.com/problems/valid-parentheses/description/

'''
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false

 

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
'''

class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        mapping ={')':'(','}':'{',']':'['}
        
        for char in s:
            if char in mapping:
                top_element= stack.pop() if stack else '#'
                if mapping[char]!=top_element:
                    return False
            else:
                stack.append(char)
        return not stack

# Complexity analysis

# Time complexity : O(n) because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1) time.
# Space complexity : O(n) as we push all opening brackets onto the stack and in the worst case, we will end up pushing all the brackets onto the stack. e.g. ((((((((((.
