//https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/


class Solution {
    
    vector<vector<vector<int>>>dp;
    
    bool dfs(int x,int y,int oc,vector<vector<char>>&grid){
        int n=grid.size(),m=grid[0].size();
        if(x == n || y == m || oc < 0) return false;
        if(x==n-1 && y==m-1){
            oc=grid[x][y]=='('?oc+1:oc-1;
            if(oc==0)return true;
            return false;
        }
        if(dp[x][y][oc]!=-1)return dp[x][y][oc] ;
        bool ans=false;
        ans=ans|dfs(x,y+1,grid[x][y]=='('?oc+1:oc-1,grid);
        ans=ans|dfs(x+1,y,grid[x][y]=='('?oc+1:oc-1,grid);
        return dp[x][y][oc]=ans;
    }
    
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(n+m+2,-1)));
        return dfs(0,0,0,grid);
    }
};




