//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/




class Solution {
    
    ListNode* tmp;
    
    TreeNode* create(int start,int end){
        if(start>end)return NULL;
        int mid=(start+end)/2;
        TreeNode* left=create(start,mid-1);
        TreeNode* parent=new TreeNode(tmp->val);
        parent->left=left;
        tmp=tmp->next;
        parent->right=create(mid+1,end);
        return parent;
    }
    
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* t=head;
        int n=0;
        while(t){
            t=t->next;
            n++;
        }
        tmp=head;
        return create(0,n-1);
    }
};

