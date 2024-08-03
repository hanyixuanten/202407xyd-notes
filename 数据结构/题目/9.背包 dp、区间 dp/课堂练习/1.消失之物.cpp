#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, w[N], f[N], g[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= w[i]; --j)
            f[j] = (f[j] + f[j - w[i]]) % 10;
    for (int i = 1; i <= n; ++i)
    {
        memset(g, 0, sizeof(g));
        g[0] = 1;
        for (int j = 1; i <= m; ++j)
        {
            if (j - w[i] >= 0)
                g[j] = (f[j] - g[j - w[i]] + 10) % 10;
            else
                g[j] = f[j] % 10;
            printf("%d", g[j] % 10);
        }
        puts("");
    }
    return 0;
}
