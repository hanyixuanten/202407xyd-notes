#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int short
using namespace std;
const int N = 2e4 + 20;
struct node
{
    int y, x1, x2, o; // y, [x1, x2], o = {+1, -1}
    bool operator<(const node &b) const
    {
        return y < b.y || (y == b.y && o > b.o);
    }
} a[N];
int n, m;
int mn[N * 4], cnt[N * 4], add[N * 4];
void build(int u, int l, int r)
{
    mn[u] = 0;
    cnt[u] = r - l + 1;
    add[u] = 0;
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(u * 2, l, m);
    build(u * 2 + 1, m + 1, r);
}
// 最小值，最小值个数，区间加标记
void pushdown(int u)
{
    if (add[u])
    {
        add[u * 2] += add[u];
        mn[u * 2] += add[u];
        add[u * 2 + 1] += add[u];
        mn[u * 2 + 1] += add[u];
        add[u] = 0;
    }
}
int q_mn, q_cnt;
void query(int u, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        if (q_mn > mn[u])
            q_mn = mn[u], q_cnt = cnt[u];
        else if (q_mn == mn[u])
            q_cnt += cnt[u];
        return;
    }
    pushdown(u);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        query(u << 1, l, mid, ql, qr);
    else if (ql > mid)
        query(u << 1 | 1, mid + 1, r, ql, qr);
    else
    {
        query(u << 1, l, mid, ql, mid);
        query(u << 1 | 1, mid + 1, r, mid + 1, qr);
    }
}
void modify(int u, int l, int r, int ql, int qr, int v)
{
    if (l == ql && r == qr)
    {
        add[u] += v;
        mn[u] += v;
        return;
    }
    pushdown(u);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        modify(u << 1, l, mid, ql, qr, v);
    else if (ql > mid)
        modify(u << 1 | 1, mid + 1, r, ql, qr, v);
    else
    {
        modify(u << 1, l, mid, ql, mid, v);
        modify(u << 1 | 1, mid + 1, r, mid + 1, qr, v);
    }
    mn[u] = min(mn[u * 2], mn[u * 2 + 1]);
    cnt[u] = 0;
    if (mn[u] == mn[u * 2])
        cnt[u] += cnt[u * 2];
    if (mn[u] == mn[u * 2 + 1])
        cnt[u] += cnt[u * 2 + 1];
}
int ans;
vector<vector<int>> v;
void solve()
{
    build(1, 1, N - 1);
    m = 0;
    for (int i = 1; i <= n; i++)
    {
        int x1 = v[i - 1][0];
        int y1 = v[i - 1][1];
        int x2 = v[i - 1][2];
        int y2 = v[i - 1][3];
        a[++m] = (node){y1, x1, x2, 1};
        a[++m] = (node){y2, x1, x2, -1};
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (a[i].o == 1)
        {
            q_mn = 1e9, q_cnt = 0;
            query(1, 1, N - 1, a[i].x1, a[i].x2 - 1);
            if (q_mn == 0)
                ans += q_cnt;
        }
        modify(1, 1, N - 1, a[i].x1, a[i].x2 - 1, a[i].o);

        if (a[i].o == -1)
        {
            q_mn = 1e9, q_cnt = 0;
            query(1, 1, N - 1, a[i].x1, a[i].x2 - 1);
            if (q_mn == 0)
                ans += q_cnt;
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 10001;
        y1 += 10001;
        x2 += 10001;
        y2 += 10001;
        v.push_back({x1, y1, x2, y2});
    }
    solve();
    for (int i = 0; i < n; i++)
    {
        swap(v[i][0], v[i][1]);
        swap(v[i][2], v[i][3]);
    }
    solve();
    printf("%d\n", ans);
    return 0;
}