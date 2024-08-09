#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n, m, k;
int curr, head[N], nxt[N], ver[N];
int dis[2][N], book[N];
bool ans[N];
vector<int> que[N];

struct node
{
    int x, y, z;
} e[N];
void add(int x, int y)
{
    ver[++curr] = y;
    nxt[curr] = head[x];
    head[x] = curr;
}
void spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(book, 0, sizeof(book));
    queue<int> q;
    q.push(s);
    dis[0][s] = 0;
    while (!q.empty())
    {
        int x = q.front(), flag = 0;
        q.pop();
        book[x] = 0;
        for (int j = head[x]; j; j = nxt[j])
        {
            int y = ver[j];
            if (dis[0][x] != dis[0][0])
                if (dis[1][y] > dis[0][x] + 1)
                    dis[1][y] = dis[0][x] + 1, flag = 1;
            if (dis[1][x] != dis[0][0])
                if (dis[0][y] > dis[1][x] + 1)
                    dis[0][y] = dis[1][x] + 1, flag = 1;
            if (flag && !book[y])
                q.push(y), book[y] = 1;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= k; i++)
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z), que[e[i].x].push_back(i);
    for (int i = 1; i <= n; i++)
    {
        if (que[i].empty())
            continue;
        spfa(i);
        for (int j = 0; j < que[i].size(); j++)
        {
            int o = que[i][j];
            if (e[o].z >= dis[e[o].z % 2][e[o].y] && head[i])
                ans[o] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (ans[i])
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}