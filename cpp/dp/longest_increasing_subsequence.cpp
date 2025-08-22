//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>dp(n+1,1);
       for(int i=0;i<n;i++){
           for(int j=0;j<=i;j++){
               if(a[i]>a[j] && dp[i]<dp[j]+1)dp[i]=dp[j]+1;
           }
       }
       int ans=INT_MIN;
       for(int i=0;i<n;i++)ans=max(ans,dp[i]);
       return ans;
    }
};

