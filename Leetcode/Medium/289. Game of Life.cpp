//https://leetcode.com/problems/game-of-life/








class Solution {
    
    bool isSafe1(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)return false;
        return true;
    }
    
    int dis[8][2]={{1,1},{-1,1},{1,-1},{-1,-1},{1,0},{-1,0},{0,1},{0,-1}};
    
    int count(vector<vector<int>>&board,int x,int y){
        int cnt=0;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<8;i++){
            int xx=x+dis[i][0];
            int yy=y+dis[i][1];
            if(isSafe1(xx,yy,n,m)){
                cnt+=board[xx][yy];
            }
        }
        return cnt;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>tmp=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=count(tmp,i,j);
                if(board[i][j]){
                    if(k<2 || k>3)board[i][j]=0;
                }
                else {
                    if(k==3)board[i][j]=1;
                }
            }
        }
    }
};
