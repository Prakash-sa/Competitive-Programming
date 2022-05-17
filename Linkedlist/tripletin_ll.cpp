//https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/






struct Node {
    int data;
    struct Node* next, *prev;
};
 
int countPairs(struct Node* first, struct Node* second, int value)
{
    int count = 0;
 
    while (first != NULL && second != NULL &&
           first != second && second->next != first) {
 
        if ((first->data + second->data) == value) {
 
            count++;
 
            first = first->next;
 
            second = second->prev;
        }
 
        else if ((first->data + second->data) > value)
            second = second->prev;
 
        else
            first = first->next;
    }
 
    return count;
}
 
int countTriplets(struct Node* head, int x)
{
    if (head == NULL)
        return 0;
 
    struct Node* current, *first, *last;
    int count = 0;
 
    last = head;
    while (last->next != NULL)
        last = last->next;
 
    for (current = head; current != NULL; current = current->next) {
 
        first = current->next;
 
        count += countPairs(first, last, x - current->data);
    }
 
    return count;
}
