//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#



bool traversal(Node* root,int mi,int ma){
    if(!root)return false;
    if(mi==ma)return true;
    return traversal(root->left,mi,root->data-1)||traversal(root->right,root->data+1,ma);
}


bool isDeadEnd(Node *root)
{
    //Your code here
    return traversal(root,1,INT_MAX);
}
