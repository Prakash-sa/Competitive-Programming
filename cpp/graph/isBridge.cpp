//Naive Approach

//Time Complexity is O(E*(V+E))


vector<bool>vis;

void dfs(int s,list<int> adj[],int V){
    vis[s]=true;
    for(auto e:adj[s]){
        if(!vis[e])dfs(e,adj,V);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    vis.assign(V,false);
    adj[s].remove(e);
    adj[e].remove(s);
    dfs(s,adj,V);
    if(!vis[e])return true;
    return false;
}


//Time Complexity is O(V+E)



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
            //this is the bridge
            if(low[tmp]>tin[start])res.push_back({start,tmp});
            
            if(p<0&&children>1)ap[start]=1;
            if(p>=0 && low[tmp]>=tin[start])ap[start]=true;
        }
    }
}
