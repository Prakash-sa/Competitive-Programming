#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    speed;
<<<<<<< HEAD
    lli t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        lli a[n];
        for(lli i=0;i<n;i++)cin>>a[i];
        lli sum=0;
        for(lli i=0;i<n;i++)sum+=m^a[i];
        cout<<sum<<endl;
    }
    
    
=======
    string s;
    cin>>s;
    lli a[s.size()];
    memset(a,0,sizeof(a));
    lli o[s.size()];
    memset(o,0,sizeof(o));
    F(i,0,s.size()-1){
        if(s[i]=='v'&&s[i+1]=='v'){
            a[i+1]=a[i]+1;
           // cout<<a[i+1];
            a[i]=0;
        }
       // else if(s[i]=='v'&&s[i+1]!='v'&&s[i-1]=='v')a[i]++;
        else if(s[i]=='v'&&s[i+1]!='v'&&s[i-1]!='v')a[i]=0;
    }
    F(i,2,s.size()-3){
        if(s[i]=='o'&&s[i+1]=='o'){
            o[i+1]=o[i]+1;
           // cout<<a[i+1];
            o[i]=0;
        }
        else if(s[i]=='o'&&s[i+1]!='o')o[i]++;
        else if(s[i]=='o'&&s[i+1]!='o'&&s[i-1]!='o')o[i]=1;
    }
    lli sum=0,lef=0,rig=0;
    //F(i,0,s.size()-1)cout<<a[i]<<" ";
    //cout<<endl;
    F(i,2,s.size()-3){
        if(o[i]>0){
            lef=0;
            rig=0;
            for(lli l=i;l>=0;l--)lef+=a[l];

            for(lli r=i+1;r<s.size();r++)rig+=a[r];
            //cout<<lef<<" "<<rig<<" "<<o[i]<<endl;
            sum+=lef*rig*o[i];
        }


    }
    cout<<sum<<endl;
 
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
}