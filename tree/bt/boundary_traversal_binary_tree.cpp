//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#


class Solution {
public:

    void leftBoundary(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left!=NULL)
            leftBoundary(root->left, ans);
        else
            leftBoundary(root->right, ans);
    }
    void leafTraversal(Node* root, vector<int> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
    }
    void rightBoundary(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right!=NULL)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        
        //left boundary
        leftBoundary(root->left, ans);
        
        //leaf Traversal
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        
        //right boundary
        rightBoundary(root->right, ans);
        return ans;
    }
};
