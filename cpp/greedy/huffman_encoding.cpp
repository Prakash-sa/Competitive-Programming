//https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

/*

Max Heap+bfs

 */


class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node( int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

struct cmp{
  bool operator()( Node*a, Node*b) {
      return a->data>b->data;
  } 
};



class Solution
{
    
    vector<string>ans;
    
    void print(Node* root,string s){
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        print(root->left,s+"0");
        print(root->right,s+"1");
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,cmp>pq;
		    for(int i=0;i<N;i++){
		        pq.push(new Node(f[i]));
		    }
		    
		    while(pq.size()>1){
		        Node* tmp1=pq.top();
		        pq.pop();
		        Node* tmp2=pq.top();
		        pq.pop();
		        Node* newN=new Node(tmp1->data+tmp2->data);
		        newN->left=tmp1;
		        newN->right=tmp2;
		        pq.push(newN);
		    }
		    ans.clear();
		    print(pq.top(),"");
		    return ans;
		}
};
