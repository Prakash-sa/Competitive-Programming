#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;
vector<vector<int>>adj;
vector<vector<bool>>vis;
int n,m;

struct payr{
    int r;
    int c;
    int t;
};
void init(){

}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool issafe(int x,int y){
    if(x>=0&&y>=0&&x<n&&y<m)if(adj[x][y]==1)return true;
    return false;
}
queue<payr>q;
void bfs(){
    int ans=0;
    while(!q.empty()){
        payr tmp=q.front();
        q.pop();
        int x=tmp.r;
        int y=tmp.c;
        int t=tmp.t;
        ans=max(ans,t);
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(issafe(xx,yy)){
                adj[xx][yy]=2;
                q.push({xx,yy,t+1});
            }
        }
        
    }
    int f=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1){
                f=1;
                break;
            }
        }
    }
    if(f){
        cout<<-1<<endl;
    }
    else 
        cout<<ans<<endl;
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
        cin>>n>>m;
        adj.assign(n,{});
        vis.assign(n,{});
        int st,e;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a;
                cin>>a;
                if(a==2)q.push({i,j,0});
                adj[i].push_back(a);
                vis[i].push_back(false);
            }
        }
        bfs();
   }
   return 0;
}