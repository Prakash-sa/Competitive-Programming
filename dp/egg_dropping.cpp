#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int ch(int n,int k){
    if(k==1||k==0)return k;
    if(n==1)return k;
    if(dp[n][k]!=-1)return dp[n][k];
    int min1=INT_MAX,res;
    for(int i=1;i<=k;i++){
        res=max(ch(n-1,i-1),ch(n,k-i));
        min1=min(min1,res);
    }
    dp[n][k]=min1+1;
    return dp[n][k];
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    memset(dp,INT_MAX,sizeof(dp));
	    cout<<ch(n,k)<<endl;
	}
	return 0;
}