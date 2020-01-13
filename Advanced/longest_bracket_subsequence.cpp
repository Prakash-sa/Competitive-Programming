#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;
lli max1=1e8+1;
map<lli,bool>mp;


int main()
{
    boost;
    string s;
    cin>>s;
    int n=s.size();
    int d[1000009];
    int c[1000009];
    for(int i=0;i<1000009;i++){
        d[i]=INT_MAX;
        c[i]=INT_MAX;
    }
    stack<int>q;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
          if(!q.empty()){

            int top=q.top();
            q.pop();
            d[i]=top;
            c[i]=top;
            if(d[i]>=1)c[i]=min(c[d[i]-1],c[i]);
            else c[i]=c[i];
          }
          
        }
        else q.push(i);
        
    }
    int ans=0,cnt=1;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            if(ans<i-c[i]+1){
                ans=i-c[i]+1;
                cnt=1;
                }

            else if(i-c[i]+1==ans)cnt++;
        }
    }
    cout<<ans;
    if(ans==0)cout<<" "<<1<<endl;
    else cout<<" "<<cnt<<endl;
    return 0;
}