#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define max1 100009

int n,m;
vector<int>adj[max1];
bool visited[max1];

bool iscycle(int x,int parent){
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++){
        if(!visited[adj[x][i]]){
            if(iscycle(adj[x][i],x))return true;
        }
        else if(adj[x][i]!=parent)return true;
    }
    return false;
}

int check(){
    for(int i=0;i<max1;i++)visited[i]=false;
    if(iscycle(1,0))return false;
    for(int i=1;i<=n;i++){
        if(!visited[i])return false;
    }
    return true;
}

int main() {
	boost;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    if(check())cout<<"YES";
    else cout<<"NO";

    return 0;
}