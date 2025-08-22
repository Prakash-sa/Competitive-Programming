//https://www.codechef.com/LRNDSA08/problems/DIGJUMP
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int num=1e5+5;
string s;
int ans;


int32_t main(){
	boost;
	int t=1;
	//cin>>t;
	while(t--){
		cin>>s;
		vector<lli>a[10];
		int n=s.size();
		for(int i=0;i<s.size();i++)a[s[i]-'0'].push_back(i);
		vector<bool>vis(n,0);
		vector<lli>dis(n,inf);
		queue<lli>q;
		q.push(0);
		dis[0]=0;
		vis[0]=true;
		while (q.size()>0 && vis[n-1]==false)
		{
			lli u=q.front();
			q.pop();
			if(u+1<n && vis[u+1]==false){
				vis[u+1]=true;
				dis[u+1]=dis[u]+1;
				q.push(u+1);
			}
			if(u-1>=0 && vis[u-1]==false){
				vis[u-1]=true;
				dis[u-1]=dis[u]+1;
				q.push(u-1);
			}
			lli x=s[u]-'0';
			for(auto i:a[x]){
				if(!vis[i] && i!=u){
					dis[i]=dis[u]+1;
					q.push(i);
					vis[i]=true;
				}
			}
			a[x].clear();
		}
		cout<<dis[n-1]<<endl;
	}
	return 0;
}
