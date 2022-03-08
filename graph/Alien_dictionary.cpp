
//by dfs

class Solution{
    public:
    unordered_map<char,bool>vis;
    unordered_map<char,vector<char>>adj;
    
    void dfs(stack<char>&s,char x){
        vis[x]=true;
        for(auto it:adj[x]){
            if(!vis[it])dfs(s,it);
        }
        s.push(x);
    }
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        for(int i=0;i<N-1;i++){
            string tmp1=dict[i];
            string tmp2=dict[i+1];
            int j=0;
            while(j<tmp1.size()&&j<tmp2.size()){
                if(tmp1[j]!=tmp2[j]){
                    adj[tmp1[j]].push_back(tmp2[j]);
                    vis[tmp1[j]]=vis[tmp2[j]]=false;
                    break;
                }
                j++;
            }
        }
        stack<char>s;
        for(auto it=vis.begin();it!=vis.end();it++){
            if(!it->second)dfs(s,it->first);
        }
        
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
        
    }
};



// indegree


class Solution{
    public:
    unordered_map<char,bool>vis;
    unordered_map<char,vector<char>>adj;
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char,int>indegree;
        for(int i=0;i<N-1;i++){
            string tmp1=dict[i];
            string tmp2=dict[i+1];
            int j=0;
            while(j<tmp1.size()&&j<tmp2.size()){
                if(tmp1[j]!=tmp2[j]){
                    adj[tmp1[j]].push_back(tmp2[j]);
                    if(indegree.find(tmp1[j])==indegree.end())
                    indegree[tmp1[j]]=0;
                    indegree[tmp2[j]]++;
                    break;
                }
                j++;
            }
        }
        
        queue<char>q;
        for(auto it:indegree){
            if(it.second==0)q.push(it.first);
        }
        string ans="";
        while(!q.empty()){
            char tmp1=q.front();
            q.pop();
            ans+=tmp1;
            for(auto it:adj[tmp1]){
                if(--indegree[it]==0)q.push(it);
            }
        }
        //if(ans.size()!=N)return "";
        return ans;
        
    }
};

