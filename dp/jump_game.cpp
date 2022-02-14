//https://leetcode.com/problems/jump-game-ii/submissions/




class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for(int i = 1;i < n;i++){
            int minValue = INT_MAX;
            for(int j = i - 1;j >= 0;j--){
                if((i - j) <= nums[j]) minValue = min(minValue,res[j] + 1);
            }
            res[i] = minValue;
        }
        return res[n - 1];
    }
};