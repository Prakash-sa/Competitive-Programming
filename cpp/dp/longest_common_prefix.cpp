class Solution {
    string lcp(string p,string s){
        string ans="";
        for(int i=0;i<min(p.size(),s.size());i++){
            if(p[i]!=s[i])break;
            ans+=p[i];
        }
        return ans;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty())return "";
        string ans=strs[0];
        for(int i=0;i<strs.size();i++){
            ans=lcp(ans,strs[i]);
            cout<<ans.size()<<" ";
        }
        return ans;
    }
};