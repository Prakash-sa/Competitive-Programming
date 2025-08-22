// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        int n=s.size();
        vector<string>bucket(n+1,"");
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        string ans="";
        for(int i=n;i>=0;i--){
            for(auto c:bucket[i]){
                ans.append(i,c);
            }
        }
        return ans;
    }
};

