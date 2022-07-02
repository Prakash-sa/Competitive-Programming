Node * removeDuplicates( Node *head) 
{
 // your code goes here
 set<int>s;
 Node*tmp=head;
 if(!head)return head;
 s.insert(head->data);
 while(head->next){
     int tmp=head->next->data;
     if(s.find(tmp)==s.end()){
         s.insert(head->next->data);
         head=head->next;
     }
     else {
         if(head->next->next){
             head->next=head->next->next;
         }
         else head->next=NULL;
     }
     
 }
 return tmp;
}
