#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

//https://codeforces.com/contest/1342/problem/C

const int N=40043;
lli p[N],len;

lli build(lli a,lli b){
  len=a*b;
  p[0]=0;
  for(lli i=1;i<=len;i++){
    p[i]=p[i-1];
    if(((i%b)%a)!=((i%a)%b))p[i]++;
  }
}

lli query(lli l){
  lli cnt=l/len;
  int rem=l%len;
  return p[len]*cnt+p[rem];
}

lli query(lli l,lli r){
  return query(r)-query(l-1);
}

int main(){
  boost;
  int t;
  cin>>t;
  while(t--){
    int a,b,q;
    cin>>a>>b>>q;
    build(a,b);
    lli l,r;
    while (q--)
    {
      cin>>l>>r;
      cout<<query(l,r)<<" ";
    }
    cout<<endl;
    
  }
return 0;
}
