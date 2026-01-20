# https://leetcode.com/problems/sum-of-two-integers/description/

'''
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3
Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
-1000 <= a, b <= 1000
'''

class Solution:
    def getSum(self, a: int, b: int) -> int:
        x,y=abs(a),abs(b)

        if x<y:
            return self.getSum(b,a)
        
        sign=1 if a>0 else -1

        if a*b>=0:
            while y:
                answer=x^y
                carry=(x&y)<<1
                x,y=answer,carry
        else:
            while y:
                answer=x^y
                borrow=((~x)&y)<<1
                x,y=answer,borrow
        return x*sign


# Complexity Analysis:
# Time complexity: O(1) because each integer contains 32 bits.
# Space complexity: O(1) because we don't use any additional data structures.
