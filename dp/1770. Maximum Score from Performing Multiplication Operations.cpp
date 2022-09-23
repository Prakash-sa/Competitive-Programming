//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

 

Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
*/


class Solution {
    
    vector<vector<int>>dp;
    
    int solve(int i,int j,int n,vector<int>& nums, vector<int>& m){
        if(j==m.size())return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int left=solve(i+1,j+1,n,nums,m)+(nums[i]*m[j]);
        int right=solve(i,j+1,n-1,nums,m)+(nums[n-1]*m[j]);
        return dp[i][j]=max(right,left);
    }
    
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solve(0,0,n,nums,multipliers);
        return dp[n-1][m-1];
    }
};

