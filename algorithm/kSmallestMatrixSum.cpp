//https://leetcode.com/contest/weekly-contest-187/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

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