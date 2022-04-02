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


//

//Function that constructs BST from its preorder traversal
int i;
Node* bst(int in[],int h,int max_val){
    if(i==h || in[i]>max_val)return NULL;
    Node* root=newNode(in[i++]);
    root->left=bst(in,h,root->data);
    root->right=bst(in,h,max_val);
    return root;
}

Node* post_order(int pre[], int size)
{
    i=0;
    return bst(pre,size,INT_MAX);
}
