#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int findKthNumber(int n, int k) {
	unsigned int root = 1;
		
		while (k > 1) {
			int subTreeSz = calcSubSize(n, root);
			if (subTreeSz < k) {
				k -= subTreeSz;
				root++;
			} else {
				root *= 10;
				k--;
		}
	}
	return root;
}

int calcSubSize(unsigned long long int n, unsigned long long int root) {
	unsigned long long int l = root, r = root + 1;
	int sz = 0;
	while (l <= n) {
		sz += min(n + 1, r) - l;
		l *= 10;
		r *= 10;
	}
	return sz;
}


int main()
{
	speed;
	lli n,k;
	cin>>n>>k;
	lli kn=1,in=1,fin,i=0;
	vector<lli>v;
	while(kn<=k){
		lli l=kn;
		if(i==k)break;
		while(l<=n){
			if(find(v.begin(),v.end(),l)==v.end())
			v.push_back(l);
			fin=l;
			i++;
			if(i==k)break;
			l=l*10;
		}
		while (fin<n)
		{
			i++;
			fin++;
			if(find(v.begin(),v.end(),l)==v.end())
			v.push_back(fin);
			if(i==k)break;
		}
		kn++;
	}
	for(auto i:v)cout<<i;
	
	return 0;
}