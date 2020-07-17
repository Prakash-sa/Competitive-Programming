void topo(vector<int>adj[],stack<int>&s,vector<int>&vis,int v){
    vis[v]=true;
    for(auto it:adj[v]){
        if(!vis[it])topo(adj,s,vis,it);
    }
    s.push(v);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int>s;
    vector<int>vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i])topo(adj,s,vis,i);
    }
    vector<int>ans;
    while(s.size()>0){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}