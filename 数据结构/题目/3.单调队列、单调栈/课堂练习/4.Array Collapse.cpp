#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5, mod = 998244353;
int T, n, tp;
int a[N], stkm[N], cxy[N], dp2[N], dp1[N];
void work1()
{
    scanf("%lld", &n);
    tp = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    dp2[0] = cxy[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        while (tp && a[stkm[tp]] > a[i])
            tp--;
        int j = stkm[tp];
        if (j)
            dp1[i] = (dp2[j] + dp1[j]) % mod;
        else
            dp1[i] = 0;
        dp2[i] = (cxy[i - 1] - (j == 0 ? 0 : cxy[j - 1]) + dp1[j] + mod) % mod,
        cxy[i] = (cxy[i - 1] + dp2[i]) % mod, stkm[++tp] = i;
    }
    printf("%lld\n", (dp2[n] + dp1[n]) % mod);
}
signed main()
{
    scanf("%lld", &T);
    while (T--)
        work1();
}