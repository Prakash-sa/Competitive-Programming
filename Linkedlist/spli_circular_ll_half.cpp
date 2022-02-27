//https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1



void splitList(Node *head, Node **head1, Node **head2)
{
    // your code goes here
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(fast_ptr->next!=head && fast_ptr->next->next!=head){
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    
    if(fast_ptr->next->next==head){
        fast_ptr=fast_ptr->next;
    }
    *head1=head;
    if(head->next!=head){
        *head2=slow_ptr->next;
    }
    fast_ptr->next=slow_ptr->next;
    slow_ptr->next=head;
}
