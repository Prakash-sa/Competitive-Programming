//https://leetcode.com/problems/redundant-connection/



  int findParent(int parent[],int node){
        while(parent[node]!=node)node=parent[node];
        return node;
    }
    
    void unionEdge(int parent[],int x,int y){
        int x_parent=findParent(parent,x);
        int y_parent=findParent(parent,y);
        
        if(x_parent!=y_parent){
            parent[y_parent]=x_parent;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int parent[n+1];
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        for(auto it:edges){
            int x_parent=findParent(parent,it[0]);
            int y_parent=findParent(parent,it[1]);
            if(x_parent==y_parent)return it;
            unionEdge(parent,x_parent,y_parent);
        }
        return  {};
        
        
    }
