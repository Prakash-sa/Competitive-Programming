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
 
 
bool issafe(string s1,string s2){
	if((s1[0]==s2[0] && s1[1]!=s2[1]) || (s1[0]!=s2[0] && s1[1]==s2[1]))return true;
	return false;
}
 
int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string>s(n);
		for(int i=0;i<n;i++)cin>>s[i];
		long long ans=0;
		map<char,int>start;
		set<string>st;
		map<char,int>end;
		for(int i=0;i<n;i++){
			start[s[i][0]]++;
		}
		for(int i=0;i<n;i++){
			if(start[s[i][0]]>1)st.insert(s[i]);
		}
		for(int i=0;i<n;i++){
			if(st.find(s[i])==st.end())end[s[i][1]]++;
		}

		for(auto it:start)ans+=it.second;
		
		for(auto it:end)ans+=it.second;
		cout<<ans;
		cout<<endl;
	}
	return 0;
}