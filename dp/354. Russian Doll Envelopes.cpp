//https://leetcode.com/problems/russian-doll-envelopes/


class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size();
        vector<int>dp;
        int ans=0;
        for(int i=0;i<envelopes.size();i++){
            auto it=lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            if(it==dp.end()){
                dp.push_back(envelopes[i][1]);
            }
            else if(*it>envelopes[i][1])*it=envelopes[i][1];
        }
        return dp.size();
    }
};
