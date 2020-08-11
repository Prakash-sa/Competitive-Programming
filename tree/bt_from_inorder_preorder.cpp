TreeNode* ch(int &r,vector<int>&preorder,map<int,int>&mp,int left,int right){
    if(left<=right){
        TreeNode* root=new TreeNode();
        r++;
        if(left==right){
            root->val=preorder[r];
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        root->val=preorder[r];
        int pos =mp[preorder[r]];
        root->left=ch(r,preorder,mp,left,pos-1);
        root->right=ch(r,preorder,mp,pos+1,right);
        return root;
    }
    return NULL;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0&&inorder.size()==0)return NULL;
    int root=-1;
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
    return ch(root,preorder,mp,0,preorder.size()-1);
}


//---gfg---

Node* ch(int &r,int pre[],map<int,int>&mp,int left,int right){
    if(left>right)return NULL;
    r++;
    Node* root=new Node(pre[r]);
    if(left==right)return root;
    int pos=mp[pre[r]];
    root->left=ch(r,pre,mp,left,pos-1);
    root->right=ch(r,pre,mp,pos+1,right);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int root=-1;
    if(n==0)return NULL;
    map<int,int>mp;
    for(int i=0;i<n;i++)mp[in[i]]=i;
    return ch(root,pre,mp,0,n-1);
}