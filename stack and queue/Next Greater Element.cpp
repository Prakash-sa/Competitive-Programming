//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#





class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>st;
        st.push(arr[n-1]);
        vector<long long>ans(n);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top())st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
