#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

#define max1 1000001

int isprime[max1];
int prime_count[max1];

void sieveis(){
	isprime[0]=0;
	isprime[1]=0;
	for(int i=2;i<=1000000;i++){
		prime_count[i]=prime_count[i-1];
		if(!isprime[i]){
			prime_count[i]++;
			for(int j=i*2;j<=1000000;j+=i){
				isprime[j]=true;
			}
		}
	}
}


void sieve(int n){
    bool pri[n+1];
    memset(pri,true,sizeof(pri));
    for(int p=2;p*p<=n;p++){
        if(pri[p]==true){
            for(int i=p*p;i<=n;i+=p)
            pri[i]=false;
        }
    }
    for(int i=2;i<=n;i++)if(pri[i]==true)cout<<i<<" ";

}



int main()
{
    sieveis();
    unsigned long long t,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	int k=sqrt(n);
    	cout<<prime_count[k]<<endl;
    }


    return 0;
}
