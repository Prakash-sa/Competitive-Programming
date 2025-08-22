#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+9;
const int num=1e5+5;
vector<vector<int>>adj(20);
vector<bool>vis(20);
void init(){

}

void dfs(int s){
   vis[s]=true;
   for(auto v:adj[s]){
      if(!vis[v])dfs(v);
   }
}

int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      string a,b;
      cin>>a>>b;
      int bad=0;
      adj.assign(20,{});
      for(int i=0;i<n;i++){
         if(a[i]!=b[i]){
            if(a[i]>b[i]){
               bad=1;
               cout<<-1<<endl;
               break;
            }
            adj[a[i]-'a'].push_back(b[i]-'a');
            adj[b[i]-'a'].push_back(a[i]-'a');
         }
      }
      if(bad)continue;
      vis.assign(20,false);
      int ans=20;
      for(int i=0;i<20;i++){
         if(!vis[i]){
            dfs(i);
            --ans;
         }
      }
      cout<<ans<<endl;
   }
   return 0;
}
