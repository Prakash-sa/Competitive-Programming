void mirror(Node* node) 
{
     if(node==NULL)return;
     if(node->left==NULL&&node->right==NULL)return;
     mirror(node->left);
     mirror(node->right);
     Node* n=node->left;
     node->left=node->right;
     node->right=n;
}

//-----------------------------------
int findMirrorRec(int target, struct Node* left,struct Node* right)
{
    if (left==NULL || right==NULL)return 0;

    if (left->key == target)return right->key;

    if (right->key == target)return left->key;

    int mirror_val = findMirrorRec(target,left->left,right->right);
    if (mirror_val)return mirror_val;
    findMirrorRec(target, left->right, right->left);
}

int findMirror(struct Node* root, int target)
{
    if (root == NULL)
        return 0;
    if (root->key == target)
        return target;
    return findMirrorRec(target, root->left, root->right);
}