//https://leetcode.com/problems/non-decreasing-array/



class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        bool first=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                if(!first)return false;
                first=false;
                if(i>0 && nums[i-1]>nums[i+1])nums[i+1]=nums[i];
                // else nums[i]=nums[i+1];
                
            }
        }
        return true;
    }
};


