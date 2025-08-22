//https://www.codechef.com/LRNDSA07/problems/KPRIME
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+9;
const int num=1e5+5;
lli dp[num+1];
lli ans[6][num+1]={0};

void init(){
	for(int i=0;i<num;i++)dp[i]=0;
	for(int i=2;i<num;i++){
		if(!dp[i]){
			dp[i]=1;
			for(int j=2;j*i<num;j++)dp[j*i]+=1;
		}
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<num;j++){
			ans[i][j]=(dp[j]==i)+ans[i][j-1];
		}
	}
}

int32_t main(){
	boost;
	int t=1;
	cin>>t;
	init();
	while(t--){
		lli a,b,k;
		cin>>a>>b>>k;
		cout<<ans[k][b]-ans[k][a-1]<<endl;
	}
	return 0;
}
