int spanningTree(int V,int E,vector<vector<int> > graph)
{
    int mark[V+1]={0};
    int minco=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,1});
    while(!q.empty()){
        pair<int,int>p=q.top();
        q.pop();
        int x=p.second;
        if(mark[x])continue;
        mark[x]=1;
        minco+=p.first;
        for(int i=0;i<V;i++){
            int k=graph[x][i];
            if(mark[i]==0)q.push({k,i});
        }
        
    }
    return minco;
    
}