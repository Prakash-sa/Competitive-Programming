//https://leetcode.com/problems/queue-reconstruction-by-height/


class Solution {
    static bool cmp(vector<int>&p1,vector<int>&p2){
        if(p1[0]!=p2[0])return p1[0]>p2[0];
        return p1[1]<p2[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>res;
        for(auto &p:people){
            res.insert(res.begin()+p[1],p);
        }
        return res;
    }
};
