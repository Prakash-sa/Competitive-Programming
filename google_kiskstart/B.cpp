#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;
 
const int mod=1e9+7;
const lli num=1e5+5;

 
int main()
{
	boost;
	int t,count=1;
	cin>>t;
	while(t--){
        cout<<"Case #"<<count++<<": ";
		int n,m,k;
		cin>>n;
        vector<int>a1(n);
        for(int i=0;i<n;i++)cin>>a1[i];
        cin>>m;
        vector<int>a2(m);
        for(int i=0;i<m;i++)cin>>a2[i];
        cin>>k;
        vector<int>dp1(k+1,0);
        vector<int>dp2(k+1,0);
        int l=0,r=n-1,i=1;
        while(l<r && i<=k){
            if(a1[l]>a1[r]){
                dp1[i++]=a1[l++]+(i>0?dp1[i-1]:0);
            }
            else {
                dp1[i++]=a1[r--]+(i>0?dp1[i-1]:0);
            }
        }
        l=0,r=m-1,i=1;
        while(l<r && i<=k){
            if(a2[l]>a2[r]){
                dp2[i++]=a2[l++]+(i>0?dp2[i-1]:0);
            }
            else {
                dp2[i++]=a2[r--]+(i>0?dp2[i-1]:0);
            }
        }
        int ans=0;
        for(int i=0;i<k;i++){
            cout<<dp1[i]<<" "<<dp2[k-1-i]<<endl;
            ans=max(ans,dp1[min(n,i)]+dp2[min(m,k-i)]);
        }
        cout<<ans<<endl;
	}
	return 0;
}
