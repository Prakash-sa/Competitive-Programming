#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double lld;
#define F(i,a,b) for(int i = a; i <= b; i++)
#define RF(i,a,b) for(int i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007

#define max2 1000000


struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* NewNode(int x){
    struct Node* new1=(struct Node*)malloc(sizeof(struct Node));
    new1->data=x;
    new1->left=new1->right=NULL;
    return(new1);
}

int maxdepth(struct Node *root){
    if(root==NULL)return 0;
    else {
        int ldep=maxdepth(root->left);
        int rdep=maxdepth(root->right);
        return max(ldep,rdep)+1;
    }
}

void insert(Node* root,Node* parent,Node* child,char l )
{
    if(root==NULL)return ;
    else{
        if(root->data==parent->data){
            if(l=='l')root->left=child;
            else root->right=child;
        }
        insert(root->left,parent,child,l);
        insert(root->right,parent,child,l);
    }
}


int main(){
int n,k,k1;
cin>>n;
char s;
struct Node *root=NULL,*ptr;
root=NewNode(1);
for(int i=0;i<n;i++){
    cin>>s>>k>>k1;
    Node* parent =new Node();
    parent->data=k;
    Node* child = new Node();
    child->data=k1;
    insert(root,parent,child,s);
}

int k2=maxdepth(root);
cout<<k2;
// int k2=noleaf(root);
// cout<<k2<<endl;


}
