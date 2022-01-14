#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kadane(int a[],int n){
    int tmp=a[0],ans=a[0];
    for(int i=1;i<n;i++){
        tmp=max(a[i],tmp+a[i]);
        ans=max(ans,tmp);
    }
    return ans;
}


int ch(int a[],int  n){
    int max1=kadane(a,n);
    int max_wrap=0;
    for(int i=0;i<n;i++){
        max_wrap+=a[i];
        a[i]=-a[i];
    }
    max_wrap=max_wrap+kadane(a,n);
    int ans=max(max_wrap,max1);
    if(ans==0)return min(max_wrap,max1);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<ch(a,n)<<endl;
    }
    return 0;
}