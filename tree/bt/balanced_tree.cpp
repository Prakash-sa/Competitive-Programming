//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1



class Solution{
    public:

     int height(Node* root){
         if(!root)return 0;
         return max(height(root->right),height(root->left))+1;
     }
     bool isBalanced(Node *root)
     {
         //  Your Code here
         if(!root)return true;
         int left=height(root->left);
         int right=height(root->right);
         if(abs(left-right)>1)return false;
         bool rel=isBalanced(root->left);
         bool rer=isBalanced(root->right);
         if( !rel|| !rer)return false;
         return true;
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
