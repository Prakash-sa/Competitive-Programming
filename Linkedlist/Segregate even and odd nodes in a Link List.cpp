//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1





class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* e=NULL;
        Node* o=NULL;
        Node* even=NULL;
        Node* odd=NULL;
        while(head){
            if(head->data%2==0){
                if(even==NULL){
                    e=head;
                    even=e;
                }
                else {
                    e->next=head;
                    e=e->next;
                }
            }
            else {
                if(odd==NULL){
                    odd=head;
                    o=odd;
                }
                else {
                    o->next=head;
                    o=o->next;
                }
            }
            head=head->next;
        }
        
        if(e)e->next=odd;
        if(o)o->next=NULL;
        if(even)return even;
        return odd;
    }
};


