//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1


class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    int dp[1001][1001];
		    for(int i=0;i<n;i++)dp[i][0]=0;
		    for(int j=0;j<n;j++)dp[0][j]=0;
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==str[j-1] && i!=j)dp[i][j]=1+dp[i-1][j-1];
		            else {
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		    
		}

};

