Node* deleteNode(Node *head,int x)
{
    Node*tmp=head;
    if(x==1){
        head=head->next;
        return head;
    }
    x-=2;
    while(x--){
        tmp=tmp->next;
    }
    Node*nxt=tmp->next;
    tmp->next=tmp->next->next;
    free(nxt);
    return head;
}