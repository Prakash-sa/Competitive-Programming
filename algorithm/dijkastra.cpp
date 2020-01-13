#include<bits/stdc++.h>

#define ll long long
#define T ll t; cin>>t; while(t--)
using namespace std;
#define speed ios_base::sync_with_stdio(0)
#define endl "\n"

vector<pair<int,int>>adj[1000001];
ll c=1000000000;
bool visited[1000001];
ll dist[1000001];

void intilization(int n)
{
    for(ll i=0;i<=n;i++)
    {
    visited[i]=0;
    dist[i]=c;
    }
}

void dijkstras()
{
ll st=1;
//cout<<"starting= ";
//cin>>st;
    dist[st]=0;
    multiset<pair<int,int>>s;
    s.insert({0,st});
    while(!s.empty())
    {
        ll from,to,cost;
        pair<int,int> p = *s.begin();
        s.erase(s.begin());
        from = p.second;
        if(visited[from]) continue;
        visited[from]=1;
        for(ll i=0;i<adj[from].size();i++)
        {
            cost=adj[from][i].first;
            to=adj[from][i].second;
            if(dist[from]+cost<dist[to])
            {
            dist[to]=dist[from]+cost;
            s.insert({dist[to],to});
            }

        }
    }
}

int main()
{
speed;
ll nodes,edges,i;
cin>>nodes>>edges;
intilization(nodes);
for(i=0;i<edges;i++)
{
ll from,to,cost;
cin>>from>>to>>cost;
adj[from].push_back({cost,to});
// adj[to].push_back({cost,from});
}
dijkstras();
// for(i=1;i<=nodes;i++)
// {
// cout<<visited[i]<<" ";
// }
// cout<<endl;
for(i=2;i<=nodes;i++)
{
cout<<dist[i]<<" ";
}
cout<<endl;

}