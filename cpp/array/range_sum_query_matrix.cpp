/*



Really good explanation by Tushar Roy: https://www.youtube.com/watch?v=PwDqpOMwg6U

*/

//Query Time:-O(N)


class NumMatrix {
    int n,m;
    vector<vector<int>>preA;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        preA.resize(n,vector<int>(m));
        preA=matrix;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)preA[i][j]+=preA[i][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            sum+=preA[i][col2]-(col1>0?preA[i][col1-1]:0);
        }
        return sum;
    }
};



//Query Time:-O(1)


class NumMatrix {
    int n,m;
    vector<vector<int>>preA;
public:

    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        preA.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)preA[i][j]=preA[i-1][j]+preA[i][j-1]+matrix[i-1][j-1]-preA[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return preA[row2][col2]-preA[row1-1][col2]-preA[row2][col1-1]+preA[row1-1][col1-1];
    }
};
