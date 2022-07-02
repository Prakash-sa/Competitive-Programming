Node* reverseDLL(Node * head)
{
    //Your code here
    Node*tmp=NULL;
    Node*current=head;
    while(current!=NULL){
        tmp=current->prev;
        current->prev=current->next;
        current->next=tmp;
        current=current->prev;
    }
    if(tmp!=NULL)head=tmp->prev;
    return head;
}


//https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
// reverse by k

Node* reverseByN(Node* head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k) {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k) {
        Node* rest = reverseByN(curr, k);
        head->next = rest;
        if (rest != NULL)
            // it is required for prev link otherwise u wont
            // be backtrack list due to broken links
            rest->prev = head;
    }
    return newHead;
}
