# https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/

'''
You are given two integers, m and k, and an integer array nums.

A sequence of integers seq is called magical if:
seq has a size of m.
0 <= seq[i] < nums.length
The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).

Return the sum of the array products for all valid magical sequences.

Since the answer may be large, return it modulo 109 + 7.

A set bit refers to a bit in the binary representation of a number that has a value of 1.

 

Example 1:

Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]

Output: 991600007

Explanation:

All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 1013.

Example 2:

Input: m = 2, k = 2, nums = [5,4,3,2,1]

Output: 170

Explanation:

The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4, 0], [4, 1], [4, 2], and [4, 3].

Example 3:
Input: m = 1, k = 1, nums = [28]
Output: 28
Explanation:
The only magical sequence is [0].

 

Constraints:
1 <= k <= m <= 30
1 <= nums.length <= 50
1 <= nums[i] <= 108
'''

from functools import lru_cache
from typing import List

MOD = 10**9 + 7

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)

        # factorials for nCr up to m
        fact = [1] * (m + 1)
        for i in range(1, m + 1):
            fact[i] = fact[i - 1] * i % MOD

        invfact = [1] * (m + 1)
        invfact[m] = pow(fact[m], MOD - 2, MOD)
        for i in range(m, 0, -1):
            invfact[i - 1] = invfact[i] * i % MOD

        def C(a: int, b: int) -> int:
            if b < 0 or b > a:
                return 0
            return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD

        # precompute nums[i]^t
        powtab = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for t in range(1, m + 1):
                powtab[i][t] = (powtab[i][t - 1] * nums[i]) % MOD

        @lru_cache(maxsize=None)
        def dp(i: int, rem: int, carry: int, kleft: int) -> int:
            if kleft < 0:
                return 0
            if i == n:
                if rem != 0:
                    return 0
                # after last index, remaining set bits must equal popcount(carry)
                return 1 if kleft == carry.bit_count() else 0

            ans = 0
            for t in range(rem + 1):
                ones_i = (carry + t) & 1
                new_carry = (carry + t) >> 1
                term = C(rem, t) * powtab[i][t] % MOD
                ans = (ans + term * dp(i + 1, rem - t, new_carry, kleft - ones_i)) % MOD
            return ans

        return dp(0, m, 0, k) % MOD


