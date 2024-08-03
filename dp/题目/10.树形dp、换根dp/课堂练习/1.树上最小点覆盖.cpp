#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct node
{
    int to, Next;
} edge[maxn];
int head[maxn], cnt, dp[maxn][2];
void addedge(int u, int v)
{
    edge[cnt].to = v, edge[cnt].Next = head[u], head[u] = cnt++;
    return;
}
void DFS(int u, int fa)
{
    dp[u][0] = 0, dp[u][1] = 1;
    for (int k = head[u]; ~k; k = edge[k].Next)
    {
        int v = edge[k].to;
        if (v == fa)
            continue;
        DFS(v, u);
        dp[u][1] += min(dp[v][0], dp[v][1]), dp[u][0] += dp[v][1];
    }
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    int a, b, x, n;
    while (~scanf("%d", &n))
    {

        for (int i = 0; i <= n; i++)
            head[i] = -1;
        cnt = 0;
        int root = -1;
        for (int k = 1; k <= n; k++)
        {
            scanf("%d:(%d)", &a, &b);
            if (root == -1)
                root = a; // 记录根节点
            for (int i = 1; i <= b; i++)
            {
                scanf("%d", &x);
                addedge(a, x);
                addedge(x, a);
            }
        }
        DFS(root, -1); // 根节点的父节点 -1
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }
}
