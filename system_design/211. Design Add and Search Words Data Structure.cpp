//https://leetcode.com/problems/design-add-and-search-words-data-structure/


class Trie{
    public:
    Trie* ch[26];
    bool isEnd;
    Trie(){
        memset(ch,NULL,sizeof(ch));
        isEnd=false;
    }
};

class WordDictionary {
    Trie* root;
    
    bool searchWord(string &word,int pos,Trie* node) {
        if(pos==word.size())return node->isEnd;
        if(word[pos]!='.'){
            node=node->ch[word[pos]-'a'];
            return node?searchWord(word,pos+1,node):false;
        }
        for(int i=0;i<26;i++){
            if(node->ch[i] && searchWord(word,pos+1,node->ch[i]))return true;
        }
        return false;
    }
    
public:
    WordDictionary() {
        root=new Trie();
    }
    
    void addWord(string word) {
        Trie* tmp=root;
        for(auto c:word){
            if(!tmp->ch[c-'a'])tmp->ch[c-'a']=new Trie();
            tmp=tmp->ch[c-'a'];
        }
        tmp->isEnd=true;
    }
    
    bool search(string word) {
        return searchWord(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
