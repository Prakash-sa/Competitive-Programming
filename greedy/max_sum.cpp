#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

int max_sum(int a[],int n)
{
    int cur_sum=0;
    for(int i=0;i<n;i++)cur_sum+=a[i];
    int cur_val=0;
    for(int i=0;i<n;i++)cur_val+=i*a[i];
    int ans=cur_val;
    for(int i=1;i<n;i++){
        cur_val=cur_val-(cur_sum-a[i-1])+a[i-1]*(n-1);
        ans=max(ans,cur_val);
    }
    return ans;
}