int Solution::lPalin(ListNode* A) {
    stack<int>st;
    ListNode*tmp=A;
    while(tmp){
        st.push(tmp->val);
        tmp=tmp->next;
    }
    tmp=A;
    while(tmp){
        int k=st.top();
        st.pop();
        if(tmp->val!=k)return false;
        tmp=tmp->next;
        
    }
    return 1;
}

bool isPalindrome(Node *head)
{
    Node *tmp=head;
    deque<int>dq;
        while(tmp!=NULL){
            dq.push_back(tmp->data);
            tmp=tmp->next;
        }
        while(dq.size()>1){
            if(dq.front()==dq.back()){
                dq.pop_back();
                dq.pop_front();
            }
            else return false;
        }
    
    return true;
}


