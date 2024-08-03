#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = 0x7f7f7f7f;
int n, m, dp[N][5];
int nxt[N], to[N];
int head[N], cnt;
void add(int too, int from)
{
    to[++cnt] = too;
    nxt[cnt] = head[from];
    head[from] = cnt;
}
void search(int u, int fa)
{
    int tot = 0, g[N];
    dp[u][0] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        search(v, u);
        dp[u][0] += min(dp[v][0], min(dp[v][1], dp[v][2]));
        dp[u][1] += dp[v][0];
        dp[u][2] += min(dp[v][0], dp[v][1]);
        g[++tot] = dp[v][1] - dp[v][0];
    }
    if (!tot)
        dp[u][1] = INF;
    else
    {
        sort(g + 1, g + 1 + tot);
        for (int i = 1; i < tot; i++)
        {
            if (g[i] < 0)
                dp[u][1] += g[i];
            else
                break;
        }
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("5.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    search(1, 0);
    printf("%d", min(dp[1][0], dp[1][1]));
    return 0;
}
