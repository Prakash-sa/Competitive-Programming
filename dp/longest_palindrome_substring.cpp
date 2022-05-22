#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    
	    int maxLength = 1; 
  
        int start = 0; 
        int len = s.size(); 
      
        int low, high; 
        for (int i = 1; i < len; ++i) { 
            low = i - 1; 
            high = i; 
            while (low >= 0 && high < len 
                   && s[low] == s[high]) { 
                if (high - low + 1 > maxLength) { 
                    start = low; 
                    maxLength = high - low + 1; 
                } 
                --low; 
                ++high; 
            } 
      
            low = i - 1; 
            high = i + 1; 
            while (low >= 0 && high < len 
                   && s[low] == s[high]) { 
                if (high - low + 1 > maxLength) { 
                    start = low; 
                    maxLength = high - low + 1; 
                } 
                --low; 
                ++high; 
            } 
        } 
        string ans=s.substr(start,maxLength);
        if(ans.size()>0)
	    cout<<ans<<endl;
	    else cout<<s[0]<<endl;
	
	}
	return 0;
}


//https://www.youtube.com/watch?v=EIf9zFqufbU&ab_channel=AlexanderLe

 string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return "";
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        
        string result="";
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && i!=j){
                    if(j==i+1) // for pallindromes of length 2, for e.g. "bb" in "abbc"
                        dp[i][j]=true;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j] && (j-i+1)>result.length())
                    result=s.substr(i,j-i+1);
            }
        }
        
        return result;
    }




//No. of palindromic substrings
//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)dp[i][j]=1;
                else if(s[i]==s[j] && j==i+1){
                    dp[i][j]=1;
                }
                else if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
