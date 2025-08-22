// https://leetcode.com/problems/longest-consecutive-sequence/ 


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int ans=0;
        for(auto num:st){
            if (!st.count(num - 1)) {
                int cnt = 1;
                int k = num;
                while (st.count(k + 1)) {
                    k++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
