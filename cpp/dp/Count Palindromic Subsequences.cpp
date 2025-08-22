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



/*
Given a string of digits s, return the number of palindromic subsequences of s having length 5. 
Since the answer may be very large, return it modulo 109 + 7.

Note:
A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. 

Example 1:
Input: s = "103301"
Output: 2
Explanation: 
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
Two of them (both equal to "10301") are palindromic.

Example 2:
Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:
Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".
*/


class Solution {
public:
    int countPalindromes(string s) {
        long long int mod=1e9+7;
        int n=s.size();
        long ans=0;

        for(int x=0;x<=9;x++){
            for(int y=0;y<=9;y++){
                vector<int>pattern={x,y,0,y,x};
                vector<int>dp(6);
                dp[5]=1;
                for(int i=0;i<n;i++){
                    for(int j=0;j<5;j++){
                        if(s[i]==pattern[j]+'0'||j==2)dp[j]=(dp[j]+dp[j+1])%mod;
                    }
                }
                ans=(ans+dp[0])%mod;
            }
        }
        return ans;  
    }
};