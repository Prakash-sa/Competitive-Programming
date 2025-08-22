//https://leetcode.com/problems/merge-k-sorted-lists/
//https://www.youtube.com/watch?v=kpCesr9VXDA&ab_channel=TECHDOSE



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
    
    
    struct compare{
        bool operator()(pair<ListNode*,int>a,pair<ListNode*,int>b){
            return a.first->val>b.first->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,compare>pq;
        ListNode* head; ListNode* tail;
        int n=lists.size();
        if(n==0)return NULL;
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)pq.push({lists[i],i});
        }
        if(pq.size()==0)return NULL;
        head=tail=pq.top().first;
        int k=pq.top().second;
        pq.pop();
        lists[k]=lists[k]->next;
        if(lists[k])pq.push({lists[k],k});
        while(!pq.empty()){
            auto tmp=pq.top();
            pq.pop();
            ListNode* ln=tmp.first;
            int id=tmp.second;
            tail->next=ln;
            tail=tail->next;
            lists[id]=lists[id]->next;
            if(lists[id])pq.push({lists[id],id});
        }
        return head;
    }
};
