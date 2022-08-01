//https://leetcode.com/problems/k-inverse-pairs-array/

//https://www.youtube.com/watch?v=U4SLvGBEqpE&ab_channel=CodingDecoded

/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. 
Since the answer can be huge, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, k = 0
Output: 1
*/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        if(dp[n][k])return dp[n][k];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=(dp[i-1][j]+(j>0?dp[i][j-1]:0))%mod;
                if(j>=i){
                    dp[i][j]=(mod+dp[i][j]-dp[i-1][j-i])%mod;
                }
            }
        }
        return dp[n][k];
    }
};



