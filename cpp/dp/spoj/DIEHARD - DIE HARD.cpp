//https://www.spoj.com/problems/DIEHARD/












#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;


int dp[1003][1003];
void init(){

}


static bool cmp(int a,int b){
	return a>b;
}

int solve(int h,int a,int i){
	if(h<=0 || a<=0)return 0;
	if(dp[h][a]!=-1)return dp[h][a];
	int x=0,y=0,z=0;
	if(i!=1)x=1+solve(h+3,a+2,1);
	if(i!=2)y=1+solve(h-5,a-10,2);
	if(i!=3)z=1+solve(h-20,a+5,3);
	dp[h][a]=max(x,max(y,z));
	return dp[h][a];
}

int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<1003;i++)for(int j=0;j<1003;j++)dp[i][j]=-1;
		cout<<max(solve(n+3,m+2,1),max(solve(n-5,m-10,2),solve(n-20,m+5,3)))<<endl;

	}
	return 0;
}
