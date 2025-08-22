//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

/*
Given a matrix and a target, return the number of non-empty submatrices that sum to target.
A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
if they have some coordinate that is different: for example, if x1 != x1'.


Time O(mnn)
Space O(m)
*/

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