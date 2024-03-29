/*
#Time Complexities

    Best case complexity: O(1)
    Average case complexity: O(log n)
    Worst case complexity: O(log n)

#Space Complexity:- The space complexity of the binary search is O(1).

#Algorithmic Paradigm: Decrease and Conquer.

*/

#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)


// binary search ------------------------------------------------
int binary_search(vector<int>nums,int target){
  auto it=lower_bound(nums.begin(),nums.end(),target);
  return it-nums.begin();
}


int binarySearch(int low,int high,int key)
{
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
         low=mid+1;
     }
     else if(a[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;                //key not found
 }

 //---------------------------------------------

int main(){
  boost;
  int t,cnt=1;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    int m[n];
    for(int i=0;i<n;i++)cin>>m[i];
    int l=1,r=m[n-1]-m[0];
    while(l<r){
      int md=(l+r)/2;
      int k2=0;
      for(int i=1;i<n;i++){
        int d=m[i]-m[i-1];
        k2+=(d+md-1)/md-1;
      }
      if(k2<=k)r=md;
      else l=md+1;
    }

    cout<<"Case "<<"#"<<cnt<<": "<<l<<endl;
    cnt++;
  }
return 0;
}
