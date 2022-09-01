//https://leetcode.com/problems/reordered-power-of-2/

/*
You are given an integer n. We reorder the digits in any order 
(including the original order) such that the leading digit is not zero.
Return true if and only if we can do this so that the resulting number is a power of two. 

Example 1:

Input: n = 1
Output: true

Example 2:

Input: n = 10
Output: false
*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int k=counter(n);
        for(int i=0;i<32;i++){
            if(counter(1<<i)==k)return true;
        }
        return false;
    }
    
    long counter(int n){
        long ans=0;
        for(;n;n/=10){
            ans+=pow(10,n%10);
        }    
        return ans;
    }
};


