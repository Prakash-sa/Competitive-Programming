//https://leetcode.com/problems/evaluate-division/


/*

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

*/




class Solution {
    
    unordered_map<string,vector<pair<string,double>>>adjList;
    unordered_map<string,bool>vis;
    double queryAns;
    
    bool dfs(string start,string end,double product){
        if(start==end && adjList.find(start)!=adjList.end()){
            queryAns=product;
            return true;
        }
        vis[start]=true;
        bool tmpAns=false;
        
        for(auto it:adjList[start]){
            if(!vis[it.first]){
                tmpAns=dfs(it.first,end,product*it.second);
                if(tmpAns)break;
            }
        }
        vis[start]=false;
        return tmpAns;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size(),m=queries.size();
        vector<double>ans(m);
        for(int i=0;i<n;i++){
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1/values[i]});
            vis[equations[i][1]]=false;
            vis[equations[i][0]]=false;
        }
        
        for(int i=0;i<m;i++){
            queryAns=1;
            bool pathAns=dfs(queries[i][0],queries[i][1],1);
            if(pathAns)ans[i]=queryAns;
            else ans[i]=-1;
        }
        return ans;
    }
};
