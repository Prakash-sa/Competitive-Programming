#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

double func(double x)
{ 
return 2*x*x - 12*x +7; 
}


lli ts(lli start,lli end)
{
    double l = start, r = end;   
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    lli n;
    double l,r;
    cin>>n;
    while(n--){
        cin>>l>>r;
        
        for(int i=0; i<200; i++) {
      double l1 = l+(r-l)/3.0;
      double l2 = r-(r-l)/3.0;
      if(func(l1) < func(l2)) r=l2; 
      else l = l1;
      }

     double x = r;
    cout<<(lli)floor(func(x))<<endl;
    }
    return 0;
}
