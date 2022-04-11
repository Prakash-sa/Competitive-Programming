


//https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1


class Solution
{
    
    vector<bool>vis;
    void dfs(vector<pair<int,int>>pipelines[],int &start,int &end,int &di){
        vis[start]=1;
        for(auto it:pipelines[start]){
            int k=it.first;
            if(vis[k]==0){
                di=min(di,it.second);
                end=k;
                dfs(pipelines,k,end,di);
            }
        }
    }
    
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<pair<int,int>>pipelines[n+1];
        vector<int>in(n+1,0);
        vector<int>out(n+1,0);
        for(int i=0;i<p;i++){
            pipelines[a[i]].push_back({b[i],d[i]});
            in[b[i]]=1;
            out[a[i]]=1;
        }
        vector<vector<int>>res;
        vis.resize(n+1,false);
        for(int i=1;i<=n;i++){
            if(vis[i]==0 && in[i]==0 && out[i]==1){
                int start=i;
                int end;
                int di=INT_MAX;
                dfs(pipelines,i,end,di);
                res.push_back({start,end,di});
            }
        }
        
        
        return res;
    }
};
