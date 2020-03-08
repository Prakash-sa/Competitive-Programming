<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int part(int a[],int st, int ed){
    int s=a[st];
    int j=st+1;
    for(int i=st+1;i<=ed;i++){
        if(s>a[i]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[st],a[j-1]);
    return j-1;
}

void quick_sort(int a[],int st,int en){
    if(st<en){
        int po=part(a,st,en);
        quick_sort(a,st,po-1);
        quick_sort(a,po+1,en);
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}
=======
#include<iostream>
using namespace std;

int modinverse(int a,int b)
{
    int k=0;
    for(int l=b;l>=0;l--)
    {
        if(((l*(a))%b)==1)
        {
            k=l;
        }
    }
    return k;
}
long long x,y;
long long extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    long long g=extended_gcd(b,a%b);
    long long x1=x;
    long long y1=y;
    x=y1;
    y=x1-((a/b)*y1);
    return g;

}

int main()
{
    int k,j;
    cin>>k;
    int a[k],b[k];
    for(int l=0;l<k;l++)
    {
        cin>>a[l];
        cin>>b[l];

    }
    for(int l=0;l<k;l++)
    {
        int j=extended_gcd(a[l],b[l]);
        if(j==1){
            j=modinverse(a[l],b[l]);
            cout<<j<<endl;
        }
        else
        {
            cout<<-1;
        }
    }
    
    
}
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
