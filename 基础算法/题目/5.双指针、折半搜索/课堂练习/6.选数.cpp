#include <bits/stdc++.h>
using namespace std;
int ans = 0, n, k, a[25];
bool e(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    for (int i = 2; i * i <= x + 1; ++i)
        if (x % i == 0)
            return false;
    return true;
}
void r(int st, int c, int s)
{
    if (c == k && e(s))
        ++ans;
    for (int i = st; i <= n; ++i)
        r(i + 1, c + 1, s + a[i]);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    r(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}