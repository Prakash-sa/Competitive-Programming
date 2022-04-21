//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/



class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(prices[n-1]);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && prices[i]<st.top())st.pop();
            if(st.empty())ans[i]=0;
            else ans[i]=st.top();
            st.push(prices[i]);
        }
        for(int i=0;i<n;i++)ans[i]=prices[i]-ans[i];
        return ans;
    }
};
