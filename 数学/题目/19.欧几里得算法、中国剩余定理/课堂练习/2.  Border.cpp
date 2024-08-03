#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
vector<int> q;
signed main()
{
    int n, k;
    int ans;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        if (i == 1)
            ans = a[1];
        else
            ans = __gcd(ans, a[i]);
    }
    ans = __gcd(ans, k);
    int ns = 0;
    while (ans * ns < k)
    {
        q.push_back(ns * ans);
        ++ns;
    }
    printf("%lld\n", q.size());
    for (int i : q)
        printf("%lld ", i);
    puts("");
    return 0;
}