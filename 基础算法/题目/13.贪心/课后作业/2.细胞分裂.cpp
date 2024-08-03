#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
signed main()
{
    int n;
    int ans = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    int pre = a[n];
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] <= pre)
        {
            pre = a[i];
        }
        else if (a[i] % pre == 0)
        {
            ans += a[i] / pre - 1;
        }
        else
        {
            ans += a[i] / pre;
            pre = a[i] / (a[i] / pre + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}