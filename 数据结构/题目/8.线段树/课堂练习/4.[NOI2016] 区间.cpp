#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int a[8 * N], sum[8 * N], lazy_tag[8 * N];
int n, m, tail, head, ans, size, minn, maxn;
void push_down(int rt)
{
    if (lazy_tag[rt])

        sum[rt << 1] += lazy_tag[rt], sum[rt << 1 | 1] += lazy_tag[rt], lazy_tag[rt << 1] += lazy_tag[rt], lazy_tag[rt << 1 | 1] += lazy_tag[rt], lazy_tag[rt] = 0;
}
void update(int rt, int l, int r, int x, int y, int k)
{
    if (x > r || l > y)
        return;
    if (x <= l && r <= y)
    {
        lazy_tag[rt] += k, sum[rt] += k;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, x, y, k);
    update(rt << 1 | 1, mid + 1, r, x, y, k);
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
struct node
{
    int l, r, z;
} qg[N];
bool cmp(node c, node d)
{
    return c.z < d.z;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("4.in", "r", stdin);
#endif
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        a[i * 2] = x, a[i * 2 + 1] = y, qg[i].l = x, qg[i].r = y, qg[i].z = y - x;
    }
    sort(a + 1, a + n * 2 + 2);
    size = unique(a + 1, a + n * 2 + 1) - (a + 1);
    sort(qg + 1, qg + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        qg[i].l = lower_bound(a + 1, a + size + 1, qg[i].l) - a, qg[i].r = lower_bound(a + 1, a + size + 1, qg[i].r) - a, minn = min(minn, qg[i].l), maxn = max(maxn, qg[i].r);
    head = 0, tail = 0, ans = INT_MAX;
    while (tail < n)
    {
        while (sum[1] < m && tail <= n)
        {
            ++tail;
            update(1, minn, maxn, qg[tail].l, qg[tail].r, 1);
        }
        if (sum[1] < m)
            break;
        while (sum[1] >= m && tail >= head)
        {
            ++head;
            update(1, minn, maxn, qg[head].l, qg[head].r, -1);
        }
        ans = min(ans, qg[tail].z - qg[head].z);
    }
    printf("%lld\n", ans);
    return 0;
}
// (ans == INT_MAX) ? -1 :