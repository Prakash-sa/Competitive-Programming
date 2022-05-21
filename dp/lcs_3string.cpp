//https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1



int lcs(string s1,string s2,string s3,int n,int m,int n1){
    int dp[n+1][m+1][n1+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n1;k++){
                if(i==0||j==0||k==0)dp[i][j][k]=0;
                else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }
    return dp[n][m][n1];
}
