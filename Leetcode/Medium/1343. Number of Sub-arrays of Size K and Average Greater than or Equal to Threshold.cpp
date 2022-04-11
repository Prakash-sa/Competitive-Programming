/*
https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/


*/



class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int t=k*threshold;
        int sum=0;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(i>=k)sum-=arr[i-k];
            if(i>=k-1 && sum>=t)cnt++;
        }
        return cnt;
    }
};
