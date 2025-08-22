#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

#define max11 1000001
unordered_set<string>dict;

bool func(string &s,int i, vector<int>&dp){
    if(i==s.length())
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    for(int j=i+1;j<=s.length();++j){
        if(dict.find(s.substr(i,j-i))!=dict.end()){
            if(func(s,j,dp)){
                return dp[i]=1;
            }
        }
    }
    return dp[i]=0;
}

bool findit(string &s,int i, vector<int> &dp ){
    if(i==s.length())
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    for(int j=i+1;j<=s.length();++j){
        if(dict.find(s.substr(i,j-i))!=dict.end()){
            if(findit(s,j,dp)){
                return dp[i]=1;
            }
        }
    }
    return dp[i]=0;
}



int main() {
	boost;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string k;
        dict.clear();
        for(int i=0;i<n;i++){
            cin>>k;
            dict.insert(k);
        }
        string se;
        cin>>se;
        vector<int>dp(se.length(),-1);
        cout<<findit(se,0,dp);
        
        cout<<endl;

    }
	return 0;
}




//https://leetcode.com/problems/word-break/





class Solution {
public:
    
    int dp[305];
    
    bool find(string s,int in,unordered_set<string>&arr){
        if(s.length()==in){
            return 1;
        }
        
        if(dp[in]!=-1)return dp[in];
        
        for(int i=1;i<=s.length()-in;i++){
            if(arr.find(s.substr(in,i))!=arr.end() && find(s,i+in,arr))return dp[in]=1;
        }
        return dp[in]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string>arr(wordDict.begin(),wordDict.end());
        return find(s,0,arr);
    }
};
