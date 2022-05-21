//---------------optimal strategy of game-------------//
int optimalstrategygame(int A[],int N){
    int n=N;
    int table[n][n];
    
    
    for(int gap=0;gap<n;++gap){
        for(int i=0,j=gap;j<n;++i,++j){
            int x=((i+2)<=j)?table[i+2][j]:0;
            int y=((i+1)<=(j-1))?table[i+1][j-1]:0;
            int z=(i<=(j+2))?table[i][j-2]:0;
            table[i][j]=max(A[i]+min(x,y),A[j]+min(y,z));
        }
    }
    return table[0][n-1];
}


//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1



#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int cal(int i,int j){
    if(i<=j)return dp[i][j];
    return 0;
}
int ch(int a[],int n){
    if(n==1)return a[0];
    if(n==2)return max(a[0],a[1]);

    for(int it=0;it<n;it++){
        for(int i=0,j=it;j<n;j++,i++){
            int st=a[i]+min(cal(i+2,j),cal(i+1,j-1));
            int en=a[j]+min(cal(i+1,j-1),cal(i,j-2));
            dp[i][j]=max(st,en);
        }
    }
    return dp[0][n-1];

}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<ch(a,n)<<endl;
	    
	
	}
	return 0;
}



