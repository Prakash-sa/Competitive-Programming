# https://leetcode.com/problems/reverse-bits/description/

'''
Reverse bits of a given 32 bits signed integer.

 

Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:

Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110
 

Constraints:

0 <= n <= 231 - 2
n is even.
 

Follow up: If this function is called many times, how would you optimize it?
'''

class Solution:
    def reverseBits(self, n: int) -> int:
        result=0
        for i in range(32):
            result=(result<<1)|(n&1)
            n>>=1
        return result

# Complexity:
# Time Complexity: O(1). Though we have a loop in the algorithm, the number of iteration is fixed regardless the input, since the integer is of fixed-size (32-bits) in our problem.
# Space Complexity: O(1), since the consumption of memory is constant regardless the input.


class Solution:
    def __init__(self):
        self.cache = {}

    def reverseByte(self, byte: int) -> int:
        if byte in self.cache:
            return self.cache[byte]
        rev = 0
        b = byte
        for i in range(8):
            rev = (rev << 1) | (b & 1)
            b >>= 1
        self.cache[byte] = rev
        return rev

    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(4):  # 4 bytes × 8 bits = 32 bits
            byte = (n >> (i * 8)) & 0xff
            result = (result << 8) | self.reverseByte(byte)
        return result
