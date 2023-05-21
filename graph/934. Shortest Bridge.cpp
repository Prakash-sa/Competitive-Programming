/*
https://leetcode.com/problems/shortest-bridge/description/

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
*/

class Solution {
    queue<pair<int,int>>q;
    vector<vector<bool>>vis;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int n,m;

    bool issafe(int x,int y){
        if(x>=n || x<0||y>=m||y<0)return false;
        return true;
    }

    void dfs(int x,int y,vector<vector<int>>&grid){
        vis[x][y]=true;
        q.push({x,y});
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(issafe(xx,yy) && grid[xx][yy] && !vis[xx][yy]){
                dfs(xx,yy,grid);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis.resize(n,vector<bool>(m,false));

        bool flag=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                    flag=true;
                }
                if(flag)break;
            }
            if(flag)break;
        }

        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                auto tmp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=tmp.first+dx[i];
                    int yy=tmp.second+dy[i];
                    if(issafe(xx,yy) && !vis[xx][yy]){
                        if(grid[xx][yy])return step;
                        q.push({xx,yy});
                        vis[xx][yy]=true;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};