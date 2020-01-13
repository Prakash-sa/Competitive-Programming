#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;
#define mo 1000000007

void multiply(lli F[2][2], lli M[2][2]); 
  
void power(lli F[2][2], lli n); 
  
lli fib(lli n) 
{ 
  lli F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 
  
void multiply(lli F[2][2], lli M[2][2]) 
{ 
  lli x =  (F[0][0]*M[0][0])%mo + (F[0][1]*M[1][0])%mo; 
  lli y =  (F[0][0]*M[0][1])%mo + (F[0][1]*M[1][1])%mo; 
  lli z =  (F[1][0]*M[0][0])%mo + (F[1][1]*M[1][0])%mo; 
  lli w =  (F[1][0]*M[0][1])%mo + (F[1][1]*M[1][1])%mo; 
  
  F[0][0] = x%mo; 
  F[0][1] = y%mo; 
  F[1][0] = z%mo; 
  F[1][1] = w%mo; 
} 
  
void power(lli F[2][2], lli n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  lli M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 

int main()
{
    boost;
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;   
        cout<<fib(n+2)%mo<<endl;
    }
    return 0;
}