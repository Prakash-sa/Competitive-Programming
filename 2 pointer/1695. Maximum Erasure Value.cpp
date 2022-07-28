//https://leetcode.com/problems/maximum-erasure-value/

/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, 
that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/


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
