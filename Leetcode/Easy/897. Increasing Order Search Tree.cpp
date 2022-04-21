//https://leetcode.com/problems/increasing-order-search-tree/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* ans;
    TreeNode* tmp;
public:
    // TreeNode* increasingBST(TreeNode* root,TreeNode* tail=NULL) {
    //     if(!root)return tail;
    //     TreeNode* res=increasingBST(root->left,root);
    //     root->left=NULL;
    //     root->right=increasingBST(root->right,tail);
    //     return res;
    // }
    
    void traversal(TreeNode* root){
        if(!root)return ;
        traversal(root->left);
        if(tmp){
            tmp->right=root;
        }
        else {
            ans=root;
        }
        root->left=NULL;
        tmp=root;
        traversal(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        ans=NULL;
        tmp=NULL;
        traversal(root);
        return ans;
    }
};
