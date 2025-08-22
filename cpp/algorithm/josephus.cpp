#include <bits/stdc++.h>
using namespace std;

//iterative
int josephus(int n, int k)
{
   int sum=0;
   for(int i=2;i<=n;i++)sum=(sum+k)%i;
   return sum+1;
   
}

//recursion
int josephus(int n, int k)
{
   if(n==1)return 1;
   return (josephus(n-1,k)+k-1)%n+1;
}

int main() {	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}
