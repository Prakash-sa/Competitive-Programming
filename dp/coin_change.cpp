#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ch(int a[],int n,int k){
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(a[i-1]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
        }
    }
    return dp[n][k];
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    int cnt;
	    cin>>cnt;
	    cout<<ch(a,n,cnt)<<endl;
	}
	return 0;
}