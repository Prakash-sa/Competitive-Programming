//https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#



class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size(),m=pattern.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m)
                    dp[i][j] = true;
                else if(i==n )
                    dp[i][j] = false;
                else if(j==m){
                    if(wild[i]=='*')
                        dp[i][j] = dp[i+1][j];
                    else
                        dp[i][j] = false;
                }
                else if((wild[i]=='?') || (wild[i]==pattern[j]))
                    dp[i][j] = dp[i+1][j+1];
                else if(wild[i]=='*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};



//https://leetcode.com/problems/wildcard-matching/


class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*')dp[0][i]=dp[0][i-1];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
            }
        }
        return dp[n][m];
        
    }
};
