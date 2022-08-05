//https://leetcode.com/problems/merge-two-sorted-lists/



class Solution {
public:
    
    ListNode* ch(ListNode* list1,ListNode* list2){
        ListNode* newn=new ListNode();
        if(list1 && list2){
            if(list1->val<list2->val){
                newn->val=list1->val;
                newn->next=ch(list1->next,list2);
            }
            else {
                newn->val=list2->val;
                newn->next=ch(list1,list2->next);
            }
        }
        else if(!list1&&list2){
            newn->val=list2->val;
            newn->next=ch(list1,list2->next);
        }
        else if(list1&&!list2){
            newn->val=list1->val;
            newn->next=ch(list1->next,list2);
        }
        else return NULL;
        return newn;
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return ch(list1,list2);
        
    }
};


//smaller


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(0);
        ListNode* h=ans;
        while(list1 && list2){
            if(list1->val>list2->val){
                h->next=list2;
                list2=list2->next;
            }
            else {
                h->next=list1;
                list1=list1->next;
            }
            h=h->next;
        }
        if(list1)h->next=list1;
        if(list2)h->next=list2;
        return ans->next;
    }
};