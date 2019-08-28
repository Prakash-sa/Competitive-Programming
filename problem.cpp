#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    boost;
    lli n,m,t,k;
    map<pair<lli,lli>,lli>mp;
    cin>>n>>m>>t;
    for(lli i=1;i<=n;i++){
        cin>>k;
        int j=1;
        while(j<=m){
            int l=k&1;
            if(l==1)mp.insert({{i,j},1});
            j++;
            k=k/10;
        }
    }
   // cout<<"now";
    int q;
    lli x,y,nx=n,ny=m;
    for(lli o=0;o<t;o++){
        cin>>q;
        if(q==1){
            //cout<<q;
            cin>>x>>y;
            nx=nx-abs(x);
            ny=ny-abs(y);
            for(auto it=mp.begin();it!=mp.end();it++){
                if(((it->first).first<=nx)&&((it->first).second<=ny)&&(it->second==1));
                else mp[it->first]=0;
            }
        }
        else if(q==2) {
            lli cnt=0;
            for(auto it=mp.begin();it!=mp.end();it++){
                if(((it->first).first<=nx)&&((it->first).second<=ny)&&(it->second==1))cnt++;
            }
            cout<<cnt<<endl;
            //cout<<q;
        }
    }
    
    
    return 0;
}