//https://leetcode.com/problems/recover-binary-search-tree/






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
