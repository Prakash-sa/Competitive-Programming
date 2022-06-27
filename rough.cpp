#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;
 
const int mod=1e9+7;
const lli num=1e5+5;

void solution(int N,int M){
	if(N>=M){
        int Difference=M+1;
        int answer=1;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				cout<<answer+Difference*(j-1) <<" ";
			}
			cout<<endl;
			answer++;
			Difference++;
		}
    }

 	else{
        int d=N+1,A=1,B=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cout<<A+ B*(j-1)<<" ";
            }
            cout<<endl;
            A+=d;
            B++;
        }
    } 
}
 
int main()
{
	boost;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		solution(n,m);
	}
	return 0;
}
