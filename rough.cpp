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

//modulus of + and - number
int modulo(int x,int N){
    return (x % N + N) %N;
}


int main()
{
   boost;
   int t;
   int cnt=1;
    cin>>t;
    
    while(t--){
      string s;
      cin>>s; 
       int sum=0;
       for(auto it:s){
          sum+=it-'0';
            sum%=9;
       }
       cout<<"Case #"<<cnt<<": ";
       
       int rem=(9-sum)%9;
       bool f=0;
       if(rem==0)f=1;
       bool p=0;
         for(auto it:s){
            int k=it-'0';
            if(k>rem && !p && f ){
               cout<<rem;
               p=1;
            }
            f=1;
            cout<<it;
         }
         if(!p)cout<<rem;
         cout<<endl;
        cnt++;
    }
   
   return 0;
}
