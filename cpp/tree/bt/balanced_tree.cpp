//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1



class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root){
        if(!root)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root)return true;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


//most efficient solution


class Solution{
    public:
    
    int height(Node* root){
        if(!root)return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(left==-1 || right==-1)return -1;
        if(abs(left-right)>1)return -1;
        return max(left,right)+1;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root)return true;
        return height(root)!=-1; 
    }
};
