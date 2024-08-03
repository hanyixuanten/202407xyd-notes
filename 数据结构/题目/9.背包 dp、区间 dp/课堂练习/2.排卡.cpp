#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[1005], f[1005][1005][2], mod = 998244353;
int fast_pow(int a, int b, int c = mod)
{
    if (a == 0 && b == 0)
        return 0;
    int x, y, m = 1;
    y = a, x = b;
    while (b)
    {
        if (b % 2)
            m = m * a % c;
        a = a * a % c;
        b /= 2;
    }
    return m;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        memset(f, 0, sizeof(f));
        //-----------------dp-------------------//
        for (int len = 1; len < n; len++)
            for (int i = 1; i + len <= n; i++)
            {
                f[i][i + len][0] = max(f[i + 1][i + len][0] + fast_pow(a[i], a[i + 1]), f[i + 1][i + len][1] + fast_pow(a[i], a[i + len]));             // left
                f[i][i + len][1] = max(f[i][i + len - 1][0] + fast_pow(a[i + len], a[i]), f[i][i + len - 1][1] + fast_pow(a[i + len], a[i + len - 1])); // right
            }
        printf("%lld\n", max(f[1][n][0], f[1][n][1]));
    }
    return 0;
}