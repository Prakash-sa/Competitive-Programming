//https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

/*
You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
You are allowed to choose exactly one element from each row to form an array.
Return the kth smallest array sum among all possible arrays.
 
Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.
*/

int kthSmallest(vector<vector<int>>& mat, int k) {
    vector<int>row=mat[0];
    for(int i=1;i<mat.size();i++){
        vector<int>nr;
        for(int j=0;j<mat[i].size();j++){
            for(auto ns:row){
                nr.push_back(ns+mat[i][j]);
            }
        }
        int k1=min(k,int(nr.size()));
        sort(nr.begin(),nr.end());
        row.resize(k1);
        for(int j=0;j<k1;j++)row[j]=nr[j];
    }
    return row[k-1];
}