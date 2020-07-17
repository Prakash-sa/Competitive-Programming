//https://www.codechef.com/LRNDSA08/problems/MARLA
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int num=1005;
int a[num][num],n,m;
int vis[num][num],cnt;
int f[num*num];

void init(){
	cnt=0;
	for(int i=0;i<num;i++)for(int j=0;j<num;j++){
		vis[i][j]=0;
		f[i]=0;
	}
}

void dfs(int x,int y,int val){
	if(x<0 || y<0 ||x>=n||y>=m||vis[x][y]||a[x][y]!=val)return;
	vis[x][y]=1;
	f[cnt]++;
	dfs(x+1,y,val);
	dfs(x,y+1,val);
	dfs(x-1,y,val);
	dfs(x,y-1,val);	
}

int32_t main(){
	boost;
	int t=1;
	//cin>>t;
	while(t--){
		cin>>n>>m;
		init();
		map<lli,lli>mp;
		int ans=0,in;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!vis[i][j]){
					cnt++;
					dfs(i,j,a[i][j]);
					if(ans<f[cnt] || (ans==f[cnt] && in>a[i][j] && ans!=0)){
						ans=f[cnt];
						in=a[i][j];
					}
				}
			}
		}
		cout<<in<<" "<<ans<<endl;

	}
	return 0;
}

