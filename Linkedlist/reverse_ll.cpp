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


struct node *reverse (struct node *head, int k)
{ 
    int cnt=0;
    node*cur=head;
    node*next=nullptr;
    node*prev=nullptr;
    while(cur && cnt<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        cnt++;
    }
    if(next)head->next=reverse(next,k);
    return prev;
    
}
