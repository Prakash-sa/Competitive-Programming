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


//https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    stack<int>st;
    st.push(a[n-1]);
    vector<int>ans(n);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && st.top()<a[i]){
            st.pop();
        }
        if(st.size()==0){
            ans[i]=-1;
        }
        else {
            ans[i]=st.top();
        }
        st.push(a[i]);
    }
    
    for(int i=0;i<n;i++)cout<<a[i]<<" "<<ans[i]<<endl;
    return 0;
}
