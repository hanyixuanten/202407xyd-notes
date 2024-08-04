#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n;
int to[N], nxt[N];
int dep[N], head[N], tot;
void add(int a, int b)
{
    to[++tot] = b, nxt[tot] = head[a], head[a] = tot;
}
int siz[N];
long long dp[N];
void search(int u, int fa)
{
    siz[u] = 1, dp[u] = dep[u];
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        search(v, u);
        siz[u] += siz[v], dp[u] += dp[v];
    }
}
void chroot(int u, int fa)
{
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dp[v] = dp[u] - siz[v] + n - siz[v];
        chroot(v, u);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("3.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    search(1, 0);
    chroot(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (dp[ans] < dp[i]) ? i : ans;
    printf("%d\n", ans);
}