class Trie {
public:
    /** Initialize your data structure here. */
    Trie* next[26];
    bool isword=false;
    Trie() {
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* tmp=this;
        for(auto c:word){
            int i=c-'a';
            if(tmp->next[i]==0)tmp->next[i]=new Trie();
            tmp=tmp->next[i];
        }
        tmp->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* tmp=this;
        for(auto c:word){
            int i=c-'a';
            if(tmp->next[i]==0)return false;
            tmp=tmp->next[i];
        }
        return tmp->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* tmp=this;
        for(auto c:prefix){
            int i=c-'a';
            if(tmp->next[i]==0)return false;
            tmp=tmp->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */