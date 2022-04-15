//https://www.spoj.com/problems/GERGOVIA/





#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;


void init(){

}




int main()
{
	boost;
	int t=1;
	while(t){
		int n;
		cin>>n;
		if(n==0)return 0;
		vector<pair<int,int>>buy,sell;
		for(int i=0;i<n;i++){
			int k;cin>>k;
			if(k>0)buy.push_back({k,i});
			else sell.push_back({k,i});
		}
		int i=0,j=0;
		long long ans=0;
		while(i<buy.size() && j<sell.size()){
			int k=min(buy[i].first,-sell[j].first);
			int siz=abs(buy[i].second-sell[j].second);
			ans+=k*siz; 
			buy[i].first-=k;
			sell[j].first+=k;
			if(buy[i].first==0)i++;
			if(sell[j].first==0)j++;
		}
		cout<<ans<<endl;

	}
	return 0;
}
