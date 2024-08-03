#include <bits/stdc++.h>
using namespace std;

struct node
{
    int w, s;
    const bool operator<(const node &x) const
    {
        return w + s < x.w + x.s;
    }
} a[50001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].w, &a[i].s);
    sort(a + 1, a + 1 + n);
    int tot = 0, ans = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, tot - a[i].s);
        tot += a[i].w;
    }
    printf("%d\n", ans);
    return 0;
}