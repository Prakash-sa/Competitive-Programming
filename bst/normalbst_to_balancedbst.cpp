//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/#








vector<int>ans;

void inorder(Node* root){
    if(!root)return ;
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

Node* inorderBST(int s,int e){
    if(s>e)return NULL;
    int mid=(s+e)/2;
    Node* root=new Node(ans[mid]);
    root->left=inorderBST(s,mid-1);
    root->right=inorderBST(mid+1,e);
    return root;
}

Node* buildBalancedTree(Node* root)
{
    ans.clear();
    inorder(root);
    return inorderBST(0,ans.size()-1);
}

