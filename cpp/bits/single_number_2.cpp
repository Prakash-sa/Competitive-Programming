//https://stackoverflow.com/questions/21297067/single-number-ii-from-leetcode
//https://leetcode.com/problems/single-number-ii/submissions/

/*
Given an integer array nums where every element appears three times except for one, 
which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0,sec=0;
        for(auto it:nums){
            first=(first^it)&(~sec);
            sec=(sec^it)&(~first);
        }
        return first;
        
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0,sec=0;
        int cnt=0;
        for(int i=0;i<32;i++){
            int mask=(1<<i);
            cnt=0;
            for(auto it:nums){
                if(it&mask)cnt++;
            }
            if(cnt%3==1){
                first|=mask;
            }
        }
        
        return first;
    }
};
