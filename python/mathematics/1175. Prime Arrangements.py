# https://leetcode.com/problems/prime-arrangements/description/

'''
Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Example 2:
Input: n = 100
Output: 682289015
 

Constraints:
1 <= n <= 100
'''

class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        is_prime=[False,False]+[True]*(n-1)
        MOD=10**9+7

        for x in range(2,int(n**0.5)+1):
            if is_prime[x]:
                step=x
                start=x*x
                for y in range(start,n+1,step):
                    is_prime[y]=False

        p=sum(is_prime)

        def fact(m):
            res=1
            for i in range(2,m+1):
                res=(res*i)%MOD
            return res

        return (fact(p)*fact(n-p))%MOD
    
# Time: O(n log log n) to sieve + O(n) for factorials

# Space: O(n)