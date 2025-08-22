#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define F(i, a, b) for (lli i = a; i <= b; i++)
#define RF(i, a, b) for (lli i = a; i >= b; i--)
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> v[100009];
int ans, node;
int visited[100009];
void dfs(int x, int pos)
{
    visited[x] = true;
    if (pos > ans)
    {
        ans = pos;
        node = x;
    }
    for (int i = 0; i < v[x].size(); i++)
    {
        if (!visited[v[x][i]])
            dfs(v[x][i], pos + 1);
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n;
        for (int i = 0; i < 100009; i++)
            visited[i] = false;
        ans = 0;
        node = 0;
        for (int i = 0; i < 100009; i++)
            v[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(0, 0);
        ans = 0;
        memset(visited, false, sizeof(visited));
        dfs(node, 0);
        if (ans % 2)
            cout << ans / 2 + 1 << endl;
        else
            cout << ans / 2 << endl;
    }
    return 0;
}