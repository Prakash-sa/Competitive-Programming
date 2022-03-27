//Phone directory



//https://practice.geeksforgeeks.org/problems/phone-directory4628/1#





class TrieNode{
  
  public:
  TrieNode* node[26];
  vector<int>index;
  bool is_end;
  
  TrieNode(){
      for(int i=0;i<26;i++)node[i]=NULL;
      is_end=false;
      index.clear();
  }
  
};

class Trie{
    TrieNode*root;
    public:
    TrieNode* getNode(){
        return root;
    }
    
    Trie(string s[],int n){
        root=new TrieNode();
        for(int i=0;i<n;i++)insert(root,s[i],i);
    }
    
    void  insert(TrieNode* root1,string s,int x){
        TrieNode* tmp=root1;
        for(auto it:s){
            int num=it-'a';
            if(!tmp->node[num])tmp->node[num]=new TrieNode();
            
            tmp=tmp->node[num];
            tmp->index.push_back(x);
        }
        tmp->is_end=true;
    }
     
};


class Solution{
    TrieNode* root;
    void findContactUtil(TrieNode* root,vector<string> &res,string s){
        if(!root)return;
        TrieNode* temp = root;
        if(temp->is_end){
            res.push_back(s);
        }
        for(int i=0;i<26;i++){
            char ch = char(i+'a');
            findContactUtil(temp->node[i],res,s+ch);
        }
    }
    void findContact(string s,vector<string> &res){
        TrieNode* temp = root;
        for(int i=0;i<s.size();i++){
            int idx = s[i]-'a';
            if(!temp->node[idx]){
                return ;
            }
            temp = temp->node[idx];
        }
        findContactUtil(temp,res,s);
    }
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* trie=new Trie(contact,n);
        root=trie->getNode();
        TrieNode* tmp=root;
        vector<vector<string>>res;
        for(int i=1;i<=s.size();i++){
            vector<string> temp;
            findContact(s.substr(0,i),temp);
            if(temp.size()==0){
                temp.push_back(to_string(0));
            }else{
                sort(temp.begin(),temp.end());    
            }
            res.push_back(temp);
        }
        
        
        
        // for(int i=0;i<s.size();i++){
        //     //cout<<s[i]<<" ";
        //     int num=s[i]-'a';
        //     vector<string>s_list;
        //     if(!tmp->node[num]){
        //         s_list.push_back("0");
        //         res.push_back(s_list);   
        //         continue;
        //     }
        //     for(auto it:tmp->index){
        //         //cout<<it<<" ";
        //         s_list.push_back(contact[it]);
        //     }
        //     //cout<<endl;
        //     res.push_back(s_list);
        //     tmp=tmp->node[num];
        // }
        return res;
    }
};
