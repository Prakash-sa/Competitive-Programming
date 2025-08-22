#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vec_vec;
typedef vector<int> vec;
typedef pair<int,int> ipair;
void print(vec_vec v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
bool is_safe(vec_vec &mat,int i,int j)
{
    int n=mat.size();
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    return true;
}
int dijkstra(vec_vec &mat)
{
    int n=mat.size(),min_cost=INT_MAX,p,q;
    int x[]= {0,-1,0,1};
    int y[]= {-1,0,1,0};
    vec_vec dist(n,vec(n,INT_MAX));
    dist[0][0]=mat[0][0];
    priority_queue<pair<int,ipair>,vector<pair<int,ipair>>,greater<pair<int,ipair> > > pq;
    pq.push({mat[0][0],{0,0}}); //{w,{u,v}}
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        pq.pop();

        for(int k=0; k<4; k++)
        {
            p=u+x[k];
            q=v+y[k];
            if(is_safe(mat,p,q) && mat[p][q]+w<dist[p][q])
            {
                dist[p][q]=mat[p][q]+w;
                pq.push({dist[p][q],{p,q}});
            }
        }

    }
    return dist[n-1][n-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vec_vec V(n,vec(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>V[i][j];
        }
        int mn_cost=dijkstra(V);
        cout<<mn_cost<<endl;
    }
}

