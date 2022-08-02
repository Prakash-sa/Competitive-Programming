//https://leetcode.com/problems/recover-binary-search-tree/

/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure. 

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
*/




class Solution {
    TreeNode *first,*second,*prev;
    
    void traversal(TreeNode* root){
        if(!root)return;
        traversal(root->left);
        if(prev){
            if(root->val<prev->val){
                if(!first)first=prev;
                second=root;
            }
        }
        prev=root;
        traversal(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first=second=prev=NULL;
        traversal(root);
        swap(first->val,second->val);
    }
};
