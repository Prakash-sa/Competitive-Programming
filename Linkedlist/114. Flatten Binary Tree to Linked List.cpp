//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/





class Solution {
    
    TreeNode* prev;
    
    void traversal(TreeNode* root){
        if(!root)return;
        
        traversal(root->right);
        
        traversal(root->left);
        root->right=prev; 
        root->left=NULL;
        prev=root;
    }
    
public:
    void flatten(TreeNode* root) {
        traversal(root);
    }
};
