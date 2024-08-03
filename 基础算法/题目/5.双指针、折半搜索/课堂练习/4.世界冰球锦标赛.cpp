#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[45];
int ans = 0;
int f[1000005];
void dfs(int dep, int sum)
{
    if (sum > m)
        return;
    if (dep == n + 1)
    {
        ++ans;
        return;
    }
    dfs(dep + 1, sum + a[dep]);
    dfs(dep + 1, sum);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    if (m >= 1e6)
        dfs(1, 0);
    else
    {
        f[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= a[i]; j--)
                f[j] += f[j - a[i]];
        for (int i = 0; i <= m; i++)
            ans += f[i];
    }
    printf("%lld\n", ans);
    return 0;
}