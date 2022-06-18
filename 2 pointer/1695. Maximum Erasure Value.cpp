//https://leetcode.com/problems/maximum-erasure-value/



class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>s;
        int ans=0,sum=0;
        int n=nums.size();
        for(int l=0,h=0;h<n;){
            if(s.find(nums[h])==s.end()){
                sum+=nums[h];
                s.insert(nums[h++]);
                ans=max(ans,sum);
            }
            else {
                sum-=nums[l];
                s.erase(s.find(nums[l++]));
            }
        }
        return ans;
    }
};
