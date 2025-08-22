#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)cin>>a[i][j];
	    }
	    
	    int l=0,r=m-1,u=0,b=n-1;
	    while(u<=b&&l<=r){
	        for(int i=l;i<=r;i++){
	            cout<<a[u][i]<<" ";
	        }
	        u++;
	        for(int i=u;i<=b;i++){
	            cout<<a[i][r]<<" ";
	        }
	        r--;
	        if(u<=b){
				for(int i=r;i>=l;i--){
					cout<<a[b][i]<<" ";
				}
	        }
	        b--;
	        if(l<=r){
				for(int i=b;i>=u;i--){
					cout<<a[i][l]<<" ";
				}
	        }
	        l++;
	    }
	    cout<<endl;
	    
	}
	return 0;
}