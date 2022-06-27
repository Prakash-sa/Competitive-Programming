//https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/



class Solution {
    vector<bitset<1001>>children;
    vector<vector<int>>graph;
    vector<int>subX;
    
    pair<int,bitset<1001>>dfs(int node,int parent,vector<int>&nums){
        int subTreeX=nums[node];
        bitset<1001>bits;
        bits[node]=1;
        for(auto &v:graph[node]){
            if(v!=parent){
                auto ret=dfs(v,node,nums);
                subTreeX^=ret.first;
                bits|=ret.second;
            }
        }    
        children[node]=bits;
        subX[node]=subTreeX;
        return {subTreeX,bits};
    }
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        graph.resize(n);
        subX.resize(n,0);
        children.resize(n);
        for(auto & i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);  
        }
        
        dfs(0,-1,nums);
        int ans=INT_MAX;
        for(int i=0;i<edges.size()-1;i++)
            for(int j=i+1;j<edges.size();j++){
                // for edge (a,b) i will make "a" as parent "b" .Same for (c,d)
                int a=edges[i][0],b=edges[i][1],c=edges[j][0],d=edges[j][1];
				// if b is parent of a then swap the values to make a as parent
                if(!children[a][b])
                    swap(a,b);
                if(!children[c][d])
                    swap(c,d);
                // now b and d are the root node of two seprated subtrees
                int x,y,z;
                // if both are two distinct subtrees
                if(!children[b][d] && !children[d][b]){
                    x=subX[b];y=subX[d];z=subX[0]^x^y;
                }
                // if b is children of d
                else if(!children[b][d] && children[d][b]){
                    x=subX[b];y=subX[d]^x;z=subX[0]^subX[d];
                }
                // if d is children of b
                else{
                    x=subX[d];y=subX[b]^x;z=subX[0]^subX[b];                    
                }
                ans=min(ans,max(x,max(y,z))-min(x,min(y,z)));
            }
        return ans;
    }
};

