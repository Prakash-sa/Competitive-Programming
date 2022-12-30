/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


Example 1:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
*/

class Solution {
    vector<vector<int>>ans;
    int n;
    void dfs(vector<vector<int>>&graph,int x,vector<int>&arr){
        if(x==n-1){
            ans.push_back(arr);
            return;
        }

        for(int i=0;i<graph[x].size();i++){
            arr.push_back(graph[x][i]);
            dfs(graph,graph[x][i],arr);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int>arr;
        arr.push_back(0);
        dfs(graph,0,arr);
        return ans;
    }
};