//https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/





    bool isCompleteBT(Node* root){
        //code here
        
        queue<Node*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            Node* tmp=q.front();
            q.pop();
            if(tmp==NULL){
                flag=true;
            }
            else {
                if(flag)return false;
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return true;
    }

