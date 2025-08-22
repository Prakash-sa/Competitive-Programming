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
       int n,m;
       cin>>n>>m;
       int a1[n],a2[m];
       for(int i=0;i<n;i++)cin>>a1[i];
       for(int i=0;i<m;i++)cin>>a2[i];
       int sum1=0,sum2=0,ans=0;
       int i=0,j=0;
       while(i<n&& j<m){
           if(a1[i]>a2[j]){
               sum2+=a2[j++];
           }
           else if(a1[i]<a2[j]){
               sum1+=a1[i++];
           }
           else {
            int tmp=a1[i];
            while(i<n&&a1[i]==tmp)sum1+=a1[i++];
            while(j<m&&a2[j]==tmp)sum2+=a2[j++];
            ans+=max(sum1,sum2);
            sum1=sum2=0;
           }
       }
       while(i<n)sum1+=a1[i++];
       while(j<m)sum2+=a2[j++];
       ans+=max(sum1,sum2);
       cout<<ans<<endl;
       
   }
   return 0;
}