//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                unordered_map<int,int>mp;
                mp[0]++;
                int cur=0;
                for(int k=0;k<m;k++){
                    cur+=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    ans+=mp[cur-target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};