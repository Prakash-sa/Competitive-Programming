//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        vector<int>ans;
        if(s.size()<p.size())return ans;
        int cnt1[26]={0},cnt2[26]={0};
        for(auto c:p)cnt1[c-'a']++;
        for(int i=0;i<n;i++)cnt2[s[i]-'a']++;
        
        for(int i=0;i<=s.size()-n;i++){
            for(int j=0;j<26;j++){
                if(cnt1[j]!=cnt2[j])break;
                if(j==25 && cnt1[j]==cnt2[j])ans.push_back(i);
            }
            if(i+n>=s.size())break;
            cnt2[s[i+n]-'a']++;
            cnt2[s[i]-'a']--;
        }
        return ans;
        
    }
};