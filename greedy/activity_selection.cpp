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
 
bool comp(const pair<int,int> & a ,const pair <int,int>& b){
  return a.second<b.second;    
    
}
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);   
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];         
   
   vector< pair<int, int> > v;
   vector< pair<int, int> >pos;
   for(int i=0;i<n;i++)    v.push_back(make_pair(a[i],b[i]));
   for(int i=0;i<n;i++)    pos.push_back(make_pair(i+1,b[i]));
   
   sort(v.begin(),v.end(), comp);
   sort(pos.begin(),pos.end() ,comp);  
    
    int i=0;
    int cnt=1;
    cout<<pos[i].first<<" ";
    
    for(int j=1;j<n;j++){
        if(v[j].first>=v[i].second){
            cout<<pos[j].first<<" ";
            cnt++;
            i=j;
        }
    }
    cout<<cnt<<endl;
   }
   return 0;
}