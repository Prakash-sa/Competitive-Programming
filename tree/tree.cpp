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
    int maxDepth(struct node* node)
    {
        if (node==NULL)
            return 0;
        else
        {
             /* compute the depth of each subtree */
              int lDepth = maxDepth(node->left);
              int rDepth = maxDepth(node->right);

              /* use the larger one */
              if((lDepth+rDepth+1)>max1)
                  max1=lDepth+rDepth+1;


              if (lDepth > rDepth)
                    return(lDepth+1);
              else
                   return(rDepth+1);
       }
    }
    int findMirrorRec(int target, struct Node* left,
                              struct Node* right)
    {
    /* if any of the Node is none then Node itself
       and decendent have no mirror, so return
       none, no need to further explore! */
    if (left==NULL || right==NULL)
        return 0;

    /* if left Node is target Node, then return
       right's key (that is mirror) and vice
       versa */
    if (left->key == target)
        return right->key;

    if (right->key == target)
        return left->key;

    // first recur external Nodes
    int mirror_val = findMirrorRec(target,
                                     left->left,
                                     right->right);
    if (mirror_val)
        return mirror_val;

    // if no mirror found, recur internal Nodes
    findMirrorRec(target, left->right, right->left);
}

// interface for mirror search
int findMirror(struct Node* root, int target)
{
    if (root == NULL)
        return 0;
    if (root->key == target)
        return target;
    return findMirrorRec(target, root->left, root->right);
}

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


//--------largest Independent set--------------------//
int LISS(struct Node *root)
{
    if(root==NULL)return 0;
    int lis_ecl;
    lis_ecl=LISS(root->left)+LISS(root->right);
    int lis_inl=1;
    if(root->left){
        lis_inl+=LISS(root->left->left)+LISS(root->left->right);
    }
    if(root->right)lis_inl+=LISS(root->right->left)+LISS(root->right->right);
    return max(lis_inl,lis_ecl);
}
//------------------------------------------------//

//mirror of tree
void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node* temp;

        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);

        /* swap the pointers in this node */
        temp     = node->left;
        node->left = node->right;
        node->right = temp;
    }
}


int main()
{
    int n,t;
    cin>>t>>n;
    string s;
    int k;
    struct node *root = NULL,*ptr;
    root=newNode(n);
    while(--t){

        cin>>s>>k;
        int i=0;
        ptr=root;
        while(s[i] && ptr ){
            if(s[i] == 'L'){
                if(ptr->left == NULL)
                    ptr->left = newNode(0);
                ptr = ptr->left;

            }
            else{
                if(ptr->right == NULL)
                    ptr->right = newNode(0);
                ptr = ptr->right;

            }
            i++;
        }

        ptr->data=k;

    }

   // maxDepth(root);
    //cout<<k<<endl;
    //cout<<max1<<endl;


  return 0;
}
