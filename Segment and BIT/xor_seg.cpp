#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e6+5;
lli tree[num]={0};
void built(lli a[],lli low,lli high, lli pos){
    if(low==high){
        tree[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    built(a,low,mid,2*pos+1);
    built(a,mid+1,high,2*pos+2);
    tree[pos]=tree[2*pos+1]^tree[2*pos+2];
}

lli query(int ql,int qh, int low,int high,int pos){
    if(ql<=low&&qh>=high)return tree[pos];
    if(ql>high||qh<low)return 0;
    int mid=(low+high)/2;
    return query(ql,qh,low,mid,2*pos+1)^query(ql,qh,mid+1,high,2*pos+2);
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
        lli n,q;
        cin>>n>>q;
        lli a[n];
        lli ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans=ans^a[i];
        }
        built(a,0,n-1,0);
        while(q--){
            int l,r;
            cin>>l>>r;
            lli tmp=query(l-1,r-1,0,n-1,0);
            cout<<(ans^tmp)<<endl;
        }
   }
   return 0;
}