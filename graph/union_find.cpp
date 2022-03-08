//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/



class UnionFind{
public:
    vector<int>parent;
    vector<int>rank;
    int noOfDisjointSet;
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size);
        noOfDisjointSet=size;
        for(int i=0;i<size;i++){
            parent[i]=i;
            rank[i]=i;
        }
    }
    
    int Find(int x){
        if(x==parent[x])return x;
        return parent[x]=Find(parent[x]);
    }
    
    void Union(int x,int y){
        int rootX=Find(x);
        int rootY=Find(y);
        
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                parent[rootY]=rootX;
            }
            else if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
                
            }
            else {
                parent[rootY]=rootX;
                rank[rootX]++;
            }
            noOfDisjointSet--;
        }
    }
    
    bool connected(int x,int y){
        return Find(x)==Find(y);
    }
    
    int getDisjointSet(){
        return noOfDisjointSet;
    }
    
};

bool cmp(vector<int>&a,vector<int>&b){
    return a[0]>b[0];
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),cmp);
        
        UnionFind a=UnionFind(n);
        UnionFind b=UnionFind(n);
        
        int ans=0;
        
        for(auto it:edges){
            int type=it[0];
            int u=it[1]-1;
            int v=it[2]-1;
            if(type==3){
                if(a.connected(u,v)||b.connected(u,v))ans++;
                else {
                    a.Union(u,v);
                    b.Union(u,v);
                }
            }
            else if(type==2){
                if(b.connected(u,v))ans++;
                else {
                    b.Union(u,v);
                }
            }
            else {
                if(a.connected(u,v))ans++;
                else a.Union(u,v);
            }
        }
        
        if(a.getDisjointSet()>1 || b.getDisjointSet()>1)return -1;
        return ans;
    }
};
