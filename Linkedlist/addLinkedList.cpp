ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    
    int carry = 0, sum = 0;
    
    sum = A->val + B->val + carry;
    ListNode* newHead = new ListNode(sum%10);
    carry = sum/10;
    A = A->next;
    B = B->next;
    ListNode* newHeadPtr = newHead;
    while( A || B || carry )
    {
        sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        ListNode* temp = new ListNode(sum%10);
        carry = sum/10;
        newHead->next = temp;
        newHead = newHead->next;
        if(A)    A = A->next;
        if(B)    B = B->next;
    }
    return newHeadPtr;
}