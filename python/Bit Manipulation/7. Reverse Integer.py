# https://leetcode.com/problems/reverse-integer/description/

'''
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321
Example 2:
Input: x = -123
Output: -321
Example 3:
Input: x = 120
Output: 21

Constraints:
-231 <= x <= 231 - 1
'''

class Solution:
    def reverse(self, x: int) -> int:
        neg=1
        if x<0:
            neg=-1
            x=-1*x
        new_n=0
        while x:
            tmp=x%10
            new_n=new_n*10+tmp
            x//=10
            if new_n>2**31-1:
                return 0
        return new_n*neg
    
# Complexity Analysis

# Time Complexity: O(log(x)). There are roughly log 10(x) digits in x.
# Space Complexity: O(1).