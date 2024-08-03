#include <bits/stdc++.h>
#include<cmath>
using namespace std;
double x;
double l, r, mid;
int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lf", &x);
        l = 0, r = x;
        while (r - l >= 1e-8)
        {
            mid = (l + r) / 2;
            if (mid * mid >= x / mid)
                r = mid;
            else
                l = mid;
        }

        printf("%.4lf\n", mid);
    }
    return 0;
}
