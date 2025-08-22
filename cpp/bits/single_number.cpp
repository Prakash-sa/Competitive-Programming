//https://leetcode.com/problems/single-number-iii/
//https://www.thecodingshala.com/2021/02/single-number-3-leetcode-solution.html

/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first=0,sec=0,allnum=0;
        for(auto it:nums)allnum^=it;
        int shift=1;
        for(int i=0;i<32;i++){
            if(allnum&(1<<i)){
                shift=i;
                break;
            }
        }
        for(auto it:nums){
            if(it&(1<<shift))first^=it;
            else sec^=it;
        }
        return {first,sec};
    }
};
