#include<bits/stdc++.h>
using namespace std;
int ans;
int mR[]={0,-1,0,1};
int mC[]={-1,0,1,0};
int n,m;
char M[2009][2009];
bool visited[2009][2009];
int max(int a,int b){return a>b?a:b;}



int a,b;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};


bool isssafe(int x,int y){
    if(x<a&&y<b&&x>=0&&y>=0)return true;
    return false;
}
int bfs(int i,int j){
    int ans=INT_MIN;
    queue<pair<pair<int,int>,int>>q;
    q.push({{i,j},0});
    while ((!q.empty()))
    {
        
        pair<pair<int,int>,int>p=q.front();
        q.pop();
        int d=p.second;
        ans=max(d,ans);
        for(int i=0;i<4;i++){
            int xx=p.first.first+dx[i];
            int yy=p.first.second+dy[i];
            if(isssafe(xx,yy)&&M[xx][yy]!='#'&&!visited[xx][yy]){
                visited[xx][yy]=true;
                q.push({{xx,yy},d+1});
            }
        }
    }
    return ans;
}



int dfs(int i,int j)
{
    //cout<<i<<” “<<j<<” “<<endl;
    int tr,tc,p;
    int m1,m2,b;
    m1=m2=-1;
    visited[i][j]=true;
    for(p=0;p<4;p++)
    {
        tr=i+mR[p];
        tc=j+mC[p];
        if(tr>=0 && tr<n && tc>=0 && tc<m && visited[tr][tc]==false && M[tr][tc]=='.')
        {
            b=dfs(tr,tc);
            if(b>=m1)
            {
                m2=m1;
                m1=b;
            }
            else if(b>m2)m2=b;
        }
    }
    ans=max(ans,m1+m2+2);
    return m1+1;
}
int main(void)
{
    int t,i,j;
    bool flag;
    cin>>t;
    while(t--)
    {
        flag=false;
        cin>>m>>n;
        a=n;b=m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>M[i][j];
                visited[i][j]=false;
            }
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
            if(M[i][j]=='.')
            {
            flag=true;
            break;
            }
            }
            if(flag)break;
        }
        //cout<<“Launching Point “<<i<<” “<<j<<endl;
        dfs(i,j);
        printf("Maximum rope length is %d.\n",ans);
    }
}