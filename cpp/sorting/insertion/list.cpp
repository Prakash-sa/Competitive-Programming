// https://leetcode.com/problems/insertion-sort-list/description/

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

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* dummy=new ListNode(0);
        ListNode* cur=head;
        while(cur){
            ListNode* prev=dummy;
            ListNode* nextNode=cur->next;
            while(prev->next!=nullptr && prev->next->val<cur->val){
                prev=prev->next;
            }
            cur->next=prev->next;
            prev->next=cur;
            cur=nextNode;
        }
        return dummy->next;
    }
};

// T: O(n*n)
// S: O(1)