#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

lli tree[100000000];
int n;
void build(int a[]){
    for(int i=0;i<n;i++)tree[i+n]=a[i];
    for(lli i=n-1;i>0;i--){
        tree[i]=min(tree[i<<1],tree[i<<1|1]);
    }
}

void update(lli p ,lli val){
 tree[p+n]=val;
 p=p+n;
 for(lli i=p;i>1;i>>=1){
     tree[i>>1]=min(tree[i],tree[i^1]);
 }
}

int query(int l,int r){
    lli res1=INT_MAX,res2=INT_MAX;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)res1=min(res1,tree[l++]);
        if(r&1)res2=min(res2,tree[--r]);
    }
    return min(res1,res2);
}



int main()
{
    speed;
        int q;
        cin>>n>>q;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        build(a);
        while(q--){
            char s;
            int y,k;
            cin>>s>>y>>k;
            y--;
            if(s=='q'){
                int res=query(y,k);
                cout<<res<<endl;            
            }
            else {
                update(y,k);
            }
        }
    return 0;
}
