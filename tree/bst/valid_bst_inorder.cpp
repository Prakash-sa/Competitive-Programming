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

bool ch(int a[],int n){
    if(n==0||n==1)return true;
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i])return false;
    }
    return true;
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
       if(ch(a,n)){
           cout<<1<<endl;
       }else {
           cout<<0<<endl;
       }
       
   }
   return 0;
}