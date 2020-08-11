int countLevel(TreeNode* root){
    if(!root)return 0;
    return max(countLevel(root->left),countLevel(root->right))+1;
}

void zigzag(TreeNode* root,int level,vector<vector<int>>&res){
    if(!root)return ;
    res[level].push_back(root->val);
    zigzag(root->left,level+1,res);
    zigzag(root->right,level+1,res);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int level=countLevel(root);
    vector<vector<int>>res(level,vector<int>());
    zigzag(root,0,res);
    for(int i=0;i<res.size();i++){
        if(i%2)reverse(res[i].begin(),res[i].end());
    }
    return res;
}