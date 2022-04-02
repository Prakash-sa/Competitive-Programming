//inorder_successor
//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#

class Solution
{
public:

    void  inorder(Node* root,Node* &prev){
        if(!root)return;
        inorder(root->left,prev);
        if(prev!=NULL)prev->next=root;
        prev=root;
        inorder(root->right,prev);
    }

    void populateNext(Node *root)
    {
        //code here
        Node* prev=NULL;
        inorder(root,prev);
    }
};
