//https://leetcode.com/problems/power-of-three/


/*
The positive divisors of 319 are exactly the powers of 3 from 30 to 319. 
That's all powers of 3 in the possible range here (signed 32-bit integer). 
So just check whether the number is positive and whether it divides 319.

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467%n==0;
    }
};

