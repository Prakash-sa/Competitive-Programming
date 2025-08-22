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
		int n;
        cin>>n;
        cout<<ceil(n/5)+(n%5!=0);
        cout<<endl;

	}
	return 0;
}
