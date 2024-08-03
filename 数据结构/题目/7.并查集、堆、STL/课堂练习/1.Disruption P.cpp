#include <bits/stdc++.h>
using namespace std;
int ans[50010];
int n, m;
int par[50010][17], dep[50010], po[50010], to[50010];
vector<pair<int, int>> G[50010];
pair<int, pair<int, int>> roads[50010];
int getfa(int x)
{
    if (to[x] == x)
        return x;
    return to[x] = getfa(to[x]); // 路径压缩
}
void dfs(int x, int p)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i].first, id = G[x][i].second;
        if (y == p)
            continue;
        po[id] = y, par[y][0] = x, dep[y] = dep[x] + 1;
        dfs(y, x);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 16; i >= 0; i--)
        if (dep[par[x][i]] >= dep[y])
            x = par[x][i];
    if (x == y)
        return x;
    for (int i = 16; i >= 0; i--)
        if (par[x][i] != par[y][i])
            x = par[x][i], y = par[y][i];
    return par[x][0];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back({y, i}), G[y].push_back({x, i});
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        roads[i] = {z, {x, y}};
    }
    dep[0] = -1;
    dfs(1, 0);
    for (int i = 1; i <= 16; i++)
        for (int j = 1; j <= n; j++)
            par[j][i] = par[par[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++)
        to[i] = i, ans[i] = -1;
    sort(roads + 1, roads + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int v = roads[i].first, x = roads[i].second.first, y = roads[i].second.second, xy = lca(x, y);
        for (x = getfa(x); dep[x] > dep[xy]; x = getfa(par[x][0]))
            ans[x] = v, to[x] = par[x][0];
        for (y = getfa(y); dep[y] > dep[xy]; y = getfa(par[y][0]))
            ans[y] = v, to[y] = par[y][0];
    }
    for (int i = 1; i < n; i++)
        printf("%d\n", ans[po[i]]);
    return 0;
}