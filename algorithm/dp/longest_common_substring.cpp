int longestCommonSubstring(std::string s, std::string t) {
    int n=s.size(),m=t.size(),maxlen=0;
    int dp[n+1][m+1];
    int endindex;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)dp[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                maxlen=max(maxlen,dp[i][j]);
                if(maxlen<dp[i][j]){
                    maxlen=dp[i][j];
                    endindex=i;
                }
            }
        }
    }
    return maxlen;
    //string is 
    return s.substr(endindex-maxlen,mwaxlen);
}
