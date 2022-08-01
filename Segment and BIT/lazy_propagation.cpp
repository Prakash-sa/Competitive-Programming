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
	int t; scanf("%d",&t);
	while(t--)
	{
		int nx, ny ,nz,q ;
		scanf("%d%d%d%d",&nx,&ny,&nz,&q);
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));

		while(q--)
		{
			int tp; 
			scanf("%d",&tp);
			if(tp == 0)
			{
				int l , r;
				scanf("%d%d",&l,&r);
				range_update(1,0,nx-1,l,r,0);
			}
			if(tp == 1)
			{
				int l , r;
				scanf("%d%d",&l,&r);
				range_update(1,0,ny-1,l,r,1);
			}
			if(tp == 2)
			{
				int l , r;
				scanf("%d%d",&l,&r);
				range_update(1,0,nz-1,l,r,2);
			}
			if(tp == 3)
			{
				int x1,x2,y1,y2,z1,z2;
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				ll r1 = range_query(1,0,nx-1,x1,x2,0);
				ll r2 = range_query(1,0,ny-1,y1,y2,1);
				ll r3 = range_query(1,0,nz-1,z1,z2,2);
				ll g1 = (x2-x1+1) - r1;
				ll g2 = (y2-y1+1) - r2;
				ll g3 = (z2-z1+1) - r3;
				ll ans = 1ll*r1*r2*r3;
				ans += 1ll*r1*g2*g3;
				ans += 1ll*g1*r2*g3;
				ans += 1ll*g1*g2*r3;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}