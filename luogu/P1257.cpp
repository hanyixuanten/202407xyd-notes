#include <bits/stdc++.h>
using namespace std;
double d;
double dmin = 1e9 + 10;
double x[10005], y[10005];
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                d = distance(x[i], y[i], x[j], y[j]);
                dmin = min(d, dmin);
            }
        }
    }
    printf("%.4lf", dmin);
    return 0;
}