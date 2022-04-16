/*
https://leetcode.com/problems/convert-bst-to-greater-tree/

inorder traverse of BST will give an ascending sequence of all values.
By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.


*/






class Solution {
    
    int cur_total;
    
    void traversal(TreeNode* root){
        if(!root)return;
        if(root->right)traversal(root->right);
        cur_total+=root->val;
        root->val=cur_total;
        if(root->left)traversal(root->left);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        cur_total=0;
        traversal(root);
        return root;
    }
};
