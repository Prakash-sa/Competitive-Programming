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

int point(int a[],int n){
    int start = 0, end =n-1;
    int mid = 0;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
            break;
        else if(a[mid]<a[mid+1] && a[mid-1]<a[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return mid;
}

int asc(int a[],int s,int e,int k){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==k)return mid;
        else if(a[mid]<k)s=mid+1;
        else e=mid-1;
    }
    return -1;
}

int desc(int a[],int s,int e,int k){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==k)return mid;
        else if(a[mid]<k)e=mid-1;
        else s=mid+1;
    }
    return -1;
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n,k;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       cin>>k;
       int mid=point(a,n);
        if(a[mid]==k){
            cout<<mid<<endl;
        }   
       else {
           int l1=asc(a,0,mid-1,k);
           int l2=desc(a,mid+1,n,k);
           if(l1!=-1){
               cout<<l1<<endl;
           }
           else if(l2!=-1){
               cout<<l2<<endl;
           }
           else cout<<-1<<endl;
       }
   }
   return 0;
}