//https://leetcode.com/problems/trim-a-binary-search-tree/


class Solution {
    
public:
    TreeNode* trimBST(TreeNode* root, int l, int h,bool top=true) {
        if(!root)return NULL;
        root->left=trimBST(root->left,l,h,false);
        root->right=trimBST(root->right,l,h,false);
        if(root->val<=h && root->val>=l)return root;
        auto result=root->val<l?root->right:root->left;
        if(!top)delete(root);
        return result;
    }
};
