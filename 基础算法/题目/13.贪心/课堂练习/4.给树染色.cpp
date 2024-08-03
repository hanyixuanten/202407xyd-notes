#include <bits/stdc++.h>
using namespace std;
int n, t, r, x, y;
int v[1005], num[1005], a[1005], fa[1005], g[1005][1005], cnt[1005];
bool vis[1005], u[1005];
queue<int> q[1005];
void merge(int x, int y)
{
    fa[x] = y, v[y] += v[x], num[y] += num[x], vis[x] = 1;
    while (!q[x].empty())
        q[y].push(q[x].front()), q[x].pop();
    return;
}

int Find(int x)
{
    if (!fa[x] || !u[x])
        return x;
    return fa[x] = Find(fa[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("4.in", "r", stdin);
#endif
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), v[i] = a[i], num[i] = 1, q[i].push(a[i]);
    for (int i = 1; i < n; i++)
        scanf("%d%d", &x, &y), g[x][++cnt[x]] = y, fa[y] = x;
    vis[r] = 1;
    for (int i = 1; i < n; i++)
    {
        int ans;
        double max = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && (double)v[i] / num[i] > max)
                ans = i, max = (double)v[i] / num[i];
        vis[ans] = 1, x = ans, u[x] = 1;
        merge(x, Find(x));
    }
    int sum = 0, k = 0;
    while (!q[r].empty())
        ++k, sum += q[r].front() * k, q[r].pop();
    printf("%d\n", sum);
    return 0;
}