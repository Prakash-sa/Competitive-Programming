//https://leetcode.com/problems/count-good-nodes-in-binary-tree/





/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree. 

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
*/


class Solution {
    int cnt;
    
    void dfs(TreeNode* root,int ma){
        if(!root)return;
        ma=max(ma,root->val);
        if(ma<=root->val)cnt++;
        dfs(root->left,ma);
        dfs(root->right,ma);
    }
    
public:
    int goodNodes(TreeNode* root) {
        cnt=0;
        dfs(root,INT_MIN);
        return cnt;
    }
};

