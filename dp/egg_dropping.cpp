//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int ch(int n,int k){
    if(k==1||k==0)return k;
    if(n==1)return k;
    if(dp[n][k]!=-1)return dp[n][k];
    int min1=INT_MAX,res;
    for(int i=1;i<=k;i++){
        res=max(ch(n-1,i-1),ch(n,k-i));
        min1=min(min1,res);
    }
    dp[n][k]=min1+1;
    return dp[n][k];
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    memset(dp,INT_MAX,sizeof(dp));
	    cout<<ch(n,k)<<endl;
	}
	return 0;
}


//binary search


lass Solution
{
    public:
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        if(k==1 || k==0)return dp[n][k]=k;
        if(n==1)return dp[n][k]=k;
        if(dp[n][k]!=-1)return dp[n][k];
        int res=INT_MAX;
        int l=1,r=k;
        while(l<=r){
            int mid=(l+r)/2;
            int x=eggDrop(n-1,mid-1),y=eggDrop(n,k-mid);
            res=min(res,1+max(x,y));
            if(x<y)l=mid+1;
            else r=mid-1;
        }
        return dp[n][k]=res;
    }
};
