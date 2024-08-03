#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
const int maxn = 5e5 + 5;
int t[maxn], a[maxn], n, q;
int query(int x)
{
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}
void add(int x, int k)
{
    for (; x <= n; x += lowbit(x))
        t[x] += k;
    return;
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n + 1; i++)
            t[i] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        while (q--)
        {
            int opt, l, r;
            scanf("%d", &opt);
            if (opt == 1)
            {
                scanf("%d%d", &l, &r);
                add(l, 1);
                add(r + 1, -1);
            }
            else
            {
                int x;
                scanf("%d", &x);
                int k = query(x), v = a[x];
                for (int i = 1; i <= k; i++)
                {
                    if (v < 10)
                        break;
                    int p = 0;
                    while (v)
                        p += (v % 10),v /= 10;
                    v = p;
                }
                printf("%d\n", v);
            }
        }
    }

    return 0;
}
