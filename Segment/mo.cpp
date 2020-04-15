#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define NUM 10000001
int fre[NUM],a[NUM];
lli ans[NUM],power=0;
int BLK=700;
struct query{
  int l;int r;int i;
};
query q[NUM];

bool cmp(query a,query b){
  if(a.l/BLK!=b.l/BLK)return a.l/BLK<b.l/BLK;
  return a.r<b.r;
}

void add(int pos){
  lli cnt=fre[a[pos]];
  fre[a[pos]]++;
  power-=cnt*cnt*a[pos];
  cnt++;
  power+=cnt*cnt*a[pos];
}

void remove(int pos){
  lli cnt=fre[a[pos]];
  fre[a[pos]]--;
  power-=cnt*cnt*a[pos];
  cnt--;
  power+=cnt*cnt*a[pos];
}




int main(){
  boost;
  int n,nq;
  cin>>n>>nq;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<nq;i++){
    cin>>q[i].l>>q[i].r;
    q[i].i=i;
    q[i].l--;
    q[i].r--;
  }
  sort(q,q+nq,cmp);
  int ML=0,MR=-1;
  for(int i=0;i<nq;i++){
    int L=q[i].l;
    int R=q[i].r;

    //increase range
    while(ML>L)ML--,add(ML);
    while(MR<R)MR++,add(MR);

    //decrease range
    while(ML<L)remove(ML),ML++;
    while(MR>R)remove(MR),MR--;

    ans[q[i].i]=power;
  }
  for(int i=0;i<nq;i++)cout<<ans[i]<<"\n";

}
