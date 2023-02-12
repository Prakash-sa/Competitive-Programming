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

int sum_di(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    speed;
    int n;
    cin >> n;
    int ans = 7 * n + 21 * sum_di(n);
    // for (int i = 0; i < 6; i++){
    //     ans+=sum_di(ans);
    //     cout<<ans<<" ";
    // }
    cout << ans << endl;

    return 0;
}