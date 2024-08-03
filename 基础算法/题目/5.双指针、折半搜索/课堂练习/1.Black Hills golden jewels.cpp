#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL a[100010];
LL n, k;
bool work(int x)
{
    LL r;
    for (int i = 1; i <= n; i++)
        if (a[i] > x)
        {
            r = i;
            break;
        }
    LL cnt = 0;
    for (LL i = 1; i < r; i++)
    {
        LL num = upper_bound(a + 1 + i, a + n + 1, x - a[i]) - a - 1 - i;
        cnt += num;
        if (cnt >= k)
            return 1;
        if (num == 0)
            break;
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (LL i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    LL l = a[1] + a[2], r = a[n] + a[n - 1];
    while (l <= r)
    {
        LL mid = (l + r) >> 1;
        if (work(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n",l);
}