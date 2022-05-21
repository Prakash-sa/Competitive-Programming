//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#



class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n);
	    int ans=arr[0];
	    for(int i=0;i<n;i++)dp[i]=arr[i];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<=i;j++){
	            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i]){
	                dp[i]=dp[j]+arr[i];
	                ans=max(ans,dp[i]);   
	            }
	        }
	    }
	    return ans;
	}  
};



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




