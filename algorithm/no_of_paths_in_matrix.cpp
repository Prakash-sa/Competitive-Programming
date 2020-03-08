#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli ncr(lli n,lli k){
    lli c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    for(lli i=1;i<=n;i++){
        for(lli j=min(i,k);j>0;j--){
            c[j]=c[j]+c[j-1];
        }
    }
    return c[k];
}




int main()
 {
	int t;
	cin>>t;
	while(t--){
        lli x,y,a,b;
        cin>>x>>y>>a>>b;
        lli k=ncr(x+y,x)-ncr(a+b,a)*ncr(x+y-a-b,x-a);
        cout<<k<<endl;
	    
	}
	return 0;
}