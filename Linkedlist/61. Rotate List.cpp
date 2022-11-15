// https://leetcode.com/problems/rotate-list/description/

/*

Given the head of a linked list, rotate the list to the right by k places.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/

class Solution
{

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        ListNode *current = head;
        int lth = 1;
        current = head;
        while (current->next)
        {
            current = current->next;
            lth++;
        }
        current->next = head;
        k %= lth;
        k = lth - k;
        // current=head;
        while (k-- > 0)
        {
            current = current->next;
        }
        ListNode *tmp = current->next;
        current->next = NULL;
        return tmp;
    }
};