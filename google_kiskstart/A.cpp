#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;
 
const int mod=1e9+7;
const lli num=1e5+5;

 
int main()
{
	boost;
	int t,count=1;
	cin>>t;
	while(t--){
        cout<<"Case #"<<count++<<": ";
		int n,m;
		cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        double ans=0;
        int i=n-1;
        while(m>1){
            ans+=arr[i--];
            m--;
        }
        double tmp=0;
        int ran=i+1;
        if(ran%2==1){
            tmp=arr[i/2];
        }
        else {
            tmp=(double)(arr[i/2]+arr[i/2+1])/2;
        }
        cout<<ans+tmp<<endl;

	}
	return 0;
}
