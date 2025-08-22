//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int id1=lower_bound(nums,target);
        int id2=lower_bound(nums,target+1)-1;
        if(id1<nums.size() && nums[id1]==target)return {id1,id2};
        return {-1,-1};
    }
    
    int lower_bound(vector<int>&nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    
};

