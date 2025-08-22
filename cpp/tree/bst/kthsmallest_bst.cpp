#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 

int kthLargest(Node* root, int *i, int k)
{
    if (root == nullptr)
        return INT_MAX;
    int left = kthLargest(root->right, i, k);
    if (left != INT_MAX)
        return left;
    if (++*i == k)
        return root->data;
    return kthLargest(root->left, i, k);
}

int kthLargest(Node* root, int k)
{
    int i = 0;
    return kthLargest(root, &i, k);
}


int kthsmallest(Tree<int>* root,int *i,int k){
    if(root==NULL)return INT_MAX;
    int left=kthsmallest(root->left,i,k);
    if(left!=INT_MAX)return left;
    if(++*i==k)return root->value;
    return kthsmallest(root->right,i,k);
}
int kthSmallestInBST(Tree<int> * t, int k) {
    int i=0;
    return kthsmallest(t, &i,k);
}



Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

Node* insert(Node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    return node; 
} 

int main() 
{ 
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    for (int k=1; k<=7; k++) 
    cout << kthSmallestInBST(root, k) << " "; 

    return 0; 
} 
