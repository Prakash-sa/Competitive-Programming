//https://leetcode.com/problems/swap-nodes-in-pairs/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* tmp;
        tmp=head->next;
        head->next=swapPairs(head->next->next);
        tmp->next=head;
        return tmp;
    }
};
