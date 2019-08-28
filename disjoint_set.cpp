#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



//     int root (int Arr[ ],int size[] ,int i)
//     {
//         while(Arr[ i ] != i)
//         {
//             Arr[ i ] = Arr[ Arr[ i ] ] ; 
//             i = Arr[ i ]; 
//            // size[i] = 1;
//         }
//     return i;
//     }

//     void weighted_union(int Arr[ ],int size[ ],int A,int B)
//     {
//         int root_A = root(Arr,size,A);
//         int root_B = root(Arr,size,B);
//         //cout<<root_A<<" "<<root_B<<endl;
//         if(root_A<root_B)
//         {
        
//         Arr[ root_A ] = Arr[root_B];
//         if(root_A!=root_B){ size[root_B] ++;size[root_A] ++;}
//         if(root_A!=A) size[A]++;
//         if(root_B!=B) size[B]++;
//         }
//         // else if(root_A > root_B )
//         // {
//         // Arr[ root_B ] = Arr[root_A];size[root_B] ++;size[root_A] ++;if(root_A!=A) size[A]++;
//         // if(root_B!=B) size[B]++;
//         // }
//         else
//         {
            
//         Arr[ root_B ] = Arr[root_A];
//         if(root_A!=root_B){ size[root_B] ++;size[root_A] ++;}
//         if(root_A!=A) size[A]++;
//         if(root_B!=B) size[B]++;
//         //size[root_B] = size[root_A]
//         }

//     }


//     void initialize( int Arr[ ],int size[], int N)
//     {
//         for(int i = 1;i<=N;i++)
//         {
//     Arr[ i ] = i ;
//     size[ i ] = 1;
//     }
//     }

//     bool find(int Arr[ ],int A,int B,int size[])
//     {
//         if( root(Arr,size,A)==root(Arr,size,B) )       //if A and B have the same root, it means that they are connected.
//         return true;
//         else
//         return false;
//     }

// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     int n,e,n1,n2;
   
//     cin>>n>>e;
//      int a[n+1],size1[n+1];
//     initialize(a,size1,n);
//     while(e--){
//         cin>>n1>>n2;
//         weighted_union(a,size1,n1,n2);
//        // cout<<"hi";
        

//     }
//     for(int i=1;i<=n;i++){
//             // cout<<" "<<a[i]<<" ";
//              cout<<size1[i]-1<<" ";
//         }
//     return 0;
// }


ll par[10000001];
ll ans[10000001];
ll root(ll x)
{
	if(x != par[x]) {
		par[x] = root(par[x]);
	}
	return par[x];
}
 
int main(){
    ll x,y,m,i,j,k,t1,t2,temp,l,n,sum,t,a[1000000];
    cin>>n>>m;
    for(ll i=0;i<n+1;i++)
    par[i]=i;
    while(m--){
        cin>>t1>>t2;
        x=root(t1);
        y=root(t2);
        int temp=max(par[x],par[y]);
        par[x]=temp;
        par[y]=temp;
    }
    for(i = 1; i <= n; i++) {
		ans[root(i)]++;
	}
    ll q;
    cin>>q;
    while(q--){
        cin>>t1>>t2;
        x=root(t1);
        y=root(t2);
        if(x!=y){
            if(root(t1)>root(t2)) cout<<t1<<endl;
            else if(root(t1)<root(t2)) cout<<t2<<endl;
            else {
                if(t1>t2) cout<<t1<<endl;
                else cout<<t2<<endl;
            }
        }
        else cout<<"TIE"<<endl;


    }
    
	// for(i = 1; i <= n; i++) {
	// 	cout<<ans[root(i)]-1<<" ";
	// }
	// cout<<endl;
	return 0;
}