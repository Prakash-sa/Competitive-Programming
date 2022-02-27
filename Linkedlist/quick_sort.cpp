//https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1


node* partition(node* head,node* tail){
   int pivot=head->data;
   node* p=head;
   node* q=head;
   while(q!=tail){
       if(q->data<pivot){
           p=p->next;
           swap(p->data,q->data);
       }
       q=q->next;
   }
   swap(p->data,head->data);// do not swap with pivot swap with originsl list
   return p;
}
void quick(node* head,node* tail){
   if(head!=tail){
       node* pivot=partition(head,tail);
       quick(head,pivot);
       quick(pivot->next,tail);
   }
}
void quickSort(struct node **headRef) {
   quick(*headRef,NULL);
}
