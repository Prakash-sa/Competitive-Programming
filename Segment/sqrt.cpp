#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

int a[100000],F[100000],BLK=1000;

//https://www.spoj.com/problems/RMQSQ/

int getMin(int l,int r){
  int LB=l/BLK;
  int RB=r/BLK;
  int mn=INT_MAX;
  if(LB==RB){
    for(int i=l;i<=r;i++)mn=min(a[i],mn);
  }
  else {
    for(int i=l;i<BLK*(LB+1);i++)mn=min(mn,a[i]);
    for(int i=LB+1;i<RB;i++)mn=min(mn,F[i]);
    for(int i=RB*BLK;i<=r;i++)mn=min(mn,a[i]);
  }
  return mn;
}

int main(){
  boost;
  int n,q,l,r;
  cin>>n;
  int j=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<100000;i++)F[i]=INT_MAX;
  int i=0;
  while(i<n){
    int tmp=i,mn=INT_MAX;
    while(i-tmp<BLK){
      mn=min(mn,a[i]);
      i++;
    }
    F[j]=mn;
    j++;
  }
  cin>>q;
  for(i=0;i<q;i++){
    cin>>l>>r;
    cout<<getMin(l,r)<<endl;
  }


}
