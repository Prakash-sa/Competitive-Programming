#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i, a, b) for (lli i = a; i <= b; i++)
#define RF(i, a, b) for (lli i = a; i >= b; i--)
#define endl "\n"
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> dp;

int main()
{
    speed;
    int n, k;
    cin >> n >> k;
    int ans=0;
    int i=1,j=0;
    if(k==0){
        for(int i=1;i<=n;i++){
            ans+=i-1;
        }
    }
    else {
        while(i<=n && j<=n){
            int cnt=floor(j/i);
            if(cnt<k){
                j++;
            }
            else if(cnt>k)i++;
            else {
                ans++;
                j++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}