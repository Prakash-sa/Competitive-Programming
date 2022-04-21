//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#







class Solution 
{
    int disx[4]={1,0,-1,0};
    int disy[4]={0,-1,0,1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>dis(n,vector<int>(m,-1));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                dis[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    while(!q.empty()){
	        auto it=q.front();
	        q.pop();
	        for(int i=0;i<4;i++){
	            int xx=it.first+disx[i];
	            int yy=it.second+disy[i];
	            if(xx>=0 &&xx<n&&yy>=0&&yy<m && dis[xx][yy]==-1){
	                q.push({xx,yy});
	                dis[xx][yy]=dis[it.first][it.second]+1;
	            }
	        }
	    }
	    return dis;
	}
};
