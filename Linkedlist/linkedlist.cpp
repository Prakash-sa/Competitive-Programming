#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);



struct LinkedList{
    int data;
    struct LinkedList *next;
 };

 
typedef struct LinkedList *node; //Define node as pointer of data type struct LinkedList

node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}

node addNode(node head, int value){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value; // add element's value to data part of node
    if(head == NULL){
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}


struct Node{
  int data;
  Node* next;
  Node(int val){
    data=val;
    next=NULL;
  }
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




