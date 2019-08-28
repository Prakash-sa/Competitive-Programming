#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** next_node,int val){
struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
new_node->next=*next_node;
new_node->data=val;
*next_node=new_node;
}

int cout_pairs(struct Node* head1,struct Node* head2,int val){
	int cnt=0;
	struct Node *p1,*p2;
	for(p1=head1;p1!=NULL;p1=p1->next){
		for(p2=head2;p2!=NULL;p2=p2->next ){
			if(p1->data+p2->data==val)cnt++;
		}
	}
	return cnt;
	
}

int main(){
    struct Node* head1=NULL;
    struct Node* head2=NULL;

    push(&head1,7);
    push(&head1,5);
    push(&head1,1);
    push(&head1,3);
    
    push(&head2,3);
    push(&head2,5);
    push(&head2,2);
    push(&head2,8);
    
    cout<<cout_pairs(head1,head2,10);

}




