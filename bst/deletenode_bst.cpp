//https://leetcode.com/problems/delete-node-in-a-bst/submissions/

Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
Node *deleteNode(Node *root,  int key)
{
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
          struct Node* temp = minValueNode(root->right); 
          root->data = temp->data; 
          root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
    
}


//easy one
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val==key){
            if(!root->left && !root->right) return NULL; 
            if(!root->right){
                TreeNode* left=root->left;
                delete(root);
                return left;
            }
            else {
                TreeNode* rightT=root->right;
                while(rightT->left)rightT=rightT->left;
                swap(root->val,rightT->val);
                root->right=deleteNode(root->right,key);
                return root;
            }
        }
        if(root->val>key)root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        return root;
    }
};
