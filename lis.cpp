#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n+1];
	    for(int i=0;i<n;i++)  cin>>arr[i];
	    int dp[n][k+1];
	    memset(dp,-1,sizeof(dp));
	    int ans=-1;
	    for(int i=0;i<n;i++)  dp[i][1]=arr[i];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]){
	                for(int l=1;l<k;l++){
	                    if(dp[j][l]!=-1){
	                        dp[i][l+1]=max(dp[i][l+1],dp[j][l]+arr[i]);
	                    }
	                }
	            }
	        }
	        ans=max(ans,dp[i][k]);
	    }
	    ans=max(ans,dp[0][k]);
	    cout<<ans<<endl;
	}
	return 0;
}