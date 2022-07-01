//https://leetcode.com/problems/longest-univalue-path/



class Solution {
    int ans;
    
    int dfs(TreeNode* root,int t){
        if(!root)return 0;
        int l=dfs(root->left,root->val);
        int r=dfs(root->right,root->val);
        ans=max(ans,l+r);
        if(t==root->val)return max(l,r)+1;
        return 0;
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        dfs(root,0);
        return ans;
    }
};
