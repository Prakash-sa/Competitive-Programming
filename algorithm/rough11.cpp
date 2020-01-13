#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long

const int maxN = 1e5+7;
int tree[4*maxN][3] , lazy[4*maxN][3];


inline void range_update(int id , int left ,int right , int lq ,int rq, int color)
{
	if(lazy[id][color])
	{
		tree[id][color] = (right-left+1) - tree[id][color];
		if(left != right)
		{
			lazy[2*id][color] ^= 1;  
			lazy[2*id+1][color] ^= 1;  
		}
		lazy[id][color] = 0;
	}
	if(left > rq || right < lq)
		return;
	if(left >= lq && right <= rq)
	{
		tree[id][color] = (right-left+1) - tree[id][color];
		if(left != right)
		{
			lazy[2*id][color] ^= 1;  
			lazy[2*id+1][color] ^= 1;  
		}
		lazy[id][color] = 0;
		return ;
	}
	int mid = (left + right)/2;
	range_update(2*id,left,mid,lq,rq,color);
	range_update(2*id+1,mid+1,right,lq,rq,color);
	tree[id][color] = tree[2*id][color] + tree[2*id+1][color];
}

inline int range_query(int id ,int left ,int right, int lq ,int rq, int color)
{
	if(lazy[id][color])
	{
		tree[id][color] = (right-left+1) - tree[id][color];
		if(left != right)
		{
			lazy[2*id][color] ^= 1;  
			lazy[2*id+1][color] ^= 1;  
		}
		lazy[id][color] = 0;
	}
	if(left > rq || right < lq)
		return 0;
	if(left >= lq && right <= rq)
	{
		return tree[id][color];
	}
	int mid = (left + right)/2;
	return  range_query(2*id,left,mid,lq,rq,color) + range_query(2*id+1,mid+1,right,lq,rq,color);
}
int main()
{
	cout<<-1%45<<endl;
}