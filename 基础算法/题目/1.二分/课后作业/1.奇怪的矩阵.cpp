#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, q;
ll a[100005];
vector<ll> s;
ll val, l, r;
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            if (i < j)
                s.push_back(a[j] - a[i]);
    sort(s.begin(), s.end());
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld%lld", &l, &r);
        ll ans = n * (r - l + 1);
        for (ll i = 0; i < s.size(); ++i) // ans-= cnt([l,r]%s[i]==0)
        {
            int ltmp = l, rtmp = r;
            if (ltmp % s[i] == 0)
                ++ltmp;
            if (rtmp % s[i] == 0)
                ++rtmp;
            while (ltmp % s[i] != 0)
                ++ltmp;
            while (rtmp % s[i] != 0)
                ++rtmp;
            ans -= (rtmp - ltmp) / s[i];
        }
        printf("%lld ", ans);
    }
    return 0;
}