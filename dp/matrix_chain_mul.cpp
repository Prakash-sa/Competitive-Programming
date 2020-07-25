#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[600][600];
int ch(int a[],int i,int j){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cnt,min1=INT_MAX;
    for(int k=i;k<j;k++){
        cnt=ch(a,i,k)+ch(a,k+1,j)+a[i-1]*a[j]*a[k];
        min1=min(min1,cnt);
    }
    dp[i][j]=min1;
    return dp[i][j];
    
}



int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<ch(a,1,n-1)<<endl;
	
	}
	return 0;
}