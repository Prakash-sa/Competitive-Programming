//https://practice.geeksforgeeks.org/problems/largest-bst/1#


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int traversal(Node* &root,int &ans,int &mi,int &ma){
        if(!root)return 0;
        int lmin,lmax,rmin,rmax;
        lmin=rmin=INT_MAX;
        lmax=rmax=INT_MIN;
        int l=traversal(root->left,ans,lmin,lmax);
        int r=traversal(root->right,ans,rmin,rmax);
        int val=l+r+1;
        if(lmax<root->data && rmin>root->data){
            ans=max(ans,val);
            mi=min(root->data,lmin);
            ma=max(root->data,rmax);
        }
        else {
            mi=INT_MIN;
            ma=INT_MAX;
        }
        return val;
    }
    
    int largestBst(Node *root)
    {
        if(!root)return 0;
        int ans=0;
        int mi=INT_MIN,ma=INT_MAX;
        traversal(root,ans,mi,ma);
        return ans;
    }
};
