#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[55][55];
char c[10005][10005] = {};
int xmax, ymax;
void draw(int x, int y, int h, bool _1, int fronth, int nowh)
{ // 以xy为左下角竖直画h个
    if (h == 0)
        return;
    // 前面
    if (_1)
    {
        c[x + 0][y] = '+', c[x + 0][y + 4] = '+';
        c[x + 1][y] = '|', c[x + 1][y + 4] = '|';
        c[x + 2][y] = '|', c[x + 2][y + 4] = '|';
        c[x + 3][y] = '+', c[x + 3][y + 4] = '+';
        c[x + 1][y + 1] = ' ', c[x + 1][y + 2] = ' ', c[x + 1][y + 3] = ' ';
        c[x + 2][y + 1] = ' ', c[x + 2][y + 2] = ' ', c[x + 2][y + 3] = ' ';
        c[x][y + 1] = '-', c[x][y + 2] = '-', c[x][y + 3] = '-';
        c[x + 3][y + 1] = '-', c[x + 3][y + 2] = '-', c[x + 3][y + 3] = '-';
        // 上面，侧面
        if (h == 1)
        {
            c[x + 4][y + 1] = '/', c[x + 4][y + 2] = ' ', c[x + 4][y + 3] = ' ', c[x + 4][y + 4] = ' ';
            c[x + 5][y + 2] = '+', c[x + 5][y + 3] = '-', c[x + 5][y + 4] = '-', c[x + 5][y + 5] = '-';
        }
        c[x + 5][y + 6] = '+';
        c[x + 4][y + 6] = '|';
        c[x + 3][y + 6] = '|', c[x + 3][y + 5] = ' ';
        c[x + 2][y + 6] = '+', c[x + 2][y + 5] = ' ';
        c[x + 1][y + 5] = '/';
        c[x + 4][y + 5] = '/';
        xmax = max(x + 5, xmax);
        ymax = max(y + 6, ymax);
        draw(x + 3, y, h - 1, true, fronth, nowh + 1);
    }
    else
    {
        if (fronth < nowh)
        {
            c[x - 3][y] = '+', c[x - 3][y + 4] = '+';
            c[x - 2][y] = '|', c[x - 2][y + 4] = '|';
            c[x - 1][y] = '|', c[x - 1][y + 4] = '|';
            c[x + 0][y] = '+', c[x + 0][y + 4] = '+';
            c[x - 2][y + 1] = ' ', c[x - 2][y + 2] = ' ', c[x - 2][y + 3] = ' ';
            c[x - 1][y + 1] = ' ', c[x - 1][y + 2] = ' ', c[x - 1][y + 3] = ' ';
            c[x - 3][y + 1] = '-', c[x - 3][y + 2] = '-', c[x - 3][y + 3] = '-';
            c[x + 0][y + 1] = '-', c[x + 0][y + 2] = '-', c[x + 0][y + 3] = '-';
        }
        c[x + 1][y + 2] = ' ';
        // c[x + 0][y + 2] = ' ';
        if (h == 1)
        {
            c[x + 1][y + 1] = '/', c[x + 1][y + 2] = ' ', c[x + 1][y + 3] = ' ', c[x + 1][y + 4] = ' ', c[x + 1][y + 5] = '/';
            c[x + 2][y + 2] = '+', c[x + 2][y + 3] = '-', c[x + 2][y + 4] = '-', c[x + 2][y + 5] = '-', c[x + 2][y + 6] = '+';
        }
        if (c[x + 1][y + 2] == '|')
            c[x + 1][y + 2] = ' ';
        if (c[x + 0][y + 2] == '|')
            c[x + 0][y + 2] = ' ';
        // c[x + 1][y + 6] = (c[x + 1][y + 6] == '-') ? '-' : '|';
        c[x + 1][y + 6] = '|';
        // c[x + 0][y + 6] = (c[x + 0][y + 6] == '-') ? '-' : '|';
        c[x + 0][y + 6] = '|';
        // c[x + 0][y + 5] = (c[x + 0][y + 5] == '-') ? '-' : ' ';
        c[x + 0][y + 5] = ' ';
        // c[x - 1][y + 5] = (c[x - 1][y + 5] == '-') ? '-' : ' ';
        c[x - 1][y + 5] = ' ';
        // c[x - 1][y + 6] = (c[x - 1][y + 6] == '-') ? '-' : '+';
        c[x - 1][y + 6] = '+';
        c[x - 2][y + 5] = '/';
        xmax = max(x + 2, xmax);
        ymax = max(y + 6, ymax);
        draw(x + 3, y, h - 1, false, fronth, nowh + 1);
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1058_2.in", "r", stdin);
    freopen("tmp.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m); // n行
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    int yy = 2500;
    int x = 2500, y;
    for (int i = 1; i <= n; ++i)
    {
        y = yy;
        if (i == n)
            x -= 3;
        for (int j = 1; j <= m; ++j)
        {
            draw(x, y, a[i][j], (i == n), a[i + 1][j], 1);
            y += 4;
        }
        yy -= 2, x -= 2;
    }
    int fx = INT_MAX, fy = INT_MAX, lx = 0, ly = 0;
    for (int i = 0; i <= 5000; ++i)
    {
        bool flag = 1;
        for (int j = 0; j <= 5000; ++j)
        {
            if (c[i][j] != 0)
                flag = 0, ly = max(ly, j), fy = min(fy, j);
        }
        if (flag == 0)
            lx = max(lx, i), fx = min(fx, i);
    }
    // printf("fx=%d lx=%d",fx,lx);
    for (int i = lx; i >= fx; --i)
    {
        bool flag = 1;
        for (int j = fy; j <= ly; ++j)
            printf("%c", (c[i][j] == 0) ? '.' : c[i][j]);
        puts("");
    }
    return 0;
}
/*
从第m行第一列的元素开始渲染，存在[0][0]处，倒序输出
*/