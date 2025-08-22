//https://leetcode.com/contest/weekly-contest-189/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& com) {
        int n=com.size();
        vector<int>ans;
        for(auto &c:com)sort(begin(c),end(c));
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<n&&!f;j++){
                if(i!=j)
                    f=includes(begin(com[j]),end(com[j]),begin(com[i]),end(com[i]));
            }
            if(!f)ans.push_back(i);
        }
        return ans;
        
    }
};