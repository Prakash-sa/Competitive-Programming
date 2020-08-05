#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e6+5;
int g;

int tree[num]={0};

void built(int a[],int l,int h,int pos){
    if(l==h){
        tree[pos]=a[l];
        return;
    }
    int mid=(l+h)/2;
    built(a,l,mid,2*pos+1);
    built(a,mid+1,h,2*pos+2);
    tree[pos]=__gcd(tree[2*pos+1],tree[2*pos+2]);
}

int query(int ql,int qh,int l,int h,int pos){
    if(ql<=l&&qh>=h)return tree[pos];
    if(ql>h||qh<l)return 0;
    int mid=(l+h)/2;
    return __gcd(query(ql,qh,l,mid,2*pos+1),query(ql,qh,mid+1,h,2*pos+2));
}

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
        int n;
        cin>>g>>n;
        int a[n];
        int f=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%g==0)f=1;
        }
        if(f){
            built(a,0,n-1,0);
            int ans=INT_MAX;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(query(j,i,0,n-1,0)==g)ans=min(ans,i-j+1);
                }
            }
            if(ans!=INT_MAX){
                cout<<ans;
            }
            else cout<<-1;
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }
        
        
   }
   return 0;
}