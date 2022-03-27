#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
 {
	 speed;
	lli n,q;
	cin>>n>>q;
	lli a[n+1],b[n+1];
	a[0]=0;b[0]=0;
	for(lli i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}

	lli i=1,ll=1,j=1;
	while(i<=n){
		lli z=pow(2,ll-1);
		while(z--&&i<=n){
			b[j]+=a[i];
			i++;
		}
		ll++;j++;
	}
	lli co,no,k;
	while(q--){
		cin>>co;
		if(co==1){
			//at node no for level ll
			cin>>no>>ll;
			lli p=pow(2,ll-1)-1+no;
			cout<<a[p]<<endl;
		}
		else if (co==2){
			//sum from no to ll
			cin>>no>>ll;
			lli ans=0;
			for(lli i=no;i<=ll;i++)ans+=b[i];
			cout<<ans<<endl;
		}
		else {
			cin>>no>>ll>>k;
			lli p=pow(2,ll-1)-1+no;
			b[ll]=b[ll]-a[p]+k;
			a[p]=k;
		}
	}
	return 0;
}