//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]<nums[r])return nums[l];
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};





//2. array with dublicate number


//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/




class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]<nums[r])return nums[l];
            int mid=(l+r)/2;
            if(nums[mid]==nums[r]){
                if(nums[mid]==nums[l]){// for dublicacy
                    l++;
                    r--;
                }
                else r=mid;
                
            }
            else if(nums[mid]>nums[r])l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
