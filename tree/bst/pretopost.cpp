#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

void ch(int a[],int n,int min_val,int max_val,int &in){
    if(in==n)return;
    if(a[in]<min_val || a[in]>max_val)return ;
    int val=a[in++];
    ch(a,n,min_val,val,in);
    ch(a,n,val,max_val,in);
    cout<<val<<" ";
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       int in=0;
       ch(a,n,INT_MIN,INT_MAX,in);
       cout<<endl;
   }
   return 0;
}