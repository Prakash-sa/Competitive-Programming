//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#



//merge sort
Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node* result;

    if (a->data < b->data) 
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }

    else 
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}


Node *flatten(Node *root)
{
    
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}


//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#













class Solution{
    
    
    Node* merge(Node* a,Node* b){
        if(!a)return b;
        if(!b)return a;
        Node* result;
        if(a->data>b->data){
            result=b;
            result->next=merge(a,b->next);
        }
        else {
            result=a;
            result->next=merge(a->next,b);
        }
        return result;
    }
    
  public:
    //Function to merge K sorted linked list.
    
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           for(int i=0;i<k-1;i++){
               arr[i+1]=merge(arr[i],arr[i+1]);
           }
           return arr[k-1];
    }
};

