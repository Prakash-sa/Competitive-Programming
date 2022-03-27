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