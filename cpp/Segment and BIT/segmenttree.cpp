#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

lli tree[100000];
vector<int>v;
int n;
void build(int a[]){
    for(int i=0;i<n;i++)tree[i+n]=a[i];
    for(lli i=n-1;i>0;i--){
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
}

// void update(lli p ,lli val){
//     tree[p+n]=value;
//     p=p+n;
//     for(lli i=p;i>1;i>>=1){
//         tree[i>>1]=tree[i]+tree[i^1];
//     }
// }

int query(int l,int r){
    lli res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)res+=tree[l++];
        if(r&1)res+=tree[--r];
    }
    return res;
}



int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
        int q;
        cin>>n>>q;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        build(a);
        while(q--){
            v.clear();
            int x,y,k;
            cin>>x>>y>>k;
            int res=query(x,y);
            cout<<res<<endl;
        }

    }

    return 0;
}