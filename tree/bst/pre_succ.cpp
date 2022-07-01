//pre and succ
//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(!root)return;
    
    Node* curr=root;
    //succ
    while(curr){
        if(curr->key>key){
            suc=curr;
            curr=curr->left;
        }
        else curr=curr->right;
    }
    
    curr=root;
    //pre
    while(curr){
        if(curr->key<key){
            pre=curr;
            curr=curr->right;
        }
        else curr=curr->left;
    }

}
