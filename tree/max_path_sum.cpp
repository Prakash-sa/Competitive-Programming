//https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/#

/*
For each node there can be four ways that the max path goes through the node: 
1. Node only 
2. Max path through Left Child + Node 
3. Max path through Right Child + Node 
4. Max path through Left Child + Node + Max path through Right Child
*/



    int findMaxUtil(Node* root,int &maxn){
        if(!root)return 0;
        
        int l=findMaxUtil(root->left,maxn);
        int r=findMaxUtil(root->right,maxn);
        
        int max_single=max(max(l,r)+root->data,root->data);
        int max_top=max(max_single,l+r+root->data);
        maxn=max(maxn,max_top);
        
        
        return max_single;
    }
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int ans=INT_MIN;
        findMaxUtil(root,ans);
        return ans;
    }
