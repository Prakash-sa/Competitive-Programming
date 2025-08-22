//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/


//method 1: dp + binary lifting(subsample in 2_ith instead of store all kk ancestors) (dis+huahua) (60 ms, faster than 95.32%)
/*
dp state: 
    dp[i][j] = j-th node's 2^(i)th ancestor in the path 
dp init: 
    dp[i][j] = dp[0][j] (first parent (2^0) of each node is given)
dp trans:
    dp[i][j] = dp[i-1][ dp[i-1][j] ] 
        meaning: A(j, 2^i) = A( A(j, 2^i-1), 2^i-1)
            To find the (2^i)-th ancestor of j, recursively find j-th node's 2^(i-1)th ancestor's 2^(i-1)th ancestor. (2^(i) = 2^(i-1) + 2^(i-1))
*/



class TreeAncestor {
    int LOG;
    vector<vector<int>>up;
    vector<int>depth;
public:
//build dp: O(nlogn)
    TreeAncestor(int n, vector<int>& parent) {
        LOG=0;
        while((1<<LOG)<=n)LOG++;
        up=vector<vector<int>>(n,vector<int>(LOG));
        for(int i=0;i<n;i++)up[i][0]=parent[i];

        //build dp by transition
        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                //j-th node's 2^(i-1)th ancestor
                if(up[i][j-1]==-1){
                    //no more ancestors in 1/2 step
                    up[i][j]=-1;
                }
                else {
                    //j-th node's 2^(i-1)th ancestor's 2^(i-1)th ancestor.
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    //Binary search: O(logn)
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            //try step from 2^(maxPower), 2^(maxPower-1) ...
            if(k&(1<<i)){
                node=up[node][i];
                if(node==-1)return -1;   
            }
        }
        return node;
    }
};

