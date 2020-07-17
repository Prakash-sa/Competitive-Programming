#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

int32_t main(){
	boost;
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		lli a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		lli sum[n]={0};
		sum[0]=a[0];
		for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
		lli ans=0;
		ans=sum[2];
		for(int i=3;i<n;i++)ans=max(ans,sum[i]-sum[i-3]);
		cout<<ans<<endl;

	}
	return 0;
}
