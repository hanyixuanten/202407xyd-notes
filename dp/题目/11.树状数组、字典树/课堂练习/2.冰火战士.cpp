// 以前做过qwq
#include <bits/stdc++.h>
using namespace std;
#define Length int(2e6 + 5)
int n, m, c[Length][2], tot, lsh[Length], now[Length], cntIce, cntFire, allFire;
struct node
{
    int opt, t, x, y;
} Sec[Length];
inline int lowbit(int x)
{
    return x & (-x);
}
inline void add(int x, int d, int op)
{
    while (x <= tot)
        c[x][op] += d, x += lowbit(x);
}
inline int qry(int x, int op)
{
    int res = 0;
    while (x)
        res += c[x][op], x -= lowbit(x);
    return res;
}
inline int Calc(int x)
{
    if (x < 1 || x > tot)
        return -1;
    return min(qry(x, 0), allFire - qry(x - 1, 1));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &Sec[i].opt);
        if (Sec[i].opt == 1)
        {
            scanf("%d%d%d", Sec[i].t, Sec[i].x, Sec[i].y);
            lsh[++tot] = Sec[i].x;
        }
        else
            scanf("%d", &Sec[i].t);
    }
    sort(lsh + 1, lsh + 1 + tot);
    tot = unique(lsh + 1, lsh + 1 + tot) - lsh - 1;
    for (int i = 1; i <= n; i++)
        if (Sec[i].opt == 1)
            Sec[i].x = lower_bound(lsh + 1, lsh + 1 + tot, Sec[i].x) - lsh;
    for (int i = 1; i <= n; i++)
    {
        if (Sec[i].opt == 1)
        {
            if (!Sec[i].t)
                cntIce++;
            else
                cntFire++, allFire += Sec[i].y, now[Sec[i].x] += Sec[i].y;
            add(Sec[i].x, Sec[i].y, Sec[i].t);
        }
        else
        {
            if (!Sec[Sec[i].t].t)
                cntIce--;
            else
                cntFire--, allFire -= Sec[Sec[i].t].y, now[Sec[Sec[i].t].x] -= Sec[Sec[i].t].y;
            add(Sec[Sec[i].t].x, -Sec[Sec[i].t].y, Sec[Sec[i].t].t);
        }
        if (!cntIce || !cntFire)
        {
            puts("Peace");
            continue;
        }
        int pos = 0, sum = 0;
        for (int i = 21; i >= 0; i--)
        {
            int to = pos | (1 << i);
            if (to <= tot && sum + c[to][0] + c[to][1] - allFire - now[to] <= 0)
                pos = to, sum += c[to][0] + c[to][1];
        }
        int ansT = Calc(pos), ansTT = Calc(pos + 1);
        if (ansT <= 0 && ansTT <= 0)
        {
            puts("Peace");
            continue;
        }
        if (ansT > ansTT)
        {
            printf("%d %d\n",lsh[pos],ansT << 1);
            continue;
        }
        pos = 0, sum = 0;
        for (int i = 21; i >= 0; i--)
        {
            int to = pos | (1 << i);
            if (to <= tot && allFire - (sum + c[to][1] - now[to]) >= ansTT)
                pos = to, sum += c[to][1];
        }
        printf("%d %d\n",lsh[pos],ansTT << 1);
    }
    return 0;
}