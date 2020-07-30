#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gc getchar_unlocked

int main()
{
    speed;
    int n1,n2;
    cin>>n1>>n2;
    lli n;
    cin>>n;
    if(n2==0)cout<<n<<endl;
    else if(n1==1)cout<<0<<endl;
    else {
    lli k=pow(10,n1-1);
    lli l=0,i=0;
    n2=n1-n2;
    while(n2&&n){
      l+=(n%10)*pow(10,i);
      i++;
      n2--;
      n=n/10;
    }
    cout<<k+l<<endl;
    }
}