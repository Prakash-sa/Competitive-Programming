#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

const int mod=1e9+7;
const lli num=1e5+5;

void init(){

}

void next(string &s,int n,string &a,int l){
   if(a.size()==n){
      cout<<a<<endl;
      return;
   }
   for(int i=l;i<s.size();i++){
      a.push_back(s[i]);
      next(s,n,a,i);
      a.pop_back();
   }
}



int main()
{
   boost;
   string s;
   cin>>s;
   string a="";
   next(s,s.size(),a,0);
   return 0;
}
