//https://leetcode.com/problems/subarray-sum-equals-k/

/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0,sum=0;
        mp[sum]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};