#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, P = 13331;
char s[N];
unsigned long long p[N], h[N];
int n, ans, last;
inline void init()
{
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] * P, h[i] = h[i - 1] * P + s[i];
}
inline unsigned long long get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        init();
        ans = 0, last = 0;
        for (int i = 1; i <= n / 2; ++i)
            if (get(last + 1, i) == get(n - i + 1, n - last))
                last = i, ans += 2;
        if (last * 2 < n)
            ++ans;
        printf("%d\n", ans);
    }

    return 0;
}