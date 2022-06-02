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

int ans;

bool isValid(int a,int b){
	if(a%2 && !b%2)return false;
	if(!a%2 && b%2)return false;
	return true;
}

 
int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>a(n);
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int flag=false;
		if(a[n-1]>n || a[0]!=1){
			cout<<-1<<endl;
			// cout<<"aa";
			continue;
		}
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]>2)flag=true;
		}
		if(flag){
			cout<<-1<<endl;
		}
		else {
			cout<<n<<" ";
			for(int i=1;i<n;i++)cout<<i<<" ";
			cout<<endl;
		}
	}
	return 0;
}