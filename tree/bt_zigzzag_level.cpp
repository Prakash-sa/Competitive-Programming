int countLevel(TreeNode* root){
    if(!root)return 0;
    return max(countLevel(root->left),countLevel(root->right))+1;
}

void zigzag(TreeNode* root,int level,vector<vector<int>>&res){
    if(!root)return ;
    res[level].push_back(root->val);
    zigzag(root->left,level+1,res);
    zigzag(root->right,level+1,res);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int level=countLevel(root);
    vector<vector<int>>res(level,vector<int>());
    zigzag(root,0,res);
    for(int i=0;i<res.size();i++){
        if(i%2)reverse(res[i].begin(),res[i].end());
    }
    return res;
}

//



vector <int> zigZagTraversal(Node* root)
    {
        vector<int>ans;
    	// Code here
    	queue<Node*>q;
    	q.push(root);
    	bool level=false;
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>tmp;
    	    for(int i=0;i<size;i++){
        	    Node* k=q.front();
        	    q.pop();
        	    if(!k)continue;
        	    tmp.push_back(k->data);
        	    q.push(k->left);
        	    q.push(k->right);
    	    }
    	    level=!level;
    	    if(!level){
    	        reverse(tmp.begin(),tmp.end());
    	    }
    	    for(auto it:tmp)ans.push_back(it);
    	}
    	return ans;
    	
    }
