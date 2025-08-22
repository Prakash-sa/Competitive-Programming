int _getIntesectionNode(int d, Node* head1, Node* head2); 
  
/* function to get the intersection point of two linked  
lists head1 and head2 */
int getIntesectionNode(Node* head1, Node* head2) 
{ 
  
    // Count the number of nodes in 
    // both the linked list 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    // If first is greater 
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
} 
  
/* function to get the intersection point of two linked  
lists head1 and head2 where head1 has d more nodes than  
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
    // Stand at the starting of the bigger list 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    // Move the pointer forward 
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    // Move both pointers of both list till they 
    // intersect with each other 
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        // Move both the pointers forward 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
} 