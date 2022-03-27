int findCousinSum(Node* root, int key)
{
    if(!root)return -1;
    if(root->data==key)return -1;
    int cnt=0;
    queue<Node*>q;
    q.push(root);
    bool found=false;
    while(q.size()>0){
        if(found)return cnt;
        cnt=0;
        int size=q.size();
        while(size){
            root=q.front();
            q.pop();
                if((root->left&&root->left->data==key) || (root->right&&root->right->data==key)){
                    found=true;
                }
                else {
                    if(root->left){
                        q.push(root->left);
                        cnt+=root->left->data;
                    }
                    if(root->right){
                        q.push(root->right);
                        cnt+=root->right->data;
                    }
                }
            size--;
        }
    }

    return -1;
}

// ---------------------is cousin---------------------//


bool isSibling(TreeNode* root,int a,int b){
    if(root==NULL)return 0;
    if(root->left&&root->right){
        if(root->left->val==a && root->right->val==b)return true;
        if(root->left->val==b && root->right->val==a)return true;
    }
    return (isSibbling(root->left,a,b) || 
            isSibbling(root->right,a,b));
}

int level(struct Node *root, struct Node *ptr, int lev)
{
    if (root == NULL) return 0;
    if (root == ptr)  return lev;
    int l = level(root->left, ptr, lev+1);
    if (l != 0)  return l;

    return level(root->right, ptr, lev+1);
}

int isCousin(struct Node *root, struct Node *a, struct Node *b)
{
    if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b)))
        return 1;
    else return 0;
}
