//https://leetcode.com/problems/binary-tree-cameras/


class Solution {
    int res;
public:
    int minCameraCover(TreeNode* root) {
        res=0;
        return (dfs(root)<1?1:0)+res;
    }
    int dfs(TreeNode* root){
        if(!root)return 2;
        int left=dfs(root->left),right=dfs(root->right);
        if(left==0 || right==0){
            res++;
            return 1;
        }
        return left==1 || right==1?2:0;
    }
};
