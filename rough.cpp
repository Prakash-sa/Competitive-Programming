#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second){
        if(p2.second-p2.first!=p1.second-p1.first)if(p1.first<p2.first)return true;
    }
    return false;
}

int main()
{
    //speed;
    int t,n,k,l;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<lli> a,b;
        for(lli i=0;i<n;i++){
            cin>>l;
            a.push_back(l);
        }
        for(lli i=0;i<k;i++){
            cin>>l;
            b.push_back(l); 
        }
        int flag=0;
    for(int i=0;i<n;i++){
        auto k=std::lower_bound(b.begin(),b.end(),a[i]);
        cout<<k-b.begin()<<" ";
        if(b[k-b.begin()-1]==a[i]){
            flag=1;
            break;
        }
    }
    if(flag==1)cout<<"asd";
    else cout<<"no";

    }
    return 0;
}
