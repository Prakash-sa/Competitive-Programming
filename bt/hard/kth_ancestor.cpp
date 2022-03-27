//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/submissions/



class TreeAncestor {
    int LOG;
    vector<vector<int>>up;
    vector<int>depth;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG=0;
        while((1<<LOG)<=n)LOG++;
        up=vector<vector<int>>(n,vector<int>(LOG));
        for(int i=0;i<n;i++)up[i][0]=parent[i];
        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                if(up[i][j-1]==-1)up[i][j]=-1;
                else up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            if(k&(1<<i)){
                node=up[node][i];
                if(node==-1)return -1;   
            }
        }
        return node;
    }
};

