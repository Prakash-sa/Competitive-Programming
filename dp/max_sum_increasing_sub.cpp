#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	  
	    int dp[n];
	    for(int i=0;i<n;i++)dp[i]=a[i];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i]&&(dp[i]<dp[j]+a[i])){
	                dp[i]=dp[j]+a[i];
	            }
	        }
	    }
	    sort(dp,dp+n);
	    cout<<dp[n-1]<<endl;
	}
	return 0;
}