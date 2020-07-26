#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int v,e;
       cin>>v>>e;
       int dist[v+1];
       dist[0]=0;
       for(int i=1;i<v;i++)dist[i]=10000;
       vector<int>adj[e];
       for(int i=0;i<e;i++){
           int a,b,c;
           cin>>a>>b>>c;
            adj[i].push_back(a);
            adj[i].push_back(b);
            adj[i].push_back(c);
       }
       for(int i=0;i<v-1;i++){
           for(int j=0;j<e;j++){
               int src=adj[j][0];
               int dest=adj[j][1];
               int w=adj[j][2];
               if(dist[src]!=10000 && dist[dest]>dist[src]+w)dist[dest]=dist[src]+w;
           }
       }
       int flag=0;
       for(int i=0;i<e;i++){
           int src=adj[i][0];
           int dest=adj[i][1];
           int w=adj[i][2];
           if(dist[dest]>dist[src]+w){
               flag=1;
               break;
           }
       }
       cout<<flag<<endl;
       
   }
   return 0;
}