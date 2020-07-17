//https://www.codechef.com/LRNDSA08/problems/ACM14KG3
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int num=200;
map<char,char>mp;
vector<int> adj[num];
void dfs(int b,int a,vector<vector<int>>&vis){
	vis[a][b]=1;
	for(int i=0;i<adj[b].size();i++){
		if(!vis[a][adj[b][i]])dfs(adj[b][i],a,vis);
	}
}

int32_t main(){
	boost;
	int t=1;
	cin>>t;
	while(t--){
		string s,t;
		cin>>s>>t;
		int m;
		cin>>m;
		for(int i=0;i<num;i++)adj[i].clear();
		for(int i=0;i<m;i++){
			string tmp;
			cin>>tmp;
			adj[tmp[0]-'a'].push_back(tmp[3]-'a');
		}
		if(s.size()!=t.size()){
			cout<<"NO\n";
			continue;
		}
		vector<vector<int>>vis(200,vector<int>(200,0));
		for(int i=0;i<26;i++){
			dfs(i,i,vis);
		}
		int flag=0;
		for(int i=0;i<s.size();i++){
			if(vis[s[i]-'a'][t[i]-'a']==0){
				cout<<"NO\n";
				flag=1;
				break;
			}
		}
		if(!flag)cout<<"YES\n";

	}
	return 0;
}
