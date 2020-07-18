//https://www.codechef.com/LRNDSA06/problems/KCON
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;

lli kadane(lli a[],int n){
	long long int cs=0;long long int ms=0;
    for(int i=0;i<n;i++)
    {
        cs+=a[i];
        ms=max(ms,cs);
        if(cs<0) cs=0;
    }
    return ms;
}

int32_t main(){
	boost;
	int t=1;
	cin>>t;
	while(t--){
		lli n,k;
		cin>>n>>k;
		lli sum=0;
		lli a[2*n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<0)sum=0;
		if(k>=2){
			lli ans=a[0],tmp=a[0];
			for(int i=1;i<2*n;i++){
				tmp=max(a[i%n],tmp+a[i%n]);
				ans=max(ans,tmp);
			}
			cout<<ans+(k-2)*sum<<endl;
		}
		else {
			lli ans=a[0],tmp=a[0];
			for(int i=1;i<n;i++){
				tmp=max(a[i],tmp+a[i]);
				ans=max(ans,tmp);
			}
			cout<<ans<<endl;
		}
		


	}
	return 0;
}
