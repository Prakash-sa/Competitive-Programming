//https://www.spoj.com/problems/CHOCOLA/
//https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/




#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;

void init(){

}

static bool cmp(int a,int b){
	return a>b;
}

// method returns minimum cost to break board into
// m*n squares
int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		n--;m--;
		vector<int>a(n,0),b(m,0);
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<m;i++)cin>>b[i];

		// sort the horizontal cost in reverse order
		sort(a.begin(),a.end(),cmp);
		// sort the vertical cost in reverse order
		sort(b.begin(),b.end(),cmp);	

		// initialize current width as 1
		int hz=1,vz=1;

		// loop until one or both cost array are processed
		int i=0,j=0,ans=0;
		while(i<n &&j<m){
			if(a[i]>b[j]){
				// increase current horizontal part count by 1
				hz++;
				ans+=a[i++]*vz;				
			}
			else {
				// increase current vertical part count by 1
				vz++;
				ans+=b[j++]*hz;
			}
		}

		// loop for horizontal array, if remains
		while(i<n){
			hz++;
			ans+=a[i++]*vz;
		}

		// loop for vertical array, if remains
		while(j<m){
			vz++;
			ans+=b[j++]*hz;
		}
		cout<<ans<<endl;
	}
	return 0;
}
