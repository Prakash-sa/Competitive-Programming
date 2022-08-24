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


//leetcode


TreeNode* sorted(vector<int>&nums,int l,int r){
    if(l==r)return NULL;
    int mid=(l+r)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=sorted(nums,l,mid);
    root->right=sorted(nums,mid+1,r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sorted(nums,0,nums.size());
}


//----------------gfg


struct node* construct(int a[],int l,int r){
    if(l>r)return NULL;
    int mid=(l+r)/2;
    node* tmp=newnode(a[mid]);
    if(l==r)return tmp;
    tmp->left=construct(a,l,mid-1);
    tmp->right=construct(a,mid+1,r);
    return tmp;
}
     
int main(){

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n],k;
        for(int i=0;i<n;i++)cin>>a[i];
        struct node* root=NULL;
        root=construct(a,0,n-1);
        preorder(root);
        cout<<endl;
    }
        
}