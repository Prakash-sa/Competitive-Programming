int cnt;
vector<int>vis;
void dfs(int s,int d){
    vis[s]=true;
    if(s==d)cnt++;
    else {
        for(auto it=adj[s].begin();it!=adj[s].end();it++){
            if(!vis[*it])dfs(*it,d);
        }
    }
    vis[s]=false;
}

int countPaths(int s, int d)
{
    // Code here
    vis.assign(V,false);
    cnt=0;
    if(s==d)return 0;
    dfs(s,d);
    return cnt;
}