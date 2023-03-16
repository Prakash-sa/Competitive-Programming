// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/
/*
    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>
                       1

                   /        \

                [4 2 5]   [6 3 7]       <= inorder array
                [4 5 2]   [6 7 3]       <= postorder array

Now we have new freash problem like need to make tree by using inorder = [4 2 5] && postorder =  [4 5 2] for left subtree
AND inorder = [6 3 7] && postorder = [6 7 3] for right  subtree
**now same process we need to do again and again  until One Of the array dose not got empty
Rest of the Process show in a diagram Form :)

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]       <= inorder array
                [4]    [5]   [6]   [7]       <= postorder array


3rd Phase =>
                 1

               /    \
              2      3

            /  \    /  \             <==== Answer

           4    5  6    7
*/

class Solution
{

    unordered_map<int, int> in;

    TreeNode *traversal(int &p, vector<int> &post, int left, int right)
    {
        if (left > right)
            return NULL;
        p--;
        TreeNode *root = new TreeNode(post[p]);
        if (left == right)
            return root;
        int pos = in[post[p]];
        root->right = traversal(p, post, pos + 1, right);
        root->left = traversal(p, post, left, pos - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int root = inorder.size();
        for (int i = 0; i < inorder.size(); i++)
            in[inorder[i]] = i;
        return traversal(root, postorder, 0, root - 1);
    }
};