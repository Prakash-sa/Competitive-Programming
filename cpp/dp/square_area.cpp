#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n][m];
	    int ans=0;
	    int dp[n+1][m+1]={0};
	    for(int i=0;i<n;i++)for(int j=0;j<m;j++)dp[i][j]=0;
	    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
    	        if(a[i][j]==1){
    	            dp[i][j]=1;
    	            if(i>0&&j>0)
    	            dp[i][j]+=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
    	        }
	            ans=max(ans,dp[i][j]);
	        }
	    }
	    
	    cout<<ans<<endl;
	    
	
	}
	return 0;
}