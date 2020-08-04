Node* deleteNode(Node *head,int x)
{
    Node*tmp=head;
    if(x==1){
        head=head->next;
        return head;
    }
    x-=2;
    while(x--){
        tmp=tmp->next;
    }
    Node*nxt=tmp->next;
    tmp->next=tmp->next->next;
    free(nxt);
    return head;
}

//doubly 


void deleteNode(Node **head_ref, int x)
{
  //Your code here
   if(head_ref==NULL){
      return ;
  }
  struct Node *temp=*head_ref;
  if(x==1){
      (*head_ref)=temp->next;
      temp->next->prev=NULL;
      return;
  }
  int c=0;
  while(temp!=NULL){
      c++;
      if(c==x){
            if(temp->next==NULL){
                temp->prev->next=NULL;
                return;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            return ;
      }
      temp=temp->next;
  }
}