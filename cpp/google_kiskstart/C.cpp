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
        vector<int>a(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int k=sum/m;
        cout<<sum-m*k<<endl;

	}
	return 0;
}
