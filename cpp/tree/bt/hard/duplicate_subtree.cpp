//https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#




unordered_map<string,int>mp;
vector<Node*>ans;
string traversal(Node* root,vector<Node*>&path){
    if(!root)return "";
    string left=traversal(root->left,path);
    string right=traversal(root->right,path);
    string s=to_string(root->data)+"$"+left+"$"+right;
    if(mp[s]==1)ans.push_back(root);
    mp[s]++;
    return s;
}


vector<Node*> printAllDups(Node* root)
{
    // Code here
    mp.clear();
    ans.clear();
    vector<Node*>path;
    traversal(root,path);
    return ans;
}

