#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef pair<lli,lli> PII;

//EC_P - Critical Edges


const int MAXN = 1e4+5;
vector<lli> adj[MAXN];
bool vis[MAXN], AP[MAXN];
int n;
int disc[MAXN];     //discovery currTime of vertices
int low[MAXN];  //low[i] is the minimum of visited currTime of all vertices which are reachable from i.
vector<PII> bridges;
int currTime;


void initialise(){
    currTime=0;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        vis[i]=false;
        AP[i]=false;
        disc[i]=0;
        low[i]=INT_MAX;
        bridges.clear();
    }
}

void dfs(int u,int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;  //since till now i have not explored the children of u all i know is the lowest numbered vertex which can be reached from u is u itself.
    int child = 0;
    for(int i = 0;i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == parent)     continue;
        if(!vis[v]){
            child = child+1;
            currTime++;
            dfs(v, u);
            //check if subtree rooted at v has a connection to one of the ancestors of u.
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){   //this means the edge connecting u-v is a bridge.
                if(u < v)
                    bridges.push_back({u, v});
                else
                    bridges.push_back({v, u});
            }
            if(parent == -1 && child > 1){ //if u is root and its child is > 1 then it is an A.P.
                AP[u] = true;
            }
            if(parent != -1 && low[v] >= disc[u]){  //if u is not a root and the lowest reachable vertex from v has time greater than discovery time of u, then u is an A.P.
                AP[u] = true;
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    speed;
    int t,kase=1;
   // cin>>t;
    while (1)
    {
        lli a,b,m;
        cin>>n>>m;
        if(n==0&&m==0)break;
        initialise();
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i])dfs(i,-1);
        }

        //No of bridges
        /*
        if(bridges.size()!=0){
            cout << bridges.size() << endl;
            sort(bridges.begin(),bridges.end());
            for(int i=0;i<bridges.size();i++){
                cout << bridges[i].first << " " << bridges[i].second << endl;
            }
        }else{
            cout << "Sin bloqueos" << endl;
        }
        kase++;

        */
       lli cnt=0;
       for(lli i=1;i<=n;i++)if(AP[i])cnt++;
       cout<<cnt<<endl;

    }
    
    
    return 0;
}
