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

vector<int> z_func(string s){
	int n=s.size();
	vector<int>z(n);
	for(int i=0,l=0,r=0;i<s.size();i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])++z[i];
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;		
		}
	}
	return z;
}

int main()
{
	boost;
	string s;
	cin>>s;
	vector<int>z=z_func(s);	
	int l=-1,len=INT_MIN;
	int n=s.size();
	map<int,int>mp;
	int flag=-1;
	for(int i=0;i<n;i++){
		//if(z[i]==0)continue;
		mp[z[i]]++;
		if(mp[z[i]]>=1)flag=1;
		if(mp[z[i]]>=2){
			if(z[i]>l){
				flag=1;
				l=z[i];
			}		
		}	
	}   
	if(l>=1 && z[n-l]==l){
		cout<<s.substr(n-l)<<endl;
	}
	else if(z[n-1]!=0 &&flag>0){
		cout<<s[n-1]<<endl;	
	}	
	else {
		cout<<"Just a legend"<<endl;
	}
	return 0;
}
