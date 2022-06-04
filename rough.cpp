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
		int l=-1,r=-1;
		if(__builtin_popcount(n)==1){
			if(n==0)cout<<1;
			else if(n==1)cout<<3;
			else cout<<n+1;
			cout<<endl;

			continue;
		}
		else {
			for(int i=0;i<32;i++){
				if(n&(1<<i)  && l<0)l=i;
				else if((n&(1<<i))==0 && r<0){
					// cout<<1;
					r=i;
				}
				if(l>=0)break;
			}
			cout<<(1<<l)<<endl;
		}
	}
	return 0;
}


// int main()
// {
// 	boost;
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		stack<lli>a;
// 		bool cnt=false;
// 		for(int i=0;i<n;i++){
// 			lli k;cin>>k;
// 			if(k%2==0)a.push(k);
// 			else cnt=true;
// 		}
// 		int ans=0;
// 		while(a.size()>1){
// 			lli k=a.top();
// 			a.pop();
// 			k+=a.top();
// 			a.pop();
// 			ans++;
// 			if(k%2==0){
// 				ans++;
// 				k=k/2;
// 				if(k%2==0)
// 				a.push(k);
// 			}
// 			else cnt=true;
// 		}
// 		if(a.size()==1 && cnt){
// 			ans++;
// 		}
// 		cout<<ans<<endl;


// 	}
// 	return 0;
// }