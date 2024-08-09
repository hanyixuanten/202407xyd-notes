#include <bits/stdc++.h>
const int MAXN = 100010;
using namespace std;
bool f;
int n, m, q;
struct node
{
    int st, ed, v;
} Edge[MAXN];
int pre[MAXN];
bool cmp(node A, node B) { return A.v > B.v; }
int fFind(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = fFind(pre[x]);
}
struct nd
{
    vector<node> G[MAXN];
    int F[MAXN][20], num[MAXN][20], lg[MAXN], deep[MAXN], root[MAXN];
    bool mark[MAXN], vis[MAXN];
    void dfs(int x, int fa, int val, int rt)
    {
        root[x] = rt;
        F[x][0] = fa;
        num[x][0] = val;
        deep[x] = deep[fa] + 1;
        for (int i = 1; (1 << i) <= deep[x]; i++)
            F[x][i] = F[F[x][i - 1]][i - 1], num[x][i] = min(num[x][i - 1], num[F[x][i - 1]][i - 1]);
        for (int i = 0; i < G[x].size(); i++)
        {
            int t = G[x][i].ed, val = G[x][i].v;
            if (t == fa)
                continue;
            dfs(t, x, val, rt);
        }
    }
    int LCA(int x, int y)
    {
        if (deep[x] < deep[y])
            swap(x, y);
        int res = 2e9 + 7;
        while (deep[x] > deep[y])
            res = min(res, num[x][lg[deep[x] - deep[y]] - 1]), x = F[x][lg[deep[x] - deep[y]] - 1];
        if (x == y)
            return res;
        for (int i = lg[deep[x]] - 1; i >= 0; i--)
        {
            if (F[x][i] == F[y][i])
                continue;
            res = min(res, num[x][i]);
            res = min(res, num[y][i]);
            x = F[x][i], y = F[y][i];
        }
        res = min(res, num[x][0]);
        res = min(res, num[y][0]);
        return res;
    }
    void work()
    {
        for (int i = 1; i <= MAXN - 10; i++)
            lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            Edge[i] = node{x, y, z};
        }
        sort(Edge + 1, Edge + 1 + m, cmp);
        for (int i = 1; i <= m; i++)
        {
            int fx = fFind(Edge[i].st), fy = fFind(Edge[i].ed);
            if (fx == fy)
                continue;
            mark[Edge[i].st] = mark[Edge[i].ed] = true;
            pre[fx] = fy;
            G[Edge[i].st].push_back(node{0, Edge[i].ed, Edge[i].v});
            G[Edge[i].ed].push_back(node{0, Edge[i].st, Edge[i].v});
        }
        for (int i = 1; i <= n; i++)
            if (!root[i])
                dfs(i, 0, 0, i);
        scanf("%d", &q);
        for (int i = 1; i <= q; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (root[x] != root[y])
            {
                puts("-1");
                continue;
            }
            printf("%d\n", LCA(x, y));
        }
    }
} r;
bool fflag;
int main()
{
    scanf("%d %d", &n, &m);
    r.work();
    return 0;
}