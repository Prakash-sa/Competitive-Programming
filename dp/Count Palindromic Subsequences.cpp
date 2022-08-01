//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

/*
Given a string str of length N, you have to find number of palindromic subsequence 
(need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;

https://www.youtube.com/watch?v=L5lBTrCC99I&ab_channel=AdityaRajiv
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
*/



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
                    // If first and last characters are same, then we 
                    // consider it as palindrome subsequence and check
                    // for the rest subsequence (i+1, j), (i, j-1)
                   if(str[i]==str[j])dp[i][j]=(dp[i][j-1]+dp[i+1][j]+1)%mod;
                    // check for rest sub-sequence and  remove common
                    // palindromic subsequences as they are counted
                    // twice when we do countPS(i+1, j) + countPS(i,j-1)
                   else dp[i][j]=(mod+dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%mod;
               }
               i++;
           }
       }
       return dp[0][n-1]%mod;
    }
     
};
