#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
struct node
{
    int d, p;
    const bool operator<(const node &x) const
    {
        return d < x.d;
    }
} dp[maxn];
priority_queue<int, vector<int>, greater<int>> q;
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &dp[i].d, &dp[i].p);
    sort(dp + 1, dp + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q.size() < dp[i].d)
        {
            q.push(dp[i].p);
            ans += dp[i].p;
        }
        else if (q.top() < dp[i].p)
        {
            ans -= q.top();
            ans += dp[i].p;
            q.pop();
            q.push(dp[i].p);
        }
    }
    printf("%lld\n", ans);
    return 0;
}