int cnt=0;
vector<bool>vis;
vector<vector<int>>adj;
vector<vector<int>>res;
vector<int>low,tin;
void dfs(int start,int p){
    vis[start]=true;
    cnt++;
    low[start]=tin[start]=cnt;
    for(int i=0;i<adj[start].size();i++){
        int tmp=adj[start][i];
        if(tmp==p)continue;
        if(vis[tmp]){
            low[start]=min(low[start],tin[tmp]);
        }
        else {
            dfs(tmp,start);
            low[start]=min(low[start],low[tmp]);
            if(low[tmp]>tin[start])res.push_back({start,tmp});
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    res.clear();
    cnt=0;
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
    return res;
}