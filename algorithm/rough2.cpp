#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mo 1000000007

lli ch(lli a,lli b){
	lli l=0,k;
	for(lli i=0;i<10;i++){
		if(a%10==b%10)k=0;
		else k=1;
		a=a/10;
		b=b/10;
		l=l*10+k;
	}
	return l;
	lli res=0;
	for(lli i=0;i<10;i++){
		if(a%10==l%10&&l%10==1)k=1;
		else k=0;
		a=a/10;
		l=l/10;
		res=res*10+k;
	}
	return res;
}

int main()
{
   // speed;
	lli t;
	cin>>t;
    while (t--)
    {
        lli n,k;
		cin>>n;
		vector<lli>v;
		for(lli i=0;i<n;i++){
			cin>>k;
			v.push_back(k);
		}
		sort(v.begin(),v.end());

		lli ans=0,l=v[n-1];
		//cout<<l<<endl;
		for(lli i=n-2;i>=0;i--){
			l=ch(l,v[i]);
			cout<<l<<endl;
		}
		cout<<l<<endl;

    }   

	return 0;
}