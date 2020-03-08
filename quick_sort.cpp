#include<bits/stdc++.h>
using namespace std;

int part(int a[],int st, int ed){
    int s=a[st];
    int j=st+1;
    for(int i=st+1;i<=ed;i++){
        if(s>a[i]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[st],a[j-1]);
    return j-1;
}

void quick_sort(int a[],int st,int en){
    if(st<en){
        int po=part(a,st,en);
        quick_sort(a,st,po-1);
        quick_sort(a,po+1,en);
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}

