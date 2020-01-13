#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll par[10000001];
ll ans[10000001];
ll root(ll x)
{
	if(x != par[x]) {
		par[x] = root(par[x]);
	}
	return par[x];
}
 
int main(){
    ll x,y,m,i,j,k,t1,t2,temp,l,n,sum,t,a[1000000];
    cin>>n>>m;
    for(ll i=0;i<n+1;i++)
    par[i]=i;
    while(m--){
        cin>>t1>>t2;
        x=root(t1);
        y=root(t2);
        int temp=max(par[x],par[y]);
        par[x]=temp;
        par[y]=temp;
    }
    for(i = 1; i <= n; i++) {
		ans[root(i)]++;
	}
    ll q;
    cin>>q;
    while(q--){
        cin>>t1>>t2;
        x=root(t1);
        y=root(t2);
        if(x!=y){
            if(root(t1)>root(t2)) cout<<t1<<endl;
            else if(root(t1)<root(t2)) cout<<t2<<endl;
            else {
                if(t1>t2) cout<<t1<<endl;
                else cout<<t2<<endl;
            }
        }
        else cout<<"TIE"<<endl;


    }
    
	// for(i = 1; i <= n; i++) {
	// 	cout<<ans[root(i)]-1<<" ";
	// }
	// cout<<endl;
	return 0;
}