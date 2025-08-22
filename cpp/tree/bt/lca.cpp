//binary search tree

Node* LCA(Node *root, int n1, int n2)
{

   if(!root)return NULL;
   if(root->data>n1&&root->data>n2)return LCA(root->left,n1,n2);
   if(root->data<n1&&root->data<n2)return LCA(root->right,n1,n2);
   return root;
}


//binary tree

Node* lca(Node* root ,int n1 ,int n2 )
{
   if(!root)return NULL;
   if(root->data==n1||root->data==n2)return root;
   Node* left=lca(root->left,n1,n2);
   Node* right=lca(root->right,n1,n2);
   if(left&&right)return root;
   return (left!=NULL)?left:right;
}
