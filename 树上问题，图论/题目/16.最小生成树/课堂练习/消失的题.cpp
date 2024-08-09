#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
int a[200005];
vector<int> b;
int c = 0;
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; ++i)
        b.push_back(a[i]);
    sort(b.begin(), b.end());
    for (int i = 0; i < k; ++i)
        c += b[i];
    printf("%lld ", c);
    for (int i = 2; i <= n - m + 1; ++i)
    {
        auto l = lower_bound(b.begin(), b.end(), a[i - 1]); // 删除
        if (l - b.begin() < k)
            c += b[k] - *l;
        b.erase(l);
        b.emplace(upper_bound(b.begin(), b.end(), a[i + m - 1]), a[i + m - 1]); // 插入
        auto r = (lower_bound(b.begin(), b.end(), a[i + m - 1]));
        if (r - b.begin() < k)
            c += a[i + m - 1] - b[k];
        printf("%lld ", c);
    }
    puts("");
    return 0;
}