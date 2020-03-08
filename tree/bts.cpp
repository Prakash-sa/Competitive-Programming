#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);


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
//   int max1=0;
// int maxDepth(struct node* node) 
//     {
//         if (node==NULL) 
//             return 0;
//         else
//         {
//              /* compute the depth of each subtree */
//               int lDepth = maxDepth(node->left);
//               int rDepth = maxDepth(node->right);

//               /* use the larger one */
//               if((lDepth+rDepth+1)>max1)
//                   max1=lDepth+rDepth+1;
              
              
//               if (lDepth > rDepth) 
//                     return(lDepth+1);
//               else 
//                    return(rDepth+1);
//        }
//     } 
void inorder(struct node*root)
    {
        if(root)
        {
            inorder(root->left);    //Go to left subtree
            printf("%d ",root->data);    //Printf root->data
            inorder(root->right);     //Go to right subtree
        }
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

    void postorder(struct node*root)
    {
        if(root)
        {
            postorder(root->left);    //Go to left sub tree
            postorder(root->right);     //Go to right sub tree
            printf("%d ",root->data);    //Printf root->data
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

    void median1(node* root,vector<int>&v){
        if(root==NULL) return ;
        else{
            median1(root->left,v);
            cout<<root->data<<" ";
            median1(root->right,v);
        }
    }

int isBSTUtil(Node* root,int min,int max){
    if(root==NULL)return true;
    if(root->data<min||root->data>max)return false;
    return isBSTUtil(root->left,min,root->data-1)&&isBSTUtil(root->right,root->data+1,max);
    
}
bool isBST(Node* root) {
    
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

void printLevelOrder(Node *root) 
{ 
    if (root == NULL)  return; 
  
    queue<Node *> q; 
  
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
  
        if (node->left != NULL) 
            q.push(node->left); 
  
        if (node->right != NULL) 
            q.push(node->right); 
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
    postorder(root);

  return 0; 
}
