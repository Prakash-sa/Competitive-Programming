#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli sum=0;
int dp[1001][100001];

bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool subset[n+1][sum+1]; 
    for (int i = 0; i <= n; i++) 
    subset[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
    subset[0][i] = false; 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]]; 
       } 
     } 
     return subset[n][sum]; 
} 

bool ch(int a[],int n,int sum){
    if(n<=0&&sum!=0)return 0;
    if(sum<0)return 0;
    if(sum==0)return 1;
    if(dp[n-1][sum]!=-1)return dp[n-1][sum];
    
    int ans=ch(a,n-1,sum-a[n-1])||ch(a,n-1,sum);
    dp[n-1][sum]=ans;
    return ans;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,sum=0;
	    cin>>n;
	    int a[n];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum%2!=0)cout<<"NO"<<endl;
    	else {
    	    if(ch(a,n,sum/2))cout<<"YES"<<endl;
    	    else cout<<"NO"<<endl;
	    }
	}
	return 0;
}