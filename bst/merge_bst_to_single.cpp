//https://leetcode.com/problems/merge-bsts-to-create-single-bst/







class Solution {
public:
    
    bool traverse(TreeNode* root,unordered_map<int,TreeNode*> &merge,int min_left=INT_MIN,int max_right=INT_MAX){
        if(!root)return true;
        if(root->val<=min_left || root->val>=max_right)return false;
        if(root->right==root->left){
            auto it=merge.find(root->val);
            if(it!=merge.end() && root!=it->second){
                root->left=it->second->left;
                root->right=it->second->right;
                merge.erase(it);
            }
        }
        return traverse(root->left,merge,min_left,root->val) && traverse(root->right,merge,root->val,max_right);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*>merge;
        unordered_map<int,int>cnt;
        
        for(auto &t:trees){
            merge[t->val]=t;
            ++cnt[t->val];
            ++cnt[t->left?t->left->val:0];
            ++cnt[t->right?t->right->val:0];
        }
        
        for(auto &t:trees){
            if(cnt[t->val]==1){
                return traverse(t,merge) && merge.size()==1?t:NULL;
            }
        }
        return NULL;
    }
};
