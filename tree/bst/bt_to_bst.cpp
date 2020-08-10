vector<int>v;

void inorder(struct Node* root){
    if(root==NULL)return ;
    else{
        
        v.push_back(root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

int i=0;
void inorder2(struct Node* root){
    if(root==NULL)return ;
    else{
        inorder2(root->left);
        root->data=v[i++];
        inorder2(root->right);
    }
}

Node *binaryTreeToBST (Node *root)
{
    
    v.clear();
    i=0;
    inorder(root);
    sort(v.begin(),v.end());
    inorder2(root);
    return root;
}