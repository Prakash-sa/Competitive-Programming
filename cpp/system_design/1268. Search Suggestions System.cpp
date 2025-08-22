//https://leetcode.com/problems/search-suggestions-system/


class TrieNode{
  public:
    TrieNode* children[26];
    bool isNext;
    TrieNode(){
        for(int i=0;i<26;i++)children[i]=NULL;
        isNext=false;
    }
};

class Trie{
    TrieNode* root;
  public:
    Trie(vector<string>arr){
        root=new TrieNode();
        for(auto s:arr)insert(s);
    }
    
    TrieNode* getNode(){
        return root;
    }
    
    void insert(string s){
        TrieNode* tmp=root;
        for(auto c:s){
            int index=c-'a';
            if(tmp->children[index]==NULL)tmp->children[index]=new TrieNode();
            tmp=tmp->children[index];
        }
        tmp->isNext=true;
    }
    
    
};

class Solution {
    TrieNode* root;
    vector<string>res;
    void dfs(TrieNode* node,string &word){
        if(res.size()==3)return;
        if(node->isNext)res.push_back(word);
        
        for(char c='a';c<='z';c++){
            if(node->children[c-'a']){
                word+=c;
                dfs(node->children[c-'a'],word);
                word.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        Trie* trie=new Trie(products);
        root=trie->getNode();
        for(int i=0;i<searchWord.size();i++){
            res.clear();
            if(root->children[searchWord[i]-'a']==NULL){
                for(;i<searchWord.size();i++)ans.push_back(res);
                return ans;
            }
            root=root->children[searchWord[i]-'a'];
            string word=searchWord.substr(0,i+1);
            dfs(root,word);
            ans.push_back(res);
        }
        return ans;
    }
};


