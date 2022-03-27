//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#









class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int>dp;
    
    int traversal(Node* root){
        if(!root)return 0;
        if(dp[root])return dp[root];
        int inc=root->data;
        if(root->left){
            inc+=traversal(root->left->left);
            inc+=traversal(root->left->right);
        }
        if(root->right){
            inc+=traversal(root->right->left);
            inc+=traversal(root->right->right);
        }
        int exc=traversal(root->right)+traversal(root->left);
        dp[root]=max(inc,exc);
        return dp[root];
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        dp.clear();
        return traversal(root);
        
        
    }
};
