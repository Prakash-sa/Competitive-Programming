//https://practice.geeksforgeeks.org/problems/next-permutation5226/1#


class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> &nums){
        // code here
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
            return nums;
        }
        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[i],nums[breakpoint]);
                reverse(nums.begin()+breakpoint+1,nums.end());
                return nums;
            }
        }
        return nums;
    }
};

