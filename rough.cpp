#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define uint64_t int
set<int>s;
void ch(int n,int num){
    queue<int>q;
    q.push(num);
    while(!q.empty()){
        num=q.front();
        q.pop();
        if(num<=n){
            s.insert(num);
            int last=num%10;
            if(last<9){
                q.push(num*10+last+1);
            }
            if(last>0)q.push(num*10+last-1);
        }
    }
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=9&&i<=n;i++)ch(n,i);
        for(auto it=s.begin();it!=s.end();it++)cout<<*it<<" ";
        cout<<endl;
    
    }
    return 0;
}