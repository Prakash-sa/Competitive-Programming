//detect cycle in undirected graph



 bool dfs1(vector<int>adj[],int parent,vector<int>&vis,int x){
      vis[x]=1;
      for(auto it:adj[x]){
          if(!vis[it]){
              if(dfs1(adj,x,vis,it)){
                  return true;
              }
          }
          else if(parent!=it)return true;
      }
      return false;
  }
  
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)vis[i]=0;
        for(int i=0;i<V;i++){
            if(!vis[i]&&dfs1(adj,-1,vis,i))return true;
        }
        return false;
    }
