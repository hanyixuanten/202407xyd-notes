// 以前做过 :D
#include <bits/stdc++.h>
using namespace std;
const int N = 1600005;
int t, n;
int head[N], cnt, dp[N][2], pos[N], dpp[N], ans[N], sizes[N], maxsizes[N];
struct node
{
    int to, nxt;
} e[N];
void add(int u, int v)
{
    e[++cnt].nxt = head[u], head[u] = cnt, e[cnt].to = v;
}
void dfs1(int rootn, int fa)
{
    sizes[rootn] = 1;
    for (int i = head[rootn]; i; i = e[i].nxt)
    {
        if (e[i].to == fa)
            continue;
        dfs1(e[i].to, rootn);
        int v;
        sizes[rootn] += sizes[e[i].to];
        if (sizes[e[i].to] > sizes[maxsizes[rootn]])
            maxsizes[rootn] = e[i].to;
        if (sizes[e[i].to] <= n / 2)
            v = sizes[e[i].to];
        else
            v = dp[e[i].to][0];
        if (dp[rootn][0] < v)
            dp[rootn][1] = dp[rootn][0], dp[rootn][0] = v, pos[rootn] = e[i].to;
        else if (dp[rootn][1] < v)
            dp[rootn][1] = v;
    }
}
void dfs2(int rootn, int fa)
{
    ans[rootn] = 1;
    if (sizes[maxsizes[rootn]] > n / 2)
        ans[rootn] = (sizes[maxsizes[rootn]] - dp[maxsizes[rootn]][0] <= n / 2);
    else if (n - sizes[rootn] > n / 2)
        ans[rootn] = (n - sizes[rootn] - dpp[rootn] <= n / 2);
    for (int i = head[rootn]; i; i = e[i].nxt)
    {
        if (e[i].to == fa)
            continue;
        int v;
        if (n - sizes[rootn] > n / 2)
            v = dpp[rootn];
        else
            v = n - sizes[rootn];
        dpp[e[i].to] = max(dpp[e[i].to], v);
        if (pos[rootn] == e[i].to)
            dpp[e[i].to] = max(dpp[e[i].to], dp[rootn][1]);
        else
            dpp[e[i].to] = max(dpp[e[i].to], dp[rootn][0]);
        dfs2(e[i].to, rootn);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs1(1, 0), dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}