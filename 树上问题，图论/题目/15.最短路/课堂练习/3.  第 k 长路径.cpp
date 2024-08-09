#include <bits/stdc++.h>
using namespace std;
int n, m, n2kcut, k;
struct node
{
    int x, y, l;
    const bool operator<(const node &b)
    {
        return l < b.l;
    }
} b[200005];
int note[200005], a[805];
long long dis[805][805];
long long d[805 * 805];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("3.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].l);
    sort(b + 1, b + m + 1);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= k; i++)
        note[b[i].x] = 1, note[b[i].y] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + note[i];
    n2kcut = a[n];
    for (int i = 1; i <= k; i++)
    {
        dis[a[b[i].x]][a[b[i].y]] = b[i].l;
        dis[a[b[i].y]][a[b[i].x]] = b[i].l;
    }
    n = n2kcut;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            d[++cnt] = dis[i][j];
    sort(d + 1, d + cnt + 1);
    printf("%lld\n", d[k]);
    return 0;
}