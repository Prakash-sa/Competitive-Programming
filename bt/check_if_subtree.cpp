bool areIdentical(Node * root1, Node *root2)  
{  
    if (root1 == NULL && root2 == NULL)  
        return true;  
  
    if (root1 == NULL || root2 == NULL)  
        return false;  
    return (root1->data == root2->data &&  
            areIdentical(root1->left, root2->left) &&  
            areIdentical(root1->right, root2->right) );  
}  
bool isSubTree(Node* T, Node* S) {
    if(!S)return true;
    if(!T)return false;
    
    int l=areIdentical(T,S);
    if(l==1)return true;
    return isSubTree(T->left,S)||
    isSubTree(T->right,S);
}