int dp[1001][1001];


int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=0;
    if(n>0)
    m=grid[0].size()-1;
    n--;
    dp[0][0]=grid[0][0];
    for(int i=1;i<=n;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<=m;j++)dp[0][j]=dp[0][j-1]+grid[0][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
        }
    }
    return dp[n][m];
}

//or

dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+grid[i][j];
