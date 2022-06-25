//https://leetcode.com/problems/match-substring-after-replacement/

//brute force

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> m;
        for(auto &p:mappings){
            m[p[0]].insert(p[1]);
        }
        for(int i=0,j=0;i+sub.size()<=s.size();i++){
            for(j=0;j<sub.size();j++){
                if(s[i+j]!=sub[j] && m[sub[j]].count(s[i+j])==0)break;
            }
            if(j==sub.size())return true;
        }
        return false;
    }
};


// KMP algo


vector<int> compute_lps(string &s, unordered_map<char, unordered_set<char>> &m) {
    vector<int> lps(s.size());
    for (int i = 1, j = 0; i < s.size(); ++i) {
        while (j && (s[i] != s[j] && m[s[i]].count(s[j]) == 0 && m[s[j]].count(s[i]) == 0))
            j = max(0, lps[j] - 1);
        j += s[i] == s[j] || m[s[i]].count(s[j]) || m[s[j]].count(s[i]);
        lps[i] = j;
    }
    return lps;
}
bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    unordered_map<char, unordered_set<char>> m;
    for (auto &p : mappings)
        m[p[0]].insert(p[1]);
    auto lps = compute_lps(sub, m);    
    for (int i = 0, j = 0; i < s.size();) {
        if (s[i] == sub[j] || m[sub[j]].count(s[i])) {
            ++i;
            ++j;
        }
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;            
        }
        if (j == sub.size())
            return true;
    }
    return false;
}

