//https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

/*

For every node that you visit, push all its unvisited neighbours to the queue in the following manner.
Every unvisited neighbour with cost 1 (having an obstacle), push to the end of the queue
Every unvisited neighbour with cost 0 (having no obstacle), push to the beginning of the queue.

*/


class Solution {
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,false));
        deque<pair<int,int>>q;
        q.push_front({0,0});
        dp[0][0]=0;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop_front();
            int x=tmp.first;
            int y=tmp.second;
            vis[x][y]=1;
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx<0||xx>=n || yy<0 || yy>=m || vis[xx][yy])continue;
                // cout<<xx<<" "<<yy<<endl;
                if(grid[xx][yy]==0){
                    dp[xx][yy]=dp[x][y];
                    q.push_front({xx,yy});
                }
                else if(dp[xx][yy]>1+dp[x][y]){
                    dp[xx][yy]=1+dp[x][y];
                    q.push_back({xx,yy});
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};


