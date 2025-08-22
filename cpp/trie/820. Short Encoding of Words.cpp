//https://leetcode.com/problems/short-encoding-of-words/



class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>s(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            for(int j=1;j<words[i].size();j++){
                s.erase(words[i].substr(j));
            }
        }
        int ans=0;
        for(auto it:s)ans+=it.size()+1;
        return ans;
    }
};
