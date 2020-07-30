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

struct Item 
{ 
    int value, weight;
}; 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

double fractionalKnapsack(int W, struct Item arr[], int n) 
{  
    sort(arr, arr + n, cmp); 
    int curWeight = 0; 
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++) 
    { 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
    return finalvalue; 
} 

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n,w;
       cin>>n>>w;
       Item a[n];
       for(int i=0;i<n;i++){
           cin>>a[i].value>>a[i].weight;
       }
       double ans=fractionalKnapsack(w,a,n);
       cout<<fixed<<setprecision(2)<<ans<<endl;
       
   }
   return 0;
}