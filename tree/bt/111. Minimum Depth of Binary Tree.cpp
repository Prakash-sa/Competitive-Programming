//https://leetcode.com/problems/minimum-depth-of-binary-tree/ 



class Solution {
public:
    
    int ans;
    
    void minCal(TreeNode* root,int level){
        if(!root->left && !root->right){
            ans=min(ans,level);
        }
        if(root->left)minCal(root->left,level+1);    
        if(root->right)minCal(root->right,level+1);
    }
    
    int minDepth(TreeNode* root) {
        ans=INT_MAX;
        if(!root)return 0;
        minCal(root,1);
        return ans;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right)return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
