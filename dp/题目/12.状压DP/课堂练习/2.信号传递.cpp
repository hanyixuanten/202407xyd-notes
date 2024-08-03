#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAX_PWR = 1 << 23;
int n, m, kx, a[MAXN], mp[23][23] = {0};
int lg2[MAX_PWR], dp[MAX_PWR][23], f[MAX_PWR];
int lowbit(int x)
{
    return x & (-x);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &kx);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n; ++i)
        ++mp[a[i - 1] - 1][a[i] - 1];
    lg2[0] = -1;
    for (int i = 1; i < (1 << m); ++i)
        lg2[i] = lg2[i >> 1] + 1; // 预处理log2
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (i != j)
                dp[0][i] += kx * mp[j][i] - mp[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 1; j < (1 << (m - 1)); ++j)
        {
            int lb = lowbit(j), posi = lg2[lb] + (lg2[lb] >= i);
            dp[j][i] = dp[j ^ lb][i] + (1 - kx) * mp[posi][i] + (kx + 1) * mp[i][posi];
        }
    // pre
    f[0] = 0;
    for (int i = 1; i < (1 << m); ++i)
    {
        f[i] = 0x7f7f7f7f;
        for (int k = i, j = lowbit(k); j = lowbit(k); k ^= j)
        {
            int posi = lg2[j], cnts = __builtin_popcount(i), last = i ^ j;
            f[i] = min(f[i], f[last] + cnts * dp[(((last >> (posi + 1))) << posi) | (last & (j - 1))][posi]);
        }
    }
    printf("%d\n", f[(1 << m) - 1]);
    return 0;
}