#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

bool isValidConfig(lli a[],lli n,lli k,lli ans){
    int students=1;
    lli current_pages=0;
    for(int i=0;i<n;i++){
        if(current_pages+a[i]>ans){
            students++;
            current_pages=a[i];
            if(students>k)return false;
        }
        else {
            current_pages+=a[i];
        }
    }
    return true;
}

lli binarySearch(lli a[],lli n,lli m){
    if(m>n)return -1;
    lli total_pages=0;
    lli s=0,e=0;
    for(int i=0;i<n;i++){
        total_pages+=a[i];
        s=max(s,a[i]);
    }
    e=total_pages;
    int finalAns=s;
    while(s<=e){
        lli mid=(s+e)/2;
        if(isValidConfig(a,n,m,mid)){
            finalAns=mid;
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return finalAns;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    lli n,m;
	    cin>>n;
	    lli a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cin>>m;
	    cout<<binarySearch(a,n,m)<<endl;
	
	}
	return 0;
}