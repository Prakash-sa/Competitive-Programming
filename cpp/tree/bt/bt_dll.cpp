//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1






class Solution
{
    public:
    int f;
    
    void traversal(Node* root,Node* &head,Node* &prev){
        if(!root)return;
        traversal(root->left,head,prev);
        if(f){
            f=0;
            head=root;
            prev=root;
        }
        else {
            prev->right=root;
            prev->right->left=prev;
            prev=prev->right;
        }
        traversal(root->right,head,prev);
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head=NULL;
        Node* prev=NULL;
        f=1;
        traversal(root,head,prev);
        return head;
    }
};
