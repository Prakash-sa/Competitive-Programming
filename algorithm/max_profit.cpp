    #include<bits/stdc++.h>
    using namespace std;
    #define int long long int
     
    signed main()
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i = 0 ; i < n ; i ++)
        {
            cin>>a[i];
        }
        int maxi[n];
        maxi[n-1] = -1;
        for(int i = n-2 ; i>=0 ; i--)
        {
            maxi[i] = max(maxi[i+1],a[i+1]);
        }
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            int bp = a[i];
            int sp = maxi[i];
            ans = max(ans,sp-bp);
        }
        
        cout<<ans*k;
    }