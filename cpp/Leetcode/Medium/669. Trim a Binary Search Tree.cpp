//https://leetcode.com/problems/trim-a-binary-search-tree/

/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. 
Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). 
It can be proven that there is a unique answer. Return the root of the trimmed binary search tree. 
Note that the root may change depending on the given bounds.
 

Example 1:

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

*/
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
