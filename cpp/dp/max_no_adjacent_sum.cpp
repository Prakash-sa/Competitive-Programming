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
       int inc=a[0],ex=0;
       for(int i=1;i<n;i++){
           int prev=inc;
           int tmp=max(inc,ex+a[i]);
           inc=tmp;
           ex=prev;
       }
       cout<<max(inc,ex)<<endl;
       
   }
   return 0;
}