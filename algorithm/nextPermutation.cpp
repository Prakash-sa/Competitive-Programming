//https://leetcode.com/problems/next-permutation/



//https://leetcode.com/problems/next-permutation/discuss/1241286/C%2B%2B-oror-simple-to-understand



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint=-1;
        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                breakpoint=i-1;
                break;
            }
        }
        if(breakpoint<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[i],nums[breakpoint]);
                reverse(nums.begin()+breakpoint+1,nums.end());
                return;
            }
        }
    }
};
