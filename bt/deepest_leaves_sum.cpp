//https://leetcode.com/problems/deepest-leaves-sum/



class Solution {
    int height(TreeNode* root){
        if(!root)return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto tmp=q.front();
                q.pop();
                TreeNode* tree=tmp.first;
                if(tmp.second==h)ans+=tree->val;
                if(tree->left)q.push({tree->left,tmp.second+1});
                if(tree->right)q.push({tree->right,tmp.second+1});
            }
        }
        return ans;
    }
};