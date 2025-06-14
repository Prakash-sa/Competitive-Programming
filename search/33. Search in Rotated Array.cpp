//https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=oizxjoit


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            // found the target
            if(nums[mid]==target)return mid;

            // left half is sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<nums[mid])r=mid-1;
                else l=mid+1;
            }
            // right half is sorted
            else {
                if(nums[mid]<target && target<=nums[r])l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};