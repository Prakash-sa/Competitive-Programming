//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/


/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k. 

Example 1:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

*/



class Solution {
    
    int solve(vector<int>&arr,int k){
        int tmp=0;
        set<int>s;
        s.insert(0);
        int res=INT_MIN;
        for(int i=0;i<arr.size();i++){
            tmp+=arr[i];
            auto it=s.lower_bound(tmp-k);
            if(it!=s.end()){
                res=max(res,tmp-*it);
            }
            s.insert(tmp);
        }
        return res;
    }
    
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            vector<int>a(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    a[k]+=matrix[k][j];
                }
                ans=max(ans,solve(a,k));
            }
        }
        return ans;
    }
};