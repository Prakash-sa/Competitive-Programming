//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#






class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> tmp=q.front();
            q.pop();
            if(mp[tmp.second]==0)mp[tmp.second]=tmp.first->data;
            if(tmp.first->left)q.push({tmp.first->left,tmp.second-1});
            if(tmp.first->right)q.push({tmp.first->right,tmp.second+1});
        }
        
        vector<int>res;
        for(auto it:mp)res.push_back(it.second);
        return res;
        
    }

};
