//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/

Node* ch(int &r,int post[],map<int,int>&mp,int left,int right){
    if(left>right)return NULL;
    r--;
    Node* root=new Node(post[r]);
    if(left==right)return root;
    int pos = mp[post[r]];
    root->right=ch(r,post,mp,pos+1,right);
    root->left=ch(r,post,mp,left,pos-1);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int root=n;
    if(n==0)return NULL;
    map<int,int>mp;
    for(int i=0;i<n;i++)mp[in[i]]=i;
    return ch(root,post,mp,0,n-1);
}