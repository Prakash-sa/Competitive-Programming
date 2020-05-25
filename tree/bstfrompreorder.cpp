class Solution {
    TreeNode* insertBST(TreeNode* root,int key){
        if(!root)return new TreeNode(key);
        if(key<root->val){
            root->left=insertBST(root->left,key);
        }
        if(key>root->val)root->right=insertBST(root->right,key);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode();
        root=NULL;
        for(int i=0;i<preorder.size();i++){
            root=insertBST(root,preorder[i]);
        }
        return root;
    }
};