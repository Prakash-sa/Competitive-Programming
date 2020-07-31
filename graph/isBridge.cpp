vector<bool>vis;

void dfs(int s,list<int> adj[],int V){
    vis[s]=true;
    for(auto e:adj[s]){
        if(!vis[e])dfs(e,adj,V);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    // Code here
    vis.assign(V,false);
    adj[s].remove(e);
    adj[e].remove(s);
    dfs(s,adj,V);
    if(!vis[e])return true;
    return false;
}