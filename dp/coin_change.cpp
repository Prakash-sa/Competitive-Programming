#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/


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