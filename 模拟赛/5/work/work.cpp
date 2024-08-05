#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, T;
struct node
{
    int t, p;
    const bool operator<(const node &x) const
    {
        return t < x.t;
    }
} tim[100005];
namespace n5 // 40pts+eps
{
    bool chosen[15];
    int ans = 0;
    int Time = 0;
    void dfs(int dep)
    {
        if (dep == n)
            return;
        for (int i = 1; i <= n; ++i)
        {
            if (!chosen[i])
            {
                Time += tim[i].t + dep * tim[i].p;
                chosen[i] = 1;
                if (Time <= T)
                {
                    ans = max(ans, dep + 1);
                    dfs(dep + 1);
                }
                Time -= tim[i].t + dep * tim[i].p;
                chosen[i] = 0;
            }
        }
        return;
    }
    void main()
    {
        dfs(0);
        printf("%lld\n", ans);
        return;
    }
}
signed main()
{
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
    scanf("%lld%lld", &n, &T);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &tim[i].t);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &tim[i].p);
    sort(tim + 1, tim + n + 1);
    n5::main();
    return 0;
}