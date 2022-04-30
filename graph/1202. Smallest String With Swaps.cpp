//https://leetcode.com/problems/smallest-string-with-swaps/



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
