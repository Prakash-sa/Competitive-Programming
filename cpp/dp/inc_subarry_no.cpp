//https://www.codechef.com/LRNDSA07/problems/SUBINC
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;

lli ch(lli a[],lli n){
	lli dp[n];
	dp[0]=1;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] <= a[i])
		{
			dp[i]= dp[i-1]+1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	lli ans=0;
	for(auto it:dp)ans+=it;
	return ans;
}

int32_t main(){
	boost;
	int t=1;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		cout<<ch(a,n)<<endl;
	}
	return 0;
}
