/*
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            auto first = q.front().second;
            auto second = q.back().second;
            ans = max((long long)ans, (long long)second - first + 1);
            for (int i = 0; i < cnt; i++)
            {
                auto p = q.front();
                int idx = p.second - first + 1;
                q.pop();
                if (p.first->left)
                    q.push({p.first->left, (long long)2 * idx + 1});
                if (p.first->right)
                    q.push({p.first->right, (long long)2 * idx + 2});
            }
        }
        return ans;
    }
};