//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#



class Solution {
    
    int countNodes(Node* root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isComplete(Node* root, int k, int cnt) {
        if (!root)
            return true;
        if (k > cnt)
            return false;
        return isComplete(root->left, k << 1, cnt) && isComplete(root->right, k << 1 | 1, cnt);
    }
    bool checkValue(Node* root) {
        if (!root)
            return true;
        if (root->left && root->data < root->left->data)
            return false;
        if (root->right && root->data < root->right->data)
            return false;
        return checkValue(root->left) && checkValue(root->right);
    }
    public:
    bool isHeap(Node* root) {
        int cnt = countNodes(root);
        return isComplete(root, 1, cnt) && checkValue(root);
    }
};
