#include <bits/stdc++.h>
using namespace std;
char c[5000][5000];
bool flag;
int n, m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF1495C.in", "r", stdin);
#endif
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d %d\n", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                c[i][j] = getchar();
            getchar();
        }
        for (int i = 1; i <= n; i += 3)
        {
            flag = 0;
            for (int j = 1; j <= m; ++j)
            {
                c[i + 1][j] = 'X';
                if (i == n)
                {
                    if (c[i - 1][j] == 'X')
                        flag = 1;
                    c[i][j] = 'X';
                }
                else
                {
                    if (c[i - 1][j] == 'X' || c[i][j] == 'X')
                    {
                        c[i][j] = 'X', c[i - 1][j] = 'X';
                        flag = 1;
                    }
                }
            }
            if (!flag)
                c[i][1] = 'X', c[i - 1][1] = 'X';
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                putchar(c[i][j]);
            puts("");
        }
    }
}