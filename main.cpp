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
    int n;
    cin >> n;
    while (n--)
    {
        int n1, k, ans = 0;
        cin >> n1;
        vector<int> a;
        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            a.push_back(k);
        }
        for (int i = 0; i < n1 - 1; i++)
        {
            int d = 0;
            for (int j = i + 1; j < n1; j++)
            {
                d += a[j - 1] - a[j];
                if (d != a[j] - a[i])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}