#include <bits/stdc++.h>
using namespace std;
int n, k, Ll, Rr, st[500005][35];
long long ans, sum[500005];
struct node
{
    int x, l, r, t;
    bool operator<(const node &y) const
    {
        return sum[t] - sum[x - 1] < sum[y.t] - sum[y.x - 1];
    }
};
priority_queue<node> q;
int calc(int l, int r)
{
    int k = floor(log2(r - l + 1)), x = st[l][k], y = st[r - (1 << k) + 1][k];
    return sum[x] > sum[y] ? x : y;
}
int main()
{
    scanf("%d%d%d%d", &n, &k, &Ll, &Rr);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++)
        st[i][0] = i;
    int t = floor(log2(n));
    for (int j = 1; j <= t; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = sum[x] > sum[y] ? x : y;
        }
    for (int i = 1; i <= n; i++)
        if (i + Ll - 1 <= n)
            q.push((node){i, i + Ll - 1, min(n, i + Rr - 1), calc(i + Ll - 1, min(n, i + Rr - 1))});
    while (k--)
    {
        int x = q.top().x, l = q.top().l, r = q.top().r, t = q.top().t;
        q.pop();
        ans += sum[t] - sum[x - 1];
        if (l != t)
            q.push((node){x, l, t - 1, calc(l, t - 1)});
        if (r != t)
            q.push((node){x, t + 1, r, calc(t + 1, r)});
    }
    printf("%lld", ans);
    return 0;
}