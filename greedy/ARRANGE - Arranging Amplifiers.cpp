//https://www.spoj.com/problems/ARRANGE/








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


int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,ones=0;
		cin>>n;
		vector<int>a;
		for(int i=0;i<n;i++){
			int k;cin>>k;
			if(k!=1)a.push_back(k);
			else ones++;	
		}
		sort(a.begin(),a.end(),greater<int>());
		for(int i=0;i<ones;i++)cout<<1<<" ";
		if(a.size()==2 && a[0]==3 &&a[1]==2 ){
			cout<<"2 3"<<endl;
		}
		else {
			for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
			cout<<endl;
		}
		

	}
	return 0;
}


