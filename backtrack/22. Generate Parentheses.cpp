//https://leetcode.com/problems/generate-parentheses/




class Solution {
    vector<string>ans;
    
    void solve(string &s,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        if(open>0){
            s.push_back('(');
            solve(s,open-1,close);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                solve(s,open,close-1);
                s.pop_back();
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s="";
        solve(s,n,n);
        return ans;
    }
};
