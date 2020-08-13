//https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;

vector<int>dp;
vector<int>adj[num];
void init(){

}

int dfs(int x){
   if(dp[x]!=-1)return dp[x];
   int tmp=0;
   for(auto c:adj[x]){
      tmp=max(tmp,dfs(c)+1);
   }
   dp[x]=tmp;
   return dp[x];
}


int main()
{
   boost;
   int t=1;
   //cin>>t;
   init();
   while(t--){
      int n,m,a,b;
      cin>>n>>m;
      for(int i=0;i<m;i++){
         cin>>a>>b;
         a--;b--;
         adj[a].push_back(b);
      }
      dp.assign(n,-1);
      int ans=0;
      for(int i=0;i<n;i++){
         ans=max(ans,dfs(i));
      }
      cout<<ans<<endl;
   }
   return 0;
}
