#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);


int nCrModpDP(int n, int r)
{
      int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]);
    }
    return C[r];
}

int main(){
  boost;
  int t,n1,n2;
  cin>>t;
  while(t--){
    cin>>n1>>n2;
    if(n1>=n2)
    cout<<nCrModpDP(n1-n2,n2)<<endl;
    else cout<<0<<endl;
  }
}
