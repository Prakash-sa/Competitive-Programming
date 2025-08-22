//https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1/


//Word break

class TrieNode{
  
  public:
  TrieNode* node[26];
  bool is_end;
  TrieNode(){
      for(int i=0;i<26;i++)node[i]=NULL;
      is_end=false;
  }
  
  bool search(TrieNode* root,string s){
      TrieNode* tmp=root;
      for(auto it:s){
          int num=it-'a';
          if(!tmp->node[num])return false;
          tmp=tmp->node[num];
      }
      return tmp->is_end;
  }
};

class Trie{
  
  TrieNode* root;
  public:
  TrieNode* getNode(){
      return root;
  }
  
  Trie(vector<string>s){
      root=new TrieNode();
      for(auto it:s){
          insert(root,it);
      }
  }
  
  void insert(TrieNode* root,string s){
      TrieNode* tmp=root;
      for(auto it:s){
          int num=it-'a';
          if(!tmp->node[num])tmp->node[num]=new TrieNode();
          tmp=tmp->node[num];
      }
      tmp->is_end=true;
  }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int ch(string s,TrieNode* root){
        int size=s.size();
        if(size==0)return 1;
        
        for(int i=1;i<=size;i++){
            if(root->search(root,s.substr(0,i)) && ch(s.substr(i,size-1),root))return 1;
        }
        return 0;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie* trie=new Trie(B);
        TrieNode* root=trie->getNode();
        return ch(A,root);
    }
};
