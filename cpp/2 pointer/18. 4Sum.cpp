//https://leetcode.com/problems/4sum/


/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/



class Solution {
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<4)return ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int l=j+1,r=n-1;
                long int Ntarget=(long int)target-(nums[i]+nums[j]);
                while(l<r){
                    int leftelem=nums[l];
                    int rightelem=nums[r];
                    if(nums[l]+nums[r]==Ntarget){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==leftelem)l++;
                        while(l<r && nums[r]==rightelem)r--;
                        // break;
                    }
                    else if(nums[l]+nums[r]>Ntarget){
                        while(l<r && nums[r]==rightelem)r--;   
                    }
                    else {
                        while(l<r && nums[l]==leftelem)l++;   
                    }
                }
            }
        }
        return ans;
    }
};
