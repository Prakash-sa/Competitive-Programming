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
  int max1=0;

//--------------level order ---------------------------//
void levelOrder(Node* node)
{
  if(node==NULL)return;
queue<struct Node*>q;
q.push(node);
while(!q.empty()){
    struct Node* ne=q.front();
    cout<<ne->data<<" ";
    q.pop();
    if(ne->left!=NULL)
    q.push(ne->left);
    if(ne->right!=NULL)
    q.push(ne->right);
}



int noleaf(Node* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    else return(noleaf(root->left)+noleaf(root->right));
}