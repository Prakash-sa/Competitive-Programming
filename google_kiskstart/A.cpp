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
		int n,m;
		cin>>n>>m;
        string s;
        cin>>s;
        unordered_map<int,int>mp;
        vector<pair<int,int>>arr[s.size()];
        for(int i=0;i<s.size();i++){
            int k=s[i]-'A';
            mp[k]++;
            for(int c=0;c<36;c++)
            arr[i].push_back({c,mp[c]});
        }
        int q1,q2;
        int ans=0;
        while(m--){
            cin>>q1>>q2;
            int len=q2-q1+1;
            int tmp;
            if(len%2==0){
                int eve=0;
                int odd=0;
                for(int i=0;i<36;i++){
                    if(q1>=2)
                    tmp=arr[q2-1][i].second-arr[q1-2][i].second;
                    else tmp=arr[q2-1][i].second;
                    if(tmp%2)odd++;
                    else eve++;
                }
                // cout<<"add"<<odd;
                if(odd==0)ans++;
            }
            else {
                int eve=0;
                int odd=0;
                for(int i=0;i<36;i++){
                    if(q1>=2)
                    tmp=arr[q2-1][i].second-arr[q1-2][i].second;
                    else tmp=arr[q2-1][i].second;
                    if(tmp%2)odd++;
                    else eve++;
                }
                if(odd==1)ans++;
            }
        }
        cout<<ans<<endl;

	}
	return 0;
}
