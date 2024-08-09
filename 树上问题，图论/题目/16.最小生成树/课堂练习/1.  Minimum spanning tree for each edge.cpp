#include <bits/stdc++.h>
#define int long long
using namespace std;
int depth[200010], f[200020][21], vis[200010], fa[200010], cnt, head[200010];
int n, m, x, y, q, start, end;
int w[200020][21], T;
struct node1
{
    int dis, u, v, id;
#define u(x) t[i].u
#define v(x) t[i].v
#define dis(x) t[i].dis
} t[400010];
struct node2
{
    int dis, ver, nxt;
} p[400010];
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
void make_tree(int u)
{
    vis[u] = 1;
    for (int j = 1; j <= 20; j++)

        f[u][j] = f[f[u][j - 1]][j - 1], w[u][j] = max(w[u][j - 1], w[f[u][j - 1]][j - 1]);
    for (int i = head[u]; i; i = p[i].nxt)
    {
        int v = p[i].ver;
        if (vis[v])
            continue;
        depth[v] = depth[u] + 1, f[v][0] = u, w[v][0] = p[i].dis;
        make_tree(v);
    }
}
int lca(int x, int y)
{
    int ans = 0;
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (depth[f[x][i]] >= depth[y])
            ans = max(ans, w[x][i]), x = f[x][i];
    if (x == y)
        return ans;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i])
            ans = max(ans, max(w[x][i], w[y][i])), x = f[x][i], y = f[y][i];
    return max(ans, max(w[x][0], w[y][0]));
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    auto add_edge = [](int u, int v, int l)
    { p[++cnt].dis = l, p[cnt].nxt = head[u], p[cnt].ver = v, head[u] = cnt; };
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u(i), &v(i), &dis(i));
        t[i].id = i;
    }
    sort(t + 1, t + m + 1, [](node1 a, node1 b)
         { return a.dis < b.dis; });
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x = u(i), y = t[i].v, fx = find(x), fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            add_edge(fx, fy, dis(i)), add_edge(fy, fx, dis(i));
            T += dis(i);
        }
    }
    make_tree(1);
    int ans = 0;
    sort(t + 1, t + m + 1, [](node1 a, node1 b)
         { return a.id < b.id; });
    for (int i = 1; i <= m; i++)
    {
        ans = T + dis(i) - lca(u(i), v(i));
        printf("%lld\n", ans);
    }
    return 0;
}