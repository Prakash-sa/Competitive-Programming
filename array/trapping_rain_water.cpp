//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

/*
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    int left[n]={0},right[n]={0};
	    left[0]=a[0];
	    for(int i=1;i<n;i++)left[i]=max(left[i-1],a[i]);
	    right[n-1]=a[n-1];
	    for(int i=n-2;i>=0;i--)right[i]=max(right[i+1],a[i]);
	    int ans=0;
	    for(int i=0;i<n;i++)ans+=min(left[i],right[i])-a[i];
	    cout<<ans<<endl;
	}
	return 0;
}
