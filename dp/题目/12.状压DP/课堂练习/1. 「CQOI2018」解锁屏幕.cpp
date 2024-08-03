#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000007;
pair<int, int> p[25];
int dp[2500005][25], ans;
int f[25][25]; // 过i，j必须经过的点
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
long double work(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
        return INT_MAX;
    return 1.0 * (y1 - y2) / (x1 - x2);
}
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
    // pre begin
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = i + 1; k <= j - 1; k++)
                if (abs(work(p[i].first, p[i].second, p[k].first, p[k].second) - work(p[k].first, p[k].second, p[j].first, p[j].second)) <= 1e-7)
                    f[i][j] |= (1 << k), f[j][i] |= (1 << k);
    // pre end
    for (int i = 1; i <= n; i++)
        dp[1 << i][i] = 1;
    for (int i = 0; i < (1 << (n + 1)); i++)
        for (int j = 1; j <= n; j++)
            if (i & (1 << j))
                for (int k = 1; k <= n; k++)
                    if ((i & (1 << k)) == 0 && k != j && (i & f[j][k]) == f[j][k])
                        dp[i | (1 << k)][k] = (dp[i | (1 << k)][k] + dp[i][j]) % MOD;
    for (int i = 0; i < (1 << (n + 1)); i++)
        if (__builtin_popcount(i) >= 4)
            for (int j = 1; j <= n; j++)
                if (i & (1 << j))
                    ans = (ans + dp[i][j]) % MOD;
    printf("%d\n", ans);
    return 0;
}