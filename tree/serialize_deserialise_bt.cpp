void serialize(Node *root,vector<int> &A)
{
    if(!root){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

/*this function deserializes
 the serialized vector A*/
 int in;
 Node* ch(vector<int>&A){
     if(in>=A.size())return NULL;
     int val=A[in++];
     if(val==-1)return NULL;
     Node* root=new Node(val);
     root->left=ch(A);
     root->right=ch(A);
     return root;
 }
Node * deSerialize(vector<int> &A)
{
   //Your code here
   Node*root;
   in=0;
   root=ch(A);
   return root;
   
}