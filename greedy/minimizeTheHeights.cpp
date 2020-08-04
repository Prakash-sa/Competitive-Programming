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
	    cin>>k>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    sort(a,a+n);
	    
	    int ans=a[n-1]-a[0];
	     a[0]=a[0]+k;
	    
	     a[n-1]=a[n-1]-k;
	    
	    int big=a[n-1];
	    int small=a[0];
	    if(small>big)swap(small,big);
	    for(int i=1;i<n-1;i++){
	        int sub=a[i]-k;
	        int addd=a[i]+k;
	        if(sub>=small||addd<=big)continue;
	        if(big-sub<=addd-small)small=sub;
	        else big=addd; 
	    }
	    
	    cout<<min(ans,big-small)<<endl;
	    
	    
   }
   return 0;
}