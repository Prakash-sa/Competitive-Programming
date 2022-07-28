//https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target)return true;
            matrix[i][j]>target?j--:i++;
        }
        return false;
    }
};

/*
Use binary search.

n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};


//https://leetcode.com/problems/search-a-2d-matrix-ii/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(matrix[i][j]==target)return true;
            matrix[i][j]>target?j--:i++;
        }
        return false;
    }
};
