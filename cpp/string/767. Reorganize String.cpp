//https://leetcode.com/problems/reorganize-string/


class Solution {
public:
    string reorganizeString(string s) {
        vector<int>c(26,0);
        int mostF=0;
        for(auto it:s){
            if(++c[it-'a']>c[mostF])mostF=it-'a';
        }
        if(2*c[mostF]-1>s.size())return "";
        int i=0;
        while(c[mostF]){
            s[i]=mostF+'a';
            c[mostF]--;
            i+=2;
        }
        // i=1;
        for(int j=0;j<26;j++){
            while(c[j]){
                if(i>=s.size())i=1;
                s[i]=j+'a';
                //cout<<s[i]<<" ";
                c[j]--;
                i+=2;
            }
        }
        return s;
    }
};
