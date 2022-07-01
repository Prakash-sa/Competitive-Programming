//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#


class Solution {
  public:
  
    unordered_map<string,int>mp;
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string traversal(Node* root){
        if(!root) return "$";
        string tmp="";
        if(!root->left && !root->right){
            tmp=to_string(root->data);
            return tmp;
        }
        tmp+=to_string(root->data);
        tmp+=traversal(root->left);
        tmp+=traversal(root->right);
        if(tmp.size()>2)mp[tmp]++;
        return tmp;
    }
    int dupSub(Node *root) {
         // code here
         mp.clear();
         traversal(root);
         for(auto x:mp){
             if(x.second>=2)return 1;
         }
         return 0;
    }
};
