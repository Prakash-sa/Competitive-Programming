#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return(node);
}
void preorder(struct node* node)
{
    //cout<<"hidf";
    if(node)
    {
        //cout<<"dknfk";
        cout<<node->data<<endl;    //Printf root->data
        preorder(node->left);    //Go to left subtree
        preorder(node->right);     //Go to right subtree
    }
}
struct node * find(struct node* node, ll key){
    if(node){
        if(node->data == key)
            return node;
        else if(node->data > key)
            return find(node->left, key);
        else
            return find(node->right, key);
    }else
        return NULL;
}
struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);
    else
    {
        //Otherwise, recur down the tree
        if (data <= node->data)
            node->left  = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        //return the (unchanged) root pointer
        return node;
    }
}

int main()
{
    int n;
    cin>>n;
    int t1,t[n];
    char s;
    int k1,k2;
    struct node *root = NULL,*ptr;
    cin>>t1;
    root=newNode(t1);
    for(ll i=0;i<n-1;i++){
            cin>>t[i];
            insert(root,t[i]);
    }
    ll q;
    cin>>q;
    //cout<<root<<" ";
   ptr=find(root,q);
   //cout<<ptr;
   //cout<<ptr;
  // cout<<ptr->data<<endl;
   preorder(ptr);

  return 0;
}
