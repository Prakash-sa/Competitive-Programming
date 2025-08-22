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

//----------------------------------------------------------------


//for array
int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}


double func(double x)
{ 
return -1*1*x*x + 2*x +3; 
}


double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     double x = l;
    return func(x);
}

double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      if(func(l1) > func(l2)) l=l1; 
      else r = l2;
      }

     double x = r;
    return func(x);
}

//for minimum
lli ts(lli start,lli end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = l+(r-l)/3.0;
      double l2 = r-(r-l)/3.0;
      if(func(l1) < func(l2)) r=l2; 
      else l = l1;
      }

     double x = r;

    return (lli)floor(func(x));
}
 
