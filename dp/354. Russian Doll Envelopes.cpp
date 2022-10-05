//https://leetcode.com/problems/russian-doll-envelopes/

/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/


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
