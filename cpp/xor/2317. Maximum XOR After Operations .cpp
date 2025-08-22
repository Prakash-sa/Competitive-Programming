//https://leetcode.com/problems/maximum-xor-after-operations/

/*
nums[i] & (nums[i]^x) cannot be more than nums[i] because we are taking AND.
So this implies that for any number we can set the bits OFF ***(only the bits which are already ON (1))***.
BUT we cannot set any bitONif it were OFFalready .

Therefore , we can say that we will set bits ON and OFF for all numbers in such a way that XOR of all the 
numbers is equal to OR of all numbers. Because if a bit is not on in any of the numbers ,there is no way we can get it on in our ans.
*/


class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto it:nums)ans|=it;
        return ans;
    }
};

