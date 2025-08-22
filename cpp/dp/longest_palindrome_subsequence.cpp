#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string tmp=s;
	    reverse(tmp.begin(),tmp.end());
	    int n=s.size();
	    int dp[n+1][n+1]={0};
	    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=n;j++){
	            if(s[i-1]==tmp[j-1])dp[i][j]=dp[i-1][j-1]+1;
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    int index=dp[n][n];
	    string ans(n,'\0');
	    int i=n,j=n;
	    while(i>0&&j>0){
	        if(s[i-1]==tmp[j-1]){
	            ans[index-1]=s[i-1];
	            i--;
	            j--;
	            index--;
	        }
	        else if(dp[i-1][j]>dp[i][j-1])i--;
	        else j--;
	    }
	    cout<<ans<<endl;
	
	}
	return 0;
}