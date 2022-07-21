#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
//---------------------------code-------------------------//

void pushit(Node* root,vector<int>&v){
    if(root==NULL)return ;
    v.push_back(root->data);
    pushit(root->left,v);https://xhamster18.desi/videos/big-tit-brunette-zeynep-rossa-gives-sensual-titty-fuck-and-cock-ride-s14-e5-xhfgmbj
    pushit(root->right,v);
}
vector<int> merge(Node *root1, Node *root2)
{
   vector<int>v;
   pushit(root1,v);
   pushit(root2,v);
   sort(v.begin(),v.end());
   return v;
}


//---------------------------code-----------------------------//
void insertNodes(BinaryTreeNode<int>* root,stack<BinaryTreeNode<int>*> &s){
    
    
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
    
}

BinaryTreeNode<int>* printMergeTrees( BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    stack<BinaryTreeNode<int>*> s1;
   stack<BinaryTreeNode<int>*> s2;
   
   // 1.First, push all the elements from root to the left-most leaf node onto a stack. Do this for both trees 
   insertNodes(root1,s1);
   insertNodes(root2,s2);
   
   while(!s1.empty() || !s2.empty()){
       
       // 2. Peek at the top element of each stack (if non-empty) and print the smaller one. 
       // If one the stack empty assign INT_MAX to value coming from that stack
       int a=(!s1.empty() ? s1.top()->data:INT_MAX);
       int b=(!s2.empty() ? s2.top()->data:INT_MAX);
       
       if(a<=b){
           cout<<a<<" ";
           BinaryTreeNode<int>*temp=s1.top();
           //3. Pop the element off the stack that contains the element we just printed
           s1.pop();
           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s1);
       }
       else{
           cout<<b<<" ";
           BinaryTreeNode<int>* temp=s2.top();
           //3. Pop the element off the stack that contains the element we just printed
           s2.pop();
           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s2);
           
       }
   }
    
    
}