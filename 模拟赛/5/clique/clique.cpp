#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
bool edg[1005][1005];    // 原图
bool edgrev[1005][1005]; // 补图
bool S[1005], T[1005];
int ans = 0;
bool used[1005];
void dfs(int last = -1) // 30pts+eps
{
    bool fla1 = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!edg[i][j] && S[i] && S[j])
            {
                fla1 = 0;
                break;
            }
        }
        if (!fla1)
            break;
    }
    bool fla2 = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!edgrev[i][j] && T[i] && T[j])
            {
                fla2 = 0;
                break;
            }
        }
        if (!fla2)
            break;
    }
    if (fla1 && fla2)
        ++ans, ans %= mod;
    for (int i = last; i <= n; ++i)
    {
        if (S[i])
        {
            S[i] = 0, T[i] = 1;
            dfs(i);
            S[i] = 1, T[i] = 0;
        }
    }
    return;
}
int main()
{
    freopen("clique.in", "r", stdin);
    freopen("clique.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v), edg[u][v] = 1, edg[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            edgrev[i][j] = !edg[i][j];
    for (int i = 1; i <= n; ++i)
        S[i] = 1, edg[i][i] = 1, edgrev[i][i] = 1;
    dfs();
    printf("%d\n", ans);
    return 0;
}