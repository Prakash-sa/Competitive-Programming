#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mo 1000000007
/*#ifndef ONLINE_JUDGE
cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
*/
vector<int>s;
void subset_rec(int a[],int k,int n){
    if(k==n){
        for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
        cout<<endl;
        return ;
    }
    else {
        subset_rec(a,k+1,n);
        s.push_back(a[k]);
        subset_rec(a,k+1,n);
        s.pop_back();
    }
    
}

void subset_bit(int a[],int n){
    
    for(int b=0;b<(1<<n);b++){
        vector<int>s;
        for(int i=0;i<n;i++){
            if(b&(1<<i))s.push_back(a[i]);
        }

    for(auto it=s.begin();it!=s.end();it++)cout<<*it<<" ";
    cout<<endl;
    }
}



int main()
{
    speed;
    lli t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        s.clear();
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        subset_bit(a,n);
    }

    return 0;
}