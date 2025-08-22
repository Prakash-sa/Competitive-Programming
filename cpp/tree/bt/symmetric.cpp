/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 
*/


bool isValid(TreeNode* t1,TreeNode*t2){
    if(!t1 && !t2)return true;
    if(!t1 || !t2)return false;
    return (t1->val==t2->val)
    &&isValid(t1->left,t2->right)
    &&isvalid(t1->right,t2->left);
}


bool isSymmetric(TreeNode* root){
    return isValid(root,root);
}

// iterative

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* t1=q.front();q.pop();
            TreeNode* t2=q.front();q.pop();
            if(!t1 && !t2)return true;
            if(!t1||!t2)return false;
            if(t1->val!=t2->val)return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
