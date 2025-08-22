//https://leetcode.com/problems/longest-cycle-in-a-graph/

/*
Borrow the idea of indexing nodes from Tarjan's algorithm. 
Obviously each node can have at most one "next" node, so a recursion is not needed. 
Simply track the path and label each node with an increamenting index until we meet one that already has an index. 
We then check if the index is in our current path and update the answer.
*/

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int res=-1;
        vector<int>ind(edges.size());
        for(int i=0,k=1;i<edges.size();i++){
            int j=i,cur=k;
            while(j!=-1 && !ind[j]){
                ind[j]=k++;
                j=edges[j];
            }
            if(j!=-1 && ind[j]>=cur)res=max(res,k-ind[j]);
        }
        return res;
    }
};