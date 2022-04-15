//https://www.spoj.com/problems/CHOCOLA/
//https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/




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

static bool cmp(int a,int b){
	return a>b;
}

int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		n--;m--;
		vector<int>a(n,0),b(m,0);
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<m;i++)cin>>b[i];
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		int hz=1,vz=1;
		int i=0,j=0,ans=0;
		while(i<n &&j<m){
			if(a[i]>b[j]){
				hz++;
				ans+=a[i++]*vz;				
			}
			else {
				vz++;
				ans+=b[j++]*hz;
			}
		}
		while(i<n){
			hz++;
			ans+=a[i++]*vz;
		}
		while(j<m){
			vz++;
			ans+=b[j++]*hz;
		}
		cout<<ans<<endl;
	}
	return 0;
}
