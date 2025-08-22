//https://leetcode.com/problems/smallest-string-with-swaps/

//union-find



class UnionFind{
private:
    vector<int>root;
    vector<int>rank;
    
public:
    
    UnionFind(int sz):root(sz),rank(sz){
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int x){
        if(x==root[x])return x;
        return root[x]=find(root[x]);
    }
    
    void unionSet(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty)return;
        if(rank[rootx]>=rank[rooty]){
            root[rooty]=rootx;
            rank[rootx]+=rank[rooty];
        }
        else {
            root[rootx]=rooty;
            rank[rooty]+=rank[rootx];
        }
    }
    
};


class Solution {
    
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        
        for(auto it:pairs){
            int src=it[0];
            int dest=it[1];
            uf.unionSet(src,dest);
        }
        
        unordered_map<int,vector<int>>roottocmpt;
        for(int i=0;i<s.size();i++){
            int root=uf.find(i);
            roottocmpt[root].push_back(i);
        }
        string ans(s.size(),' ');
        for(auto component:roottocmpt){
            vector<int>indixes=component.second;
            
            vector<char>characters;
            for(auto it:indixes){
                characters.push_back(s[it]);
            }
            sort(characters.begin(),characters.end());
            
            for(int i=0;i<indixes.size();i++){
                ans[indixes[i]]=characters[i];
            }
        }
        return ans;    
    }
};



//dfs


class Solution {
    
    vector<vector<int>>adj;
    vector<bool>vis;
    
    string indiceString;
    vector<int>indice;
    
public:
    
    void dfs(string &s,int i){
        vis[i]=true;
        indice.push_back(i);
        indiceString+=s[i];
        for(auto it:adj[i]){
            if(!vis[it])dfs(s,it);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        adj.resize(n);
        vis.resize(n,false);
        for(int i=0;i<pairs.size();i++){
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                indice.clear();
                indiceString="";
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());
                sort(indice.begin(),indice.end());
                for(int i=0;i<indice.size();i++){
                    s[indice[i]]=indiceString[i];
                }
            }
        }
        return s;
    }
};
