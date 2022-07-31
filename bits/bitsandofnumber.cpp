//https://leetcode.com/problems/bitwise-and-of-numbers-range/

/*
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.
 

Example 1:

Input: left = 5, right = 7
Output: 4
*/




class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if((left&(1<<i))!=(right&(1<<i)))break;
            else ans=ans|(left&(1<<i));
        }
        return ans;
    }
};
