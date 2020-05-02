#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int >g[n+1];
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    int anj;
    cin>>anj;
    int l[n+1];
    int v[n+1];
    for(int i=0;i<=n;i++)
    {
        l[i]=1;
        v[i]=0;
    }
    list<int >q;
    q.push_back(1);
    while(q.size()>0)
    {
        int t=q.front();
        q.pop_front();
        for(int i=0;i<g[t].size();i++)
        {
            if(v[g[t][i]]==0)
            {
                l[g[t][i]]=l[t]+1;
                q.push_back(g[t][i]);
            }
        }
        v[t]=1;
    }
    int ans=0;
    for(int i=1;i<n+1;i++)
    {
        if(l[i]==anj)
        ans++;
    }
    cout<<ans;
}