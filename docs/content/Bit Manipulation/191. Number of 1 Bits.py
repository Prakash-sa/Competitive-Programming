# https://leetcode.com/problems/number-of-1-bits/description/

'''
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:

The input binary string 1011 has a total of three set bits.
Example 2:
Input: n = 128
Output: 1

Explanation:
The input binary string 10000000 has a total of one set bit.
Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:
1 <= n <= 231 - 1

Follow up: If this function is called many times, how would you optimize it?
'''

class Solution:
    def hammingWeight(self, n: int) -> int:
        ans=0
        while n:
            n&=(n-1)
            ans+=1
        return ans
        

# Complexity
# Time: O(k), where k = number of set bits (≤ 32 for int32)
# Space: O(1)


class Solution:
    def hammingWeight(self, n: int) -> int:
        return n.bit_count()


# Runs in O(1) for fixed-width integers.