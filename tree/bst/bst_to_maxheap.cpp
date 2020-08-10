void inorderTraversal(Node* root, vector<int>& arr) 
{ 
    if (root == NULL) 
        return; 
  
    // first recur on left subtree 
    inorderTraversal(root->left, arr); 
  
    // then copy the data of the node 
    arr.push_back(root->data); 
  
    // now recur for right subtree 
    inorderTraversal(root->right, arr); 
} 
  
void BSTToMaxHeap(Node* root, vector<int> arr, int* i) 
{ 
    if (root == NULL) 
        return; 
  
    // recur on left subtree 
    BSTToMaxHeap(root->left, arr, i); 
  
    // recur on right subtree 
    BSTToMaxHeap(root->right, arr, i); 
  
    // copy data at index 'i' of 'arr' to 
    // the node 
    root->data = arr[++*i]; 
} 
  
// Utility function to convert the given BST to 
// MAX HEAP 
void convertToMaxHeapUtil(Node* root) 
{ 
    // vector to store the data of all the 
    // nodes of the BST 
    vector<int> arr; 
    int i = -1; 
  
    // inorder traversal to populate 'arr' 
    inorderTraversal(root, arr); 
  
    // BST to MAX HEAP conversion 
    BSTToMaxHeap(root, arr, &i); 
} 