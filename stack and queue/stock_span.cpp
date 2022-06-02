#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/stock-span-problem/0

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    stack<int>s;
	    s.push(0);
	    int tmp[n];
	    tmp[0]=1;
	    for(int i=1;i<n;i++){
	        while(!s.empty() && a[s.top()]<=a[i])s.pop();
	        tmp[i]=(s.empty())?(i+1):(i-s.top());
	        s.push(i);
	    }
	    for(int i=0;i<n;i++)cout<<tmp[i]<<" ";
	    cout<<endl;
	
	}
	return 0;
}