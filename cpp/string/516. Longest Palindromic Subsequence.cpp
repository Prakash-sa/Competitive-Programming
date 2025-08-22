//https://leetcode.com/problems/longest-palindromic-subsequence/




class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int k=0;k<n;k++){
            int i=0;
            for(int j=k;j<n;j++){
                if(i==j)dp[i][j]=1;
                else {
                    if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
                    else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
                i++;
            }
        }
        return dp[0][n-1];
    }
};
