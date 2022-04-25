//https://leetcode.com/problems/longest-path-with-different-adjacent-characters/





class Solution {
    int ans;
    vector<vector<int>>adj;
    vector<int>dis;
    
    void dfs(int src,string &s){
        dis[src]=1;
        for(auto it:adj[src]){
            dfs(it,s);
            if(s[it]!= s[src]){
                ans=max(ans,dis[src]+dis[it]);
                dis[src]=max(dis[src],dis[it]+1);
            }
        }
    }
    
public:
    int longestPath(vector<int>& parent, string s) {
        adj.resize(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        dis.resize(100001,-1);
        ans=1;
        dfs(0,s);
        return ans;
    }
};
