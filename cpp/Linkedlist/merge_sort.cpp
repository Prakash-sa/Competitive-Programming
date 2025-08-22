//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#    


    Node* merge(Node* head1, Node* head2)
    {
        Node* merged = new Node(-1);
        Node* temp = merged;
       
        // While head1 is not null and head2
        // is not null
        while (head1 != NULL && head2 != NULL) {
            if (head1->data < head2->data) {
                temp->next = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
       
        // While head1 is not null
        while (head1 != NULL) {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
       
        // While head2 is not null
        while (head2 !=NULL) {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return merged->next;
    }
    
    Node* findMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if (head->next == NULL)
            return head;
 
        Node* mid = findMid(head);
        Node* head2 = mid->next;
        mid->next = NULL;
        Node* newHead1 = mergeSort(head);
        Node* newHead2 = mergeSort(head2);
        Node* finalHead = merge(newHead1, newHead2);
 
        return finalHead;
    }
