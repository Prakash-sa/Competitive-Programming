#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m,f;
	    cin>>n>>m;
	    int a[n][m];
	    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	    cin>>f;
	    int i=0,j=m-1;
	    int ans=0;
	    while(i<n && j>=0){
	        while(a[i][j]>f && j>=0)j--;
	        while(a[i][j]<f && i<n)i++;
	        if(a[i][j]==f){
	            ans=1;
	            break;
	        }
	    }
	    cout<<ans<<endl;
	    
	
	}
	return 0;
}