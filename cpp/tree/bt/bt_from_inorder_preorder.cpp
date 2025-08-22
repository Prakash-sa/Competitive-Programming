//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//https://www.youtube.com/watch?v=aZNaLrVebKQ&ab_channel=takeUforward


class Solution {
    map<int,int>mp;
    
    TreeNode* traversal(vector<int>&preorder,int &p,int left,int right){
        if(left>right)return NULL;
        p++;
        TreeNode* root=new TreeNode(preorder[p]);
        if(left==right)return root;
        int pos=mp[preorder[p]];
        
        root->left=traversal(preorder,p,left,pos-1);
        root->right=traversal(preorder,p,pos+1,right);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        if(n==0)return NULL;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
        int p=-1;
        return traversal(preorder,p,0,n-1);
    }
};


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