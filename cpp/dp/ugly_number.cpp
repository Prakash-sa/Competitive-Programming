#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long lcm(long a,long b){
    return (a*b)/__gcd(a,b);
}

int ch(int a,int b,int c,int n){
    int low = 1;
    int high = INT_MAX;
    
    long A = long(a); long B = long(b); long C = long(c);
    long AB = lcm(A, B);
    long AC = lcm(A, C);
    long BC = lcm(B, C);
    long ABC = lcm(A, BC);
    
    while (low < high) {
        int mid = low + (high-low)/2;
        int count = mid/A + mid/B + mid/C - mid/AB - mid/BC - mid/AC + mid/ABC;

        if (count < n)
            low = mid+1;
        else
            high = mid;
    }
    
    return low;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<ch(2,3,5,n-1)<<endl;
	
	}
	return 0;
}