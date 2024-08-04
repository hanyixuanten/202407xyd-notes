#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int a, c;
        scanf("%lld%lld", &a, &c);
        if (a / c * (c + 1) > a)
            printf("%lld\n", c);
        else
            puts("-1");
    }
    return 0;
}