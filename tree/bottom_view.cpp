void bottomView(Node *root)
{
   queue<pair<Node*,int>>q;
   int val=0;
   map<int,int>mp;
   q.push({root,val});
   while(!q.empty()){
       pair<Node*,int>cut;
       cut=q.front();
       Node* newr=cut.first;
       q.pop();
       mp[cut.second]=cut.first->data;
       if(cut.first->left!=NULL)q.push({cut.first->left,cut.second-1});
       if(cut.first->right!=NULL)q.push({cut.first->right,cut.second+1});
   }
   for(auto it=mp.begin();it!=mp.end();it++)cout<<it->second<<" ";   
}
