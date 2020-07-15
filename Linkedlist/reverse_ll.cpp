struct Node* reverseList(struct Node *head)
{
    Node* current=head;
    Node* next=NULL;
    Node* prev=NULL;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
