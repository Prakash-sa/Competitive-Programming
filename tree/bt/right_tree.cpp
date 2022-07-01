int maxl;
void ch(Node* root,int level){
    if(!root)return ;
    if(maxl<level){
        cout<<root->data<<" ";
        maxl=level;
    }
    ch(root->right,level+1);
    ch(root->left,level+1);
}

void rightView(Node *root)
{
   if(!root)return;
   maxl=0;
   cout<<root->data<<" ";
   ch(root,0);
}

