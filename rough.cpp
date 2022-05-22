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
 int cnt_s;

vector<vector<int>>dp;

bool isPalin(string s,int i,int j){
	if(i>=j)return true;
	if(dp[i][j]!=-1)return dp[i][j];
	if(s[i]==s[j])return dp[i][j]=isPalin(s,i+1,j-1);
	return dp[i][j]=false;
}

 void backtrack(string &s,int start){
	 if(isPalin(s,0,s.size()-1))cnt_s+=s.size();
	 for(int i=start;i<s.size();i++){
		 string tmp=s.substr(0,i)+s.substr(i+1);
		 cout<<tmp<<" ";
		 backtrack(tmp,start+1);
	 }
 }
 
 
int main()
{
	boost;
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		cout<<"Case #"<<cnt<<": ";
		cnt++;
		int n,l;
		cin>>n;
		string s;
		cin>>s;
		dp.resize(n,vector<int>(n,0));
		cnt_s=n;
		backtrack(s,0);
		cout<<cnt_s;
		cout<<endl;
	}
	return 0;
}