//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#


class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(wt[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
            }
        }
        return dp[n][w];
        
    }
};
