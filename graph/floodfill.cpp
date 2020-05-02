#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);


lli mat[11][11];
lli visited[11][11];


int dfs(lli x,lli y,lli n,lli m,lli des_x,lli des_y){
    if(x==des_x&&y==des_y)return true;
    if(x>=n || y>=m)return false;
    if(x<0 || y<0)return false;
    if(visited[x][y]==true)return false;
    if(mat[x][y]==0)return false;
    visited[x][y]=true;
    if(dfs(x-1,y,n,m,des_x,des_y)==true)return true;
    if(dfs(x+1,y,n,m,des_x,des_y)==true)return true;
    if(dfs(x,y+1,n,m,des_x,des_y)==true)return true;
    if(dfs(x,y-1,n,m,des_x,des_y)==true)return true;
    return false;
}

int main()
{
    speed;
    lli n,m;
    cin>>n>>m;
    memset(mat,0,sizeof(mat));

    memset(visited,0,sizeof(visited));
    F(i,0,n-1){
        F(j,0,m-1)cin>>mat[i][j];
    }
    if(dfs(0,0,n,m,n-1,m-1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isvalid(int n,int m,int x,int y){
    if(x>=n||x<0)return false;
    if(y>=m||y<0)return false;
    return true;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int ad[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>ad[i][j];
	        }
	    }
	    int cx[]={1,-1,0,0};
	    int cy[]={0,0,-1,1};
	    int x,y,k;
	    cin>>x>>y>>k;
	    int old=ad[x][y];
	    ad[x][y]=k;
	    queue<pair<int,int>>q;
	    q.push({x,y});
	    while(!q.empty()){
	        pair<int,int>p=q.front();
	        q.pop();
	        for(int i=0;i<4;i++){
	            int xx=p.first+cx[i];
	            int yy=p.second+cy[i];
	            if(isvalid(n,m,xx,yy)&&ad[xx][yy]==old){
	                ad[xx][yy]=k;
	                q.push({xx,yy});
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++) cout<<ad[i][j]<<" ";
	    }
	    cout<<endl;
	
	}
	return 0;
} 