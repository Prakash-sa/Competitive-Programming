//https://www.youtube.com/watch?v=l3hda49XcDE&t=918s&ab_channel=TusharRoy-CodingMadeSimple


 bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*')dp[0][i]=dp[0][i-2];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='.' || s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    if(p[j-2]=='.' || p[j-2]==s[i-1]){
                        dp[i][j]=dp[i][j]|dp[i-1][j];
                    }
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
        
    }
