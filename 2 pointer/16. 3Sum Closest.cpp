//https://leetcode.com/problems/3sum-closest/

/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return -1;
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int first=0;first<nums.size()-2;first++){
            if(first>0 && nums[first]==nums[first-1])continue;
            int second=first+1;
            int third=nums.size()-1;
            
            while(second<third){
                int cursum=nums[first]+nums[second]+nums[third];
                if(cursum==target)return cursum;
                if(abs(cursum-target)<abs(closest-target))closest=cursum;
                else if(cursum>target)third--;
                else second++;
            }
            
        }
        return closest;
    }
};


