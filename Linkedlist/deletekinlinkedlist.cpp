
ListNode<int> * removeKFromList(ListNode<int> * head, int k) {

    while(head && head->value==k){
        head=head->next;
    }
    ListNode<int> * tmp=head;
    while(tmp && tmp->next){
        if(tmp->next->value==k)tmp->next=tmp->next->next;
        else  tmp=tmp->next;
    }
    return head;
}