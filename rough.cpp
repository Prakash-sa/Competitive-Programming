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
    map<char,string>mp;
    mp['U']='U';
    mp['R']='R';
    mp['Y']='Y';
    mp['B']='B';
    mp['O']="RY";
    mp['P']="RB";
    mp['G']="YB";
    mp['A']="RYB";
    while(t--){
       int n;
        string s;
        cin>>n>>s;
        int res=0;
        int last=0,i=0;
        char tmp;
        if(n>0){
           tmp=s[0];
            if(mp[tmp].size()>1){
               tmp=mp[tmp][0];
            }
            res++;
        }
        while(last!=n-1 && i<n){
           if(s[i]==tmp || mp[s[i]].find(tmp)!=string::npos){
              last=i;
           }
           else { 
              res++;
            tmp=s[i];
               if(mp[tmp].size()>1){
                  tmp=mp[tmp][0];
               }
           }
           i++;
        }
        cout<<"Case #"<<cnt<<": "<<res<<endl;
        cnt++;
    }
   
   return 0;
}
