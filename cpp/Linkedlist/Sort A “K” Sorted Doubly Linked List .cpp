//https://www.codingninjas.com/codestudio/problems/sort-a-k-sorted-doubly-linked-list_1118118?leftPanelTab=1



Node *sortedDll(Node *head, int k)
{
    // Write your code here
	priority_queue<int,vector<int>,greater<int>>pq;
	Node* cur=head;
	int cnt=0;
	while(head && cnt<=k){
		pq.push(cur->data);
		cur=cur->next;
		cnt++;
	}
	Node* tmp=head;
	while(cur){
		tmp->data=pq.top();
		pq.pop();
		pq.push(cur->data);
		cur=cur->next;
		tmp=tmp->next;
	}
	while(!pq.empty()){
		tmp->data=pq.top();
		pq.pop();
		tmp=tmp->next;
	}
	return head;
}
