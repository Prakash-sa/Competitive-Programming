//https://practice.geeksforgeeks.org/problems/k-sum-paths/1/#






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
