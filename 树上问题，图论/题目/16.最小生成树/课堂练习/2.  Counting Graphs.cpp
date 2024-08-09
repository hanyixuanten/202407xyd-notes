#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 998244353;
int T, n, S;
struct Edge
{
    int u, v, w;
} e[N];

int power(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % mod;
        y >>= 1, x = x * x % mod;
    }
    return ans;
}

struct node
{
    int fa[N], sz[N];
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        if (find(x) == find(y))
            return;
        x = find(x), y = find(y);
        fa[x] = y, sz[y] += sz[x];
        return;
    }
} cxy;
map<int, int> cnt;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    scanf("%lld", &T);
    while (T--)
    {
        cnt.clear();
        scanf("%lld%lld", &n, &S);
        for (int i = 1; i < n; ++i)
            scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
        sort(e + 1, e + n, [](Edge a, Edge b)
             { return a.w < b.w; });
        for (int i = 1; i <= n; ++i)
            cxy.fa[i] = i, cxy.sz[i] = 1;
        for (int i = 1; i < n; ++i)
        {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            cnt[w] += cxy.sz[cxy.find(u)] * cxy.sz[cxy.find(v)] - 1;
            cxy.merge(u, v);
        }
        int ans = 1;
        for (auto i : cnt)
        {
            if (i.second)
                ans = ans * power(S - i.first + 1, i.second) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}