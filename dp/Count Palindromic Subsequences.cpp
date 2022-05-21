//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1





class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       long long int mod=1e9+7;
       long long int n=str.size();
       vector<vector<long long int>>dp(n,vector<long long int>(n,0));
       for(long long int k=0;k<n;k++){
           long long int i=0;
           for(long long int j=k;j<n;j++){
               if(i==j)dp[i][j]=1;
               else if(j==i+1)dp[i][j]=str[i]==str[j]?3:2;
               else {
                   if(str[i]==str[j])dp[i][j]=(dp[i][j-1]+dp[i+1][j]+1)%mod;
                   else dp[i][j]=(mod+dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%mod;
               }
               i++;
           }
       }
       return dp[0][n-1]%mod;
    }
     
};
