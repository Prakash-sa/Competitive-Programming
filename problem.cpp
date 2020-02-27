#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

<<<<<<< HEAD

bool search(int key,vector<int>v){
    for(int i=0;i<v.size();i++){
        if(v[i]==key)return true;
    }
    return false;
}

int predict(vector<int>s,vector<int>v,int n,int index ){
    int far=index;
    int res=-1;
    for(int i=0;i<s.size();i++){
        int j;
        for(j=index;j<n;j++){
            if(s[i]==v[j]){
                if(j>far){
                    far=j;
                    res=i;
                }
                break;
            }
        }
        if(j==n)return i;
    }
    if(res!=-1)return res;
    else return 0;

}

int optimal(vector<int>v,int n,int m){
    queue<int>q;
    int page=0;
    vector<int>s;
    for(int i=0;i<n;i++){
        if(search(v[i],s))continue;
        if(s.size()<m){
            s.push_back(v[i]);
            page++;
        }
        else {
            int j=predict(s,v,n,i);
            s[j]=v[i];
            page++;
        }
    }
    return page;
}

int main()
{
    boost;
    lli t;
    cin>>t;
    while(t--){
        lli l,n,m,k;
        cin>>n>>m;
        vector<int>a;
        for(int i=0;i<m;i++){
            cin>>l;
            a.push_back(l);
        }
        k=optimal(a,m,n);
        cout<<k<<endl;
    }
=======
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
    
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
    
    return 0;
}