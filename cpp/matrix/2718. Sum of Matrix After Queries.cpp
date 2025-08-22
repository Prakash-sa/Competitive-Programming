/*
https://leetcode.com/problems/sum-of-matrix-after-queries/description/

You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].
Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:
if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
Return the sum of integers in the matrix after all queries are applied.

Example 1:
Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
Output: 23
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 

Example 2:
Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
Output: 17
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
*/

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        reverse(queries.begin(),queries.end());
        set<int>row;
        set<int>col;
        long long ans=0;
        for(int i=0;i<queries.size();i++){
            int type=queries[i][0],index=queries[i][1],val=queries[i][2];
            if(type==0){
                if(row.find(index)!=row.end())continue;
                ans+=val*(n-col.size());
                row.insert(index);
            }
            else {
                if(col.find(index)!=col.end())continue;
                ans+=val*(n-row.size());
                col.insert(index);
            }
        }
        return ans;
    }
};