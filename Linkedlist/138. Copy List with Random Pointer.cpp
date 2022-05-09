//https://leetcode.com/problems/copy-list-with-random-pointer/

//https://www.youtube.com/watch?v=4apaOcK586U&ab_channel=AnujBhaiya

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* cur=head;
        while(cur){
            Node* tmp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=tmp;
            cur=tmp;
        }
        
        cur=head;
        while(cur){
            if(cur->next){
                cur->next->random=cur->random?cur->random->next:NULL;
            }
            cur=cur->next->next;
        }
        
        Node* org=head;
        Node* cpy=head->next;
        Node* ans=cpy;
        while(org){
            org->next=org->next->next;
            if(cpy->next)
            cpy->next=cpy->next->next;
            org=org->next;
            cpy=cpy->next;
        }
        return ans;
    }
};
