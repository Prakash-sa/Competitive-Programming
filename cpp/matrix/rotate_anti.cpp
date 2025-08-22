#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n][n];
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	    int ans[n][n];
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)ans[n-j-1][i]=a[i][j];
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
	    cout<<endl;
	    
	
	}
	return 0;
}