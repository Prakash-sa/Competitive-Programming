https://leetcode.com/problems/restore-ip-addresses/submissions/

class Solution {
public:
    
    vector<string>ans;
    
    void backtrack(string &s,int i=0,int dotcount=0,string tmp="" ){
        if(i>=s.length())return ;
        if(dotcount==3){
            string rem = s.substr(i);
            if(rem.length() > 1 && rem[0] == '0') return;
            if(rem.length() < 3)
                tmp+=rem;
            else if(rem.length() == 3 && atoi(rem.c_str()) <= 255)
                tmp+=rem;
            else return;
            ans.push_back(tmp);
        }
        
        string t="";
        for(int k=i;k<i+3;k++){
            t+=s[k];
            if(atoi(t.c_str())<=255){
                backtrack(s,k+1,dotcount+1,tmp+t+".");
            }
            if(k==i && s[k]=='0')break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12)return {};
        backtrack(s);
        return ans;
    }
};