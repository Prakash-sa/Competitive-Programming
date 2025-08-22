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
       int n,k;
	    cin>>n>>k;
	    int a[n],sum=0;
	    for(int i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	    int ans=INT_MAX,temp=0,t2=0;
	    for(int i=0;i<n;i++){
	        temp=t2;
	        t2+=a[i];
	        for(int j=n-1;j>i;j--){
	            if(a[j]-a[i]-k>0)temp+=a[j]-a[i]-k;
	        }
	        ans=min(ans,temp);
	    }
	cout<<ans<<endl;
   }
   return 0;
}