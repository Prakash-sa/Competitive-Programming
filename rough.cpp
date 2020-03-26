#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);




int main()
 {
    boost;
    lli n;
    cin>>n;
    lli a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<lli,lli>mp;
for(int i=0;i<n;i++)mp[a[i]]++;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>2){
            cout<<"NO\n";
            return 0;
        }
    }
    int cnt=0;
    vector<int>a1,a2;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==2){
            a1.push_back(it->first);
            a2.push_back(it->first);
        }
        else a2.push_back(it->first); 
    }
    cout<<"YES\n";
    cout<<a1.size()<<endl;
    for(int i=0;i<a1.size();i++)cout<<a1[i]<<" ";
    cout<<endl<<a2.size()<<endl;

for(int i=a2.size()-1;i>=0;i--)cout<<a2[i]<<" ";

    return 0;
}