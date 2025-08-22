//https://practice.geeksforgeeks.org/problems/count-of-sum-of-consecutives/0
/*
Input:
2
10
15
Output:
1
3
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int ans=0;
       double x=2;
       while(2*n+x-(x*x)>0){
           double a=1.0*(x-x*x+2*n)/(2*x);
           if(a-(int)a==0.0)ans++;
           x++;
       }
       cout<<ans<<endl;
   }
   return 0;
}