<<<<<<< HEAD
#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int main(){
cpp_int a,b;
while(cin>>a>>b)
{
cout<<a+b<<"\n";
}
}
=======
#include <bits/stdc++.h>
using namespace std;

//---now---//
bool vis[1000][1000];
int issafe(int n,int m,int i,int j){
    if(i<n&&i>=0&&j>=0&&j<m)return true;
    else return false;
}

void findis(vector<int>A[],int x,int y,int n,int m ){
    vis[x][y]=true;
    int rox[]={-1,-1,-1,0,0,1,1,1};
    int coly[]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++){
        if(issafe(n,m,x+rox[i],y+coly[i]))findis(A,x+rox[i],y+coly[i],n,m);
    }
}


int findIslands(vector<int> A[], int N, int M)
{
    
    
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!vis[i][j]&&A[i][j]){
                findis(A,i,j,N,M);
                cnt++;
            }
        }
        
    }
    return cnt;
}
int a[100000];
void fsc(){
    int b[6];
    for(int i=0;i<6;i++)b[i]=i;
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=4;
    a[5]=5;
    int k=1,i=6;
    while(i<100000){
        for(int j=0;j<6;j++){
            a[i++]=a[k]*10+b[j];
        }
        k++;
    }
}

int main() {
    
	int T;
	cin>>T;
    fsc();
    //for(int i=0;i<20;i++)cout<<a[i]<<" ";
	while(T--)
	{
		int n;
        cin>>n;
        int k1=355,k2=113;
        cout<<k1/k2;
        k1=k1%k2*10;
        if(n>=1)cout<<".";
        for(int i=1;i<=n;i++){
            cout<<k1/k2;
            k1=k1%k2*10;
        }


	}
	return 0;
}

>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
