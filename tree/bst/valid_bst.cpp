//https://leetcode.com/problems/validate-binary-search-tree/


static bool cmp(int a,int b){return a <= b;}
void in(TreeNode* root, vector<int>& t) {
    if(!root) return;
    in(root->left, t);
    t.push_back(root->val);
    in(root->right, t);
}
bool isValidBST(TreeNode* root) {
    if(!root)return true;
    vector<int> t;
    in(root, t);
    return is_sorted(t.begin(), t.end(),cmp);
}


class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minval=NULL,TreeNode* maxval=NULL) {
        if(!root)return true;
        if((minval && root->val<=minval->val) || (maxval && root->val>=maxval->val))return false;
        return isValidBST(root->left,minval,root)&&isValidBST(root->right,root,maxval);
    }
};