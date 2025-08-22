//https://leetcode.com/problems/sum-of-total-strength-of-wizards/



class Solution {
public:
    int totalStrength(vector<int>& s) {
        long long res = 0, sz = s.size(), mod = 1000000007;
        vector<int> ps_l(sz + 1), pm_l(sz + 1); // prefix sum and prefix mul from the left.
        vector<int> ps_r(sz + 1), pm_r(sz + 1); // ... from the right.
        vector<int> st; // mono-decreasing stack.
        for (long long i = 0; i < sz; ++i) {
            ps_l[i + 1] = (ps_l[i] + s[i]) % mod;
            pm_l[i + 1] = (pm_l[i] + (i + 1) * s[i]) % mod;
        }
        for (int i = sz - 1; i >= 0; --i) {
            ps_r[i] = (ps_r[i + 1] + s[i]) % mod;
            pm_r[i] = (pm_r[i + 1] + (sz - i) * s[i]) % mod;
        }        
        for (int right = 0; right <= sz; ++right) {
            while(!st.empty() && (right == sz || s[st.back()] >= s[right])) {
                int pivot = st.back();
                st.pop_back();
                long long left = st.empty() ? 0 : st.back() + 1;
                long long left_sum = (mod + pm_l[pivot + 1] - pm_l[left] - left * (ps_l[pivot + 1] - ps_l[left]) % mod) % mod;
                long long right_sum = (mod + pm_r[pivot + 1] - pm_r[right] - (sz - right) * (ps_r[pivot + 1] - ps_r[right])) % mod;
                long long all_sum = (right_sum * (pivot - left + 1) + left_sum * (right - pivot)) % mod;
                res = (res + all_sum * s[pivot]) % mod;
            }
            st.push_back(right);
        }
        return res;
    }
};
