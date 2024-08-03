#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1000005;
int n;
int pre1[MAXN], pre2[MAXN], a[MAXN], q[MAXN];
int ll = 1, rr, ans;
int xx(int i);
int yy(int i);
long double divi(int a, int b)
{
    return (yy(a) - yy(b)) * 1.0 / (xx(a) - xx(b));
}
int ww(int l, int r)
{
    return pre2[r] - pre2[l - 1] - (l - 1) * (pre1[r] - pre1[l - 1]);
}
int xx(int i)
{
    return i - 1;
}
int yy(int i)
{
    return (i - 1) * pre1[i - 1] - pre2[i - 1];
}

int Search(int x)
{
    if (ll > rr)
        return 0;
    int l = ll, r = rr;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (divi(q[mid - 1], q[mid]) >= pre1[x])
            l = mid;
        else
            r = mid - 1;
    }
    return q[l];
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
        ans = max(ans, a[i]);
        pre1[i] = pre1[i - 1] + a[i], pre2[i] = pre2[i - 1] + i * a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int j = Search(i);
        if (j)
            ans = max(ans, ww(j, i));
        while (ll < rr && divi(i, q[rr]) >= divi(q[rr], q[rr - 1]))
            rr--;
        q[++rr] = i;
    }
    printf("%lld",&ans);
    return 0;
}
