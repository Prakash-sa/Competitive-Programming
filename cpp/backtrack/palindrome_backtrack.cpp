#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s){
        string tmp=s;
        reverse(s.begin(),s.end());
        return s==tmp;
    }
    
    void backtrack(string s,vector<string>&path,vector<vector<string>>&res,int pos){
        int n=s.size();
        if(pos>=n){
            res.push_back(path);
            return;
        }
        for(int i=1;i<=n-pos;i++){
            if(isPalindrome(s.substr(pos,i))){
                path.push_back(s.substr(pos,i));
                backtrack(s,path,res,pos+i);
                path.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>res;
        backtrack(s,path,res,0);
        return res;
    }
};