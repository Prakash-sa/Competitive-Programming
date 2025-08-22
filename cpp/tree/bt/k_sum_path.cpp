//Path sum 1
//https://leetcode.com/problems/path-sum/

/*
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.
*/


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum,int current=0) {
        if(!root)return false;
        current+=root->val;
        if(!root->left && !root->right){
            if(current==targetSum)return true;
        }
        return hasPathSum(root->left,targetSum,current) || hasPathSum(root->right,targetSum,current);
    }
};



//https://leetcode.com/problems/path-sum-ii/
//Path Sum 2

/*
Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.
*/


class Solution {
private:
    vector<vector<int>>res;
    
    void traversal(TreeNode* root,vector<int>&ans,int targetSum,int sum){
        if(!root)return ;
        sum+=root->val;
        ans.push_back(root->val);
        if(sum==targetSum && !root->left && !root->right){
            res.push_back(ans);
        }
        traversal(root->left,ans,targetSum,sum);
        traversal(root->right,ans,targetSum,sum);
        ans.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        vector<int>ans;
        traversal(root,ans,targetSum,0);
        return res;
    }
};




//https://practice.geeksforgeeks.org/problems/k-sum-paths/1/#

//https://leetcode.com/problems/path-sum-iii/

/*
Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.
*/




class Solution{
  public:
//   unordered_map<int,int>mp;
//   int ans;
//   void traversal(Node* root,int cs,int s){
//       if(!root)return;
//       int tmp=cs+root->data;
//       ans+=mp[tmp-s];
//       mp[tmp]++;
//       traversal(root->left,tmp,s);
//       traversal(root->right,tmp,s);
//       mp[tmp]--;
//   }
//     int sumK(Node *root,int k)
//     {
//         // code here
//         ans=0;
//         mp.clear();
//         mp[0]=1;
//         traversal(root,0,k);
//         return ans;
//     }

    int cnt;
    void traversal(Node* root,vector<int>&path,int k){
        if(!root)return;
        path.push_back(root->data);
        traversal(root->left,path,k);
        traversal(root->right,path,k);
        int sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==k)cnt++;
        }
        path.pop_back();
    }

    int sumK(Node *root,int k)
    {
        // code here
        cnt=0;
        vector<int>path;
        traversal(root,path,k);
        return cnt;
    }
    
};

//Simple one

class Solution {
    
    int traversal(TreeNode* root,long long targetSum){
        if(!root)return 0;
        return (root->val==targetSum) + traversal(root->left,targetSum-root->val)+traversal(root->right,targetSum-root->val);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        return traversal(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};


