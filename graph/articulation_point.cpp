#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

int cnt=0;
vector<bool>vis;
vector<vector<int>>adj;
vector<vector<int>>res;
vector<bool>ap;
vector<int>low,tin;
void dfs(int start,int p){
    vis[start]=true;
    cnt++;
    int children=0;
    low[start]=tin[start]=cnt;
    for(int i=0;i<adj[start].size();i++){
        int tmp=adj[start][i];
        if(tmp==p)continue;
        if(vis[tmp]){
            low[start]=min(low[start],tin[tmp]);
        }
        else {
            children++;
            dfs(tmp,start);
            low[start]=min(low[start],low[tmp]);
            if(low[tmp]>tin[start])res.push_back({start,tmp});
            if(p<0&&children>1)ap[start]=1;
            if(p>=0 && low[tmp]>=tin[start])ap[start]=true;
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    res.clear();
    cnt=0;
    ap.assign(n,0);
    vis.assign(n,0);
    adj.assign(n,{});
    low.assign(n,INT_MAX);
    tin.assign(n,INT_MAX);
    for(int i=0;i<connections.size();i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i,-1);
    }
    for(int i=0;i<n;i++)if(ap[i])cout<<i<<" ";
    return res;
}