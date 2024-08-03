#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q, ans;
int yl[N]; // 依赖的包
vector<int> yled[N];
bool ied[N];
void dfs(int x)
{
    if (!ied[x])
        return;
    for (int i = 0; i < yled[x].size(); ++i)
        if (ied[yled[x][i]])
            dfs(yled[x][i]);
    ied[x] = 0;
    ++ans;
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &yl[i]);
        yled[yl[i]].push_back(i);
    }
    scanf("%d", &q);
    while (q--)
    {
        ans = 0;
        string opt;
        int x, xbf;
        cin >> opt;
        scanf("%d", &x);
        if (opt == "install")
        {
            while (x != 0 && !ied[x])
                ied[x] = 1, ++ans, x = yl[x];
            if (x == 0 && !ied[0])
                ++ans, ied[0] = 1;
        }
        else
            dfs(x);
        printf("%d\n", ans);
    }
    return 0;
}