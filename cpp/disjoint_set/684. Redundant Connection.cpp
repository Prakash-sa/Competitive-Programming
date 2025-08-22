//https://leetcode.com/problems/redundant-connection/description/
// https://www.youtube.com/watch?v=1lNK80tOTfc
/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

class Solution {

    int findParent(vector<int>&parent,int x){
        if(parent[x]==x)return x;
        return parent[x]=findParent(parent,parent[x]);
    }

    bool unionEdges(vector<int>&parent,vector<int>&rank,int x,int y){
        int p1=findParent(parent,x);
        int p2=findParent(parent,y);
        if(p1==p2)return false;
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else {
            parent[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0);
        vector<int>rank(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        for(auto it:edges){
            if(!unionEdges(parent,rank,it[0],it[1]))return it;
        }

        return {};
    }
};

