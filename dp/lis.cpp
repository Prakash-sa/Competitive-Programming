#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int


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

int lcs_string(char s1[],char s2[],int n1,int n2){
    int dp[n1+1][n2+1]={0};
    for(int i=0;i<=n1;i++)dp[i][0]=0;
    for(int i=0;i<=n2;i++)dp[0][i]=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}
int lis_array(vector<int>chart){
	int n=chart.size();
    int lis[500]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(chart[i]>chart[j]&&lis[i]<lis[j]+1)lis[i]=lis[j]+1;
        }
    }
    int max1=0;
    for(int i=0;i<n;i++)max1=max(max1,lis[i]);
    return chart.size()-max1-1;
}
int liss(int a[],int n){
    int l[n+1]; 
    memset(l,0,sizeof(l));
    l[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&(i-j)<=(a[i]-a[j])&&l[j]>l[i])l[i]=l[j];
        }
        l[i]++;
    }
    int res=*max_element(l,l+n);
    return n-res;
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
    cout<<liss(a,n)<<endl;
	}
	return 0;
}
