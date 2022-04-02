//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


class Solution {
public:
    int x;
    TreeNode* pre(vector<int>preorder,int bound){
        if(x>=preorder.size() || preorder[x]>bound)return NULL;
        TreeNode* root=new TreeNode(preorder[x++]);
        root->left=pre(preorder,root->val);
        root->right=pre(preorder,bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        x=0;
        return pre(preorder,INT_MAX);
    }
};
