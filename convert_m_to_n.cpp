#include <bits/stdc++.h>
using namespace std;

int convert(int m, int n) 
{
    if (m == n)
        return 0;
    if (m > n)
        return m - n;
    if (m <= 0 && n > 0)
        return -1;

    if (n % 2 == 1)
        return 1 + convert(m, n + 1);
    else
        return 1 + convert(m, n / 2);
}

int main()
{
    int m = 3, n = 11;
    cout << "Minimum number of operations : "
         << convert(m, n);
    return 0;
}
