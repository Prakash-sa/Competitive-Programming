#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+9;
const int num=1e5+5;
lli dp[num+1];
lli ans[6][num+1]={0};

void init(){

}

 
int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       vector<int>s;
       for(int i=0;i<n;i++){
           int tmp=upper_bound(s.begin(),s.end(),a[i])-s.begin();
            if(tmp>=s.size()){
                s.push_back(a[i]);
            }
            else {
                s[tmp]=a[i];
            }
       }
       cout<<s.size()<<" ";
       for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
       cout<<endl;

   }
   return 0;
}

