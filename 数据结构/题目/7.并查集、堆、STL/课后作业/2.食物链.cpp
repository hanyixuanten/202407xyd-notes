#include <bits/stdc++.h>
const int maxN = 100005;
int n, m, ans, fa[maxN * 3];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= maxN; ++i)
        fa[i] = i;
    while (m--)
    {
        int opt, u, v;
        scanf("%d%d%d", &opt, &u, &v);
        if (u > n || v > n)
        {
            ++ans;
            continue;
        }
        if (opt == 1)
        {
            if (find(u + n) == find(v) || find(u) == find(v + n))
                ++ans;
            else
                fa[find(u)] = find(v), fa[find(u + n)] = find(v + n), fa[find(u + n + n)] = find(v + n + n);
        }
        else
        {
            if (find(u) == find(v) || find(u) == find(v + n))
                ++ans;
            else
                fa[find(u + n)] = find(v), fa[find(u + n + n)] = find(v + n), fa[find(u)] = find(v + n + n);
        }
    }
    printf("%d\n", ans);
    return 0;
}
