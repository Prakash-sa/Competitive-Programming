//https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#

//Two trees are called isomorphic if one can be obtained from another by a series of flips,
// i.e. by swapping left and right children of several nodes. 
// Any number of nodes at any level can have their children swapped.



class Solution{
  public:
    // Return True if the given trees are isomorphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
        if(!root1 && !root2)return true;
        if(!root1 || !root2)return false;
        if(root1->data!=root2->data)return false;
        int l=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
        int r=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
        return l|r;
    }
};

