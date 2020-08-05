#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;


int build_st(int* st,int sum[],int l,int r,int i){
    if(l==r){
        st[i]=sum[l];
        return sum[l];
    }
    int m=l+(r-l)/2;
    st[i]=max(build_st(st,sum,l,m,2*i+1),build_st(st,sum,m+1,r,2*i+2));
    return st[i];
}
int query(int* st,int l,int r,int a,int b,int i){
    if(l>=a&&r<=b){
        return st[i];
    }
    if(l>b||r<a){
        return INT_MIN;
    }
    return max(query(st,l,l+(r-l)/2,a,b,2*i+1),query(st,((l+r)/2)+1,r,a,b,2*i+2));
}

int main()
{
    boost;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int q;cin>>q;
        int sum[n];
        for(int i=0;i<n;i++){
            cin>>sum[i];
            if(i!=0)sum[i]+=sum[i-1];
        }
        int* st=new int[4*n+1];
        build_st(st,sum,0,n-1,0);
        int l,r,ans;
        for(int i=0;i<q;i++){
            cin>>l>>r;
            ans=query(st,0,n-1,l,r,0);
            if(l!=0)ans-=sum[l-1];
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
