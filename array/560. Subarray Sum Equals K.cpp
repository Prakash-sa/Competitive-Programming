//https://leetcode.com/problems/subarray-sum-equals-k/


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