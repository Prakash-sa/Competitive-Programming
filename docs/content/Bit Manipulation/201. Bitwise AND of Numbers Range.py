# https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

'''
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4
Example 2:
Input: left = 0, right = 0
Output: 0
Example 3:
Input: left = 1, right = 2147483647
Output: 0

Constraints:
0 <= left <= right <= 231 - 1
'''


class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while left<right:
            right=right&(right-1)
        return right


# Complexity Analysis
# Time Complexity: O(1).
# Similar to the bit shift approach, the number of iterations in the algorithm is bounded by the number of bits in an integer number, which is constant.
# Though having the same asymptotic complexity as the bit shift approach, Brian Kernighan's algorithm requires fewer iterations, since it skips all the zero bits in between.

# Space Complexity: O(1), since no additional memory is consumed by the algorithm.
