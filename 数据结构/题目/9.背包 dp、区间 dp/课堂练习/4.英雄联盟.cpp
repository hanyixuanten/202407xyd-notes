#include <bits/stdc++.h>
// fi = max(fi, f[i - g * c[p]] * g)
#define int long long
const int N = 1000005;
using namespace std;
int f[N], k[N], c[N], n, m, sq, ans;
signed main()
{
    f[0] = 1;
    scanf("%lld%lld", &n, &m);
    for (int p = 1; p <= n; ++p)
        scanf("%lld", &k[p]);
    for (int p = 1; p <= n; ++p)
    {
        scanf("%d", &c[p]);
        sq += k[p] * c[p];
    }
    for (int p = 1; p <= n; ++p)
        for (int i = sq; i >= 0; --i)
            for (int g = 0; g <= k[p] && g * c[p] <= i; ++g)
                f[i] = max(f[i], f[i - g * c[p]] * g);
    while (ans < sq && f[ans] < m)
        ++ans;
    printf("%d\n", ans);
}