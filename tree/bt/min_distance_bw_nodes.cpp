//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#






class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* lca(Node* root,int a,int b){
        if(!root)return NULL;
        if(root->data==a || root->data==b)return root;
        Node* left=lca(root->left,a,b);
        Node* right=lca(root->right,a,b);
        if(left&&right)return root;
        return left!=NULL?left:right;
    }
    
    int solve(Node* root,int a,int level){
        if(!root)return INT_MAX;
        if(root->data==a)return level;
        return min(solve(root->left,a,level+1),solve(root->right,a,level+1));
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca1=lca(root,a,b);
        int left=solve(lca1,a,0);
        int right=solve(lca1,b,0);
        return left+right;
        
    }
};

