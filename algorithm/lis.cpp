#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int lis_string(char s1[],char s2[],int n1,int n2){
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