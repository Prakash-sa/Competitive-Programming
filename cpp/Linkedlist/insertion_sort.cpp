

void insertion(ListNode* &head,int x){
    ListNode* newnode=new ListNode(x);
    if(head==NULL || newnode->val<=head->val){
        newnode->next=head;
        head=newnode;
    }else {
        ListNode* curr=head;
        while(curr->next!= NULL && curr->next->val<newnode->val){
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
}


ListNode* Solution::insertionSortList(ListNode* head) {
    if(head==NULL||head->next==NULL)return head;

    ListNode* ans=NULL;
    ListNode* curr=head;

    while(curr){
        insertion(ans,curr->val);
        curr=curr->next;
    }
    return ans;

}
