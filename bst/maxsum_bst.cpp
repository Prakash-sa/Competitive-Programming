//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/




class Solution {
public:
     int traversal(TreeNode* root,int &ans,int &mi,int &ma){
         if(!root)return 0;
         int lmin,lmax,rmin,rmax;
         lmin=rmin=INT_MAX;
         lmax=rmax=INT_MIN;
         int l=traversal(root->left,ans,lmin,lmax);
         int r=traversal(root->right,ans,rmin,rmax);
        int val=l+r+root->val;
         if(lmax<root->val && rmin>root->val){
             ans=max(ans,val);
             mi=min(lmin,root->val);
             ma=max(rmax,root->val);
         }
         else {
             mi=INT_MIN;
             ma=INT_MAX;
         }
         return val;
     }
    
    int maxSumBST(TreeNode* root) {
         int ans=0;
        int mi=INT_MAX,ma=INT_MIN;
         traversal(root,ans,mi,ma);
         return ans;
    }
};
