//https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=1<<k;
        vector<bool>got(need,false);
        int allone=need-1;
        int hashVal=0;
        for(int i=0;i<s.size();i++){
            hashVal=((hashVal<<1)&allone)|(s[i]-'0');
            if(i>=k-1 && !got[hashVal]){
                need--;
                got[hashVal]=true;
                if(need==0)return true;
            }
        }
        return false;
    }
};
