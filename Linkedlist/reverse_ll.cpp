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



//https://leetcode.com/problems/reverse-linked-list-ii/

/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

head = [1,2,3,4,5], left = 2, right = 4

First locate the node before the m-th node (pre) and the m-th node (cur). 
Then movecur -> next to be after pre for n - m times.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(0), *prev=dummy,*cur;
        dummy->next=head;
        for(int i=0;i<left-1;i++)prev=prev->next;
        cur=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode* tmp=prev->next;
            prev->next=cur->next;
            cur->next=cur->next->next;
            prev->next->next=tmp;
        }
        
        return dummy->next;
    }
};


