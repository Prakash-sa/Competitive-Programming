//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1



class Solution {
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        int maxDeadline=INT_MIN;
        vector<pair<int,int>>a;
        
        for(int i=0;i<n;i++){
            maxDeadline=max(deadline[i],maxDeadline);
            a.push_back({deadline[i],profit[i]});   
        }
        sort(a.begin(),a.end(),cmp);
        vector<int>hash(maxDeadline+1,-1);
        int cnt=0;
        int pr=0;
        for(int i=0;i<a.size();i++){
            int d=a[i].first;
            for(int j=d;j>0;j--){
                if(hash[j]==-1){
                    hash[j]=1;
                    cnt++;
                    pr+=a[i].second;
                    break;
                }
            }
        }
        return {cnt,pr};
    }
};


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