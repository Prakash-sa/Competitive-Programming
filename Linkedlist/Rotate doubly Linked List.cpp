//https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/#







class Solution {
public:
    Node *update(Node *head,int k)
    {
        //Add your code here
        Node* tmp=head;
        Node* last=head;
        for(int i=1;i<k;i++)tmp=tmp->next;
        while(last->next!=NULL){
            last=last->next;
        }
        
        last->next=head;
        head->prev=last;
        head=tmp->next;
        tmp->next=NULL;
        head->prev=NULL;
        return head;
    }
};
