/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

bool isPalindrome(ListNode* head) {
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* nxt=nullptr;
    ListNode* prev=nullptr;
    while(slow){
        nxt=slow->next;
        slow->next=prev;
        prev=slow;
        slow=nxt;
    }
    while(prev){
        if(prev->val!=head->val)return false;
        prev=prev->next;
        head=head->next;
    }
    return true;
}

