#include <bits/stdc++.h>
using namespace std;
int fa[10002][1002], ans[1000002], n, m, k;
// ans[i]表示第i条边被删掉的人的编号
int gf(int p, int q)
{
    // 并查集查找
    return fa[p][q] == q ? q : (fa[p][q] = fa[p][gf(p, fa[p][q])]);
}
struct node
{
    int w, u, v, i;
    constexpr bool operator<(const node &p) const
    {
        return w > p.w;
    }
} a[1000002];
int main()
{
    scanf("%d%d%d", &n, &m, &k); // n点m边k人
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w), a[i].i = i;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            fa[i][j] = j;   // init
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = k + 1, mid, p = a[i].u, q = a[i].v;
        while (l < r) // 二分被谁删掉
            mid = l + r >> 1, gf(mid, p) == gf(mid, q) ? (l = mid + 1) : (r = mid);
        if (l <= k)
            fa[ans[a[i].i] = l][gf(l, p)] = gf(l, q);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
}