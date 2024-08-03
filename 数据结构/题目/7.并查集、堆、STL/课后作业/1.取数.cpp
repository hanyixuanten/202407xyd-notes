// 如果a[i] + a[j]是第k小和,则min(a[i + 1] + b[j], a[i]+b[j + 1])是第k+1小和
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma GCC optimize(3,"Ofast","inline")
#endif
using namespace std;
int m, n, k, a[805][805], cxy[805], c[805], top;
priority_queue<int> q;
void search(int t, int s)
{
    for (int i = 1; i <= m; i++)
    {
        s += a[t][i];
        if (s + cxy[n] - cxy[t] > q.top())
            return;
        if (t == n)
        {
            if (s < q.top())
                q.pop(), q.push(s);
        }
        else
            search(t + 1, s);
        s -= a[t][i];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
        sort(a[i] + 1, a[i] + 1 + m);
        cxy[i] = cxy[i - 1] + a[i][1]; // 前缀和
    }
    for (int i = 1; i <= k; i++)
        q.push(0x7f7f7f7f);
    search(1, 0);
    while (q.size())
        c[++top] = q.top(), q.pop();
    for (int i = k; i >= 1; i--)
        printf("%d ", c[i]);
    puts("");
    return 0;
}
