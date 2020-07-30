#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)


int frq[1000002];
int n;
void ch(int a[],int start,int end){
  if(end==n)return;
  else if(start>end){
    ch(a,0,end+1);
  }
  else {
    int min1=1000001;
    for(int i=start;i<=end;i++){
      min1=min(min1,a[i]);
    //  cout<<a[i]<<" ";
    }
    //cout<<endl;
    frq[min1]++;
    ch(a,start+1,end);
  }
}

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    memset(frq,0,sizeof(frq));
    for(int i=0;i<n;i++)cin>>a[i];
    ch(a,0,0);
    for(int i=0;i<n;i++)cout<<frq[a[i]]<<" ";
    cout<<endl;
  }
return 0;
}
