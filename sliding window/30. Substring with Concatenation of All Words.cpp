/*

https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string s and an array of strings words of the same length. 
Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, 
in any order, and without any intervening characters.
You can return the answer in any order. 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.



Approach : We are using Hashing & Sliding Window Technique to solve the above problem.
Let’s see the steps :
    Declare a map wordCount which stores all words count
    Select a window of size wordsWindow (total number of characters produced if all the words are concatenated).
    Check if that window is possible to build using our wordCount map.
    If True, add the starting index to our result vector
    Increasing the window by 1 & check until we are able to select wordsWindow size window.
*/




class Solution {
    
    bool checkSubstring(unordered_map<string,int>wordCount,string s,int wordLen){
        for(int j=0;j<s.size();j+=wordLen){
            string w=s.substr(j,wordLen);
            if(wordCount.find(w)!=wordCount.end()){
                if(--wordCount[w]==-1)return false;
            }
            else return false;
        }
        return true;
    }
    
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int wordLen=words[0].size();
        int sLen=s.size();
        int wordsWindow=words.size()*wordLen;
        
        unordered_map<string,int>wordCount;
        for(int i=0;i<words.size();i++){
            wordCount[words[i]]++;
        }
        int i=0;
        
        while(i+wordsWindow<=sLen){
            if(checkSubstring(wordCount,s.substr(i,wordsWindow),wordLen)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};