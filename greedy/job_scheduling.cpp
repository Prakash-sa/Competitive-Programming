//https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

struct job{
    int id;int d;
    int p;
};

bool cmp(job a,job b){
    if(a.p!=b.p){
        return a.p>b.p;
    }
    return a.id<b.id;
}
 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       job a[n];
       int len=0;
       memset(a,-1,sizeof(a));
       for(int i=0;i<n;i++){
           int l,k,m;
           cin>>l>>k>>m;
           len=max(len,k);
           a[i].id=l;
           a[i].d=k;
           a[i].p=m;
       }
       int vis[n]={false};
       int cnt=0,ans=0;
       sort(a,a+n,cmp);
       for(int i=0;i<n;i++){
           for(int j=min(n-1,a[i].d-1);j>=0;j--){
               if(!vis[j]){
                   cnt++;
                   vis[j]=true;
                   ans+=a[i].p;
                   break;
               }
           }
       }
       cout<<cnt<<" "<<ans<<endl;
   }
   return 0;
}