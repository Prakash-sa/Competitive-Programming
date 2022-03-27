//largest independent set

int LISS(struct Node *root)
{
    if(root==NULL)return 0;
    int lis_ecl;
    lis_ecl=LISS(root->left)+LISS(root->right);
    int lis_inl=1;
    if(root->left){
        lis_inl+=LISS(root->left->left)+LISS(root->left->right);
    }
    if(root->right)lis_inl+=LISS(root->right->left)+LISS(root->right->right);
    return max(lis_inl,lis_ecl);
}
