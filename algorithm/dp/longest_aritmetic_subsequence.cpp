#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod =1e9+7;


int las(int a[],int n){
    if(n<=2)return n;
    map<int,int>mp[n];
    int ans=0;for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=a[i]-a[j];
            mp[i][diff]=mp[j][diff]+1;
            ans=max(ans,mp[i][diff]);
        }
    }
    return ans+1;
}


int main()
{
    speed;
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n]; 
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<las(a,n)<<endl;
	    
	    
	}
    return 0;
}