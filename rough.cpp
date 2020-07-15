#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
#define int long long

const int num=1e5; 
vector<int>adj[num];
bool vis[num];
int f[num],cnt=0;
const int mod=1e9+7;

void dfs(int a){
	vis[a]=true;
	f[cnt]++;
	for(int i=0;i<adj[a].size();i++)
		if(!vis[adj[a][i]])dfs(adj[a][i]);
}

void initialise(){
	for(int i=0;i<num;i++){
		vis[i]=0;
		cnt=0;
		adj[i].clear();
		f[i]=0;
	}
}


int32_t main(){
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,m,a,b;
		cin>>n>>m;
		initialise();
		for(int i=0;i<m;i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				cnt++;
				dfs(i);
			}
		}
		int ans=1;
		for(int i=1;i<=cnt;i++){
			ans*=f[i];
			ans=ans%mod;
		}
		cout<<cnt<<" "<<ans<<endl;
	}
	return 0;
}
