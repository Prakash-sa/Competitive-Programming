//https://leetcode.com/problems/out-of-boundary-paths/

/*
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
*/


class Solution {
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int mod=1e9+7;
    int n,m;
    vector<vector<vector<int>>>dp;
    int func(int x,int y,int maxMove){
        if(x<0||y<0||x>=m||y>=n)return 1;
        if(dp[x][y][maxMove]!=-1)return dp[x][y][maxMove];
        if(maxMove<=0)return 0;
        int ans=0;
        for(int i=0;i<4;i++){
            ans=(ans+func(x+dx[i],y+dy[i],maxMove-1))%mod;
        }
        return dp[x][y][maxMove]=ans;
    }
    
public:
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        m=_m,n=_n;
        dp.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return func(startRow,startColumn,maxMove);
    }
};