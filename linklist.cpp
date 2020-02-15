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

// tree
struct node
    {
         int data;                 //Data element
         struct node * left;          //Pointer to left node
         struct node * right;         //Pointer to right node
    };

    struct node root;

    struct node * root;
    root=(node * )malloc(sizeof(node));


    struct node * newnode(int element)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        temp->data=element;
        temp->left=temp->right=NULL;
        return temp;
    }
    int maxDepth(struct node* node) 
    {
        if (node==NULL) 
            return 0;
        else
        {
             /* compute the depth of each subtree */
              int lDepth = maxDepth(node->left);
              int rDepth = maxDepth(node->right);

              /* use the larger one */
              if (lDepth > rDepth) 
                    return(lDepth+1);
              else 
                   return(rDepth+1);
       }
    } 