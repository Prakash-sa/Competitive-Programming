//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],minm=nums[0],maxm=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(maxm,minm);
            maxm=max(nums[i],nums[i]*maxm);
            minm=min(nums[i],nums[i]*minm);
            ans=max(ans,maxm);
        }
        return ans;
    }
};
