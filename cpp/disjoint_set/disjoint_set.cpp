
#include <iostream> 
using namespace std;
typedef int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mo 1000000007
#define parn 1000009
lli *parent;

int find(int x) 
{ 
    if (parent[x] != x) { 
        parent[x] = find(parent[x]); 
    } 
    return parent[x]; 
} 
    
int main()
{
    lli t;
    cin>>t;
    while(t--){
       lli n;
       cin>>n;
       lli a[n];
       for(lli i=0;i<n;i++)cin>>a[i];
       lli q,c,x,y;

		parent = new lli[n+1];
        for(lli i=0;i<n;i++)parent[i]=i;
       cin>>q;
       while(q--){
           cin>>c;
           if(c==0){
                cin>>x>>y;
                x--;y--;
                lli k1=find(x);
                lli k2=find(y);
                if(k1==k2)cout<<"Invalid query!"<<'\n';
                else {
                    if(a[k1]<a[k2])
                    parent[k1]=k2;
                    else if(a[k1]>a[k2]) parent[k2]=k1;
                }
           }
           else {
                cin>>x;
                x--;
                printf("%d\n", find(x)+1);
           }
       }
    }

	return 0;
}