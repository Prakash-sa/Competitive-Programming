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


void median(double arr[], int n) 
{ 
    priority_queue<double> s; 
  
    priority_queue<double,vector<double>,greater<double> > g; 
  
    double med = arr[0]; 
    s.push(arr[0]); 
  
    cout << med << endl; 
  
    for (int i=1; i < n; i++) 
    { 
        double x = arr[i]; 
  
        // case1(left side heap has more elements) 
        if (s.size() > g.size()) 
        { 
            if (x < med) 
            { 
                g.push(s.top()); 
                s.pop(); 
                s.push(x); 
            } 
            else
                g.push(x); 
  
            med = (s.top() + g.top())/2.0; 
        } 
  
        // case2(both heaps are balanced) 
        else if (s.size()==g.size()) 
        { 
            if (x < med) 
            { 
                s.push(x); 
                med = (double)s.top(); 
            } 
            else
            { 
                g.push(x); 
                med = (double)g.top(); 
            } 
        } 
  
        // case3(right side heap has more elements) 
        else
        { 
            if (x > med) 
            { 
                s.push(g.top()); 
                g.pop(); 
                g.push(x); 
            } 
            else
                s.push(x); 
  
            med = (s.top() + g.top())/2.0; 
        } 
  
        cout << (int)med << endl; 
    } 
} 
 
int main()
{
   boost;
   int t=1;
  // cin>>t;
   while(t--){
       int n;
       cin>>n;
       double a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       if(n==1){
           cout<<a[0];
       }
       else 
        median(a,n);
   }
   return 0;
}