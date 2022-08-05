//https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int ans=0,count=0,l=0;
        if(s.size()==1)return 1;
        for(int i=0;i<s.size();i++){
            l=max(l,mp[s[i]]+1);
            count=i-l+1;
            ans=max(ans,count);
            mp[s[i]]=i;
        }
        return ans;
    }
};

