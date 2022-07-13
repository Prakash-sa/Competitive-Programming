//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/


/*
Example 1:

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.

Example 2:

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.

*/

class Solution {
    
    vector<vector<int>>dp;
    int n;
    int solve(vector<vector<int>>& piles,int i,int k){
        if(dp[i][k]>0)return dp[i][k];
        if(i==n || k==0)return 0;
        int res=solve(piles,i+1,k),cur=0;
        for(int j=0;j<piles[i].size() && j<k;j++){
            cur+=piles[i][j];
            res=max(res,solve(piles,i+1,k-j-1)+cur);
        }
        dp[i][k]=res;
        return res;
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        dp.resize(n+1,vector<int>(k+1,0));
        return solve(piles,0,k);
    }
};

