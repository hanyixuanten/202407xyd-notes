#include <bits/stdc++.h>
using namespace std;
int n;
double x[20], y[20];
double d[20][20];
double dis(int x1, int y1, int x2, int y2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j] = dis(x[i], y[i], x[j], y[j]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }

    return 0;
}