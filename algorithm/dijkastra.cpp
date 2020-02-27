#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define len 500009

typedef pair<lli,lli>PII;

//https://www.spoj.com/problems/SHPATH/


vector<pair<lli,lli>>adj[len];
int dist[len],n;
int visited[len];

void dijkastra(int x,int fi){
    for(int i=1;i<=n;i++)visited[i]=false;
    for(int i=1;i<=n;i++)dist[i]=INT_MAX-10000;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,x});
    dist[x]=0;
    while(!q.empty()){
        pair<lli,lli>p=q.top();
        q.pop();
        if(visited[p.second])continue;
        visited[p.second]=true;
        for(int i=0;i<adj[p.second].size();i++){
            int from=p.second;
            int to=adj[from][i].second;
            int weight=adj[from][i].first;
            if(dist[from]+weight<dist[to]){
                dist[to]=dist[from]+weight;
                q.push({dist[to],to});
            }
        }

    }
 //   for(int i=0;i<n;i++)cout<<dist[i];
}


int main()
{
    speed;
   int t;
   cin>>t;
   while (t--)
   {
       map<string,lli>mp;
       string s,s1,s2;
       cin>>n;
       for(int i=1;i<=n;i++){
           cin>>s;
           mp[s]=i;
           int a,b,k;
           cin>>k;
           while(k--){
               cin>>a>>b;
                adj[i].push_back({b,a});
                adj[a].push_back({b,i});
           }
       }
       int q;
       cin>>q;
       while(q--){
           cin>>s1>>s2;
            dijkastra(mp[s1],mp[s2]);
            cout<<dist[mp[s2]]<<endl;
       }
   }
   
    return 0;
}


//Almost shortest path
//https://www.spoj.com/problems/SAMER08A/

#include<bits/stdc++.h>
using namespace std;
typedef int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define len 500009

const int inf=1e9;

typedef pair<lli,lli>PII;

int n,m,startp,endp;
vector<pair<lli,lli>>adj[len];
int dist[len],dist2[len];
int parent[len];
int visited[len];
vector<pair<lli,lli>>avoid_edges;

void edge_store(int e,int parent_node){
    while(parent_node!=-1){
        avoid_edges.push_back({parent_node,e});
        e=parent_node;
        parent_node=parent[e];
    }
}



void dijkastra(int x){
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,x});
    dist[x]=0;
    parent[x]=-1;
    while(!q.empty()){
        pair<lli,lli>p=q.top();
        q.pop();
        for(int i=0;i<adj[p.second].size();i++){
            int from=p.second;
            int to=adj[from][i].second;
            int weight=adj[from][i].first;
            if(to==endp){
                if(dist[to]==dist[from]+weight){
                    edge_store(to,from);
                    continue;
                }
            }
            if(dist[from]+weight<dist[to]){
                dist[to]=dist[from]+weight;
                parent[to]=from;
                q.push({dist[to],to});
                if(to==endp){
                    avoid_edges.clear();
                    edge_store(to,from);    
                }
                
            }
        }

    }
 //   for(int i=0;i<n;i++)cout<<dist[i];
}


void dijkastra2(int x){
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,x});
    dist2[x]=0;
    while(!q.empty()){
        pair<lli,lli>p=q.top();
        q.pop();
        if(visited[p.second])continue;
        else visited[p.second]=true;
        for(int i=0;i<adj[p.second].size();i++){
            int from=p.second;
            int to=adj[from][i].second;
            int weight=adj[from][i].first;
            if(dist2[from]+weight<dist2[to] && 
                (find(avoid_edges.begin(),avoid_edges.end(),make_pair(from,to))==avoid_edges.end())){
                dist2[to]=dist2[from]+weight;
                q.push({dist2[to],to});                
            }
        }

    }
}

int main()
{
    speed;
    while(1){
        cin>>n>>m;
        if(n==0&&m==0)break;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            parent[i]=-1;
            dist2[i]=inf;
            visited[i]=false;
            dist[i]=inf;
        }
        cin>>startp>>endp;
        int a,b,w;
        for(int i=0;i<m;i++){
            cin>>a>>b>>w;
            adj[a].push_back({w,b});
        }
        dijkastra(startp);
        dijkastra2(startp);
        if(dist2[endp]!=inf)cout<<dist2[endp]<<endl;
        else cout<<-1<<endl;

    }
   
    return 0;
}
