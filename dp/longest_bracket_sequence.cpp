#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

//https://codeforces.com/problemset/problem/5/C

int mod1= 1000001;
int S[1000001],E[1000001],F[1000001];

int main(){
  boost;
  stack<int>st;
  string s;
  cin>>s;
  int mx=0;
  for(int i=0;i<s.size();i++){
      char c=s[i];
      if(c=='(')st.push(i);
      else {
        if(st.empty()){
          S[i]=E[i]=-1;
        }
        else {
          int idx= st.top();
          st.pop();
          S[i]=E[i]=idx;
          if(idx>0 && s[idx-1]==')' && S[idx-1]>=0)E[i]=E[idx-1];
          int l=i-E[i]+1;
          F[l]++;
          mx=max(mx,l);
        }
      }
  }
  F[0]=1;
  cout<<mx<<" "<<F[mx]<<endl;

}
