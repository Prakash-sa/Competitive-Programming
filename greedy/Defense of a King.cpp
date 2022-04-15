//https://www.spoj.com/problems/DEFKIN/





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

int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,h,w;
		cin>>w>>h>>n;
		vector<int>a,b;
		a.push_back(0);
		b.push_back(0);
		for(int i=0;i<n;i++){
			int n1,n2;			
			cin>>n1>>n2;
			a.push_back(n1);
			b.push_back(n2);
		}
		a.push_back(w+1);
		b.push_back(h+1);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int mx=0,my=0;
		for(int i=0;i<a.size()-1;i++){
			mx=max(mx,a[i+1]-a[i]-1);
			my=max(my,b[i+1]-b[i]-1);
		}
		cout<<mx*my<<endl;
	}
	return 0;
}
