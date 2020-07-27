TreeNode* ch(vector<int>&v,int s,int e){
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(v[mid]);
    if(mid-s>0){
        root->left=ch(v,s,mid-1);
    }
    if(e-mid>0)root->right=ch(v,mid+1,e);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A)return NULL;
    vector<int>v;
    while(A){
    v.push_back(A->val);
    ListNode* temp = A;
    A = A->next;
    delete temp;
}
    TreeNode* root=ch(v,0,v.size()-1);
    return root;
}