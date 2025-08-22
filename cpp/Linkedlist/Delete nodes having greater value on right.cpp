//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#




class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next){
            return head;
        }
        head->next=compute(head->next);
        return head->data<head->next->data?head->next:head;
    }
    
};
  
