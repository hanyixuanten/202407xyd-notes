#include <bits/stdc++.h>
using namespace std;
int n, m, k, b;
int a[200005], tmp[200005], l[200005], r[200005];
set<int> chose, unchose;
int fullmax = 0;
void dfs(int nowdepth)
{
    if (nowdepth == k)
    {
        int minn = 1e9 + 10;
        memset(tmp, 0, sizeof(tmp));
        for (auto j = chose.begin(); j != chose.end(); ++j)
            for (int i = l[*j]; i <= r[*j]; ++i)
                tmp[i] = b;
        for (int i = 1; i <= n; ++i)
            tmp[i] += a[i], minn = min(minn, tmp[i]);
        fullmax = max(fullmax, minn);
        return;
    }
    for (int i = 1; i <= unchose.size(); ++i)
    {
        chose.insert(i);
        unchose.erase(i);
        dfs(nowdepth + 1);
        chose.erase(i);
        unchose.insert(i);
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        fullmax = 0;
        chose.clear();
        unchose.clear();
        scanf("%d%d%d%d", &n, &m, &k, &b);
        for (int i = 1; i <= k; ++i)
            unchose.insert(i);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &l[i], &r[i]);
        dfs(0);
        printf("%d\n", fullmax);
    }

    return 0;
}