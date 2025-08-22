//https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

/*
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.


Let f(n) be the answer. sum_len(a, b) = sum( len(i) | a <= i <= b) and len(i) is the number of bits in i.

For example: len(1) = 1, len(3) = 2, len(6) = 3. sum_len(1,4) = len(1) + len(2) + len(3) + len(4) = 1 + 2 + 2 + 3 = 8.

So we have

f(n)   = (1 << sum_len(2, n))   + (2 << sum_len(3, n))   + ... + ((n - 1) << sum_len(n, n)) + (n << 0)

// Example: f(4) = 11011100 = (1 << (2+2+3)) + (2 << (2+3)) + (3 << 3) + (4 << 0)

f(n-1) = (1 << sum_len(2, n-1)) + (2 << sum_len(3, n-1)) + ... + ((n - 1) << 0)

f(n) = (f(n-1) << len(n)) + n
*/


class Solution {
public:
    int concatenatedBinary(int n) {
        long sum=0;
        int mod=1e9+7;
        int length=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                length++;
            }
            sum=((sum<<length)|i)%mod;
        }
        return sum;
    }
};