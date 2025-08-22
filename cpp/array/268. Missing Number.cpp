//https://leetcode.com/problems/missing-number/
//https://leetcode.com/problems/missing-number/discuss/70056/Simple-C%2B%2B-codes


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=(i+1)^nums[i];
        }
        return x;
    }
};
